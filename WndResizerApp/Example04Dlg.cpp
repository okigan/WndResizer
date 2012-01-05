// Example04Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "WndResizerApp.h"
#include "Example04Dlg.h"


// CExample04Dlg dialog

IMPLEMENT_DYNAMIC(CExample04Dlg, CDialog)

CExample04Dlg::CExample04Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExample04Dlg::IDD, pParent)
{

}

CExample04Dlg::~CExample04Dlg()
{
}

void CExample04Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CExample04Dlg, CDialog)
END_MESSAGE_MAP()


// CExample04Dlg message handlers

BOOL CExample04Dlg::OnInitDialog()
{
  CDialog::OnInitDialog();

  BOOL bOk = FALSE;
  
  bOk = m_resizer.Hook(this);
   ASSERT( bOk );

  CUIntArray arr;
  arr.Add(IDC_BUTTON1);
  arr.Add(IDC_BUTTON2);
  arr.Add(IDC_BUTTON3);
  arr.Add(IDC_BUTTON4);
  arr.Add(IDC_BUTTON5);
  arr.Add(IDC_BUTTON6);
  bOk = m_resizer.CreateFlowLayoutPanel(_T("FlowLayoutLeftToRight"), &arr, TRUE);
  ASSERT( bOk);
  bOk = m_resizer.SetFlowItemSpacingX(_T("FlowLayoutLeftToRight"), 4);
  ASSERT( bOk);
  bOk = m_resizer.SetFlowItemSpacingY(_T("FlowLayoutLeftToRight"), 8);
  ASSERT( bOk);
  bOk = m_resizer.SetAnchor(_T("FlowLayoutLeftToRight"), ANCHOR_ALL);
  ASSERT( bOk);
  bOk = m_resizer.SetParent(_T("FlowLayoutLeftToRight"), IDC_FRAME_LEFT);
  ASSERT( bOk);

  arr.RemoveAll();
  arr.Add(IDC_BUTTON7);
  arr.Add(IDC_BUTTON8);
  arr.Add(IDC_BUTTON9);
  arr.Add(IDC_BUTTON10);
  arr.Add(IDC_BUTTON11);
  arr.Add(IDC_BUTTON12);
  bOk = m_resizer.CreateFlowLayoutPanel(_T("FlowLayoutTopToBottom"), &arr, TRUE);
  ASSERT( bOk);
  bOk = m_resizer.SetFlowItemSpacingX(_T("FlowLayoutTopToBottom"), 4);
  ASSERT( bOk);
  bOk = m_resizer.SetFlowItemSpacingY(_T("FlowLayoutTopToBottom"), 8);
  ASSERT( bOk);
  bOk = m_resizer.SetAnchor(_T("FlowLayoutTopToBottom"), ANCHOR_ALL);
  ASSERT( bOk);
  bOk = m_resizer.SetParent(_T("FlowLayoutTopToBottom"), IDC_FRAME_RIGHT);
  ASSERT( bOk);
  bOk = m_resizer.SetFlowDirection(_T("FlowLayoutTopToBottom"), 2); // 2 = top to bottom
  ASSERT( bOk);


  bOk = m_resizer.CreateSplitContainer(_T("MySplitter"), IDC_FRAME_LEFT, IDC_FRAME_RIGHT);
  ASSERT( bOk);

  bOk = m_resizer.SetAnchor(_T("MySplitter"), ANCHOR_ALL);
  ASSERT( bOk);
  

  bOk = m_resizer.SetShowSplitterGrip(_T("MySplitter"), TRUE);
  ASSERT( bOk);


  m_resizer.SetShowResizeGrip(TRUE);

  bOk = m_resizer.SetAnchor(IDOK, ANCHOR_RIGHT | ANCHOR_BOTTOM);
  ASSERT( bOk);

  bOk = m_resizer.SetAnchor(IDCANCEL, ANCHOR_RIGHT | ANCHOR_BOTTOM);
  ASSERT( bOk);

  bOk = m_resizer.InvokeOnResized();
  ASSERT( bOk);

  CString sDebugInfo = m_resizer.GetDebugInfo();

  return TRUE;  // return TRUE unless you set the focus to a control
  // EXCEPTION: OCX Property Pages should return FALSE
}
