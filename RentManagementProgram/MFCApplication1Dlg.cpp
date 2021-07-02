
// MFCApplication1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

//here
#include "AddHouse.h"
#include "AddGuest.h"
#include "AddRegister.h"
#include "DlgSearch.h"
#include "mainClass.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, n_edit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, n_edit);
	DDX_Control(pDX, IDC_BUTTON1, n_button1);
	DDX_Control(pDX, IDC_BUTTON2, n_button2);
	DDX_Control(pDX, IDC_BUTTON3, n_button3);
	DDX_Text(pDX, IDC_EDIT1, n_edit);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_RADIO1, &CMFCApplication1Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCApplication1Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication1Dlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CMFCApplication1Dlg::OnBnClickedButton1()  //租客信息
{
	BOOL m_Value;
	if ((m_Value = UpdateData(TRUE))) {

		UINT option;
		option = GetCheckedRadioButton(IDC_RADIO1, IDC_RADIO2);
		switch (option) {
		case IDC_RADIO1:
		{
			AddGuest addGuest;
			addGuest.DoModal();
		}
			break;
		case IDC_RADIO2:

		{
			CString cstr;
			GetDlgItem(IDC_EDIT1)->GetWindowText(cstr);
			if (cstr == "") MessageBox(_T("查询的ID不能为空"), _T("警告"), MB_ICONEXCLAMATION);
			else
			{	
				Guest gread;
				string str(CW2A(cstr.GetString()));
				ifstream is("Guest.dat", ios_base::binary);
				bool flag = false;
				while (!is.eof())
				{
					is >> gread;
					if (gread.getId() == str)
					{
						flag = true;
						break;
					}
				}
				if (flag)
				{
					//printInfo
					string info = {
						"身份证号："+gread.getId()+"\n"+
						"姓名：    "+gread.getName()+"\n"+
						"工作单位：" + gread.getWorkUnit() + "\n" +
						"工龄：" + gread.getWorkAge() + "\n" +
						"联系方式：" + gread.getContacts() + "\n" +
						"租房补贴：" + gread.getAllowance() + "\n"
					};
					CString cinfo(info.c_str());
					MessageBox(cinfo,_T("查询结果"));
				}
				else 
					MessageBox(_T("没有找到该ID的相关信息"), _T("查询结果"), MB_OK);
				is.close();
			}
		}
			break;
		default:
			MessageBox(_T("请选择服务项"), _T("警告"), MB_ICONEXCLAMATION);
		}
	}
}


void CMFCApplication1Dlg::OnBnClickedButton2()	//房屋信息
{
	BOOL m_Value;
	if ((m_Value = UpdateData(TRUE))) {

		UINT option;
		option = GetCheckedRadioButton(IDC_RADIO1, IDC_RADIO2);
		switch (option) {
		case IDC_RADIO1:
		{
			AddHouse addHouse;
			addHouse.DoModal();
		}
		break;
		case IDC_RADIO2:
		{
			CString cstr;
			GetDlgItem(IDC_EDIT1)->GetWindowText(cstr);
			if (cstr == "") MessageBox(_T("查询的ID不能为空"), _T("警告"), MB_ICONEXCLAMATION);
			else
			{
				House hread;
				string str(CW2A(cstr.GetString()));
				ifstream is("House.dat", ios_base::binary);
				bool flag = false;
				while (!is.eof())
				{
					is >> hread;
					if (hread.getHouseId() == str)
					{
						flag = true;
						break;
					}
				}
				if (flag)
				{
					//printInfo
					string info = {
						"地址：    " + hread.getAddress() + "\n" +
						"房产证号：" + hread.getHouseId() + "\n" +
						"户型：    " + hread.getHouseType() + "\n" +
						"面积：    " + hread.getArea() + "\n" +
						"装修等级：" + hread.getDecorateLv() + "\n" +
						"月租金：  " + hread.getRent() + "\n"
					};
					CString cinfo(info.c_str());
					MessageBox(cinfo, _T("查询结果"));
				}
				else
					MessageBox(_T("没有找到该ID的相关信息"), _T("查询结果"), MB_OK);
				is.close();
			}
		}
		break;
		default:
			MessageBox(_T("请选择服务项"), _T("警告"), MB_ICONEXCLAMATION);
		}
	}

}

