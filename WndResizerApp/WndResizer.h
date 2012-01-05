/*
DISCLAIMER

Auther: Mizan Rahman
Original publication location: http://www.codeproject.com/KB/dialog/WndResizer.aspx

This work is provided under the terms and condition described in The Code Project Open License (CPOL)
(http://www.codeproject.com/info/cpol10.aspx)

This disclaimer should not be removed and should exist in any reproduction of this work.
*/

#pragma once


#define ANCHOR_LEFT                   1
#define ANCHOR_TOP                    2
#define ANCHOR_RIGHT                  4
#define ANCHOR_BOTTOM                 8
#define ANCHOR_HORIZONTALLY_CENTERED  16
#define ANCHOR_VERTICALLY_CENTERED    32
#define ANCHOR_PRIORITY_RIGHT         64   // by defualt, left has higher priority
#define ANCHOR_PRIORITY_BOTTOM        128  // by defualt, top has higher priority
#define ANCHOR_VERTICALLY             (ANCHOR_TOP | ANCHOR_BOTTOM)
#define ANCHOR_HORIZONTALLY           (ANCHOR_LEFT | ANCHOR_RIGHT)
#define ANCHOR_ALL                    (ANCHOR_VERTICALLY | ANCHOR_HORIZONTALLY)

#define DOCK_NONE   0
#define DOCK_LEFT   1
#define DOCK_TOP    2
#define DOCK_RIGHT  3
#define DOCK_BOTTOM 4
#define DOCK_FILL   5

class CPanel;
class CUIPanel;

typedef CList<CPanel *, CPanel *> CPanelList;

class CPanel : public CRect
{
public:
    CPanel();
    CPanel(const CRect * prc);
    virtual ~CPanel();
    UINT Anchor;
    UINT Dock;
    CString Name;
    CPanel * Parent;
    CPanelList Children;
    int LeftOffset;
    int TopOffset;
    int RightOffset;
    int BottomOffset; 
    CSize MinSize;
    CSize MaxSize;
    virtual void OnResized();
    virtual BOOL AddChild(CPanel * prc);
    virtual BOOL RemoveChild(CPanel * prc);
    virtual BOOL SetAnchor(UINT anchor);
    virtual BOOL SetMinSize(CSize & size);
    virtual BOOL SetMaxSize(CSize & size);
    virtual CString ToString();
    virtual CString GetTypeName();
    virtual CWnd * GetHookedWnd();
private:
    void Init();
};

class CRootPanel : public CPanel
{
public:
    CRootPanel();
    ~CRootPanel();
    virtual CWnd * GetHookedWnd();
    CWnd * m_pHookWnd;
    virtual CString GetTypeName();
}; 

class CWndResizer 
{
public:
  CWndResizer(void);
  ~CWndResizer(void);
public:

  typedef enum tagSplitterOrientation 
  {
    // a horizontal splitter container panel
    SPLIT_CONTAINER_H = 1,
    // a vertical splitter contianer panel
    SPLIT_CONTAINER_V = 2, 

  } SplitterOrientation;


  typedef enum tagFlowDirection 
  {
    // left to right flow direction
    LEFT_TO_RIGHT = 3,
    // top to bottom flow direction
    TOP_TO_BOTTOM = 4, 

  } FlowDirection;

public:
  BOOL SetAnchor(LPCTSTR panelName, UINT anchor);
  BOOL SetAnchor(UINT panelID, UINT anchor);
  BOOL GetAnchor(LPCTSTR panelName, UINT & anchor);
  BOOL GetAnchor(UINT panelID, UINT & anchor);

  BOOL SetOffset(LPCTSTR panelName, UINT anchor, int offset);
  BOOL SetOffset(UINT panelID, UINT anchor, int offset);

  BOOL SetDock(LPCTSTR panelName, UINT anchor);
  BOOL SetDock(UINT panelID, UINT anchor);
  BOOL GetDock(LPCTSTR panelName, UINT & anchor);
  BOOL GetDock(UINT panelID, UINT & anchor);

  BOOL SetFixedPanel(LPCTSTR splitContainerName, short panel);
  BOOL GetFixedPanel(LPCTSTR splitContainerName, short & panel);

  BOOL SetIsSplitterFixed(LPCTSTR splitContainerName, BOOL fixed);
  BOOL GetIsSplitterFixed(LPCTSTR splitContainerName, BOOL &fixed);

  BOOL SetFlowDirection(LPCTSTR flowPanelName, short direction);
  BOOL GetFlowDirection(LPCTSTR flowPanelName, short &direction);

  BOOL SetFlowItemSpacingX(LPCTSTR flowPanelName, int nSpacing);
  BOOL GetFlowItemSpacingX(LPCTSTR flowPanelName, int &nSpacing);

