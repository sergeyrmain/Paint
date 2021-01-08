#pragma once
#include "SO_shape.h"
class SO_pen :
    public SO_shape
{
    DECLARE_SERIAL(SO_pen);
    SO_pen();
    SO_pen(int size, COLORREF front, COLORREF back);
    void drawShape(CPaintDC& dc);
};