// Example05Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "WndResizerApp.h"
#include "Example05Dlg.h"


// CExample05Dlg dialog

IMPLEMENT_DYNAMIC(CExample05Dlg, CDialog)

CExample05Dlg::CExample05Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExample05Dlg::IDD, pParent)
{

}

CExample05Dlg::~CExample05Dlg()
{
}

void CExample05Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CExample05Dlg, CDialog)
END_MESSAGE_MAP()


// CExample05Dlg message handlers

BOOL CExample05Dlg::OnInitDialog()
{
  CDialog::OnInitDialog();

  BOOL bOk = FALSE;
  bOk = m_resizer.Hook(this);
  ASSERT( bOk);
  
  bOk = m_resizer.CreateSplitContainer(_T("MainSpliter"), IDC_FRAME_DEMO_H, IDC_FRAME_DEMO_V);
  ASSERT( bOk);

  bOk = m_resizer.SetAnchor(_T("MainSpliter"), ANCHOR_ALL);
  ASSERT( bOk);

  bOk = m_resizer.SetShowSplitterGrip(_T("MainSpliter"), TRUE);
  ASSERT( bOk);


  bOk = m_resizer.CreateSplitContainer(_T("SpliterH"), IDC_FRAME_LEFT, IDC_FRAME_RIGHT);
  ASSERT( bOk);

  bOk = m_resizer.SetShowSplitterGrip(_T("SpliterH"), TRUE);
  ASSERT( bOk);


  bOk = m_resizer.SetParent(_T("SpliterH"), IDC_FRAME_DEMO_H);
  ASSERT( bOk);

  bOk = m_resizer.SetAnchor(_T("SpliterH"), ANCHOR_ALL);
  ASSERT( bOk);

  bOk = m_resizer.CreateSplitContainer(_T("SpliterV"), IDC_FRAME_TOP, IDC_FRAME_BOTTOM);
  ASSERT( bOk);

  bOk = m_resizer.SetShowSplitterGrip(_T("SpliterV"), TRUE);
  ASSERT( bOk);

  bOk = m_resizer.SetParent(_T("SpliterV"), IDC_FRAME_DEMO_V);
  ASSERT( bOk);

  bOk = m_resizer.SetAnchor(_T("SpliterV"), ANCHOR_ALL);
  ASSERT( bOk);

  bOk = m_resizer.SetMinimumSize(IDC_FRAME_DEMO_H, CSize(150, 0)); // cy is ignored here
  ASSERT( bOk);

  bOk = m_resizer.SetMinimumSize(IDC_FRAME_DEMO_V, CSize(150, 0)); // cy is ignored here
  ASSERT( bOk);

  bOk = m_resizer.SetMinimumSize(IDC_FRAME_LEFT, CSize(60, 0)); // cy is ignored here
  ASSERT( bOk);

  bOk = m_resizer.SetMinimumSize(IDC_FRAME_RIGHT, CSize(60, 0)); // cy is ignored here
  ASSERT( bOk);

  bOk = m_resizer.SetMinimumSize(IDC_FRAME_TOP, CSize(0, 60)); // cx is ignored here
  ASSERT( bOk);

  bOk = m_resizer.SetMinimumSize(IDC_FRAME_BOTTOM, CSize(0, 60)); // cx is ignored here
  ASSERT( bOk);

  bOk = m_resizer.SetAnchor(IDOK, ANCHOR_RIGHT | ANCHOR_BOTTOM);
  ASSERT( bOk);

  bOk = m_resizer.SetAnchor(IDCANCEL, ANCHOR_RIGHT | ANCHOR_BOTTOM);
  ASSERT( bOk);

  m_resizer.SetShowResizeGrip(TRUE);

  bOk = m_resizer.InvokeOnResized();
  ASSERT( bOk);

  return TRUE;  // return TRUE unless you set the focus to a control
  // EXCEPTION: OCX Property Pages should return FALSE
}


