// DelDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "DelDlg.h"
#include "InfoFile.h"


// CDelDlg

IMPLEMENT_DYNCREATE(CDelDlg, CFormView)

CDelDlg::CDelDlg()
	: CFormView(CDelDlg::IDD)
	, m_price(0)
	, m_num(0)
{

}

CDelDlg::~CDelDlg()
{
}

void CDelDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_EDIT1, m_price);
	DDX_Text(pDX, IDC_EDIT2, m_num);
}

BEGIN_MESSAGE_MAP(CDelDlg, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDelDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDelDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDelDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CDelDlg ���

#ifdef _DEBUG
void CDelDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDelDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDelDlg ��Ϣ�������


void CDelDlg::OnInitialUpdate()
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


	//����һ����Ʒ����ΪĬ��ѡ����
	m_combo.SetCurSel(0);
}


void CDelDlg::OnCbnSelchangeCombo1()
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
			m_price = it->price;
			m_num = 0;
			UpdateData(FALSE); //���ݸ��µ���Ӧ�Ŀؼ�
		}
	}
}


void CDelDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//��ȡ�ؼ��ϵ����ݣ����µ���Ӧ�����ı�����
	UpdateData(TRUE);

	if (m_num == 0)
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
	str.Format(_T("ɾ����Ʒ��%s \r\n���ۣ�%d \r\n������%d "), type, m_price, m_num);
	MessageBox(str);


	//��Ҫ����#include "InfoFile.h"
	CInfoFile file;
	file.ReadDocline(); //��ȡ��Ʒ��Ϣ
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (type == it->name.c_str())
		{
			it->num = it->num - m_num;
		}
	}
	file.WirteDocline(); //�����ļ�����



	m_num = 0;
	UpdateData(FALSE); //���µ���Ӧ�Ŀؼ�
}


void CDelDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	m_combo.SetCurSel(0); //ѡ���0��Ŀ
	m_num = 0;
	OnCbnSelchangeCombo1();
}
