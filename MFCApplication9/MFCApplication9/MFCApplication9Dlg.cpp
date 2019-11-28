
// MFCApplication9Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication9.h"
#include "MFCApplication9Dlg.h"
#include "afxdialogex.h"
#include "math.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication9Dlg 对话框

//CMFCApplication9Dlg::buttonDownNum(int numSize);

CMFCApplication9Dlg::CMFCApplication9Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication9Dlg::IDD, pParent)
	
	//, m_display(0)
{
	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//{{AFX_DATA_INIT(CCounterDlg)
    //初始化
    m_display = 0;
    num1 = 0;
    num2 = 0;
    result = 0.0;
    str = "";
    str_flag = FALSE;
    continue_flg = FALSE;
    downDot = FALSE;
    count = 1;


    //}}AFX_DATA_INIT
    // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication9Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_display);
}

BEGIN_MESSAGE_MAP(CMFCApplication9Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication9Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication9Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication9Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication9Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication9Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication9Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication9Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication9Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication9Dlg::OnBnClickedButton8)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication9Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTONDIV, &CMFCApplication9Dlg::OnBnClickedButtondiv)
	ON_BN_CLICKED(IDC_BUTTONMULT, &CMFCApplication9Dlg::OnBnClickedButtonmult)
	ON_BN_CLICKED(IDC_BUTTONSUB, &CMFCApplication9Dlg::OnBnClickedButtonsub)
	ON_BN_CLICKED(IDC_BUTTONADD, &CMFCApplication9Dlg::OnBnClickedButtonadd)
	ON_BN_CLICKED(IDC_BUTTONEQU, &CMFCApplication9Dlg::OnBnClickedButtonequ)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplication9Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCApplication9Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTONdot, &CMFCApplication9Dlg::OnBnClickedButtondot)
	ON_BN_CLICKED(IDC_BUTTONdel, &CMFCApplication9Dlg::OnBnClickedButtondel)
	ON_BN_CLICKED(IDC_MFCMENUBUTTON1, &CMFCApplication9Dlg::OnBnClickedMfcmenubutton1)
	ON_COMMAND(ID_32779, &CMFCApplication9Dlg::On32779)
	ON_COMMAND(ID_32773, &CMFCApplication9Dlg::On32773)
	ON_COMMAND(ID_32774, &CMFCApplication9Dlg::On32774)
	ON_COMMAND(ID_32775, &CMFCApplication9Dlg::On32775)
	ON_COMMAND(ID_32776, &CMFCApplication9Dlg::On32776)
	ON_COMMAND(ID_32777, &CMFCApplication9Dlg::On32777)
	ON_COMMAND(ID_32778, &CMFCApplication9Dlg::On32778)
	ON_COMMAND(ID_32780, &CMFCApplication9Dlg::On32780)
END_MESSAGE_MAP()


// CMFCApplication9Dlg 消息处理程序

BOOL CMFCApplication9Dlg::OnInitDialog()
{
	m_Menu.LoadMenu(IDR_MENU1);
	SetMenu(&m_Menu);
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication9Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication9Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication9Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication9Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_display = buttonDownNum(1);    
    UpdateData(FALSE);    
}


void CMFCApplication9Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_display = buttonDownNum(2);    
    UpdateData(FALSE);    
}


void CMFCApplication9Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_display = buttonDownNum(3);    
    UpdateData(FALSE);    
}


void CMFCApplication9Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	m_display = buttonDownNum(4);    
    UpdateData(FALSE);    
}




void CMFCApplication9Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	m_display = buttonDownNum(5);    
    UpdateData(FALSE);    
}


void CMFCApplication9Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	m_display = buttonDownNum(6);    
    UpdateData(FALSE);    
}


void CMFCApplication9Dlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	m_display = buttonDownNum(7);    
    UpdateData(FALSE);    
}


void CMFCApplication9Dlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	m_display = buttonDownNum(8);    
    UpdateData(FALSE);    
}

void CMFCApplication9Dlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	m_display = buttonDownNum(9);    
    UpdateData(FALSE);    
}



void CMFCApplication9Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

//#1015

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication9Dlg::OnBnClickedButtondiv()
{
	// TODO: 在此添加控件通知处理程序代码
	str = "/";    
    str_flag = TRUE;
    continue_flg = FALSE;
    downDot = FALSE;
    count = 1;
    UpdateData(FALSE);
}


void CMFCApplication9Dlg::OnBnClickedButtonmult()
{
	// TODO: 在此添加控件通知处理程序代码
	str = "*";    
    str_flag = TRUE;
    continue_flg = FALSE;
    downDot = FALSE;
    count = 1;
    UpdateData(FALSE);
}


void CMFCApplication9Dlg::OnBnClickedButtonsub()
{
	// TODO: 在此添加控件通知处理程序代码
	str = "-";    
    str_flag = TRUE;
    continue_flg = FALSE;
    downDot = FALSE;
    count = 1;
    UpdateData(FALSE);
}


void CMFCApplication9Dlg::OnBnClickedButtonadd()
{
	// TODO: 在此添加控件通知处理程序代码
	str = "+";    
    str_flag = TRUE;
    continue_flg = FALSE;
    downDot = FALSE;
    count = 1;
    UpdateData(FALSE);
}






