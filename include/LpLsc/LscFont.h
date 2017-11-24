// Interface for the LscFont cLscss.
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _LscFont_H_
#define _LscFont_H_


#pragma warning(disable : 4786)
#include <vector>


namespace	LpLua
{

struct LscFont
{
	struct ILpCont											// ContainerFont
	{
		std::vector<LscH* >	vLscH;

		virtual ~ILpCont();
		INT		Alloc(void* pInf);
		INT		Release(INT nKey);
		LscH* Find(INT nKey);
	};


	static ILpDevGL*	m_pDevGL;							// OpenGL Device
	static INT			Create(ILpDevGL* pDevGL);

	static ILpCont*	m_pContAuto	;							// 지역 변수
	static ILpCont*	m_pContStat	;							// 정적 변수
	

	static INT	Lsc_Alloc(lua_State *pL);					// 폰트 로딩
	static INT	Lsc_Release(lua_State *pL);					// 폰트 해제

	static INT	Lsc_FontDraw(lua_State *pL);				// 폰트 Draw
	static INT	Lsc_FontColorFore(lua_State *pL);			// 폰트 Foreground Color
	static INT	Lsc_FontColorBack(lua_State *pL);			// 폰트 Background Color

	static INT	OpenLib(lua_State *pL);


	static INT	ContCreate();
	static INT	ContDestroy();
	static INT	StaticCreate();
	static INT	StaticDestroy();
};

}// namespace Lua

#endif