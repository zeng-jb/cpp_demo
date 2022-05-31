// simpleCalcDlg.h : header file
//

#if !defined(AFX_SIMPLECALCDLG_H__A8294435_BD10_4405_AA4C_825CD35E952C__INCLUDED_)
#define AFX_SIMPLECALCDLG_H__A8294435_BD10_4405_AA4C_825CD35E952C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSimpleCalcDlg dialog

class CSimpleCalcDlg : public CDialog
{
// Construction
public:
	CSimpleCalcDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSimpleCalcDlg)
	enum { IDD = IDD_SIMPLECALC_DIALOG };
	float	m_N1;
	float	m_N2;
	float	m_Result;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimpleCalcDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSimpleCalcDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton3();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnRadio4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	char Operator;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIMPLECALCDLG_H__A8294435_BD10_4405_AA4C_825CD35E952C__INCLUDED_)
