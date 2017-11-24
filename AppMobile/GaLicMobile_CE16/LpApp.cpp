// Implementation of the CLpApp class.
//
////////////////////////////////////////////////////////////////////////////////


#include <Windows.h>
#include <tchar.h>
#include <stdio.h>

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <EGL/egl.h>

#include <Lp/LpEuclid.h>
#include <Lp/LpString.h>
#include <Lp/LpUtil.h>
#include <Lp/ILpDev.h>
#include <Lp/ILpDevGL.h>


#include "LpApp.h"



#define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }


CLpApp*	CLpApp::g_pD3DMApp = NULL;


CLpApp::CLpApp()
{
	g_pD3DMApp	= this;

	m_dIcon		= 32512;
	m_dStyle	= WS_VISIBLE | WS_CAPTION | WS_SYSMENU;

	_tcscpy(m_sCls, _T("Galic Mobile2D Example") );
	_tcscpy(m_sWin, _T("Galic Mobile2D Example") );

	m_hInst		= NULL;
	m_hWnd		= NULL;

	m_nScnW		= 600;
	m_nScnH		= 400;
	m_nScnX		= 0;
	m_nScnY		= 0;

	m_pDevGL	= NULL;

	m_TimeDelta		= LpUtil_TimeGetTime();
	m_TimeFPS		= 60;
	m_bShowStats	= TRUE;

	m_dClrCol		= 0xFF006699;
	m_dClrMod		= GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT;
}


CLpApp::~CLpApp()
{
}



INT CLpApp::Init()		{	return 0;	}
INT CLpApp::Destroy()	{	return 0;	}
INT CLpApp::FrameMove()	{	return 0;	}
INT CLpApp::Render()	{	return 0;	}



INT CLpApp::Create(void* p1, void* p2, void* p3, void* p4)
{
	HINSTANCE	hInst = (HINSTANCE)p1;
	char		sLa[160]={0};
	WNDCLASS	wc={0};


	m_hInst = hInst;

	wc.style			= CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc		= (WNDPROC) WndProc;
	wc.cbClsExtra		= 0;
	wc.cbWndExtra		= 0;
	wc.hInstance		= hInst;
	wc.hIcon			= LoadIcon(NULL, MAKEINTRESOURCE(m_dIcon));
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground	= (HBRUSH)GetStockObject(GRAY_BRUSH);
	wc.lpszMenuName		= 0;
	wc.lpszClassName	= m_sCls;

	if( 0==	RegisterClass(&wc))
		return -1;

	RECT rc = {0,0,m_nScnW, m_nScnH};
	AdjustWindowRectEx(&rc, m_dStyle, FALSE, WS_EX_TOPMOST);

	m_hWnd = CreateWindow(m_sCls
		, m_sWin
		, m_dStyle
		, m_nScnX
		, m_nScnY
		, rc.right  - rc.left
		, rc.bottom - rc.top
		, NULL
		, NULL
		, hInst
		, NULL);

	if (NULL == m_hWnd)
		return -1;

	EnableWindow(m_hWnd, TRUE);
	SetForegroundWindow(m_hWnd);
	ShowWindow(m_hWnd, SW_SHOWNORMAL);

	GetWindowRect(m_hWnd, &m_rcWin);

	InvalidateRect(m_hWnd, 0, 1);


	if(FAILED(LpDev_CreateGL(NULL, &m_pDevGL, m_hWnd, this)))
		return -1;

	glClearColor (0.0,0.4f,0.6f,1.f);


	if(FAILED(Init()))
	{
		MessageBox(m_hWnd, _T("Main Init Failed"), _T("Err"), MB_ICONWARNING);

		delete m_pDevGL;
		DestroyWindow(m_hWnd);
		return -1;
	}


	return 0;
}

