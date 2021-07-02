#pragma once


// AddGuest 对话框

class AddGuest : public CDialogEx
{
	DECLARE_DYNAMIC(AddGuest)

public:
	AddGuest(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~AddGuest();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_addGuest };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
//	CEdit g_edit1;
private:
	CEdit g_edit1;
public:
	afx_msg void OnBnClickedCancel();
};
