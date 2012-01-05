#pragma once
#include "WndResizer.h"

// CExample03Dlg dialog

class CExample03Dlg : public CDialog
{
	DECLARE_DYNAMIC(CExample03Dlg)

public:
	CExample03Dlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CExample03Dlg();

// Dialog Data
	enum { IDD = IDD_EX03_DLG };
private:
  CWndResizer m_resizer;
  void CalculateTotalArea(CUIntArray * parr, CRect *rc);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
  virtual BOOL OnInitDialog();
};
