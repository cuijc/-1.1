
// MFCApplication9Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication9.h"
#include "MFCApplication9Dlg.h"
#include "afxdialogex.h"
#include "math.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCApplication9Dlg �Ի���

//CMFCApplication9Dlg::buttonDownNum(int numSize);

CMFCApplication9Dlg::CMFCApplication9Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication9Dlg::IDD, pParent)
	
	//, m_display(0)
{
	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//{{AFX_DATA_INIT(CCounterDlg)
    //��ʼ��
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


// CMFCApplication9Dlg ��Ϣ�������

BOOL CMFCApplication9Dlg::OnInitDialog()
{
	m_Menu.LoadMenu(IDR_MENU1);
	SetMenu(&m_Menu);
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication9Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplication9Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication9Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_display = buttonDownNum(1);    
    UpdateData(FALSE);    
}


void CMFCApplication9Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_display = buttonDownNum(2);    
    UpdateData(FALSE);    
}


void CMFCApplication9Dlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_display = buttonDownNum(3);    
    UpdateData(FALSE);    
}


void CMFCApplication9Dlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_display = buttonDownNum(4);    
    UpdateData(FALSE);    
}




void CMFCApplication9Dlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_display = buttonDownNum(5);    
    UpdateData(FALSE);    
}


void CMFCApplication9Dlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_display = buttonDownNum(6);    
    UpdateData(FALSE);    
}


void CMFCApplication9Dlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_display = buttonDownNum(7);    
    UpdateData(FALSE);    
}


void CMFCApplication9Dlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_display = buttonDownNum(8);    
    UpdateData(FALSE);    
}

void CMFCApplication9Dlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_display = buttonDownNum(9);    
    UpdateData(FALSE);    
}



void CMFCApplication9Dlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

//#1015

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMFCApplication9Dlg::OnBnClickedButtondiv()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	str = "/";    
    str_flag = TRUE;
    continue_flg = FALSE;
    downDot = FALSE;
    count = 1;
    UpdateData(FALSE);
}


void CMFCApplication9Dlg::OnBnClickedButtonmult()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	str = "*";    
    str_flag = TRUE;
    continue_flg = FALSE;
    downDot = FALSE;
    count = 1;
    UpdateData(FALSE);
}


void CMFCApplication9Dlg::OnBnClickedButtonsub()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	str = "-";    
    str_flag = TRUE;
    continue_flg = FALSE;
    downDot = FALSE;
    count = 1;
    UpdateData(FALSE);
}


void CMFCApplication9Dlg::OnBnClickedButtonadd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	str = "+";    
    str_flag = TRUE;
    continue_flg = FALSE;
    downDot = FALSE;
    count = 1;
    UpdateData(FALSE);
}






void CMFCApplication9Dlg::OnBnClickedButtonequ()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		if (!str_flag) //�����û�б����£��Ǿ���num1
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

	 if (!str_flag) //�����û�б����£��Ǿ���num1
    {
        if (!continue_flg) //����һ��
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
    else  //�������������
    {
        if (!continue_flg) //�Ƿ���������
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


void CMFCApplication9Dlg::OnBnClickedButton12()//����

{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	downDot = TRUE; 
}


void CMFCApplication9Dlg::OnBnClickedButtondel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
   m_display = buttonDownNum(99);
	UpdateData(FALSE);

}


void CMFCApplication9Dlg::OnBnClickedMfcmenubutton1()
{


	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMFCApplication9Dlg::On32779()
{
	// TODO: �ڴ���������������
	num1 = 0;
    num2 = 0;
    m_display = 0;
    continue_flg = FALSE;
    str_flag = FALSE;
    downDot = FALSE;
    count = 1;
    UpdateData(FALSE);
}


void CMFCApplication9Dlg::On32773()//��
{
	// TODO: �ڴ���������������
	str = "+";    
    str_flag = TRUE;
    continue_flg = FALSE;
    downDot = FALSE;
    count = 1;
    UpdateData(FALSE);

}


void CMFCApplication9Dlg::On32774()
{
	// TODO: �ڴ���������������
	str = "-";    
    str_flag = TRUE;
    continue_flg = FALSE;
    downDot = FALSE;
    count = 1;
    UpdateData(FALSE);
}


void CMFCApplication9Dlg::On32775()//*
{
	// TODO: �ڴ���������������
	str = "*";    
    str_flag = TRUE;
    continue_flg = FALSE;
    downDot = FALSE;
    count = 1;
    UpdateData(FALSE);
}


void CMFCApplication9Dlg::On32776()
{
	// TODO: �ڴ���������������
	str = "/";    
    str_flag = TRUE;
    continue_flg = FALSE;
    downDot = FALSE;
    count = 1;
    UpdateData(FALSE);
}


void CMFCApplication9Dlg::On32777()
{
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������

	
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();

}


void CMFCApplication9Dlg::On32780()
{
	m_display = buttonDownNum(99);
	UpdateData(FALSE);
	// TODO: �ڴ���������������
}
