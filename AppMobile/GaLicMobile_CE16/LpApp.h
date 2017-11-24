// Interface for the CLpApp class.
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _LpApp_H_
#define _LpApp_H_


class CLpApp : public ILpDev
{
protected:
	DWORD		m_dIcon		;
	DWORD		m_dStyle	;

protected:
	HINSTANCE	m_hInst		;
	HWND		m_hWnd		;
	TCHAR		m_sCls[128]	;
	TCHAR		m_sWin[128]	;
	RECT		m_rcWin		;

	INT			m_nScnW		;
	INT			m_nScnH		;
	INT			m_nScnX		;
	INT			m_nScnY		;
	ILpDevGL*	m_pDevGL	;		// OpenGL Device

	DOUBLE		m_TimeDelta		;			// Elapsed Time
	DOUBLE		m_TimeFPS		;
	DOUBLE		m_TimeStart		;			// Start Time

	DWORD		m_dClrCol		;
	DWORD		m_dClrMod		;
	BOOL		m_bShowStats	;

	DWORD		m_CloseTime		;

public:
	CLpApp();
	virtual ~CLpApp();

	virtual INT		Create(void* =0, void* =0, void* =0, void* =0);
	virtual INT		Init();
	virtual INT		Destroy();

	virtual INT		FrameMove();
	virtual INT		Render();
	virtual	INT		Run();

	virtual INT		Query(char* sCmd, void* pData);
	virtual INT		Clear(DWORD Flags,DWORD Color);

	virtual void*	GetHinst();
	virtual void*	GetHwnd();
	virtual void*	GetGLDevice();

	virtual LRESULT MsgProc(HWND,UINT,WPARAM, LPARAM);

public:
	INT		Cleanup();
	INT		CloseTimer();

	static	CLpApp*	g_pD3DMApp;
	static	LRESULT CALLBACK WndProc(HWND,UINT,WPARAM, LPARAM);

protected:
	void	UpdateStatus();
};


#endif

