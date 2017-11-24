// Interface for the LscInput class.
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _LscInput_H_
#define _LscInput_H_


namespace	LpLua
{

struct LscInput
{
	static ILpDevGL*	m_pDevGL;							// OpenGL Device
	static	ILpInput*	m_pInput;
	static	INT			Create(ILpDevGL* pDevGL);

	//Lsc API.
	static INT	Lsc_KeyboardAll(lua_State *pL);				// keyboard All Key
	static INT	Lsc_KeyboardOne(lua_State *pL);				// keyboard One Key
	static INT	Lsc_MousePos(lua_State *pL);				// Mouse Pos
	static INT	Lsc_MouseDelta(lua_State *pL);
	static INT	Lsc_MouseEvnt(lua_State *pL);				// Mouse Event

	static INT	OpenLib(lua_State *pL);
};

}// namespace Lua

#endif

