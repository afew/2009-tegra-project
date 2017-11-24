// Interface for the LscSnd class.
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _LsSmd_H_
#define _LsSmd_H_


#pragma warning(disable : 4786)
#include <vector>


namespace	LpLua
{

struct LscSmd
{
	struct ILpCont											// Container
	{
		std::vector<LscH* >	vLscH;

		virtual ~ILpCont();
		INT		Alloc(void* pInf);							// 사운드 생성
		INT		Release(INT nKey);							// 사운드 해제
		LscH*	Find(INT nKey);						// 찾기
	};

	static ILpDevGL*	m_pDevGL;							// OpenGL Device
	static	INT			Create(ILpDevGL* pDevGL);
	
	static	ILpCont*	m_pContAuto	;						// 지역 변수
	static	ILpCont*	m_pContStat	;						// 정적 변수

	
	static INT	Lsc_Alloc(lua_State *pL);					// 사운드 파일 로딩
	static INT	Lsc_Release(lua_State *pL);					// 사운드 파일 해제
	
	static INT	Lsc_SoundPlay(lua_State *pL);				// 사운드 플레이
	static INT	Lsc_SoundStop(lua_State *pL);				// 사운드 Stop
	static INT	Lsc_SoundReset(lua_State *pL);				// 사운드 Reset
	static INT	Lsc_SoundVolume(lua_State *pL);				// 사운드 Volume

	static INT	Lsc_SetRepeat(lua_State *pL);				// 사운드 Repeat
	static INT	Lsc_GetState(lua_State *pL);				// 사운드 State

	static INT	Lsc_FrameMove(lua_State *pL);				// 사운드 Play 검사

	static INT	Lsc_Draw(lua_State *pL);					// DShow Draw

	static INT	OpenLib(lua_State *pL);

	
	static INT	ContCreate();
	static INT	ContDestroy();
	static INT	StaticCreate();
	static INT	StaticDestroy();
};

}// namespace Lua

#endif
