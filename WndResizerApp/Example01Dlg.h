#pragma once
#include "WndResizer.h"

// CExample01Dlg dialog

class CExample01Dlg : public CDialog
{
	DECLARE_DYNAMIC(CExample01Dlg)

public:
	CExample01Dlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CExample01Dlg();

// Dialog Data
	enum { IDD = IDD_EX01_DLG };
private:
  CWndResizer m_resizer;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
  virtual BOOL OnInitDialog();
};
