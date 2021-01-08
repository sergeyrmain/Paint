#pragma once
#include "SO_shape.h"
class SO_ellipse :
	public SO_shape
{
public:
	DECLARE_SERIAL(SO_ellipse)
	SO_ellipse();
	SO_ellipse(int size, COLORREF front, COLORREF back);
	void drawShape(CPaintDC& dc);
	bool isIn(CPoint& p);
};

