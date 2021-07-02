#pragma once


// DlgSearch 对话框

class DlgSearch : public CDialogEx
{
	DECLARE_DYNAMIC(DlgSearch)

public:
	DlgSearch(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DlgSearch();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SEARCH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	CListCtrl n_list1;
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
};
