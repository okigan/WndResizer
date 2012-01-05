// Example10Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "WndResizerApp.h"
#include "Example10Dlg.h"


////////////////////////////////////////////////////////////////////////////////////////
// CExample10Dlg dialog
////////////////////////////////////////////////////////////////////////////////////////

#define EMBEDED_VIEW_ID 1001

IMPLEMENT_DYNAMIC(CExample10Dlg, CDialog)

CExample10Dlg::CExample10Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExample10Dlg::IDD, pParent)
{
  m_pView = NULL;
}

CExample10Dlg::~CExample10Dlg()
{

}

void CExample10Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CExample10Dlg, CDialog)
  ON_WM_DESTROY()
END_MESSAGE_MAP()

BOOL CExample10Dlg::OnInitDialog()
{
  CDialog::OnInitDialog();

  m_pView = CreateFormViewOnTheFly();
  ASSERT( m_pView != NULL );

  m_pView->SetDlgCtrlID(EMBEDED_VIEW_ID);

  BOOL bOk = m_resizer.Hook(this);
  ASSERT ( bOk );

  bOk = m_resizer.SetAnchor(EMBEDED_VIEW_ID, ANCHOR_ALL);
  ASSERT( bOk );

  bOk = m_resizer.SetAnchor(IDOK, ANCHOR_RIGHT | ANCHOR_BOTTOM);
  ASSERT(bOk );

  bOk = m_resizer.SetAnchor(IDCANCEL, ANCHOR_RIGHT | ANCHOR_BOTTOM);
  ASSERT(bOk );

  m_resizer.SetShowResizeGrip(TRUE);

  bOk = m_resizer.InvokeOnResized();
  ASSERT(bOk );

  return TRUE;  // return TRUE unless you set the focus to a control
  // EXCEPTION: OCX Property Pages should return FALSE
}



CFormView * CExample10Dlg::CreateFormViewOnTheFly()
{
  CCreateContext  ctx;
  // memebers we do not use, so set them to null
  ctx.m_pNewViewClass = RUNTIME_CLASS(CTestView);
  ctx.m_pNewDocTemplate = NULL;
  ctx.m_pLastView = NULL;
  ctx.m_pCurrentFrame = NULL;

  CFrameWnd * pFrameWnd = (CFrameWnd*) this;
  CFormView * pView = (CFormView *) pFrameWnd->CreateView(&ctx);
  if (pView->GetSafeHwnd() == NULL )
  {
    AfxMessageBox(_T("Failed to create view."));
    pView = NULL;
    return NULL;
  }
  // After a view is created, resize that to
  // have the same size as the dialog.
  
  CRect rc(0, 0, 0, 0);
  GetDlgItem(IDC_STATIC_MARKER)->GetWindowRect(&rc);
  ScreenToClient( &rc );
  pView->MoveWindow(rc);

  pView->OnInitialUpdate();
  pView->ShowWindow(SW_NORMAL);

  return pView;
}

void CExample10Dlg::OnDestroy()
{
  CDialog::OnDestroy();

  if (m_pView != NULL )
  {
    delete m_pView;
    m_pView = NULL;
  }}


////////////////////////////////////////////////////////////////////////////////////////
// CTestView
////////////////////////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNCREATE(CTestView, CFormView)

CTestView::CTestView()
	: CFormView(CTestView::IDD)
{
  m_szDesignTimeSize.SetSize(0,0);
}

CTestView::~CTestView()
{
}

void CTestView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestView, CFormView)
  ON_WM_CREATE()
END_MESSAGE_MAP()


// CTestView diagnostics

#ifdef _DEBUG
void CTestView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CTestView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CTestView message handlers



void CTestView::OnInitialUpdate()
{
  CFormView::OnInitialUpdate();
  SetupResizer();


}
void CTestView::SetupResizer()
{
  BOOL bOk = m_resizer.Hook(this, m_szDesignTimeSize);
  ASSERT( bOk );

  bOk = m_resizer.SetAnchor(IDC_EDIT1, ANCHOR_HORIZONTALLY);
  ASSERT( bOk );

  bOk = m_resizer.SetAnchor(IDC_BUTTON1, ANCHOR_RIGHT);
  ASSERT( bOk );

  bOk = m_resizer.SetAnchor(IDC_EDIT2, ANCHOR_ALL);
  ASSERT( bOk );

  bOk = m_resizer.SetAnchor(IDC_BUTTON2, ANCHOR_RIGHT | ANCHOR_BOTTOM);
  ASSERT( bOk );

  bOk = m_resizer.InvokeOnResized();
  ASSERT( bOk );

  CString sDebug = m_resizer.GetDebugInfo();
}



int CTestView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
  if (CFormView::OnCreate(lpCreateStruct) == -1)
    return -1;

  m_szDesignTimeSize.SetSize(lpCreateStruct->cx, lpCreateStruct->cy);

  return 0;
}
