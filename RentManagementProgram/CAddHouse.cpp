// CAddHouse.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "CAddHouse.h"
#include "afxdialogex.h"


// CAddHouse 对话框

IMPLEMENT_DYNAMIC(CAddHouse, CDialogEx)

CAddHouse::CAddHouse(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_addGuest, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CAddHouse::~CAddHouse()
{
}

void CAddHouse::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddHouse, CDialogEx)
END_MESSAGE_MAP()


// CAddHouse 消息处理程序
