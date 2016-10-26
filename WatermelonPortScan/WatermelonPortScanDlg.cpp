// WatermelonPortScanDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WatermelonPortScan.h"
#include "WatermelonPortScanDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	
	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA
	
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//{{AFX_MSG_MAP(CAboutDlg)
// No message handlers
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWatermelonPortScanDlg dialog

CWatermelonPortScanDlg::CWatermelonPortScanDlg(CWnd* pParent /*=NULL*/)
: CDialog(CWatermelonPortScanDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWatermelonPortScanDlg)
	m_Ports = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWatermelonPortScanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWatermelonPortScanDlg)
	DDX_Control(pDX, IDC_IPADDRESSStart, m_IPStart);
	DDX_Control(pDX, IDC_IPADDRESSEnd, m_IPEnd);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrol);
	DDX_Text(pDX, IDC_Ports, m_Ports);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWatermelonPortScanDlg, CDialog)
//{{AFX_MSG_MAP(CWatermelonPortScanDlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_BUTTON, OnButtonClick)
//}}AFX_MSG_MAP
ON_MESSAGE(WM_MY_MESSAGE, MyMessage)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWatermelonPortScanDlg message handlers

BOOL CWatermelonPortScanDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// Add "About..." menu item to system menu.
	
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	LONG lStyle; 
    lStyle = GetWindowLong(m_ListCtrol.m_hWnd, GWL_STYLE);//获取当前窗口style 
    
	lStyle &= ~LVS_TYPEMASK; //清除显示方式位 
    lStyle |= LVS_REPORT; //设置style 
    SetWindowLong(m_ListCtrol.m_hWnd, GWL_STYLE, lStyle);//设置style 
    DWORD dwStyle = m_ListCtrol.GetExtendedStyle(); 
    dwStyle |= LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格的listctrl） 
	dwStyle |= LVS_EX_GRIDLINES;//网格线（只适用与report风格的listctrl） 
	//	dwStyle |= LVS_EX_CHECKBOXES;//item前生成checkbox控件 
	m_ListCtrol.SetExtendedStyle(dwStyle); //设置扩展风格
	
	m_ListCtrol.InsertColumn( 0, "IP地址", LVCFMT_LEFT, 150 );//插入列 
    m_ListCtrol.InsertColumn( 1, "打开的端口", LVCFMT_LEFT, 145 ); 
	//m_ListCtrol.InsertColumn( 2, "端口状态", LVCFMT_LEFT, 100 ); 
	m_ListCtrol.InsertColumn( 2, "端口所对应的服务", LVCFMT_LEFT, 200 ); 
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWatermelonPortScanDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CWatermelonPortScanDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CWatermelonPortScanDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWatermelonPortScanDlg::OnButtonClick() 
{

	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_ListCtrol.DeleteAllItems();
	PlaySound("F:\\WatermelonPortScan\\The Rain.wav", NULL, SND_FILENAME | SND_ASYNC);
	u_long   ulIPStart;
	m_IPStart.GetAddress(ulIPStart);
	u_long   ulIPEnd;
	m_IPEnd.GetAddress(ulIPEnd);
	
	if(ulIPStart == 0){
		MessageBox("起始ip不能为空");
		return;
	}
	
	
	if(ulIPEnd == 0){
		MessageBox("结束ip不能为空");
		return;
	}
	
	
	int len = m_Ports.GetLength();
	if(len==0)
	{
		MessageBox("请输入端口号");
		return;
	}
	int count,spacenum=0;
	for(count=0;count<len;count++)
	{
		if(m_Ports[count]==' ')
			spacenum++;
	}
	int portnum=spacenum+1;
	
	u_short *ports = (u_short *)malloc(sizeof(u_short)*portnum);	
	count=0;
	int start,end;
	if(portnum==1)
		ports[0]=atoi(m_Ports);
	else
	{
		for(start=0;start<len;start=end+1)
		{
			for(end=start;end<len;end++)
			{
				if(m_Ports[end]==' '||end==len-1)
				{
					if(count==0)
					{
						ports[count++]=atoi(m_Ports.Left(end-start));
						break;
					}
					else if(count==portnum-1)
					{
						ports[count]=atoi(m_Ports.Right(end-start+1));
						break;
					}
					else
					{
						
						ports[count++]=atoi(m_Ports.Mid(start,end-start));
						break;
					}
					
				}
			}
		}
	}
	if(ulIPStart>ulIPEnd)
	{
		MessageBox("开始IP不能大于结束IP");
		return;
	}

	
	for(u_long ulIPNow = ulIPStart;ulIPNow<=ulIPEnd;ulIPNow++)
	{
		if("cmd /c ping %s -n 1",ulIPNow)
		{
			for(count = 0;count < portnum; count++)
			{
				stru_scan_param *m_param = new stru_scan_param;
				m_param->dest_ip = ulIPNow;
				m_param->dest_port = ports[count];
				_beginthreadex(NULL,NULL,ScanThread,(LPVOID)m_param,NULL,NULL);
			}
		}
	}
	MessageBox("扫描完成");
}


