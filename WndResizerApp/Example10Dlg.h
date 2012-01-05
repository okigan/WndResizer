#pragma once
#include "WndResizer.h"

// CExample10Dlg dialog

class CExample10Dlg : public CDialog
{
	DECLARE_DYNAMIC(CExample10Dlg)

public:
	CExample10Dlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CExample10Dlg();

// Dialog Data
	enum { IDD = IDD_EX10_DLG };

private:
  CWndResizer m_resizer;
  CFormView * m_pView;
private:
  CFormView * CreateFormViewOnTheFly();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
  virtual BOOL OnInitDialog();
  afx_msg void OnDestroy();
};
#pragma once



// CTestView form view

class CTestView : public CFormView
{
	DECLARE_DYNCREATE(CTestView)

protected:
	CTestView();           // protected constructor used by dynamic creation
	virtual ~CTestView();

public:
	enum { IDD = IDD_EX10_VIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

private:
  CWndResizer m_resizer;
  CSize m_szDesignTimeSize;
public:
  void SetupResizer();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
  virtual void OnInitialUpdate();
  afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};


