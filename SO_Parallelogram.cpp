#include "pch.h"
#include "SO_parallelogram.h"


IMPLEMENT_SERIAL(SO_parallelogram, SO_quadrilateral, 1)
SO_parallelogram::SO_parallelogram() {};
SO_parallelogram::SO_parallelogram(int size, COLORREF front, COLORREF back) :SO_quadrilateral(size, front, back) {};
void SO_parallelogram::drawShape(CPaintDC& dc) {
	CPoint b, c;
	int side;
	side = (getEnd().x - getBegin().x)/2;
	b.SetPoint(getBegin().x + side, getBegin().y); 
	c.SetPoint(getEnd().x - side, getEnd().y);
	CPoint points[4] = { begin, b, end, c }; // setting Points array for parallelogram polygon 
	dc.Polygon(points, 4); //draw Parallelogram

};

bool SO_parallelogram::isIn(CPoint& p) { // Parallelogram is composed from 2 overlapping triangles 
	CPoint b, c;
	int dx;
	dx = (getEnd().x - getBegin().x) / 2;
	b.SetPoint(getBegin().x + dx, getBegin().y);
	c.SetPoint(getEnd().x - dx, getEnd().y);

	// Calculate ABC (=BCE) triangle area
	double ABC = abs((getBegin().x * (b.y - c.y) + b.x * (c.y - getBegin().y) + c.x * (getBegin().y - b.y)) / 2); 

	// Calculate ABP triangle area
	double ABP = abs((getBegin().x * (b.y - p.y) + b.x * (p.y - getBegin().y) + p.x * (getBegin().y - b.y)) / 2);
	// Calculate APC triangle area
	double APC = abs(getBegin().x * (p.y - c.y) + p.x * (c.y - getBegin().y) + c.x * (getBegin().y - p.y)) / 2; 
	// Calculate PBC triangle area
	double PBC = abs(p.x * (b.y - c.y) + b.x * (c.y - p.y) + c.x * (p.y - b.y)) / 2;  
	
	// Calculate BPE triangle area
	double BPE = abs((b.x * (getEnd().y - p.y) + getEnd().x * (p.y - b.y) + p.x * (b.y - getEnd().y)) / 2); 
	// Calculate CPE triangle area
	double CPE = abs(b.x * (p.y - c.y) + p.x * (c.y - b.y) + c.x * (b.y - p.y)) / 2; 
	// Calculate BPC triangle area
	double BPC =abs(p.x * (getEnd().y - c.y) + getEnd().x * (c.y - p.y) + c.x * (p.y - getEnd().y)) / 2; 

	// Check if mouse Point is within ABC or BCE triangles 
	if (((ABP + APC + PBC - ABC)<=1) ||  ((BPE+CPE+BPC-ABC)<=1)) 
	{
		return true; // is in the Parallelogram!
	}
	return false; // is not in the Parallelogram!
};
