// Example09Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "WndResizerApp.h"
#include "Example09Dlg.h"


// CExample09Dlg dialog
#define ID_PROP_SHEET 90
#define ID_TREE_CTRL 91

IMPLEMENT_DYNAMIC(CExample09Dlg, CDialog)

CExample09Dlg::CExample09Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExample09Dlg::IDD, pParent)
{
  m_pSheet = NULL;
  m_pPageA = NULL;
  m_pPageB = NULL;

  m_pTree = NULL;
}

CExample09Dlg::~CExample09Dlg()
{
    DestroyPropertySheet();
    DestroyTreeControl();
}

void CExample09Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CExample09Dlg, CDialog)
END_MESSAGE_MAP()


// CExample09Dlg message handlers

BOOL CExample09Dlg::OnInitDialog()
{
  CDialog::OnInitDialog();

  BOOL bOk = m_resizer.Hook(this);
  ASSERT( bOk == TRUE );  

  DestroyPropertySheet();
  bOk = CreatePropertySheetOnTheFly();
   ASSERT( bOk );

  m_pSheet->SetDlgCtrlID(ID_PROP_SHEET);  // IMPORTATNT: asssing a uniqe ID
  //m_pSheet->SetIsChild(TRUE);
  
  DestroyTreeControl();
  bOk = CreateTreeControlOnTheFly();
  ASSERT( bOk);

  // id of the tree control was assigned during create, so we do not need to
  // assign it again
  //m_pTree->SetDlgCtrlID(ID_TREE_CTRL); // IMPORTATNT: asssing a uniqe ID




  bOk = m_resizer.CreateSplitContainer(_T("MySplitContainer"), ID_PROP_SHEET, ID_TREE_CTRL);
  ASSERT ( bOk == TRUE );

  bOk = m_resizer.SetAnchor(_T("MySplitContainer"), ANCHOR_ALL);
  ASSERT ( bOk == TRUE );

  bOk = m_resizer.SetShowSplitterGrip(_T("MySplitContainer"), TRUE);
  ASSERT ( bOk == TRUE );

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

BOOL CExample09Dlg::CreatePropertySheetOnTheFly()
{
  m_pPageA = new CExample08APpg();
  m_pPageB = new CExample08BPpg();
  m_pSheet = new CExample08Sheet(_T("On-the-fly CPropertySheet"));
  m_pSheet->AddPage( m_pPageA );
  m_pSheet->AddPage( m_pPageB );

	//// create a modeless property page
	if (m_pSheet->Create(this, DS_CONTEXTHELP | DS_SETFONT | WS_CHILD | WS_VISIBLE))
	{
    CRect rc;
    GetDlgItem(IDC_STATIC_A)->GetWindowRect(&rc);
    ScreenToClient(&rc);

    m_pSheet->MoveWindow(&rc);


	  // we use the style from the template - but make sure that
	  // the WS_BORDER bit is correct.
	  // the WS_BORDER bit will be whatever is in dwRequestedStyle
	  m_pSheet->ModifyStyle(WS_BORDER|WS_CAPTION, m_pSheet->GetStyle() & (WS_BORDER|WS_CAPTION));


    // the tab control, by default, keeps a margin around it.
    // since we host the propertysheet as child, we do not need the margin.
    // so we fill the entire client area of the propertysheet with the tab control.
    //m_pSheet->GetClientRect(&rc);
    //m_pSheet->GetTabControl()->MoveWindow(&rc);

    //m_pSheet->SetActivePage( 0 );

    return TRUE;
  }

  DestroyPropertySheet();
  return FALSE;
}

void CExample09Dlg::DestroyPropertySheet()
{
  if (m_pSheet != NULL)
  {
    delete m_pSheet;
    m_pSheet = NULL;
  }
  if (m_pPageA != NULL)
  {
    delete m_pPageA;
    m_pPageA = NULL;
  }
  if (m_pPageB != NULL)
  {
    delete m_pPageB;
    m_pPageB = NULL;
  }
}

BOOL CExample09Dlg::CreateTreeControlOnTheFly()
{
  m_pTree = new CTreeCtrl();

  CRect rc;
  GetDlgItem(IDC_STATIC_B)->GetWindowRect(&rc);
  ScreenToClient(&rc);

  if (m_pTree->Create(WS_VISIBLE | WS_TABSTOP | WS_CHILD | WS_BORDER
     | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_HASLINES
     | TVS_DISABLEDRAGDROP | TVS_NOTOOLTIPS | TVS_EDITLABELS,
     rc, this, ID_TREE_CTRL))
  {
    return TRUE;
  }
  DestroyTreeControl();
  return FALSE;

}
void CExample09Dlg::DestroyTreeControl()
{
  if (m_pTree != NULL)
  {
    delete m_pTree;
    m_pTree = NULL;
  }
}
