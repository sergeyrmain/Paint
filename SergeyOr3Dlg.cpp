
// SergeyOr3Dlg.cpp : implementation file
//
#include "pch.h"
#include "framework.h"
#include "SergeyOr3.h"
#include "SergeyOr3Dlg.h"
#include "afxdialogex.h"
#include "SO_shape.h"
#include "SO_ellipse.h"
#include "SO_rectanle.h"
#include "SO_square.h"
#include "SO_quadrilateral.h"
#include "SO_Line.h"
#include "So_pen.h"
#include "So_spray.h"
#include "SO_circle.h"
#include "SO_parallelogram.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSergeyOr3Dlg dialog




CSergeyOr3Dlg::CSergeyOr3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SERGEYOR3_DIALOG, pParent)
	, isPressed(false), frontH(RGB(0, 0, 0)), backH(RGB(255, 255, 255)), sizeOfLine(0), typeOfShape(0)
	,fill_in(false),shapes()

{
	hcur = AfxGetApp()->LoadCursorW(MAKEINTRESOURCE(IDC_AFXBARRES_LINE));
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	frontColorButton.SetColor(frontH);
	backColorButton.SetColor(backH);

}

void CSergeyOr3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, frontColorButton);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON2, backColorButton);
//	DDX_Check(pDX, OnBnClickedCheck2, fill_in);


}

BEGIN_MESSAGE_MAP(CSergeyOr3Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_Ellipse1, &CSergeyOr3Dlg::OnBnClickedEllipse1)
	ON_BN_CLICKED(IDC_Rctangle, &CSergeyOr3Dlg::OnBnClickedRctangle)
	ON_BN_CLICKED(IDC_square, &CSergeyOr3Dlg::OnBnClickedsquare)
	ON_BN_CLICKED(IDC_Line, &CSergeyOr3Dlg::OnBnClickedLine)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &CSergeyOr3Dlg::OnBnClickedMfccolorbutton1)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON2, &CSergeyOr3Dlg::OnBnClickedMfccolorbutton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CSergeyOr3Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSergeyOr3Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_save, &CSergeyOr3Dlg::OnBnClickedsave)
	ON_BN_CLICKED(IDC_Load, &CSergeyOr3Dlg::OnBnClickedLoad)
	ON_BN_CLICKED(IDC_Clear, &CSergeyOr3Dlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_undo1, &CSergeyOr3Dlg::OnBnClickedundo1)
	ON_BN_CLICKED(IDC_redo1, &CSergeyOr3Dlg::OnBnClickedredo1)
	ON_BN_CLICKED(IDC_Pen, &CSergeyOr3Dlg::OnBnClickedPen)
	ON_BN_CLICKED(IDC_spray, &CSergeyOr3Dlg::OnBnClickedspray)
	ON_BN_CLICKED(IDC_circle, &CSergeyOr3Dlg::OnBnClickedcircle)
	ON_BN_CLICKED(IDC_fill, &CSergeyOr3Dlg::OnBnClickedfill)
	ON_BN_CLICKED(IDC_Parallelogram, &CSergeyOr3Dlg::OnBnClickedParallelogram)
END_MESSAGE_MAP()


// CSergeyOr3Dlg message handlers

BOOL CSergeyOr3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSergeyOr3Dlg::OnPaint()
{

	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this); // device context for painting
		dc.Rectangle(200, 70, 1350, 600); //Create Board 
		for (int i = 0; i < shapes.GetSize(); i++) {
			shapes[i]->draw(dc); // Polimorfizem of draw shapes
		}
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSergeyOr3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// Create Shapes according to button typeOfShape value
SO_shape* CSergeyOr3Dlg::getShape() {
	SO_shape* s=NULL;
	switch (typeOfShape) {
	case 1:
		// Create Ellipse
		s = (SO_shape*)new SO_ellipse(sizeOfLine, frontH, backH);
		break;
	case 2:
		// Create Retangle
		s = (SO_shape*)new SO_rectanle(sizeOfLine, frontH, backH);
		break;
	case 3:
		// Create Line
		s = (SO_shape*)new SO_Line(sizeOfLine, frontH, backH);
		break;

	case 4:
		// Create Square
		s = (SO_shape*)new SO_square(sizeOfLine, frontH, backH);
		break;
	case 5:
		// Create Free Style Pen
		s = (SO_shape*)new SO_pen(sizeOfLine, frontH, backH);
		break;
	case 6:
		// Create Free Style Spray
		s = (SO_shape*)new So_spray(sizeOfLine, frontH, backH);
		break;
	case 7:
		// Create Circle
		s = (SO_shape*)new SO_circle(sizeOfLine, frontH, backH);
		break;
	case 8:
		// Create Parallelogram
		s = (SO_shape*)new SO_parallelogram(sizeOfLine, frontH, backH);
		break;
	}
	return s;
}

