// Interface for the LspMdl class.
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _LspMdl_H_
#define _LspMdl_H_


#pragma warning(disable : 4786)
#include <vector>


namespace	LpLua
{
	
struct LspMdl
{
	struct ILcCont
	{
		virtual ~ILcCont();
		
		std::vector<LscH* >	vLscHorg;
		std::vector<LscH* >	vLscH;

		INT				Alloc(void** pMdl,char* sName,void* pLscHorg);
		INT				Release(INT nKey);
		LscH*	Find(INT nKey);

		INT				AllocOrg(char* sName, char* sTxFolder, char* sEffect);
		LscH*	FindOrg(char* sName);
		void			SetOrgElapseTime(FLOAT fTime);
	};

	static ILpDevGL*	m_pDevGL;							// OpenGL Device
	static INT			Create(ILpDevGL* pDevGL);
	
	static ILcCont*	m_pContAuto	;							// 지역 변수
	static ILcCont*	m_pContStat	;							// 정적 변수

	static INT	Lsc_Alloc(lua_State *pL);					// Lcm 로딩
	static INT	Lsc_Release(lua_State *pL);					// Lcm 해제
	static INT	Lsc_FrameMove(lua_State *pL);				// Lcm FrameMode
	static INT	Lsc_Render(lua_State *pL);					// Lcm 그리기
	
	static INT	Lsc_LcmRotation(lua_State *pL);				// Lcm Rotation
	static INT	Lsc_LcmScaling(lua_State *pL);				// Lcm Scaling
	static INT	Lsc_LcmPosition(lua_State *pL);				// Lcm Position
	static INT	Lsc_LcmStartFrame(lua_State *pL);			// Lcm Set Start Frame
	static INT	Lsc_LcmCamera(lua_State *pL);				// Lcm Set Camera
	
	static INT	OpenLib(lua_State *pL);

	static INT	ContCreate();
	static INT	ContDestroy();
	static INT	StaticCreate();
	static INT	StaticDestroy();

	static void* FindAlloc(char* sMdl, char* sTex, char* sEft);
};

}// namespace Lua


#endif

