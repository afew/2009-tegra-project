// Interface for the LscSys class.
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _LscSys_H_
#define _LscSys_H_


namespace	LpLua
{
	
struct LscSys
{
	static ILpDev*	m_pDevSys;								// System
	static INT		Create(ILpDevGL* pDevGL);
	static INT		Destroy();


	static INT	Lsc_CreateWindow(lua_State *pL);			// Window Create
	static INT	Lsc_ScriptFile(lua_State *pL);				// Script File Load
	static INT	Lsc_Release(lua_State *pL);					// Window Release

	static INT	Lsc_ConsoleAlloc(lua_State *pL);
	static INT	Lsc_ConsoleSet(lua_State *pL);				// Use console
	static INT	Lsc_ConsoleSend(lua_State *pL);				// Send String to colsole

	static INT	Lsc_Sleep(lua_State *pL);					// Sleep
	static INT	Lsc_ShowCursor(lua_State *pL);				// Show Cursor

	static INT	Lsc_GetScnSize(lua_State *pL);				// ȭ���� ũ�⸦ ��������
	static INT	Lsc_GetWindowStyle(lua_State *pL);
	static INT	Lsc_SetWindowStyle(lua_State *pL);			// window Style
	static INT	Lsc_ShowState(lua_State *pL);				// State ���̱�
	static INT	Lsc_ChangeMode(lua_State *pL);				// Full <--> Window
	static INT	Lsc_SetClearColor(lua_State *pL);			// ���ȭ�� Ŭ���� ������
	static INT	Lsc_GetClearColor(lua_State *pL);			// ���ȭ�� Ŭ���� ���� ��������

	static INT	Lsc_GetTime(lua_State *pL);					// ���α׷��� ������ �ĺ���...

	static INT	Lsc_WindowTitle(lua_State *pL);				// Set Window Title
	static INT	Lsc_ModulePath(lua_State *pL);				// Get Module Path
	static INT	Lsc_DoFile(lua_State *pL);					// Do File
	static INT	Lsc_OpenFile(lua_State *pL);				// Open File

	static INT	Lsc_MessageBox(lua_State *pL);				// Window Box

	static INT	OpenLib(lua_State *pL);
};

}// namespace Lua

#endif

