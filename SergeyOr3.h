
// SergeyOr3.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CSergeyOr3App:
// See SergeyOr3.cpp for the implementation of this class
//

class CSergeyOr3App : public CWinApp
{
public:
	CSergeyOr3App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CSergeyOr3App theApp;
