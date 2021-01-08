#include "pch.h"
#include "SO_quadrilateral.h"


IMPLEMENT_SERIAL(SO_quadrilateral, SO_shape, 1)

SO_quadrilateral::SO_quadrilateral() {};
SO_quadrilateral::SO_quadrilateral(int size, COLORREF front, COLORREF back) :SO_shape(size, front, back) {};

void SO_quadrilateral::drawShape(CPaintDC& dc) {};
bool SO_quadrilateral::isIn(CPoint& p) {return false;};