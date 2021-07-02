#pragma once


// AddHouse 对话框

class AddHouse : public CDialogEx
{
	DECLARE_DYNAMIC(AddHouse)

public:
	AddHouse(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~AddHouse();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_addHouse };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