// Check is Point is In Board domain
bool CSergeyOr3Dlg::isInRange(CPoint& point)
{
	if ((point.x >= 200) && (point.x <= 1350) && (point.y >= 70) && (point.y <= 600)) // Board Domain Values
		return true;
	else
		return false;
}


void CSergeyOr3Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (typeOfShape != 0) { 
		if (isInRange(point))
		{
			if (fill_in) { // check if fill-in style is enabled
				for (int i = shapes.GetSize() - 1; i >= 0; i--) { // find the correct shape and fill-in color
					if (shapes[i]->isIn(point)) {
						shapes[i]->_front = frontH; // change front/line color
						shapes[i]->_back = backH; // change background color
						shapes[i]->sizeOfLine = this->sizeOfLine; // change size of line
						Invalidate();
						return;
					}
				}
				return;
			}
			
			SO_shape* s; // create a pointer to 1 shape 
			s = getShape(); // get shape type into s pointer
			shapes.Add(s); // add new shape to shapes array
			s->setBegin(point); 
			s->setEnd(point);
			isPressed = true;
			Invalidate();

		}
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CSergeyOr3Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// Check if shape is within the Board Domain
	if (isInRange(point)) {
		isPressed = false;
		if (!fill_in) {
			if (shapes.GetSize() > 0) {
				shapes[shapes.GetSize() - 1]->setEnd(point);
			}
		}
		Invalidate();

	}
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CSergeyOr3Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (isInRange(point)) {
		if (isPressed) // check if mouse button is hold clicked 
		{
			if (!penMode) { // Preview of shape while drawing it
				shapes[shapes.GetSize() - 1]->setEnd(CPoint(point.x, point.y)); // setting new end point
			}
			else { // Pen & Spray Draw Movement
				shapes[shapes.GetSize() - 1]->setEnd(CPoint(point.x, point.y)); // setting new end point
				shapes.Add(getShape()); // Each piece of Pen / Spray is added to shapes array
				shapes[shapes.GetSize() - 1]->setBegin(CPoint(point.x, point.y)); // setting new begining point
				shapes[shapes.GetSize() - 1]->setEnd(CPoint(point.x, point.y)); // setting new end point
			}
			Invalidate();
		}
	}
	CDialogEx::OnMouseMove(nFlags, point);
}

void CSergeyOr3Dlg::OnBnClickedEllipse1()
{
	if (IsDlgButtonChecked(IDC_Ellipse1))
	{
	//Ellipse
	typeOfShape = 1;
	if (!fill_in) {
		hcur = AfxGetApp()->LoadCursorW(MAKEINTRESOURCE(IDC_AFXBARRES_ELLIPSE));
		SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)hcur);
		penMode = false;
		}
	}
}

void CSergeyOr3Dlg::OnBnClickedRctangle()
{
	if (IsDlgButtonChecked(IDC_Rctangle))
	{
		//Rectangle		
		typeOfShape = 2;
		if (!fill_in) {
			hcur = AfxGetApp()->LoadCursorW(MAKEINTRESOURCE(IDC_AFXBARRES_RECT));
			SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)hcur);
			penMode = false;
		}
	}
}

void CSergeyOr3Dlg::OnBnClickedsquare()
{
	if (IsDlgButtonChecked(IDC_square))
	{
		//square
		typeOfShape = 4;
		if (!fill_in) {
			hcur = AfxGetApp()->LoadCursorW(MAKEINTRESOURCE(IDC_AFXBARRES_RECT));
			SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)hcur);
			penMode = false;
		}
	}
}

void CSergeyOr3Dlg::OnBnClickedLine()
{
	if (IsDlgButtonChecked(IDC_Line))
	{
		//Line
		typeOfShape = 3;
		if (!fill_in) {
			hcur = AfxGetApp()->LoadCursorW(MAKEINTRESOURCE(IDC_AFXBARRES_LINE));
			SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)hcur);
			penMode = false;
		}
	}
}

// Front/Line color choice
void CSergeyOr3Dlg::OnBnClickedMfccolorbutton1()
{
	frontH = frontColorButton.GetColor();
}

// Background color choice
void CSergeyOr3Dlg::OnBnClickedMfccolorbutton2()
{
	backH=backColorButton.GetColor();
}

//Reduce size of Line
void CSergeyOr3Dlg::OnBnClickedButton1()
{
	if (sizeOfLine > 1)
	{
		sizeOfLine--;
		UpdateData(false);
	}
}

//Increase size of Line
void CSergeyOr3Dlg::OnBnClickedButton2()
{
	if (sizeOfLine < 50)
	{
		sizeOfLine++;
		UpdateData(false);
	}
}

