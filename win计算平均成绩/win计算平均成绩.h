// win����ƽ���ɼ�.h : main header file for the WIN����ƽ���ɼ� application
//

#if !defined(AFX_WIN_H__CC07896C_8641_4966_B8C2_036FFC2EF937__INCLUDED_)
#define AFX_WIN_H__CC07896C_8641_4966_B8C2_036FFC2EF937__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyWinApp:
// See win����ƽ���ɼ�.cpp for the implementation of this class
//

class CMyWinApp : public CWinApp
{
public:
	CMyWinApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyWinApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyWinApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WIN_H__CC07896C_8641_4966_B8C2_036FFC2EF937__INCLUDED_)
