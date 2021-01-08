#include "pch.h"
#include "SO_circle.h"
using namespace std;


IMPLEMENT_SERIAL(SO_circle, SO_ellipse, 1)

SO_circle::SO_circle() {};
SO_circle::SO_circle(int size, COLORREF front, COLORREF back) : SO_ellipse(size, front, back) {};

void SO_circle::drawShape(CPaintDC& dc) {
	int height, width;
	width = abs(getBegin().x - getEnd().x);
	height = abs(getBegin().y - getEnd().y);

	if (height > width) { // if Delta(y) > Delta(x) 
		if (getEnd().y > getBegin().y)
			setEnd(CPoint(getEnd().x, getBegin().y + width)); // adding width to Y.begin value to make a circle
		else
			setEnd(CPoint(getEnd().x, getBegin().y - width)); // reducing width to Y.begin value to make a circle

	}
	else {  // if Delta(x) > Delta(y) 
		if (getEnd().x > getBegin().x)
			setEnd(CPoint(getBegin().x + height, getEnd().y)); // adding height to X.begin value to make a circle
		else
			setEnd(CPoint(getBegin().x - height, getEnd().y)); // reducing height to X.begin value to make a circle
	}
	dc.Ellipse(getBegin().x, getBegin().y, getEnd().x, getEnd().y); // draw Circle
};
