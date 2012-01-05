// Example07Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "WndResizerApp.h"
#include "Example07Dlg.h"


// CExample07Dlg dialog

IMPLEMENT_DYNAMIC(CExample07Dlg, CDialog)

CExample07Dlg::CExample07Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExample07Dlg::IDD, pParent)
{

}

CExample07Dlg::~CExample07Dlg()
{
}

void CExample07Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CExample07Dlg, CDialog)
END_MESSAGE_MAP()


// CExample07Dlg message handlers

BOOL CExample07Dlg::OnInitDialog()
{
  CDialog::OnInitDialog();

  BOOL bOk = FALSE;
  
  bOk = m_resizer.Hook(this);
   ASSERT( bOk );


  bOk = m_resizer.CreateSplitContainer(_T("InnerSplit"), IDC_LIST2, IDC_LIST3);
   ASSERT( bOk );

  bOk = m_resizer.SetAnchor(_T("InnerSplit"), ANCHOR_ALL);
   ASSERT( bOk );

  bOk = m_resizer.SetIsSplitterFixed(_T("InnerSplit"), TRUE);
   ASSERT( bOk );

  bOk = m_resizer.CreateSplitContainer(_T("OutterSplit"), IDC_LIST1, _T("InnerSplit") );
   ASSERT( bOk );

  bOk = m_resizer.SetShowSplitterGrip(_T("OutterSplit"), TRUE );
   ASSERT( bOk );

  CSize size(40, 0); // cy member will be ignored
  bOk = m_resizer.SetMinimumSize(_T("InnerSplit"), size);
   ASSERT( bOk );


  bOk = m_resizer.SetAnchor(_T("OutterSplit"), ANCHOR_ALL);
   ASSERT( bOk );

  bOk = m_resizer.SetFixedPanel(_T("OutterSplit"), 1); 
   ASSERT( bOk );

  bOk = m_resizer.SetAnchor(IDC_STATIC_NOTE, /*ANCHOR_LEFT |*/ ANCHOR_BOTTOM); // ANCHOR_LEFT is default
  ASSERT( bOk);


  bOk = m_resizer.SetAnchor(IDOK, ANCHOR_RIGHT | ANCHOR_BOTTOM);
  ASSERT( bOk);

  bOk = m_resizer.SetAnchor(IDCANCEL, ANCHOR_RIGHT | ANCHOR_BOTTOM);
  ASSERT( bOk);

  m_resizer.SetShowResizeGrip(TRUE);

  bOk = m_resizer.InvokeOnResized();
  return TRUE;  // return TRUE unless you set the focus to a control
  // EXCEPTION: OCX Property Pages should return FALSE
}
void CExample07Dlg::CalculateArea(CUIntArray * parr, CRect *prcResult)
{  
  for(int i = 0; i < parr->GetCount(); i++)
  {
    CRect rc;
    GetDlgItem(parr->GetAt(i))->GetWindowRect(&rc);
    ScreenToClient(&rc);
    prcResult->UnionRect(prcResult, &rc);
  }


}