void CMFCApplication1Dlg::OnBnClickedButton3()	//租房登记信息
{
	BOOL m_Value;
	if ((m_Value = UpdateData(TRUE))) {

		UINT option;
		option = GetCheckedRadioButton(IDC_RADIO1, IDC_RADIO2);
		switch (option) {
		case IDC_RADIO1:
		{
			AddRegister addRegister;
			addRegister.DoModal();
		}
		break;
		case IDC_RADIO2:

		{
			CString cstr;
			GetDlgItem(IDC_EDIT1)->GetWindowText(cstr);
			if (cstr == "") MessageBox(_T("查询的ID不能为空"), _T("警告"), MB_ICONEXCLAMATION);
			else
			{
				Register rread;
				string str(CW2A(cstr.GetString()));
				ifstream is("Register.dat", ios_base::binary);
				bool flag = false;
				while (!is.eof())
				{
					is >> rread;
					if (rread.getAgreementNum() == str)
					{
						flag = true;
						break;
					}
				}
				if (flag)
				{
		////////////////////////////////////////////////////////////////////////////////////////////
					//printInfo
					string info = {
						"身份证号：" + rread.getId() + "\n" +
						"房产证号：" + rread.getHouseId() + "\n" +
						"入住时间：" + rread.getCheckInTime() + "\n" +
						"租房合同号:" + rread.getAgreementNum() + "\n" +
						"备注：    " + rread.getRemark() + "\n" 
					};
					CString cinfo(info.c_str());
					//MessageBox(cinfo, _T("查询结果"),MB_OK);
					// 
					//check Guest.dat
					Guest gread;
					ifstream isg("Guest.dat", ios_base::binary);
					bool flag1 = false;
					while (!isg.eof())
					{
						isg >> gread;
						{
							if (gread.getId() == rread.getId())
							{
								flag1 = true;
								break;
							}

						}
					}
					//check House.dat
					House hread;
					ifstream ish("House.dat", ios_base::binary);
					bool flag2 = false;
					while (!ish.eof())
					{
						ish >> hread;
						{
							if (hread.getHouseId() == rread.getHouseId())
							{
								flag2 = true;
								break;
							}
						}
					}
					if (flag1&&!flag2)
					{
						//printInfo
						string info1 = {
							"\n找到相关租客信息：\n身份证号：" + gread.getId() + "\n" +
							"姓名：    " + gread.getName() + "\n" +
							"工作单位：" + gread.getWorkUnit() + "\n" +
							"工龄：" + gread.getWorkAge() + "\n" +
							"联系方式：" + gread.getContacts() + "\n" +
							"租房补贴：" + gread.getAllowance() + "\n"
						};
						CString cinfo1(info1.c_str());
						MessageBox(cinfo + cinfo1, _T("查询结果"),MB_OK);
					}
					else if (flag2&&!flag1)
					{
						//printInfo
						string info2 = {
						"\n找到相关房屋信息：\n地址：    " + hread.getAddress() + "\n" +
						"房产证号：" + hread.getHouseId() + "\n" +
						"户型：    " + hread.getHouseType() + "\n" +
						"面积：    " + hread.getArea() + "\n" +
						"装修等级：" + hread.getDecorateLv() + "\n" +
						"月租金：  " + hread.getRent() + "\n"
						};
						CString cinfo2(info2.c_str());
						MessageBox(cinfo + cinfo2,_T("查询结果"), MB_OK);
						//MessageBox(cinfo2, _T("查询结果"));
					}
					else if (flag1 && flag2)
					{
						string info12 = {
							"\n找到相关租客信息：\n身份证号：" + gread.getId() + "\n" +
							"姓名：    " + gread.getName() + "\n" +
							"工作单位：" + gread.getWorkUnit() + "\n" +
							"工龄：" + gread.getWorkAge() + "\n" +
							"联系方式：" + gread.getContacts() + "\n" +
							"租房补贴：" + gread.getAllowance() + "\n"+
							"\n找到相关房屋信息：\n地址：    " + hread.getAddress() + "\n" +
						"房产证号：" + hread.getHouseId() + "\n" +
						"户型：    " + hread.getHouseType() + "\n" +
						"面积：    " + hread.getArea() + "\n" +
						"装修等级：" + hread.getDecorateLv() + "\n" +
						"月租金：  " + hread.getRent() + "\n"
						};
						CString cinfo12(info12.c_str());
						MessageBox(cinfo + cinfo12, _T("查询结果"), MB_OK);
					}
					else MessageBox(cinfo + _T("没有找到更多关联信息"), _T("查询结果"), MB_OK);//
					isg.close();
					ish.close();
		///////////////////////////////////////////////////////////////////////////////////////////////
				}
				else
					MessageBox(_T("没有找到该ID的相关信息"), _T("查询结果"), MB_OK);
				is.close();
			}
		}
		break;
		default:
			MessageBox(_T("请选择服务项"), _T("警告"), MB_ICONEXCLAMATION);
		}
	}

}

void CMFCApplication1Dlg::OnBnClickedRadio1()	//添加
{
	CButton* radio = (CButton*)GetDlgItem(IDC_RADIO1);
	if (radio->GetCheck())
		GetDlgItem(IDC_EDIT1)->EnableWindow(false);
	/*
	CButton* radio = (CButton*)GetDlgItem(IDC_RADIO1);
	radio->SetCheck(1);
	BOOL check = radio->GetCheck();
	*/

}


void CMFCApplication1Dlg::OnBnClickedRadio2()	//查询
{
	CButton* radio = (CButton*)GetDlgItem(IDC_RADIO2);
	if (radio->GetCheck())
		GetDlgItem(IDC_EDIT1)->EnableWindow(true);
}


void CMFCApplication1Dlg::OnBnClickedButton4()
{
	MessageBox(_T("作者：chuchu\n学号：1918000146\nQQ：  2496729202\nVersion：1.0"), _T("关于"), MB_OK);
	// TODO: 在此添加控件通知处理程序代码
}
