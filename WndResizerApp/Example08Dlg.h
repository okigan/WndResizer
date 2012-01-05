#pragma once
#include "WndResizer.h"

// CExample08APpg dialog

class CExample08APpg : public CPropertyPage
{
	DECLARE_DYNAMIC(CExample08APpg)

public:
	CExample08APpg();
	virtual ~CExample08APpg();

// Dialog Data
	enum { IDD = IDD_EX08_A_PPG };

private:
  CWndResizer m_resizer;
  
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
  virtual BOOL OnInitDialog();
};
#pragma once


// CExample08BPpg dialog

class CExample08BPpg : public CPropertyPage
{
	DECLARE_DYNAMIC(CExample08BPpg)

public:
	CExample08BPpg();
	virtual ~CExample08BPpg();

// Dialog Data
	enum { IDD = IDD_EX08_B_PPG };
private:
  CWndResizer m_resizer;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
  virtual BOOL OnInitDialog();
};
#pragma once



// CExample08Sheet

class CExample08Sheet : public CPropertySheetEx
{
	DECLARE_DYNAMIC(CExample08Sheet)

public:
	CExample08Sheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CExample08Sheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CExample08Sheet();

private:
  CWndResizer m_resizer;

  BOOL IsHostedInAnotherWindow();
protected:
	DECLARE_MESSAGE_MAP()
public:
  virtual BOOL OnInitDialog();
  virtual INT_PTR DoModal();

private:
  static int CALLBACK PropSheetProc(HWND hwndDlg, UINT uMsg, LPARAM lParam);

public:
  afx_msg void OnSize(UINT nType, int cx, int cy);
};


