// Interface for the CLpApp class.
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef _LpApp_H_
#define _LpApp_H_

#pragma warning(disable : 4786)
#include <vector>
using namespace std;


class CLpApp : public ILpDev
{
protected:
	DWORD		m_dIcon;
	DWORD		m_dStyle;
protected:
	HINSTANCE	m_hInst;
	HWND		m_hWnd;
	TCHAR		m_sCls[160];
	TCHAR		m_sWin[160];
	RECT		m_rcWin;

	INT			m_nScnW;
	INT			m_nScnH;
	INT			m_nScnX;
	INT			m_nScnY;
	ILpDevGL*	m_pDevGL;				// OpenGL Device

	vector<char*> m_vScFile	;			// Lua Script Files.

	DOUBLE		m_TimeDelta	;			// Elapsed Time
	DOUBLE		m_TimeFPS	;
	DOUBLE		m_TimeStart	;			// Start Time

	DWORD		m_dClrCol	;
	DWORD		m_dClrMod	;
	BOOL		m_bShowStats;

	DWORD		m_CloseTime	;

public:
	CLpApp();
	virtual ~CLpApp();

	virtual INT		Create(void* p1=0, void* p2=0, void* p3=0, void* p4=0);
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

