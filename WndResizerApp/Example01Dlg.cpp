// Example01Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "WndResizerApp.h"
#include "Example01Dlg.h"


// CExample01Dlg dialog

IMPLEMENT_DYNAMIC(CExample01Dlg, CDialog)

CExample01Dlg::CExample01Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExample01Dlg::IDD, pParent)
{

}

CExample01Dlg::~CExample01Dlg()
{
}

void CExample01Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CExample01Dlg, CDialog)
END_MESSAGE_MAP()


// CExample01Dlg message handlers

BOOL CExample01Dlg::OnInitDialog()
{
  CDialog::OnInitDialog();

  BOOL bOk = FALSE;
  bOk = m_resizer.Hook(this);
  ASSERT( bOk);

  bOk = m_resizer.SetAnchor(IDC_EDIT_INPUT_FILE, ANCHOR_HORIZONTALLY);
  ASSERT( bOk);

  bOk = m_resizer.SetAnchor(IDC_BUTTON_BROWSE, ANCHOR_RIGHT);
  ASSERT( bOk);


  bOk = m_resizer.SetAnchor(IDC_FRAME_INPUT_TYPE, ANCHOR_VERTICALLY);
  ASSERT( bOk);

  bOk = m_resizer.SetAnchor(IDC_FRAME_COMMENTS, ANCHOR_ALL);
  ASSERT( bOk);

  bOk = m_resizer.SetAnchor(IDC_EDIT_COMMENTS, ANCHOR_ALL);
  ASSERT( bOk);


  bOk = m_resizer.SetAnchor(IDC_CHECK_LOG, ANCHOR_HORIZONTALLY_CENTERED | ANCHOR_BOTTOM);
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