UINT __stdcall ScanThread(LPVOID lParam){
	char* service[65535]={"unknown service"};
	service[21]="FTP服务";
	service[22]="SSH服务";
	service[23]="Telnet服务";
	service[25]="SMTP服务";
	service[80]="HTTP服务";
	service[110]="POP2服务";
	service[135]="RPC服务";
	service[139]="文件和打印机共享服务";
	service[443]="HTTPS服务";
	service[445]="CIFS服务";
	service[1433]="SQL Server默认端口";
	service[3389]="远程桌面服务";
	service[3306]="MySQL的默认端口";
	service[8080]="WWW代理服务";
	stru_scan_param *scan_param = (stru_scan_param *) lParam;
	u_long   ulDestIP = scan_param->dest_ip;
	u_short  usDestPort = scan_param->dest_port;
	WSADATA wsaData;
    int err;
    err = WSAStartup(MAKEWORD(2,2),&wsaData);
    if (err != 0)
    {
        AfxMessageBox("加载套接字库失败");
        return 0;
    }
	
	SOCKET clientSocket;
    clientSocket = socket(AF_INET,SOCK_STREAM,0);
    if (clientSocket == INVALID_SOCKET)
    {
        AfxMessageBox("创建套接字失败！");
		WSACleanup();
        return 0;
    }
	
	sockaddr_in addrClient;
    addrClient.sin_addr.s_addr = htonl(ulDestIP);
    addrClient.sin_family=AF_INET;
    addrClient.sin_port=htons(usDestPort);
    if(connect(clientSocket,(sockaddr*)&addrClient,sizeof(addrClient)) != SOCKET_ERROR)
    {
		in_addr addr; 
		addr.s_addr = htonl(ulDestIP);
		
		stru_message_param *param = new stru_message_param;
		param->cli_ip = inet_ntoa(addr);
		param->cli_port = usDestPort;
	//	param->cli_status = "open!";
		if((usDestPort==135||usDestPort==21||usDestPort==22||usDestPort==23||usDestPort==25||usDestPort==139||usDestPort==110||usDestPort==8080||usDestPort==443||usDestPort==445||usDestPort==3389||usDestPort==1433||usDestPort==3306))
			param->cli_service = service[usDestPort];
		else
			param->cli_service = "Unknown service!!!";
		PostMessage(AfxGetMainWnd()->GetSafeHwnd(),
			WM_MY_MESSAGE,0,(LPARAM)param);
		delete scan_param;
    }
/*	else{
		in_addr addr; 
		addr.s_addr = htonl(ulDestIP);
		
		stru_message_param *param = new stru_message_param;
		param->cli_ip = inet_ntoa(addr);
		param->cli_port = usDestPort;
		param->cli_status = "close!";
		if(usDestPort>8080)
			param->cli_service = "unknown service";
		else
			param->cli_service = service[usDestPort];
		
		PostMessage(AfxGetMainWnd()->GetSafeHwnd(),
			WM_MY_MESSAGE,0,(LPARAM)param);
		delete scan_param;
	}*/
	closesocket(clientSocket);
	WSACleanup();
	return 0;
}

LRESULT CWatermelonPortScanDlg::MyMessage(WPARAM wParam, LPARAM lParam)
{
	stru_message_param *param = (stru_message_param *)lParam;
	
	char *cli_ip = param->cli_ip;	
	u_short cli_port = param->cli_port;
	//char *cli_status = param->cli_status;
	char *cli_service = param->cli_service;
	
	char port[10];
	itoa(cli_port,port,sizeof(port));
	
	//往listctrol插入数据，新插入的在上面
    int nRow = m_ListCtrol.InsertItem(0, cli_ip);// 插入行
    m_ListCtrol.SetItemText(nRow, 1, port);//设置其它列数据
//	m_ListCtrol.SetItemText(nRow,2,cli_status);
	m_ListCtrol.SetItemText(nRow,2,cli_service);
	
	delete param;
	
	return 0;
	
}
