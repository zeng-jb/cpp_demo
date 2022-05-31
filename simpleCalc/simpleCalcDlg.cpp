// simpleCalcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "simpleCalc.h"
#include "simpleCalcDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSimpleCalcDlg dialog

CSimpleCalcDlg::CSimpleCalcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSimpleCalcDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSimpleCalcDlg)
	m_N1 = 0.0f;
	m_N2 = 0.0f;
	m_Result = 0.0f;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSimpleCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSimpleCalcDlg)
	DDX_Text(pDX, IDC_EDIT1, m_N1);
	DDX_Text(pDX, IDC_EDIT2, m_N2);
	DDX_Text(pDX, IDC_EDIT3, m_Result);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSimpleCalcDlg, CDialog)
	//{{AFX_MSG_MAP(CSimpleCalcDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_RADIO4, OnRadio4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSimpleCalcDlg message handlers

BOOL CSimpleCalcDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSimpleCalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSimpleCalcDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSimpleCalcDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSimpleCalcDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK(); 
}

void CSimpleCalcDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	switch(Operator)
	{
	case '+':
				m_Result=m_N1+m_N2;
				break;
	case '-':
		m_Result=m_N1-m_N2;
		break;
	case '*':
		m_Result=m_N1*m_N2;
		break;
	case '/':
		if(m_N2== 0 )MessageBox("��������Ϊ�㣡");
		else{
			m_Result = m_N1/m_N2; 
			break;
			}
	default:
		m_Result=m_N1+m_N2;
	}
	UpdateData(FALSE);
}

void CSimpleCalcDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_N1=0;
	m_N2=0;
	m_Result=0;
	UpdateData(FALSE);
}

/*void CSimpleCalcDlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	
}

void CSimpleCalcDlg::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	
}

void CSimpleCalcDlg::OnRadio3() 
{
	// TODO: Add your control notification handler code here
	
}

void CSimpleCalcDlg::OnRadio4() 
{
	// TODO: Add your control notification handler code here
	
}*/
//ѡ�������
void CSimpleCalcDlg::OnRadio1() 
		{Operator='+';   }
void CSimpleCalcDlg::OnRadio2()
		{Operator='-';   }
void CSimpleCalcDlg::OnRadio3() 
		{Operator='*';   }
void CSimpleCalcDlg::OnRadio4() 
		{Operator='/';}
//����

