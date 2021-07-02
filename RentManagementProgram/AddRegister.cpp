// AddRegister.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "AddRegister.h"
#include "afxdialogex.h"
//add
#include "mainClass.h"
#include<iostream>
#include <fstream>
#include <sstream>
#include<string>
using namespace std;

// AddRegister 对话框

IMPLEMENT_DYNAMIC(AddRegister, CDialogEx)

AddRegister::AddRegister(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_addRegister, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

AddRegister::~AddRegister()
{
}

void AddRegister::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AddRegister, CDialogEx)
	ON_BN_CLICKED(IDOK, &AddRegister::OnBnClickedOk)
END_MESSAGE_MAP()


// AddRegister 消息处理程序


void AddRegister::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cstr1, cstr2, cstr3, cstr4, cstr5;
	GetDlgItem(IDC_EDIT1)->GetWindowText(cstr1);
	GetDlgItem(IDC_EDIT2)->GetWindowText(cstr2);
	GetDlgItem(IDC_EDIT3)->GetWindowText(cstr3);
	GetDlgItem(IDC_EDIT4)->GetWindowText(cstr4);
	GetDlgItem(IDC_EDIT5)->GetWindowText(cstr5);
	//CString -> string
	string str1(CW2A(cstr1.GetString()));
	string str2(CW2A(cstr2.GetString()));
	string str3(CW2A(cstr3.GetString()));
	string str4(CW2A(cstr4.GetString()));
	string str5(CW2A(cstr5.GetString()));
	ofstream os("Register.dat", ios_base::binary | ios_base::app);
	Register r(str1, str2, str3, str4, str5);	//string -> double (please view mainClass.h)
	os << r<<' ';
	os.close();
	CDialogEx::OnOK();
}
