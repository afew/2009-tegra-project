// Interface for the LscFldS class.
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _LspMap_H_
#define _LspMap_H_


namespace	LpLua
{

struct LspMap
{
	static ILpDevGL*	m_pDevGL;						// OpenGL Device
	static INT			Create(ILpDevGL* pDevGL);

	static void*	m_pCam		;
	static void*	m_pEft		;
	static void*	m_pTbMdl	;
	static void*	m_pFld		;

	static INT	Lsc_Alloc(lua_State*)	;				// Map 로딩
	static INT	Lsc_ReAlloc(lua_State*)	;				// Map 다시 로딩
	static INT	Lsc_Release(lua_State*)	;				// Map 해제
	static INT	Lsc_FrameMove(lua_State*);				// Map 갱신
	static INT	Lsc_Render(lua_State*)	;				// Map 그리기

	static INT	OpenLib(lua_State*);

	static INT	ContCreate();
	static INT	ContDestroy();
	static INT	StaticCreate();
	static INT	StaticDestroy();
};

}// namespace Lua

#endif


