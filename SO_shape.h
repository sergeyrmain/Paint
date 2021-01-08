#pragma once
#include <afx.h>
#include <cmath>
class SO_shape :
	public CObject
{
public:
	CPoint begin, end;
	COLORREF _front, _back;
	int sizeOfLine;

	DECLARE_SERIAL(SO_shape)
	SO_shape();
	SO_shape(int size, COLORREF front, COLORREF back);
	void setBegin(const CPoint& p);
	void setEnd(const CPoint& p);
	void draw(CPaintDC& dc);
	CPoint getBegin();
	CPoint getEnd();
	void Serialize(CArchive& archive);
	virtual void drawShape(CPaintDC& dc);
	virtual bool isIn(CPoint& p);
};
