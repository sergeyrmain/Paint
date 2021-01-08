#pragma once
#include "SO_shape.h"
#include "SO_quadrilateral.h"

class SO_quadrilateral :
    public SO_shape
{
	DECLARE_SERIAL(SO_quadrilateral)
    SO_quadrilateral();
    SO_quadrilateral(int size, COLORREF front, COLORREF back);
	virtual void drawShape(CPaintDC& dc);
	virtual bool isIn(CPoint& p);
};

