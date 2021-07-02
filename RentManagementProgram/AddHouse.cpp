// AddHouse.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "AddHouse.h"
#include "afxdialogex.h"
//add
#include "mainClass.h"
#include<iostream>
#include <fstream>
#include <sstream>
#include<string>
using namespace std;

// AddHouse 对话框

IMPLEMENT_DYNAMIC(AddHouse, CDialogEx)

AddHouse::AddHouse(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_addHouse, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

AddHouse::~AddHouse()
{
}

void AddHouse::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AddHouse, CDialogEx)
	ON_BN_CLICKED(IDOK, &AddHouse::OnBnClickedOk)
END_MESSAGE_MAP()


// AddHouse 消息处理程序


void AddHouse::OnBnClickedOk()
{

	// TODO: 在此添加控件通知处理程序代码
	CString cstr1, cstr2, cstr3, cstr4, cstr5, cstr6;
	GetDlgItem(IDC_EDIT1)->GetWindowText(cstr1);
	GetDlgItem(IDC_EDIT2)->GetWindowText(cstr2);
	GetDlgItem(IDC_EDIT3)->GetWindowText(cstr3);
	GetDlgItem(IDC_EDIT4)->GetWindowText(cstr4);
	GetDlgItem(IDC_EDIT5)->GetWindowText(cstr5);
	GetDlgItem(IDC_EDIT6)->GetWindowText(cstr6);
	//CString -> string
	string str1(CW2A(cstr1.GetString()));
	string str2(CW2A(cstr2.GetString()));
	string str3(CW2A(cstr3.GetString()));
	string str4(CW2A(cstr4.GetString()));
	string str5(CW2A(cstr5.GetString()));
	string str6(CW2A(cstr6.GetString()));

	ofstream os("House.dat", ios_base::binary | ios_base::app);
	House h(str1, str2, str3, str4, str5, str6);	//string -> double (please view mainClass.h)
	os << h<<' ';
	os.close();
	CDialogEx::OnOK();
}
