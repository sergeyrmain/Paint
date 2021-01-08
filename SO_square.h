#pragma once
#include "SO_rectanle.h"
class SO_square :
    public SO_quadrilateral
{
    DECLARE_SERIAL(SO_square)
    SO_square();
    SO_square(int size, COLORREF front, COLORREF back);
    void drawShape(CPaintDC& dc);
    bool isIn(CPoint& p);
};

