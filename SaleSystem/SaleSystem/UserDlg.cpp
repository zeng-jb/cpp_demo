// UserDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "UserDlg.h"
#include "InfoFile.h"

// CUserDlg

IMPLEMENT_DYNCREATE(CUserDlg, CFormView)

CUserDlg::CUserDlg()
	: CFormView(CUserDlg::IDD)
	, m_user(_T(""))
	, m_name(_T(""))
	, m_newPwd(_T(""))
	, m_surePwd(_T(""))
{

}

CUserDlg::~CUserDlg()
{
}

void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_EDIT3, m_newPwd);
	DDX_Text(pDX, IDC_EDIT4, m_surePwd);
}

BEGIN_MESSAGE_MAP(CUserDlg, CFormView)
	ON_BN_CLICKED(IDC_BUTTON3, &CUserDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CUserDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CUserDlg ���

#ifdef _DEBUG
void CUserDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUserDlg ��Ϣ�������


void CUserDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	//��ʼ��
	m_user=TEXT("����Ա");

	CInfoFile file;
	CString name ,pwd;
	file.ReadLogin(name,pwd);
	m_name=name;

	UpdateData(FALSE);
	// TODO: �ڴ����ר�ô����/����û���
}


void CUserDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//�޸����빦��
	UpdateData(TRUE);//�����µ�ֵ

	if (m_newPwd.IsEmpty()||m_surePwd.IsEmpty())
	{
		MessageBox(TEXT("�������ݲ���Ϊ��"));
		return;
	}

	//�������ȷ������һ��
	if(m_newPwd!=m_surePwd){
		MessageBox(TEXT("��������ȷ�����벻һ��"));
		return;
	}

	//������������벻��һ��
	CInfoFile file;
	CString name,pwd;
	file.ReadLogin(name,pwd);
	if(pwd==m_newPwd)
	{
		MessageBox(TEXT("������������벻��һ��"));
		return;

	}
	//CString ת char*
	CStringA tmp; 
	CStringA tem2;
	tmp=name;
	tem2=m_newPwd;
	file.WritePwd(tmp.GetBuffer(),tem2.GetBuffer());
	MessageBox(TEXT("�޸ĳɹ�"));

	//�������
	m_newPwd.Empty();
	m_surePwd.Empty();
	UpdateData(FALSE);
}


void CUserDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//ȡ���޸�
	//�������
	m_newPwd.Empty();
	m_surePwd.Empty();
	UpdateData(FALSE);
}
