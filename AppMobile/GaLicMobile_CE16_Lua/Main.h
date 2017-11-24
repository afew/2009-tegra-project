// Interface for the CMain class.
//
////////////////////////////////////////////////////////////////////////////////

#pragma once


#ifndef _Main_H_
#define _Main_H_


class CMain : public CLpApp
{
protected:
	ILpSprite*	m_pSprite	;
	ILpInput*	m_pInput	;
	ILpLsc*		m_pLsc		;
	ILpFont*	m_pFont		;

	ILpTbl*		m_pTbMdl	;

	ILpTex*		m_pTxArr	;

	ILpEffect*	m_pEft		;

	ILpCamM*	m_pCamM		;					// Multi Camera
	ILpCam*		m_pCam		;					// Camera

public:
	CMain();
	virtual ~CMain();

	virtual INT		Init();
	virtual INT		Destroy();
	virtual INT		FrameMove();
	virtual INT		Render();
	virtual LRESULT MsgProc(HWND,UINT,WPARAM, LPARAM);

protected:
	INT				m_ePhCur	;					// Current Phase
	INT				m_ePhOld	;					// Old Phase
	INT				m_nGmPhs	;					// Total Game Phase
	ILpApp**		m_pGmPhs	;					// Game Phase Class
	MEMORYSTATUS	m_mmSt		;

public:
	virtual	INT		SetPhase(INT);
};


extern	CMain*	g_pApp;

#endif