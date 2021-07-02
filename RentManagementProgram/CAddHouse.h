#pragma once


// CAddHouse 对话框

class CAddHouse : public CDialogEx
{
	DECLARE_DYNAMIC(CAddHouse)

public:
	CAddHouse(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CAddHouse();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_addGuest };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
