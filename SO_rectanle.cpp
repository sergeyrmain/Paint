#include "pch.h"
#include "SO_rectanle.h"
IMPLEMENT_SERIAL(SO_rectanle, SO_quadrilateral, 1)


SO_rectanle::SO_rectanle() {};
SO_rectanle::SO_rectanle(int size, COLORREF front, COLORREF back) :SO_quadrilateral(size, front, back){};


void SO_rectanle::drawShape(CPaintDC& dc) {
	dc.Rectangle(getBegin().x, getBegin().y,getEnd().x, getEnd().y); // draw Rectangle 

};


bool SO_rectanle::isIn(CPoint& p)
{
	// Check if mouse Point is between Delta X of the the Rectangle
	if (p.x > min(getEnd().x, getBegin().x) && p.x < max(getEnd().x, getBegin().x))
	{
		// Check if mouse Point is between Delta Y of the the Rectangle
		if (p.y > min(getEnd().y, getBegin().y) && p.y < max(getEnd().y, getBegin().y))
		{
			return true; // is in Rectangle!
		}
	}
	return false; //is not in Rectangle!
}
