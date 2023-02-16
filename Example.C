{

	TF1 *f1=new TF1("F1","gaus",-50,50);
	f1->SetParameters(1.0,0,5.0);
	
	TH1F *h1=new TH1F("TH1F","Gaus distrib", 2000,-50,50);
	
	int n=10000;
	TGraph *G=new TGraph(n);
	
	for (int i=0; i<n; i++) {
		G->SetPoint(i,i, (i/100.0)+f1->GetRandom());
	}

	//You have to draw the plot before using the function
	G->Draw("AP");
	
	//x and y contains coordinates of the selected points
	vector<vector<double>> Data=Select_data(G);
	double *x=Data[0].data();
	double *y=Data[1].data();
	
	//Highlighting of the points just for a better visualisation of the slection
	TGraph *G2=new TGraph(Data[0].size(),x,y);
	G2->SetMarkerColor(kRed);
	G2->Draw("PSAME");
	
}


std::vector<vector<double>> Select_data(TGraph *plot) {

	//gcut allows to draw the area on the plot 
	//cout<<"Draw the area on the figure. Each click place a point, double click to close the area"<<endl;
	TCutG *gcut = (TCutG*)gPad->WaitPrimitive("CUTG","CutG");
	double *x=plot->GetX();
	double *y=plot->GetY();
	
	
	
	vector<double> xc;
	vector<double> yc;
	
	//Loop to check which points are inside the area
	
	for (int i=0; i<plot->GetN(); i++) {
		if (gcut->IsInside(x[i],y[i])==1) {
			xc.push_back(x[i]);
			yc.push_back(y[i]);
		}
	}
	
	//return the points inside the drawn areas
	
	vector<vector<double>> Datas;
	Datas.push_back(xc);
	Datas.push_back(yc);
	
	return Datas;
}
