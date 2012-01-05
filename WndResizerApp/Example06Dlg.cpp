// Example06Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "WndResizerApp.h"
#include "Example06Dlg.h"


// CExample06Dlg dialog

IMPLEMENT_DYNAMIC(CExample06Dlg, CDialog)

CExample06Dlg::CExample06Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExample06Dlg::IDD, pParent)
{

}

CExample06Dlg::~CExample06Dlg()
{
}

void CExample06Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CExample06Dlg, CDialog)

END_MESSAGE_MAP()


// CExample06Dlg message handlers

BOOL CExample06Dlg::OnInitDialog()
{
  CDialog::OnInitDialog();

  GetDlgItem(IDC_EDIT1)->SetWindowText(_T("Dock: Fill"));
  BOOL bOk = FALSE;

  bOk = m_resizer.Hook(this);
  ASSERT( bOk);

  CUIntArray arr;
  arr.Add(IDC_BUTTON1);
  arr.Add(IDC_BUTTON2);
  arr.Add(IDC_BUTTON3);
  arr.Add(IDC_BUTTON4);
  arr.Add(IDC_EDIT1);

  bOk = m_resizer.CreatePanel(_T("MyDocking"), &arr, TRUE);
   ASSERT( bOk );

  bOk = m_resizer.SetAnchor(_T("MyDocking"), ANCHOR_ALL);
   ASSERT( bOk );

  bOk = m_resizer.SetDock(IDC_BUTTON1, DOCK_TOP);
   ASSERT( bOk );
  bOk = m_resizer.SetDock(IDC_BUTTON2, DOCK_RIGHT);
   ASSERT( bOk );
  bOk = m_resizer.SetDock(IDC_BUTTON3, DOCK_BOTTOM);
   ASSERT( bOk );
  bOk = m_resizer.SetDock(IDC_BUTTON4, DOCK_LEFT);
   ASSERT( bOk );
  bOk = m_resizer.SetDock(IDC_EDIT1, DOCK_FILL);
   ASSERT( bOk );


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

