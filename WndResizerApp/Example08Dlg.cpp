// Example08.cpp : implementation file
//

#include "stdafx.h"
#include "WndResizerApp.h"
#include "Example08Dlg.h"


// CExample08APpg dialog

IMPLEMENT_DYNAMIC(CExample08APpg, CPropertyPage)

CExample08APpg::CExample08APpg()
	: CPropertyPage(CExample08APpg::IDD)
{

}

CExample08APpg::~CExample08APpg()
{
}

void CExample08APpg::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CExample08APpg, CPropertyPage)
END_MESSAGE_MAP()

BOOL CExample08APpg::OnInitDialog()
{
  CPropertyPage::OnInitDialog();
  BOOL bOk = FALSE;

  bOk = m_resizer.Hook(this);
  ASSERT( bOk);

  CUIntArray arrID;
  arrID.Add(IDC_BUTTON1);
  arrID.Add(IDC_BUTTON2);
  arrID.Add(IDC_BUTTON3);
  arrID.Add(IDC_BUTTON4);

  bOk = m_resizer.CreatePanel(_T("ButtonPanel"), &arrID, TRUE);
  ASSERT( bOk);


  arrID.RemoveAll();
  arrID.Add(IDC_LIST1);
  arrID.Add(IDC_STATIC_AVAILABLE);

  bOk = m_resizer.CreatePanel(_T("LeftPanel"), &arrID, TRUE);
  ASSERT( bOk);
  bOk = m_resizer.SetAnchor(IDC_LIST1, ANCHOR_ALL);
  ASSERT( bOk);

  arrID.RemoveAll();
  arrID.Add(IDC_LIST2);
  arrID.Add(IDC_STATIC_SELECTED);
  bOk = m_resizer.CreatePanel(_T("RightPanel"),  &arrID, TRUE);
  ASSERT( bOk);
  bOk = m_resizer.SetAnchor(IDC_LIST2, ANCHOR_ALL);
  ASSERT( bOk);

  bOk = m_resizer.CreateSplitContainer(_T("Splitter"), _T("LeftPanel"), _T("RightPanel"));
  ASSERT( bOk);

  bOk = m_resizer.SetShowSplitterGrip(_T("Splitter"), TRUE);
  ASSERT( bOk);

  bOk = m_resizer.SetAnchor(_T("Splitter"), ANCHOR_ALL);
  ASSERT( bOk);

  bOk = m_resizer.SetParent(_T("ButtonPanel"), _T("LeftPanel"));
  ASSERT( bOk);

  bOk = m_resizer.SetAnchor(_T("ButtonPanel"), ANCHOR_VERTICALLY_CENTERED | ANCHOR_RIGHT);
  ASSERT( bOk);

  bOk = m_resizer.InvokeOnResized();
   ASSERT( bOk );


  return TRUE;  // return TRUE unless you set the focus to a control
  // EXCEPTION: OCX Property Pages should return FALSE
}

// CExample08APpg message handlers
// Example08Dlg.cpp : implementation file
//


// CExample08BPpg dialog

IMPLEMENT_DYNAMIC(CExample08BPpg, CPropertyPage)

CExample08BPpg::CExample08BPpg()
	: CPropertyPage(CExample08BPpg::IDD)
{

}

CExample08BPpg::~CExample08BPpg()
{
}

void CExample08BPpg::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CExample08BPpg, CPropertyPage)
END_MESSAGE_MAP()


// CExample08BPpg message handlers



BOOL CExample08BPpg::OnInitDialog()
{
  CPropertyPage::OnInitDialog();

  BOOL bOk = FALSE;

  bOk = m_resizer.Hook(this);
  ASSERT( bOk);

  bOk = m_resizer.SetAnchor(IDC_EDIT1, ANCHOR_ALL);
  ASSERT( bOk);

  return TRUE;  // return TRUE unless you set the focus to a control
  // EXCEPTION: OCX Property Pages should return FALSE
}
// Example08Dlg.cpp : implementation file
//

// CExample08Sheet

IMPLEMENT_DYNAMIC(CExample08Sheet, CPropertySheet)

CExample08Sheet::CExample08Sheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{

}

CExample08Sheet::CExample08Sheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{

}

CExample08Sheet::~CExample08Sheet()
{
}


BEGIN_MESSAGE_MAP(CExample08Sheet, CPropertySheet)

  ON_WM_SIZE()
END_MESSAGE_MAP()


// CExample08Sheet message handlers


BOOL CExample08Sheet::OnInitDialog()
{
  BOOL bResult = CPropertySheet::OnInitDialog();

  BOOL bOk = FALSE;

  bOk = m_resizer.Hook(this);
  ASSERT( bOk);

  bOk = m_resizer.SetAnchor(IDOK, ANCHOR_RIGHT | ANCHOR_BOTTOM);
  ASSERT( bOk);

  bOk = m_resizer.SetAnchor(IDCANCEL, ANCHOR_RIGHT | ANCHOR_BOTTOM);
  ASSERT( bOk);

  bOk = m_resizer.SetAnchor(IDHELP, ANCHOR_RIGHT | ANCHOR_BOTTOM);
  ASSERT( bOk);

  bOk = m_resizer.SetAnchor(ID_APPLY_NOW, ANCHOR_RIGHT | ANCHOR_BOTTOM);
  ASSERT( bOk);

  // if the property sheet is hosted in another window, then
  // we should fill its client area with the tab control completely.
  /// (before anchoring the tab control)
  if ( IsHostedInAnotherWindow() )
  {
    CRect rc;
    GetClientRect(&rc);
    GetTabControl()->MoveWindow(&rc);
  }

  bOk = m_resizer.SetAnchor(GetTabControl()->GetDlgCtrlID(), ANCHOR_ALL);
  ASSERT( bOk);

  m_resizer.SetShowResizeGrip( !IsHostedInAnotherWindow()  );

  return bResult;
}

INT_PTR CExample08Sheet::DoModal()
{
  m_psh.dwFlags |= PSH_USECALLBACK;
  m_psh.pfnCallback = PropSheetProc;

  return CPropertySheet::DoModal();
}



int CALLBACK CExample08Sheet::PropSheetProc(HWND hWnd, UINT message, LPARAM lParam)
{
   switch (message)
   {
   case PSCB_PRECREATE:
      // Set our own window styles
      ((LPDLGTEMPLATE)lParam)->style |= (DS_3DLOOK | DS_SETFONT
         | WS_THICKFRAME | WS_SYSMENU | WS_POPUP | WS_VISIBLE | WS_CAPTION);
      break;
   }
   return 0;
}

void CExample08Sheet::OnSize(UINT nType, int cx, int cy)
{
    CPropertySheet::OnSize(nType, cx, cy);

  // following part is needed due to 
  // the fact that CTabCtrl does not automatically resize the
  // item when it resizes itself
 
  if (GetActivePage() != NULL)
  {
    SetActivePage(GetActivePage() );
  }

}


BOOL CExample08Sheet::IsHostedInAnotherWindow()
{
   return ((GetStyle() & WS_CHILD)> 0);
}
