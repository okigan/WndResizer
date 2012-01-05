#pragma once
#include "WndResizer.h"


// CExample07Dlg dialog

class CExample07Dlg : public CDialog
{
	DECLARE_DYNAMIC(CExample07Dlg)

public:
	CExample07Dlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CExample07Dlg();
private:
  CWndResizer m_resizer;

  void CalculateArea(CUIntArray * parr, CRect *prcResult);

// Dialog Data
	enum { IDD = IDD_EX07_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
  virtual BOOL OnInitDialog();
};
