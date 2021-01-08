
// SergeyOr3Dlg.h : header file
//

#pragma once
#include "SO_shape.h"
#include "afxwin.h"
#include <stack>
#include <vector>
using namespace std;

// CSergeyOr3Dlg dialog
class CSergeyOr3Dlg : public CDialogEx
{
// Construction
public:
	CSergeyOr3Dlg(CWnd* pParent = nullptr);	// standard constructor
	COLORREF frontH, backH;
	int sizeOfLine;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SERGEYOR3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()


private:
	bool isPressed;
	SO_shape* getShape();
	int typeOfShape;
	CTypedPtrArray<CObArray, SO_shape*> shapes;
	stack<SO_shape*> removed;
	bool penMode;

public:
	COLORREF RefillColor;
	bool isInRange(CPoint& p);
	BOOL fill_in=false;
	HCURSOR hcur;
	CRect rect;
	CMFCColorButton frontColorButton;
	CMFCColorButton backColorButton;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedRctangle();
	afx_msg void OnBnClickedEllipse1();
	afx_msg void OnBnClickedsquare();
	afx_msg void OnBnClickedLine();
	afx_msg void OnBnClickedMfccolorbutton1();
	afx_msg void OnBnClickedMfccolorbutton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedsave();
	afx_msg void OnBnClickedLoad();
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedundo1();
	afx_msg void OnBnClickedredo1();
	afx_msg void OnBnClickedPen();
	afx_msg void OnBnClickedspray();
	afx_msg void OnBnClickedcircle();
	afx_msg void OnBnClickedfill();
	afx_msg void OnBnClickedParallelogram();
};