void CMFCApplication9Dlg::OnBnClickedButtonequ()
{
	// TODO: 在此添加控件通知处理程序代码
	    if(str == "+")
        result = num1 + num2;
    else if(str == "-")
        result = num1 - num2;
    else if(str == "*")
        result = num1 * num2;
    else if(str == "/")
    {
        result = double(num1) / double(num2);
    }


    num1 = result;
    m_display = result;
    str_flag = FALSE;
    continue_flg = FALSE;
    downDot = FALSE;
    count = 1;
    UpdateData(FALSE);
}


void CMFCApplication9Dlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	m_display = buttonDownNum(0);    
    UpdateData(FALSE);    
}



double CMFCApplication9Dlg::buttonDownNum(int numSize)
{
	float num3;
	int counta=0;
	int countb=0;
	if(numSize==99)
	{
		if (!str_flag) //运算符没有被按下，那就是num1
		{
			if(downDot)
			{	
				num3 = num1-(int)num1;
				for(counta=1;counta<10;counta++)
					{
						num3*=10;
						if(num3-(int)num3==0)
							{
								  break;
							 }
					}
				countb=counta-1;
				while(countb)
				{
					num1*=10;
					countb--;
		
				}
				num1=(int)num1;
				counta=counta-1;
				while(counta)
				{
					num1/=10;
					counta--;
				}
				return num1;
			}
			else
			{	
				num1=(int)num1/10;
				return num1;	
			}
		}
		else
		{
				if(downDot)
			{	
				num3 = num2-(int)num2;
				for(counta=1;counta<10;counta++)
					{
						num3*=10;
						if(num3-(int)num3==0)
							{
								  break;
							 }
					}
				countb=counta-1;
				while(countb)
				{
					num2*=10;
					countb--;
		
				}
				num2=(int)num2;
				counta=counta-1;
				while(counta)
				{
					num2/=10;
					counta--;
				}
				return num2;
			}
			else
			{	
				num2=(int)num2/10;
				return num2;	
			}
		}
	}

	 if (!str_flag) //运算符没有被按下，那就是num1
    {
        if (!continue_flg) //按下一次
        {
            num1 = numSize;
            continue_flg =TRUE;
        }
        else
        {
            num1 = num1*pow(double(10),count) + numSize;
            if (downDot)
            {
                num1 = num1/(pow(double(10),count));
                count++;
            }
        }
        
        return num1;
    }
    else  //有运算符被按下
    {
        if (!continue_flg) //是否连续按下
        {
            num2 = numSize;
            continue_flg =TRUE;
        }
        else
        {
            num2 = num2*pow(double(10),count) + numSize;
            if (downDot)
            {
                num2 = num2/(pow(double(10),count));
                count++;
            }
        }
        
        return num2;
    }
}


void CMFCApplication9Dlg::OnBnClickedButton12()//清屏

{
	// TODO: 在此添加控件通知处理程序代码
	num1 = 0;
    num2 = 0;
    m_display = 0;
    continue_flg = FALSE;
    str_flag = FALSE;
    downDot = FALSE;
    count = 1;
    UpdateData(FALSE);
}


void CMFCApplication9Dlg::OnBnClickedButtondot()
{
	// TODO: 在此添加控件通知处理程序代码
	downDot = TRUE; 
}


void CMFCApplication9Dlg::OnBnClickedButtondel()
{
	// TODO: 在此添加控件通知处理程序代码
   m_display = buttonDownNum(99);
	UpdateData(FALSE);

}


void CMFCApplication9Dlg::OnBnClickedMfcmenubutton1()
{


	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication9Dlg::On32779()
{
	// TODO: 在此添加命令处理程序代码
	num1 = 0;
    num2 = 0;
    m_display = 0;
    continue_flg = FALSE;
    str_flag = FALSE;
    downDot = FALSE;
    count = 1;
    UpdateData(FALSE);
}


void CMFCApplication9Dlg::On32773()//加
{
	// TODO: 在此添加命令处理程序代码
	str = "+";    
    str_flag = TRUE;
    continue_flg = FALSE;
    downDot = FALSE;
    count = 1;
    UpdateData(FALSE);

}


void CMFCApplication9Dlg::On32774()
{
	// TODO: 在此添加命令处理程序代码
	str = "-";    
    str_flag = TRUE;
    continue_flg = FALSE;
    downDot = FALSE;
    count = 1;
    UpdateData(FALSE);
}


void CMFCApplication9Dlg::On32775()//*
{
	// TODO: 在此添加命令处理程序代码
	str = "*";    
    str_flag = TRUE;
    continue_flg = FALSE;
    downDot = FALSE;
    count = 1;
    UpdateData(FALSE);
}


void CMFCApplication9Dlg::On32776()
{
	// TODO: 在此添加命令处理程序代码
	str = "/";    
    str_flag = TRUE;
    continue_flg = FALSE;
    downDot = FALSE;
    count = 1;
    UpdateData(FALSE);
}


void CMFCApplication9Dlg::On32777()
{
	// TODO: 在此添加命令处理程序代码
	if(str == "+")
        result = num1 + num2;
    else if(str == "-")
        result = num1 - num2;
    else if(str == "*")
        result = num1 * num2;
    else if(str == "/")
    {
        result = double(num1) / double(num2);
    }


    num1 = result;
    m_display = result;
    str_flag = FALSE;
    continue_flg = FALSE;
    downDot = FALSE;
    count = 1;
    UpdateData(FALSE);
}


void CMFCApplication9Dlg::On32778()
{
	// TODO: 在此添加命令处理程序代码

	
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();

}


void CMFCApplication9Dlg::On32780()
{
	m_display = buttonDownNum(99);
	UpdateData(FALSE);
	// TODO: 在此添加命令处理程序代码
}
