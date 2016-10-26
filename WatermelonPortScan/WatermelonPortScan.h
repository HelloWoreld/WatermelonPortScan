// WatermelonPortScan.h : main header file for the WATERMELONPORTSCAN application
//

#if !defined(AFX_WATERMELONPORTSCAN_H__70DFDD6A_9BA4_43FC_AA86_C7C65458F593__INCLUDED_)
#define AFX_WATERMELONPORTSCAN_H__70DFDD6A_9BA4_43FC_AA86_C7C65458F593__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWatermelonPortScanApp:
// See WatermelonPortScan.cpp for the implementation of this class
//

class CWatermelonPortScanApp : public CWinApp
{
public:
	CWatermelonPortScanApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWatermelonPortScanApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWatermelonPortScanApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WATERMELONPORTSCAN_H__70DFDD6A_9BA4_43FC_AA86_C7C65458F593__INCLUDED_)
