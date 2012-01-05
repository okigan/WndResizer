#pragma once
#include "Example08Dlg.h"


// CExample09Dlg dialog

class CExample09Dlg : public CDialog
{
	DECLARE_DYNAMIC(CExample09Dlg)

public:
	CExample09Dlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CExample09Dlg();

// Dialog Data
	enum { IDD = IDD_EX09_DLG };

private:
  BOOL CreatePropertySheetOnTheFly();
  void DestroyPropertySheet();

  BOOL CreateTreeControlOnTheFly();
  void DestroyTreeControl();

  CExample08Sheet * m_pSheet;
  CExample08APpg * m_pPageA;
  CExample08BPpg * m_pPageB;

  CTreeCtrl * m_pTree;
  CWndResizer m_resizer;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
  virtual BOOL OnInitDialog();
};
