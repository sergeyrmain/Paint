#pragma once
#include <vector>
#include "SO_shape.h"
using namespace std;

class So_spray :
    public SO_shape
{
    DECLARE_SERIAL(So_spray)
    So_spray();
    So_spray(int size, COLORREF front, COLORREF back);
    void drawShape(CPaintDC& dc);
    void addPoints();
    CPoint randomPixel;

private:
    vector<int> Dx;
    vector<int> Dy;
};