// Serialization - Save Function
void CSergeyOr3Dlg::OnBnClickedsave()
{
	CFile file;
	CFileDialog FileDlg(TRUE);
	FileDlg.m_ofn.lpstrFilter = _T("DATA Files (*.dat)\0*.dat\0");
	FileDlg.m_ofn.lpstrTitle = _T("Save DATA File As");
	CString filename;
	if (FileDlg.DoModal() == IDOK)
	{
		filename = FileDlg.GetPathName();
		filename.Append(_T(".dat"));
	}
	if (file.Open(filename, CFile::modeCreate | CFile::modeWrite))
	{
		CArchive ar(&file, CArchive::store);
		shapes.Serialize(ar);
		ar.Close();
	}
	else
		return;
	file.Close();
}

// Serialization - Load Function
void CSergeyOr3Dlg::OnBnClickedLoad()
{
	CFile file;
	CFileDialog FileDlg(TRUE);
	FileDlg.m_ofn.lpstrFilter = _T("DATA Files (*.dat)\0*.dat\0");
	FileDlg.m_ofn.lpstrTitle = _T("Load DATA File");
	CString filename;
	if (FileDlg.DoModal() == IDOK)
	{
		filename = FileDlg.GetPathName();
	}
	if (file.Open(filename, CFile::modeRead))
	{
		CArchive ar(&file, CArchive::load);
		shapes.Serialize(ar);
		ar.Close();
	}
	else
		return;
	file.Close();
	Invalidate();
}

// Clear Board from shapes
void CSergeyOr3Dlg::OnBnClickedClear()
{
	//Clear Board
	int size = shapes.GetSize();
	for (int i = 0; i < size; i++) delete shapes[i];
	shapes.RemoveAll(); // Remove all shapes from board
	Invalidate();
}

// UNDO Shape
void CSergeyOr3Dlg::OnBnClickedundo1()
{
	//UNDO
	if (shapes.IsEmpty()) return;
	removed.push(shapes[shapes.GetSize() - 1]); //stack
	shapes.RemoveAt(shapes.GetSize() - 1);
	Invalidate();
}

// ReDo Shape
void CSergeyOr3Dlg::OnBnClickedredo1()
{
	//ReDo
	if (removed.empty()) return;
	shapes.Add(removed.top());
	removed.pop();
	Invalidate();
}

void CSergeyOr3Dlg::OnBnClickedPen()
{
	//Pen
	if (IsDlgButtonChecked(IDC_Pen))
	{
		//Pen 
		typeOfShape = 5;
		if (!fill_in) {
			hcur = AfxGetApp()->LoadCursorW(MAKEINTRESOURCE(IDC_AFXBARRES_PEN));
			SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)hcur);
			penMode = true;
		}
	}
}

void CSergeyOr3Dlg::OnBnClickedspray()
{
	if (IsDlgButtonChecked(IDC_spray))
	{
		//Spray 
		typeOfShape = 6;
		if (!fill_in) {
			hcur = AfxGetApp()->LoadCursorW(MAKEINTRESOURCE(IDC_AFXBARRES_PEN));
			SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)hcur);
			penMode = true;
		}
	}
}

void CSergeyOr3Dlg::OnBnClickedcircle()
{	
	if (IsDlgButtonChecked(IDC_circle))
	{
		//Circle 
		typeOfShape = 7;
		if (!fill_in) {
			hcur = AfxGetApp()->LoadCursorW(MAKEINTRESOURCE(IDC_AFXBARRES_ELLIPSE));
			SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)hcur);
			penMode = false;
		}
	}
}

void CSergeyOr3Dlg::OnBnClickedfill()
{
	if (fill_in) { // when uncheckboxing fill-in 
		fill_in = false;
		switch (typeOfShape) {
		case 1:
			OnBnClickedEllipse1();
			break;
		case 2:
			OnBnClickedRctangle();
			break;
		case 3:
			OnBnClickedsquare();
			break;
		case 4:
			OnBnClickedLine();
			break;
		case 5:
			OnBnClickedPen();
			break;
		case 6:
			OnBnClickedspray();
			break;
		case 7:
			OnBnClickedcircle();
			break;
		case 8:
			OnBnClickedParallelogram();
			break;
		}

	}
	else { // when checkboxing fill-in 
		fill_in = true;
		hcur = AfxGetApp()->LoadCursorW(MAKEINTRESOURCE(IDC_AFXBARRES_FILL));
		SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)hcur);
	}
}

void CSergeyOr3Dlg::OnBnClickedParallelogram()
{
	if (IsDlgButtonChecked(IDC_Parallelogram))
	{
		//Parallelogram
		typeOfShape = 8;
		if (!fill_in) {
			hcur = AfxGetApp()->LoadCursorW(MAKEINTRESOURCE(IDC_AFXBARRES_RECT));
			SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)hcur);
			penMode = false;
		}
	}
}
