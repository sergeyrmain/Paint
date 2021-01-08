#pragma once
#include "SO_shape.h"
class SO_Line :
    public SO_shape
{
    DECLARE_SERIAL(SO_Line)
    SO_Line();
    SO_Line(int size, COLORREF front, COLORREF back);
    void drawShape(CPaintDC& dc);
};

