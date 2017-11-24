// Interface for the LscTex class.
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _LscTex_H_
#define _LscTex_H_


#pragma warning(disable : 4786)
#include <vector>


namespace	LpLua
{
	
struct LscTex
{
	struct ILpCont
	{
		std::vector<LscH* >	vLscH;
		
		virtual ~ILpCont();
		INT		Alloc(void* pInf);
		INT		ReAlloc(INT nKey, void* pInf);
		INT		Release(INT nKey);
		LscH* Find(INT nKey);
		LscH* Find(INT* nKey, char* sFile);		
	};

	static ILpDevGL*	m_pDevGL;							// OpenGL Device
	static ILpSprite*	m_pSprite;							// 2D Sprite
	static INT			Create(ILpDevGL* pDevGL);

	static ILpCont*		m_pContAuto	;						// 지역 변수
	static ILpCont*		m_pContStat	;						// 정적 변수
	

	static INT	Lsc_Alloc(lua_State *pL);					// 이미지 파일 로딩
	static INT	Lsc_ReAlloc(lua_State *pL);					// 이미지 파일 다시 로딩
	static INT	Lsc_Release(lua_State *pL);					// 이미지 파일 해제

	static INT	Lsc_TextureWidth(lua_State *pL);			// 이미지 파일 너비
	static INT	Lsc_TextureHeight(lua_State *pL);			// 이미지 파일 높이
	static INT	Lsc_TexturePointer(lua_State *pL);			// Get texture Point
	static INT	Lsc_TextureDraw(lua_State *pL);				// 이미지 그리기
	static INT	Lsc_TextureDrawMask(lua_State *pL);			// 배경 레이어와 같이 이미지 그리기

	static INT	Lsc_SetTexture(lua_State *pL);				// Device->SetTexture
	static INT	Lsc_SetTextureNull(lua_State *pL);

	static INT	OpenLib(lua_State *pL);

	
	static INT	ContCreate();
	static INT	ContDestroy();
	static INT	StaticCreate();
	static INT	StaticDestroy();
};

}// namespace Lua

#endif
