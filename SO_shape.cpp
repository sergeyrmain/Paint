#include "pch.h"
#include "So_shape.h"

IMPLEMENT_SERIAL(SO_shape, CObject, 1)


SO_shape::SO_shape() {};
SO_shape::SO_shape(int size, COLORREF front, COLORREF back) :sizeOfLine(size), _front(front), _back(back) {}

void SO_shape::setBegin(const CPoint& p) { begin = p; }

void SO_shape::setEnd(const CPoint& p) { end = p; }

// draw Function will care for Colors and sizing of the Shape
void SO_shape::draw(CPaintDC& dc) { 
	CPen pen(PS_SOLID, sizeOfLine, _front);
	CBrush brush(_back);
	CPen* oldPen = dc.SelectObject(&pen);
	CBrush* oldBrush = dc.SelectObject(&brush);

	// drawShape Function will draw the exact shape with the color and size settings as configured 
	drawShape(dc); 
	dc.SelectObject(oldPen);
	dc.SelectObject(oldBrush);
};
CPoint SO_shape::getBegin() { return begin; };
CPoint SO_shape::getEnd() { return end; };
void SO_shape::drawShape(CPaintDC& dc) {};
void SO_shape::Serialize(CArchive& archive) // Load/Save Functions
{
	CObject::Serialize(archive);
	if (archive.IsStoring())
		archive << begin.x << begin.y << end.x << end.y << _back << _front << sizeOfLine;
	else
		archive >> begin.x >> begin.y >> end.x >> end.y >> _back >> _front >> sizeOfLine;
}

bool SO_shape::isIn(CPoint& p) { return false; };
