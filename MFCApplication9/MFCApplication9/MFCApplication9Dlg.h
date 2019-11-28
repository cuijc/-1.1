
// MFCApplication9Dlg.h : 头文件
//
#include "ABOUTBOX.h"
#pragma once


// CMFCApplication9Dlg 对话框
class CMFCApplication9Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication9Dlg(CWnd* pParent = NULL);	// 标准构造函数
	CMenu m_Menu;
// 对话框数据
	enum { IDD = IDD_MFCAPPLICATION9_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButtondiv();
	afx_msg void OnBnClickedButtonmult();
	afx_msg void OnBnClickedButtonsub();
	afx_msg void OnBnClickedButtonadd();
	afx_msg void OnBnClickedButtonequ();
	afx_msg void OnBnClickedButton10();

 int count;  //计数
 BOOL dot_flg; //小数点标志
 BOOL continue_flg;//没按运算符，是否一直连续按数字按钮标志
 BOOL str_flag;//有没按运算符标志
 CString str;//记录当前按的运算符
 double result; //num1和num2运算的结果
 double num1; //按运算符之前的第一个数
 double num2; //按运算符之后的第二个数
 bool downDot ;
// double m_display;
 double m_display;
 double buttonDownNum(int numSize);

 CABOUTBOX dlg;

 afx_msg void OnBnClickedButton12();
 afx_msg void OnBnClickedButtondot();
 afx_msg void OnBnClickedButtondel();
 afx_msg void OnBnClickedMfcmenubutton1();
 afx_msg void On32779();
 afx_msg void On32773();
 afx_msg void On32774();
 afx_msg void On32775();
 afx_msg void On32776();
 afx_msg void On32777();
 afx_msg void On32778();
 afx_msg void On32780();
};
