#pragma once
#include "WndResizer.h"

// CExample02Dlg dialog

class CExample02Dlg : public CDialog
{
	DECLARE_DYNAMIC(CExample02Dlg)

public:
	CExample02Dlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CExample02Dlg();

// Dialog Data
	enum { IDD = IDD_EX02_DLG };

private:
  CWndResizer m_resizer;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
  virtual BOOL OnInitDialog();
};
