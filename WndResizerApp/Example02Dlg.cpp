// Example02Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "WndResizerApp.h"
#include "Example02Dlg.h"


// CExample02Dlg dialog

IMPLEMENT_DYNAMIC(CExample02Dlg, CDialog)

CExample02Dlg::CExample02Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExample02Dlg::IDD, pParent)
{

}

CExample02Dlg::~CExample02Dlg()
{
}

void CExample02Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CExample02Dlg, CDialog)
END_MESSAGE_MAP()


// CExample02Dlg message handlers

BOOL CExample02Dlg::OnInitDialog()
{
  CDialog::OnInitDialog();

  BOOL bOk = FALSE;
  
  bOk = m_resizer.Hook(this);
   ASSERT( bOk );

  bOk = m_resizer.SetAnchor(IDC_STATIC_RIGHT, ANCHOR_ALL | ANCHOR_PRIORITY_RIGHT);
   ASSERT( bOk );

  bOk = m_resizer.SetMinimumSize(IDC_STATIC_RIGHT, CSize(150, 100));
   ASSERT( bOk );
  
  bOk = m_resizer.SetMaximumSize(IDC_STATIC_RIGHT, CSize(400, 200));
   ASSERT( bOk );



  bOk = m_resizer.SetAnchor(IDC_STATIC_LEFT, ANCHOR_ALL | ANCHOR_PRIORITY_BOTTOM);
   ASSERT( bOk );

  bOk = m_resizer.SetMinimumSize(IDC_STATIC_LEFT, CSize(150, 100));
   ASSERT( bOk );
  
  bOk = m_resizer.SetMaximumSize(IDC_STATIC_LEFT, CSize(400, 200));
   ASSERT( bOk );

  bOk = m_resizer.SetAnchor(IDC_STATIC_INFO, ANCHOR_BOTTOM);
   ASSERT( bOk );


  // also set the min/max for this dlg. you have to use "" for the panel name
  bOk = m_resizer.SetMinimumSize(_T("_root"), CSize(100, 100));
   ASSERT( bOk );

  bOk = m_resizer.SetMaximumSize(_T("_root"), CSize(500, 500));
   ASSERT( bOk );

  m_resizer.SetShowResizeGrip(TRUE);

  bOk = m_resizer.SetAnchor(IDOK, ANCHOR_RIGHT | ANCHOR_BOTTOM);
  ASSERT( bOk);

  bOk = m_resizer.SetAnchor(IDCANCEL, ANCHOR_RIGHT | ANCHOR_BOTTOM);
  ASSERT( bOk);

  bOk = m_resizer.InvokeOnResized();
  ASSERT( bOk);

  return TRUE;  // return TRUE unless you set the focus to a control
  // EXCEPTION: OCX Property Pages should return FALSE
}

