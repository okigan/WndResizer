#pragma once
#include "WndResizer.h"

// CExample06Dlg dialog

class CExample06Dlg : public CDialog
{
	DECLARE_DYNAMIC(CExample06Dlg)

public:
	CExample06Dlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CExample06Dlg();

// Dialog Data
	enum { IDD = IDD_EX06_DLG };
private:
  CWndResizer m_resizer;


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
  virtual BOOL OnInitDialog();

};
