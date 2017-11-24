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

	ILpFont*	m_pFont		;

	ILpTbl*		m_pTbMdl	;

	ILpCamM*	m_pCamM		;					// Multi Camera
	ILpCam*		m_pCam		;					// Camera
	ILpTex*		m_pTxArr	;

	ILpEnt*		m_pGeoAxis	;
	ILpEnt*		m_pGeoGrid	;

	ILpMdl*		m_pMdAsOrg	;		// Original
	ILpMdl*		m_pMdAsIn1	;		// Instance
	ILpMdl*		m_pMdAsIn2	;		// Instance

	ILpMdl*		m_pMdXorg	;		// X-File
	ILpMdl*		m_pMdXins	;		// X-File Instance

	ILpEffect*	m_pEft		;
	ILpmFld*	m_pFld		;

public:
	CMain();
	virtual ~CMain();

	virtual INT		Init();
	virtual INT		Destroy();
	virtual INT		FrameMove();
	virtual INT		Render();
	virtual LRESULT MsgProc(HWND,UINT,WPARAM, LPARAM);

public:
	virtual	INT		SetPhase(INT);
};


extern	CMain*	g_pApp;

#endif