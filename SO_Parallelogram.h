#pragma once
#include "SO_quadrilateral.h"
class SO_parallelogram :
    public SO_quadrilateral
{
    DECLARE_SERIAL(SO_parallelogram)
    SO_parallelogram();
    SO_parallelogram(int size, COLORREF front, COLORREF back);
    void drawShape(CPaintDC& dc);
    bool isIn(CPoint& p);
};

