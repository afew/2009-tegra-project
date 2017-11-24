// Interface for the LscEnt class.
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _LscEnt_H_
#define _LscEnt_H_


namespace	LpLua
{

struct LscEnt
{
	static ILpDevGL*	m_pDevGL;							// OpenGL Device
	static INT			Create(ILpDevGL* pDevGL);

	static void*	m_pGrid		;							// Grid
	static void*	m_pAxis		;							// Axis

	static INT	Lsc_CamSetType(lua_State*);
	static INT	Lsc_CamFrameMove(lua_State*);
	static INT	Lsc_CamViewParam(lua_State*);
	static INT	Lsc_CamSetEye(lua_State*);
	static INT	Lsc_CamGetEye(lua_State*);
	static INT	Lsc_CamSetLook(lua_State*);
	static INT	Lsc_CamGetLook(lua_State*);
	static INT	Lsc_CamSetUp(lua_State*);

	static INT	Lsc_CamSetBasis(lua_State*);
	static INT	Lsc_CamSetEpsilonY(lua_State*);
	static INT	Lsc_CamSetGap(lua_State*);
	static INT	Lsc_CamGetGap(lua_State*);

	static INT	Lsc_CamProjParam(lua_State*);
	static INT	Lsc_CamSetFov(lua_State*);
	static INT	Lsc_CamSetScreen(lua_State*);
	static INT	Lsc_CamSetNear(lua_State*);
	static INT	Lsc_CamSetFar(lua_State*);

	static INT	Lsc_CamSetSpeed(lua_State*);
	static INT	Lsc_CamSetControl(lua_State*);

	static INT	Lsc_CamMoveForward(lua_State*);
	static INT	Lsc_CamMoveSideward(lua_State*);
	static INT	Lsc_CamRotateYaw(lua_State*);
	static INT	Lsc_CamRotatePitch(lua_State*);
	static INT	Lsc_CamZoom(lua_State*);

	static INT	Lsc_CamTransformView(lua_State*);
	static INT	Lsc_CamTransformProj(lua_State*);
	static INT	Lsc_CamTransformVP(lua_State*);

	static INT	Lsc_Command(lua_State*);

	static INT	OpenLib(lua_State*);

	static INT	ContCreate();
	static INT	ContDestroy();
	static INT	StaticCreate();
	static INT	StaticDestroy();
};

}// namespace Lua

#endif

