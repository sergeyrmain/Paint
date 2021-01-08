#pragma once
#include "SO_shape.h"
#include "SO_quadrilateral.h"

class SO_rectanle :
    public SO_quadrilateral
{
    DECLARE_SERIAL(SO_rectanle)
    SO_rectanle();
    SO_rectanle(int size, COLORREF front, COLORREF back);
    void drawShape(CPaintDC& dc);
    bool isIn(CPoint& p);
};

