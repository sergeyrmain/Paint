#include "pch.h"
#include "SO_Line.h"
#include <algorithm>
using namespace std;

IMPLEMENT_SERIAL(SO_Line, SO_shape, 1)

SO_Line::SO_Line() {};
SO_Line::SO_Line(int size, COLORREF front, COLORREF back) : SO_shape(size, front, back) {};
void SO_Line::drawShape(CPaintDC& dc) {
	dc.MoveTo(getBegin().x, getBegin().y); // start Point of line
	dc.LineTo(getEnd().x, getEnd().y); // end Point of line and then draw Line
};