INT CLpApp::Run()
{
	BOOL bQuit = FALSE;

	MSG Msg ={0};

	while (Msg.message != WM_QUIT)
	{
		if(PeekMessage(&Msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}

		else
		{
			if(FALSE == bQuit)
			{
				if(FAILED(CloseTimer()))
				{
					SendMessage(m_hWnd, WM_CLOSE, 0, 0);
					bQuit = TRUE;
					Sleep(150);
					continue;
				}

				if(FAILED(FrameMove()))
				{
					SendMessage(m_hWnd, WM_CLOSE, 0, 0);
					bQuit = TRUE;
					Sleep(150);
					continue;
				}

				if(m_pDevGL)
				{
					if(FAILED(Render()))
					{
						SendMessage(m_hWnd, WM_CLOSE, 0, 0);
						bQuit = TRUE;
						Sleep(150);
						continue;
					}

					INT hr = m_pDevGL->Present();

					if(FAILED(hr))
					{
						SendMessage(m_hWnd, WM_CLOSE, 0, 0);
						bQuit = TRUE;
						Sleep(150);
						continue;
					}

					UpdateStatus();
				}
			}
		}    
	}

	return Msg.wParam;
}



INT CLpApp::Query(char* sCmd, void* pData)
{
	if(0==_stricmp("TimeGetTime", sCmd))
	{
		*((DOUBLE*)pData) = LpUtil_TimeGetTime();
		return 0;
	}

	else if(0==_stricmp("Get FPS", sCmd))
	{
		*((DOUBLE*)pData) = m_TimeFPS;
		return 0;
	}

	else if(0==_stricmp("Get Elapsed Average Time", sCmd))
	{
		*((DOUBLE*)pData) = m_TimeDelta;
		return 0;
	}


	else if(0==_stricmp("Set Screen Pos X"	, sCmd))	{	INT	dVal = *((INT*)pData);	m_nScnX = dVal;		return 0;	}
	else if(0==_stricmp("Set Screen Pos Y"	, sCmd))	{	INT	dVal = *((INT*)pData);	m_nScnY = dVal;		return 0;	}
	else if(0==_stricmp("Set Screen Width"	, sCmd))	{	INT	dVal = *((INT*)pData);	m_nScnW = dVal;		return 0;	}
	else if(0==_stricmp("Set Screen Height"	, sCmd))	{	INT	dVal = *((INT*)pData);	m_nScnH = dVal;		return 0;	}

	else if(0==_stricmp("Get Screen Width"	, sCmd))	{	*((INT*)pData) = m_nScnW;	return 0;	}
	else if(0==_stricmp("Get Screen Height"	, sCmd))	{	*((INT*)pData) = m_nScnH;	return 0;	}

	else if(0==_stricmp("Set Class Name"	, sCmd))
	{
		char*	sVal = (char*)pData;
		LpStr_AnsiToUnicode(m_sCls, sVal, strlen(sVal));

		return 0;
	}

	else if(0==_stricmp("Set Window Title"	, sCmd))
	{
		char*	sVal = (char*)pData;
		LpStr_AnsiToUnicode(m_sWin, sVal, strlen(sVal));

		return 0;
	}

	else if(0==_stricmp("Set FullMode Start", sCmd))
	{
		return 0;
	}

	else if(0==_stricmp("Set Script File"	, sCmd))
	{
		return -1;
	}

	else if(0==_stricmp("Get Script File"	, sCmd))
	{
		return -1;
	}

	else if(0==_stricmp("Get Script File Number", sCmd))
	{
		return -1;
	}

	else if(0==_stricmp("Console Alloc", sCmd))
	{
		return -1;
	}

	else if(0==_stricmp("Set Console"		, sCmd))
	{
		return -1;
	}

	else if(0==_stricmp("Send Console", sCmd))
	{
		return -1;
	}

	else if(0==_stricmp("Set Show State", sCmd))
	{
		BOOL	dVal = *((BOOL*)pData);
		m_bShowStats = dVal;
		return 0;
	}

	else if(0==_stricmp("Set Toggle Full", sCmd))
	{
		return -1;
	}

	else if(0==_stricmp("Set Clear Color", sCmd))
	{
		DWORD	dVal = *((DWORD*)pData);
		m_dClrCol = dVal;
		return 0;
	}


	else if(0==_stricmp("Get Time Stored", sCmd))
	{
		DOUBLE fElipse = LpUtil_TimeGetTime();

		fElipse -=m_TimeDelta;

		*((DOUBLE*)pData) = fElipse;

		return 0;
	}

	else if(0==_stricmp("Get Show State", sCmd))	{	*((BOOL*)pData) = m_bShowStats;		return 0;	}
	else if(0==_stricmp("Get Clear Color", sCmd))	{	*((DWORD*)pData) = m_dClrCol;		return 0;	}

	else if(0==_stricmp("Get Clear Mode", sCmd))	{	*((DWORD*)pData) = m_dClrMod;		return 0;	}

	

	return -1;
}








INT CLpApp::Clear(DWORD Flags,DWORD Color)
{
	LCXCOLOR	c(Color);
	glClearColor(c.r, c.g, c.b, c.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	return 0;
}

void* CLpApp::GetHinst()	{	return m_hInst		;	}
void* CLpApp::GetHwnd()		{	return m_hWnd		;	}
void* CLpApp::GetGLDevice()	{	return m_pDevGL		;	}


INT CLpApp::Cleanup()
{
	if(!m_hWnd)
		return 0;

	Destroy();
	Sleep(150);
	m_hWnd = NULL;

	
	if(m_pDevGL)
	{
		delete m_pDevGL;
		m_pDevGL = NULL;
	}


	return 0;
}

INT CLpApp::CloseTimer()
{
	static DWORD	dBgn	= GetTickCount();
	DWORD			dEnd	= GetTickCount();

	if(dEnd - dBgn>m_CloseTime)
		return -1;

	return 0;
}



void CLpApp::UpdateStatus()
{
	static DWORD	dFrames=0;
	static DOUBLE	dB	= LpUtil_TimeGetTime();
	DOUBLE			dE	= LpUtil_TimeGetTime();

	++dFrames;

	if(dFrames>=8)
	{
		m_TimeFPS = dE-dB;

		m_TimeDelta = m_TimeFPS/dFrames;
		m_TimeFPS	= DOUBLE(dFrames)/m_TimeFPS;

		if(m_TimeDelta>5000)
			m_TimeDelta = 5000;

		dFrames = 0;
		dB = dE;
	}
}


LRESULT CALLBACK CLpApp::WndProc(HWND hW, UINT uM, WPARAM wP, LPARAM lP)
{
	return g_pD3DMApp->MsgProc(hW, uM, wP, lP);
}

LRESULT CLpApp::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) 
	{
		//case WM_SIZE:
		//case WM_MOVE:
		//{
		//	RECT rc;
		//	GetWindowRect(hWnd, &rc);

		//	INT ScnX = m_rcWin.left;
		//	INT ScnY = m_rcWin.top;

		//	if( !(ScnX == rc.left && ScnY == rc.right))
		//	{
		//		INT ScnW = m_rcWin.right - m_rcWin.left;
		//		INT ScnH = m_rcWin.bottom - m_rcWin.top;

		//		SetWindowPos(hWnd, HWND_TOPMOST, ScnX, ScnY, ScnW, ScnH, SWP_NOSIZE);
		//	}

		//	return 0;
		//}

		case WM_CLOSE:
		case WM_DESTROY:
		{
			Cleanup();
			PostQuitMessage(0);
			return 0;
		}
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}



