#include "pch.h"
#include "SO_square.h"

IMPLEMENT_SERIAL(SO_square, SO_quadrilateral, 1)

SO_square::SO_square() {};
SO_square::SO_square(int size, COLORREF front, COLORREF back):SO_quadrilateral(size,front,back){};
void SO_square::drawShape(CPaintDC& dc)
{
	int height, width;
	height = abs(getBegin().y - getEnd().y);
	width = abs(getBegin().x -getEnd().x);
	if (height > width) // if Delta(y) > Delta(x) 
	{ 
		if (getEnd().y > getBegin().y)
			setEnd(CPoint(getEnd().x, getBegin().y + width)); // adding width to Y.begin value to make a Square
		else
			setEnd(CPoint(getEnd().x, getBegin().y - width)); // reducing width to Y.begin value to make a Square

	}
	else {
		if (getEnd().x > getBegin().x)
			setEnd(CPoint(getBegin().x + height, getEnd().y)); // adding width to X.begin value to make a Square
		else
			setEnd(CPoint(getBegin().x - height, getEnd().y)); // reducing width to X.begin value to make a Square

	}
	dc.Rectangle(getBegin().x, getBegin().y,getEnd().x, getEnd().y); // draw Square
};


bool SO_square::isIn(CPoint& p) {
	// Check if mouse Point is between Delta X of the the Square
	if (p.x > min(getEnd().x, getBegin().x) && p.x < max(getEnd().x, getBegin().x))
	{
		// Check if mouse Point is between Delta Y of the the Square
		if (p.y > min(getEnd().y, getBegin().y) && p.y < max(getEnd().y, getBegin().y))
		{
			return true; // is in Square!
		}
	}
	return false; // is not in Square!
};

