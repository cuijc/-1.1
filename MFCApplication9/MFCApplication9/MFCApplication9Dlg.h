
// MFCApplication9Dlg.h : ͷ�ļ�
//
#include "ABOUTBOX.h"
#pragma once


// CMFCApplication9Dlg �Ի���
class CMFCApplication9Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication9Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	CMenu m_Menu;
// �Ի�������
	enum { IDD = IDD_MFCAPPLICATION9_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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

 int count;  //����
 BOOL dot_flg; //С�����־
 BOOL continue_flg;//û����������Ƿ�һֱ���������ְ�ť��־
 BOOL str_flag;//��û���������־
 CString str;//��¼��ǰ���������
 double result; //num1��num2����Ľ��
 double num1; //�������֮ǰ�ĵ�һ����
 double num2; //�������֮��ĵڶ�����
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
