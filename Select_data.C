






std::vector<vector<double>> Select_data(TGraph *plot) {

	//gcut allows to draw the area on the plot 

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
