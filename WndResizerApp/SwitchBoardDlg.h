#pragma once


// CSwitchBoardDlg dialog

class CSwitchBoardDlg : public CDialog
{
	DECLARE_DYNAMIC(CSwitchBoardDlg)

public:
	CSwitchBoardDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSwitchBoardDlg();

// Dialog Data
	enum { IDD = IDD_SWITCH_BOARD_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnBnClickedButtonEx1();
  afx_msg void OnBnClickedButtonEx2();
  afx_msg void OnBnClickedButtonEx3();
  afx_msg void OnBnClickedButtonEx4();
  afx_msg void OnBnClickedButtonEx5();
  afx_msg void OnBnClickedButtonEx6();
  afx_msg void OnBnClickedButtonEx7();
  afx_msg void OnBnClickedButtonEx8();
  afx_msg void OnBnClickedButtonTest();
  afx_msg void OnBnClickedButtonEx9();
  afx_msg void OnBnClickedButtonEx10();
};
