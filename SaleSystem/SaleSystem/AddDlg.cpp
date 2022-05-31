// AddDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "AddDlg.h"
#include "InfoFile.h"


// CAddDlg

IMPLEMENT_DYNCREATE(CAddDlg, CFormView)

CAddDlg::CAddDlg()
	: CFormView(CAddDlg::IDD)
	, m_price1(0)
	, m_num1(0)
	, m_name2(_T(""))
	, m_price2(0)
	, m_num2(0)
{

}

CAddDlg::~CAddDlg()
{
}

void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_EDIT1, m_price1);
	DDX_Text(pDX, IDC_EDIT2, m_num1);
	DDX_Text(pDX, IDC_EDIT7, m_name2);
	DDX_Text(pDX, IDC_EDIT3, m_price2);
	DDX_Text(pDX, IDC_EDIT6, m_num2);
}

BEGIN_MESSAGE_MAP(CAddDlg, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CAddDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAddDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CAddDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CAddDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CAddDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CAddDlg ���

#ifdef _DEBUG
void CAddDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CAddDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CAddDlg ��Ϣ�������


void CAddDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���

	//��ȡ�ļ�����ȡ��Ʒ��������Ͽ�����ַ���
	//��Ҫ����#include "InfoFile.h"
	CInfoFile file;
	file.ReadDocline(); //��ȡ��Ʒ��Ϣ
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		m_combo.AddString((CString)it->name.c_str());
	}

	file.ls.clear(); //���list������

	//����һ����Ʒ����ΪĬ��ѡ����
	m_combo.SetCurSel(0);
}


void CAddDlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CString text;
	//��ȡ��ǰѡ����
	int index = m_combo.GetCurSel();
	//��ȡ��ǰ����
	m_combo.GetLBText(index, text);

	//��Ҫ����#include "InfoFile.h"
	CInfoFile file;
	file.ReadDocline(); //��ȡ��Ʒ��Ϣ
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (text == it->name.c_str())
		{
			m_price1 = it->price;
			m_num1 = 0;
			UpdateData(FALSE); //���ݸ��µ���Ӧ�Ŀؼ�
		}
	}

	file.ls.clear(); //���list������
}


void CAddDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//��ȡ�ؼ��ϵ����ݣ����µ���Ӧ�����ı�����
	UpdateData(TRUE);

	if (m_num1 == 0)
	{
		MessageBox(TEXT("��������Ϊ0"));
		return;
	}

	CString type;
	//��ȡ��ǰѡ����
	int index = m_combo.GetCurSel();
	//��ȡ��Ͽ�ǰ����
	m_combo.GetLBText(index, type);

	CString str;
	str.Format(_T("����� ��Ʒ��%s \r\n���ۣ�%d \r\n������%d"), type, m_price1, m_num1);
	MessageBox(str);


	//��Ҫ����#include "InfoFile.h"
	CInfoFile file;
	file.ReadDocline(); //��ȡ��Ʒ��Ϣ
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (type == it->name.c_str())
		{
			it->num +=  m_num1;
		}
	}
	file.WirteDocline(); //�����ļ�����

	file.ls.clear(); //���list������

	m_num1 = 0;
	UpdateData(FALSE); //���µ���Ӧ�Ŀؼ�
}


void CAddDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_combo.SetCurSel(0);
	m_num1 = 0;
	OnCbnSelchangeCombo1();

}


void CAddDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	UpdateData(TRUE); //��ȡ�ؼ�����

	if (m_num2 <= 0 || m_price2 <= 0 || m_name2.IsEmpty())
	{
		MessageBox(TEXT("������Ϣ����"));
		return;
	}

	//��Ҫ����#include "InfoFile.h"
	CInfoFile file;
	file.ReadDocline(); //��ȡ��Ʒ��Ϣ
	file.Addline(m_name2, m_num2, m_price2); //�����Ʒ
	file.WirteDocline(); //д�ļ�
	file.ls.clear(); //���list������
	MessageBox(_T("��ӳɹ�"));

	m_name2.Empty();
	m_num2 = 0;
	m_price2 = 0;
	UpdateData(FALSE);
}


void CAddDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	m_name2.Empty();
	m_num2 = 0;
	m_price2 = 0;
	UpdateData(FALSE);
}
