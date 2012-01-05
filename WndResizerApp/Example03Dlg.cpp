// Example03Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "WndResizerApp.h"
#include "Example03Dlg.h"


// CExample03Dlg dialog

IMPLEMENT_DYNAMIC(CExample03Dlg, CDialog)

CExample03Dlg::CExample03Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExample03Dlg::IDD, pParent)
{

}

CExample03Dlg::~CExample03Dlg()
{
}

void CExample03Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CExample03Dlg, CDialog)
END_MESSAGE_MAP()


// CExample03Dlg message handlers

BOOL CExample03Dlg::OnInitDialog()
{
  CDialog::OnInitDialog();
  BOOL bOk = FALSE;
  
  bOk = m_resizer.Hook(this);
   ASSERT( bOk );

  bOk = m_resizer.SetAnchor(IDC_BTN_H, ANCHOR_HORIZONTALLY_CENTERED);
   ASSERT( bOk );

  bOk = m_resizer.SetAnchor(IDC_BTN_V, ANCHOR_VERTICALLY_CENTERED | ANCHOR_RIGHT);
   ASSERT( bOk );

  CUIntArray arrID;
  arrID.Add(IDC_BTN_TOP);
  arrID.Add(IDC_BTN_LEFT);
  arrID.Add(IDC_BTN_RIGHT);
  arrID.Add(IDC_BTN_BOTTOM);

  CRect rcPanel;
  CalculateTotalArea(&arrID, &rcPanel);

  bOk = m_resizer.CreatePanel(_T("MyCenteredPanel"), &rcPanel);
   ASSERT( bOk );

  bOk = m_resizer.SetAnchor(_T("MyCenteredPanel"), ANCHOR_HORIZONTALLY_CENTERED | ANCHOR_VERTICALLY_CENTERED);
   ASSERT( bOk );
  
  bOk = m_resizer.SetParent(IDC_BTN_TOP, _T("MyCenteredPanel"));
   ASSERT( bOk );
  bOk = m_resizer.SetParent(IDC_BTN_LEFT, _T("MyCenteredPanel"));
   ASSERT( bOk );
  bOk = m_resizer.SetParent(IDC_BTN_RIGHT, _T("MyCenteredPanel"));
   ASSERT( bOk );
  bOk = m_resizer.SetParent(IDC_BTN_BOTTOM, _T("MyCenteredPanel"));
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


void CExample03Dlg::CalculateTotalArea(CUIntArray * parr, CRect *prcResult)
{  
  for(int i = 0; i < parr->GetCount(); i++)
  {
    CRect rc;
    GetDlgItem(parr->GetAt(i))->GetWindowRect(&rc);
    ScreenToClient(&rc);
    prcResult->UnionRect(prcResult, &rc);
  }


}
