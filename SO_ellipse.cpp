#include "pch.h"
#include "SO_ellipse.h"

IMPLEMENT_SERIAL(SO_ellipse, SO_shape, 1)

SO_ellipse::SO_ellipse() {};
SO_ellipse::SO_ellipse(int size, COLORREF front, COLORREF back) : SO_shape(size, front, back) {};

void SO_ellipse::drawShape(CPaintDC& dc) {
	dc.Ellipse(getBegin().x, getBegin().y, getEnd().x, getEnd().y); // draw Ellipse
}
bool SO_ellipse::isIn(CPoint& p) {
	CPoint middle;
	double length, hight;
	middle.SetPoint((getBegin().x + getEnd().x) / 2, (getBegin().y + getEnd().y) / 2); // find the middle of the shape

	length = abs(getBegin().x - middle.x);
	hight = abs(getBegin().y - middle.y);
	if ((((p.x - middle.x) * (p.x - middle.x) / 
		(length * length)) + ((p.y - middle.y) * (p.y - middle.y)
			/ (hight * hight))) <= 1) // Furmula for finding if a point is in Ellipse/Circle
		return true;
	return false;
};