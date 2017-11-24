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
		INT		Alloc(void* pInf);							// ���� ����
		INT		Release(INT nKey);							// ���� ����
		LscH*	Find(INT nKey);						// ã��
	};

	static ILpDevGL*	m_pDevGL;							// OpenGL Device
	static	INT			Create(ILpDevGL* pDevGL);
	
	static	ILpCont*	m_pContAuto	;						// ���� ����
	static	ILpCont*	m_pContStat	;						// ���� ����

	
	static INT	Lsc_Alloc(lua_State *pL);					// ���� ���� �ε�
	static INT	Lsc_Release(lua_State *pL);					// ���� ���� ����
	
	static INT	Lsc_SoundPlay(lua_State *pL);				// ���� �÷���
	static INT	Lsc_SoundStop(lua_State *pL);				// ���� Stop
	static INT	Lsc_SoundReset(lua_State *pL);				// ���� Reset
	static INT	Lsc_SoundVolume(lua_State *pL);				// ���� Volume

	static INT	Lsc_SetRepeat(lua_State *pL);				// ���� Repeat
	static INT	Lsc_GetState(lua_State *pL);				// ���� State

	static INT	Lsc_FrameMove(lua_State *pL);				// ���� Play �˻�

	static INT	Lsc_Draw(lua_State *pL);					// DShow Draw

	static INT	OpenLib(lua_State *pL);

	
	static INT	ContCreate();
	static INT	ContDestroy();
	static INT	StaticCreate();
	static INT	StaticDestroy();
};

}// namespace Lua

#endif
