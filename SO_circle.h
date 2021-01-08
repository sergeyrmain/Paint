#pragma once
#include "SO_ellipse.h"
class SO_circle :
	public SO_ellipse
{
public:
	DECLARE_SERIAL(SO_circle)
	SO_circle();
	SO_circle(int size, COLORREF front, COLORREF back);
	void drawShape(CPaintDC& dc);
	
	//isIn function is taken from Ellipse Class
};

