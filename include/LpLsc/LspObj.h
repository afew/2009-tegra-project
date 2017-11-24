// Interface for the LspObj class.
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _LspObj_H_
#define _LspObj_H_


#pragma warning(disable : 4786)
#include <vector>


namespace	LpLua
{
	
struct LspObj
{
	struct ILcCont
	{
		virtual ~ILcCont();
		
		std::vector<LscH* >	vLscHorg;
		std::vector<LscH* >	vLscH;

		INT			Alloc(char* sName, INT nID);
		INT			Release(INT nKey);
		LscH*		Find(INT nKey);
	};

	static ILpDevGL*	m_pDevGL;						// OpenGL Device
	static INT			Create(ILpDevGL* pDevGL);
	
	static ILcCont*	m_pContAuto	;						// 지역 변수
	static ILcCont*	m_pContStat	;						// 정적 변수

	static INT	Lsc_Alloc(lua_State *pL);				// Lcm 로딩
	static INT	Lsc_Release(lua_State *pL);				// Lcm 해제
	static INT	Lsc_FrameMove(lua_State *pL);			// Lcm FrameMode
	static INT	Lsc_Render(lua_State *pL);				// Lcm 그리기
	static INT	Lsc_Query(lua_State *pL);				// Query: 질의 명령문
	static INT	Lsc_SetAttrib(lua_State *pL);			// Setup Attribute
	static INT	Lsc_SetAnimation(lua_State *pL);		// Setup Animation

	static INT	OpenLib(lua_State *pL);

	static INT	ContCreate();
	static INT	ContDestroy();
	static INT	StaticCreate();
	static INT	StaticDestroy();
};

}// namespace Lua


#endif

