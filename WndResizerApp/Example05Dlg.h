#pragma once
#include "WndResizer.h"

// CExample05Dlg dialog

class CExample05Dlg : public CDialog
{
	DECLARE_DYNAMIC(CExample05Dlg)

public:
	CExample05Dlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CExample05Dlg();

// Dialog Data
	enum { IDD = IDD_EX05_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
private:
  CWndResizer m_resizer;

	DECLARE_MESSAGE_MAP()
public:
  virtual BOOL OnInitDialog();
};
