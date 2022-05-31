// win计算平均成绩Dlg.h : header file
//

#if !defined(AFX_WINDLG_H__3DD66081_2B46_45CB_95A2_849CAA0950AF__INCLUDED_)
#define AFX_WINDLG_H__3DD66081_2B46_45CB_95A2_849CAA0950AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWinDlg dialog

class CWinDlg : public CDialog
{
// Construction
public:
	CWinDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWinDlg)
	enum { IDD = IDD_WIN_DIALOG };
	int		m_s1;
	int		m_s2;
	int		m_s3;
	CString	m_sav;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWinDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWinDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void On75();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINDLG_H__3DD66081_2B46_45CB_95A2_849CAA0950AF__INCLUDED_)
