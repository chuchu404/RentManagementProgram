// DlgSearch.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "DlgSearch.h"
#include "afxdialogex.h"


// DlgSearch 对话框

IMPLEMENT_DYNAMIC(DlgSearch, CDialogEx)

DlgSearch::DlgSearch(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SEARCH, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

DlgSearch::~DlgSearch()
{
}

void DlgSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_LIST1, n_list1);
}


BEGIN_MESSAGE_MAP(DlgSearch, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &DlgSearch::OnLvnItemchangedList1)
END_MESSAGE_MAP()


// DlgSearch 消息处理程序


void DlgSearch::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	/*
	//title
	CString cstr[] = { TEXT("注释"),TEXT("数据")};
	for (int i = 0;i < 2;i++)
	{
		n_list1.InsertColumn(i, cstr[i], LVCFMT_LEFT, 100);
	}
	//context
	//n_list1.InsertItem()
	*/

	*pResult = 0;
}