  BOOL SetFlowItemSpacingY(LPCTSTR flowPanelName, int nSpacing);
  BOOL GetFlowItemSpacingY(LPCTSTR flowPanelName, int &nSpacing);


  BOOL SetShowSplitterGrip(LPCTSTR splitContainerName, BOOL bShow);
  BOOL GetShowSplitterGrip(LPCTSTR splitContainerName, BOOL & bShow);

  BOOL SetParent(LPCTSTR panelName, LPCTSTR parentName);
  BOOL SetParent(UINT panelID, LPCTSTR parentName);
  BOOL SetParent(LPCTSTR panelName, UINT parentID);
  BOOL SetParent(UINT panelID, UINT parentID);
  BOOL GetParent(LPCTSTR panelName, CString & parentName);
  BOOL GetParent(UINT panelID, CString & parentName);

  BOOL SetMinimumSize(LPCTSTR panelName, CSize & size);
  BOOL SetMinimumSize(UINT panelID, CSize & size);
  BOOL GetMinimumSize(LPCTSTR panelName, CSize & size) ;
  BOOL GetMinimumSize(UINT panelID, CSize & size) ;

  BOOL SetMaximumSize(LPCTSTR panelName, CSize & size);
  BOOL SetMaximumSize(UINT panelID, CSize & size);
  BOOL GetMaximumSize(LPCTSTR panelName, CSize & size) ;
  BOOL GetMaximumSize(UINT panelID, CSize & size) ;

  void SetShowResizeGrip(BOOL show = TRUE);
  BOOL GetShowResizeGrip();
  BOOL Hook(CWnd * pWnd);
  BOOL Hook(CWnd * pWnd, CSize & size);
  BOOL Unhook();
  
  BOOL CreateFlowLayoutPanel(LPCTSTR panelName, const CRect * prcPanel);
  BOOL CreateFlowLayoutPanel(LPCTSTR panelName, const CUIntArray * parrID, BOOL setAsChildren = FALSE);

  BOOL CreatePanel(LPCTSTR panelName, const CRect * prcPanel);
  BOOL CreatePanel(LPCTSTR panelName, const CUIntArray * parrID, BOOL setAsChildren = FALSE);

  BOOL CreatePanel(UINT uID);

  BOOL CreateSplitContainer(LPCTSTR splitContainerName, LPCTSTR panelNameA, LPCTSTR panelNameB);    
  BOOL CreateSplitContainer(LPCTSTR splitContainerName, LPCTSTR panelNameA, UINT panelIDB);  
  BOOL CreateSplitContainer(LPCTSTR splitContainerName, UINT panelIDA, UINT panelIDB);  
  BOOL CreateSplitContainer(LPCTSTR splitContainerName, UINT panelIDA, LPCTSTR panelNameB); 

  // useful for persisting UI layout
  BOOL SetSplitterPosition(LPCTSTR splitContainerName, UINT position);  
  BOOL GetSplitterPosition(LPCTSTR splitContainerName, UINT & position);  

  BOOL InvokeOnResized();
  
  CString GetDebugInfo();
  
private:
  
  CWnd * m_pHookedWnd;
  CRootPanel root;
  CPanel * m_pCaptured;
  HCURSOR m_hOldCursor;
  int m_splitterOffset;  

  void OnPaint();
  void OnSize(UINT nType, int cx, int cy);
  void OnSizing(UINT fwSide, LPRECT pRect);
  void OnScroll();
  void OnDestroy();
	void OnLButtonDown(UINT nFlags, CPoint point);
	void OnMouseMove(UINT nFlags, CPoint point);
	void OnLButtonUp(UINT nFlags, CPoint point);

  CWndResizer::CPanel * FindPanelByName(CWndResizer::CPanel * pRoot, LPCTSTR name);
  CWndResizer::CPanel * FindSplitterFromPoint(CWndResizer::CPanel * pRoot, CPoint point);
  void GetUIPanels(CWndResizer::CPanel * pRoot, CPanelList * pList, BOOL bOle);
  void GetVisualPanels(CWndResizer::CPanel * pRoot, CPanelList * pList);

  void ResizeUI(CWndResizer::CPanel * pRoot);

  CString IdToName(UINT uID);
  CUIPanel * CreateUIPanel(UINT uID);
  CUIPanel * GetUIPanel(UINT uID);

  void UpdateSplitterOffset(CPoint ptCurr);
  void GetDebugInfo(CPanel * pRoot, CString & info, CString  indent);
  void GetTrueClientRect(CWnd * pWnd, CRect * prc);
  void EnsureRootMinMax();

  WNDPROC m_pfnWndProc;
  static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


};

   