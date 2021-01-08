#include "pch.h"
#include "SO_pen.h"

IMPLEMENT_SERIAL(SO_pen, SO_shape, 1)

SO_pen::SO_pen() {};

SO_pen::SO_pen(int size, COLORREF front, COLORREF back) : SO_shape(size, front, back) {};

void SO_pen::drawShape(CPaintDC& dc) {

	CPen myPen(PS_SOLID, sizeOfLine, _front);
	CPen* oldPen = dc.SelectObject(&myPen);
	dc.MoveTo(getBegin().x,getBegin().y); // get mouse begin Point
	dc.LineTo(getEnd().x, getEnd().y); // get mouse end Point & draw free style Pen
	dc.SelectObject(oldPen);
}
