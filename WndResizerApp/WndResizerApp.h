
// WndResizerApp.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CWndResizerApp:
// See WndResizerApp.cpp for the implementation of this class
//

class CWndResizerApp : public CWinApp
{
public:
	CWndResizerApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CWndResizerApp theApp;