// TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WndResizerApp.h"
#include "TestDlg.h"


// CTestDlg dialog

IMPLEMENT_DYNAMIC(CTestDlg, CDialog)

CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlg::IDD, pParent)
{

}

CTestDlg::~CTestDlg()
{
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
END_MESSAGE_MAP()


// CTestDlg message handlers

BOOL CTestDlg::OnInitDialog()
{
  CDialog::OnInitDialog();


  BOOL bOk = FALSE;

  bOk = m_resizer.Hook(this);
  ASSERT( bOk);


  //bOk = m_resizer.SetAnchor(IDC_Group, ANCHOR_ALL); // group box
  //ASSERT( bOk);

  CUIntArray arr;
  arr.Add(IDC_BUTTON3);
  arr.Add(IDC_BUTTON2);
  arr.Add(IDC_BUTTON1);
  arr.Add(IDC_BUTTON4);
  arr.Add(IDC_STATIC);

  bOk = m_resizer.CreatePanel(_T("MyFlow"), &arr, TRUE);
   ASSERT( bOk );

  bOk = m_resizer.SetAnchor(_T("MyFlow"), ANCHOR_ALL);
   ASSERT( bOk );

  bOk = m_resizer.SetDock(IDC_BUTTON1, DOCK_TOP);
   ASSERT( bOk );
  bOk = m_resizer.SetDock(IDC_BUTTON2, DOCK_RIGHT);
   ASSERT( bOk );
  bOk = m_resizer.SetDock(IDC_BUTTON3, DOCK_BOTTOM);
   ASSERT( bOk );
  bOk = m_resizer.SetDock(IDC_BUTTON4, DOCK_LEFT);
   ASSERT( bOk );
  bOk = m_resizer.SetDock(IDC_STATIC, DOCK_FILL);
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
