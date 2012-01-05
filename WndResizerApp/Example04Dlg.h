#pragma once
#include "WndResizer.h"

// CExample04Dlg dialog

class CExample04Dlg : public CDialog
{
	DECLARE_DYNAMIC(CExample04Dlg)

public:
	CExample04Dlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CExample04Dlg();

// Dialog Data
	enum { IDD = IDD_EX04_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
private:
  CWndResizer m_resizer;

	DECLARE_MESSAGE_MAP()
public:
  virtual BOOL OnInitDialog();
};
