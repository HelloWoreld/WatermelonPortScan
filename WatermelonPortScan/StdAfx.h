// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__A8E27309_6585_4E3D_A19C_820DEF70349A__INCLUDED_)
#define AFX_STDAFX_H__A8E27309_6585_4E3D_A19C_820DEF70349A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__A8E27309_6585_4E3D_A19C_820DEF70349A__INCLUDED_)

#include <winsock2.h>//2.0版本
#pragma comment(lib,"ws2_32.lib")
#include <process.h>//线程函数头文件
#include <mmsystem.h> //必须包含这文件
#pragma comment( lib, "Winmm.lib" ) //必须包含这文件
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct stru_message_param 
{
	char *cli_ip;	
	u_short cli_port;
//	char *cli_status;
	char *cli_service;
}STRU_MESSAGE_PARAM;

typedef struct stru_scan_param 
{
	u_long   dest_ip;	
	u_short dest_port;
};
