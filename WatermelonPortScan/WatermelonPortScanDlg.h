// WatermelonPortScanDlg.h : header file
//
#define WM_MY_MESSAGE WM_USER+100
#if !defined(AFX_WATERMELONPORTSCANDLG_H__25DAC606_F6BD_43E8_9176_B81C0F39A6B2__INCLUDED_)
#define AFX_WATERMELONPORTSCANDLG_H__25DAC606_F6BD_43E8_9176_B81C0F39A6B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWatermelonPortScanDlg dialog

class CWatermelonPortScanDlg : public CDialog
{
// Construction
public:
	CWatermelonPortScanDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWatermelonPortScanDlg)
	enum { IDD = IDD_WATERMELONPORTSCAN_DIALOG };
	CIPAddressCtrl	m_IPStart;
	CIPAddressCtrl	m_IPEnd;
	CListCtrl	m_ListCtrol;
	CString	m_Ports;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWatermelonPortScanDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWatermelonPortScanDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonClick();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	LRESULT MyMessage(WPARAM wParam, LPARAM lParam);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WATERMELONPORTSCANDLG_H__25DAC606_F6BD_43E8_9176_B81C0F39A6B2__INCLUDED_)
UINT __stdcall ScanThread(LPVOID lParam);
