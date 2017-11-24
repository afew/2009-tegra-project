// Implementation of the CMain class.
//
////////////////////////////////////////////////////////////////////////////////


#include "_StdAfx.h"


CMain::CMain()
{
	GlobalMemoryStatus(&m_mmSt);
	
	m_dIcon		= IDI_ICON1;	//IDC_ICON = MAKEINTRESOURCE(32512)
	m_dStyle	= WS_VISIBLE| WS_BORDER | WS_CAPTION|WS_SYSMENU|WS_THICKFRAME;
	m_dStyle	= WS_VISIBLE;
	_tcscpy(m_sCls, _T("GaLic Mobile3D for Tegra") );

	m_CloseTime = 10*60*1000;

	m_nScnX		= 0;
	m_nScnY		= 0;
	m_nScnW		= 800;
	m_nScnH		= 450;

	m_pSprite	= NULL;
	m_pInput	= NULL;
	m_pLsc		= NULL;
	m_pFont		= NULL;

	m_pTbMdl	= NULL;

	m_ePhCur	= 1;
	m_ePhOld	= 0;
	m_nGmPhs	= 0;
	m_pGmPhs	= NULL;
	
	m_pEft		= NULL;

	m_pTxArr	= NULL;

	m_pCam		= NULL;
	m_pCamM		= NULL;
}



CMain::~CMain()
{
}



INT CMain::Init()
{
	// Initialize Effect
	LpDev_EffectInit();

	// Initialize Sound
//	LpSmd_DeviceInit();

	DWORD	dGsVsDev=0;
	DWORD	dGsFsDev=0;

	DWORD	dGsVsSpt=0;
	DWORD	dGsFsSpt=0;

	DWORD	dGsVsFld=0;
	DWORD	dGsFsFld=0;

#if	_WIN32_WCE
	dGsVsDev = IDR_3D_BIN_VS;
	dGsFsDev = IDR_3D_BIN_FS;
	dGsVsSpt = IDR_2D_BIN_VS;
	dGsFsSpt = IDR_2D_BIN_FS;
	dGsVsFld = IDR_MAP_BIN_VS;
	dGsFsFld = IDR_MAP_BIN_FS;
#else
	dGsVsDev = IDR_3D_TXT_VS;
	dGsFsDev = IDR_3D_TXT_FS;
	dGsVsSpt = IDR_2D_TXT_VS;
	dGsFsSpt = IDR_2D_TXT_FS;
	dGsVsFld = IDR_MAP_TXT_VS;
	dGsFsFld = IDR_MAP_TXT_FS;
#endif

	// Create Effect for Filed
	if(FAILED(LpDev_CreateEffect(NULL, &m_pEft, NULL, NULL, (void*)IDR_MAP_BIN_VS, (void*)IDR_MAP_BIN_FS)))
		return -1;

	// Setup 3D Shader
	if(FAILED(m_pDevGL->Setup3DShader(NULL, NULL, dGsVsDev, dGsFsDev)))
		return -1;


	// Create 2D Sprite
	if(FAILED(LpDev_CreateSprite(NULL, &m_pSprite, m_hWnd, &dGsVsSpt, &dGsFsSpt)))
		return -1;

	m_pDevGL->SetSprite(m_pSprite);


	// Create Input
	if(FAILED(LpInput_Create("CE Input", &m_pInput, m_hWnd)))
		return -1;

	m_pDevGL->SetInput(m_pInput);


	// Create Camera
	if(FAILED(LpEnt_CreateMutiCamera(NULL, &m_pCamM, m_pDevGL)))
		return -1;

	m_pCam	= (ILpCam*)m_pCamM->GetCameraPointer(0);
	m_pCam->SetType(ILpCam::LC_CAM_FIRST);
	m_pCam->SetParamView(&LCXVECTOR3(11, 29, -101), &LCXVECTOR3(17, 19,  23), &LCXVECTOR3(0,1,0) );
	m_pCam->SetParamView(&LCXVECTOR3(500,500,-600), &LCXVECTOR3(500, 100, 0), &LCXVECTOR3(0,1,0) );
	m_pCam->SetParamView(&LCXVECTOR3(0,200,0), &LCXVECTOR3(500, 100, 400), &LCXVECTOR3(0,1,0) );
	m_pCam->SetParamView(&LCXVECTOR3(-200,100,-200), &LCXVECTOR3(500, 50, 400), &LCXVECTOR3(0,1,0) );
	m_pCam->SetParamProj(LCXToRadian(45), FLOAT(m_nScnW), FLOAT(m_nScnH), 1.f, 3000.f);
	m_pCam->FrameMove();

	if(FAILED(LpDev_SetUserCamera(m_pDevGL, m_pCamM)))
		return -1;



	// LuaScript Initialize
	LpLua::LscSys	::Create(m_pDevGL);						// Lua System
	LpLua::LscInput	::Create(m_pDevGL);						// Lua Input Class
	LpLua::LscUtil	::Create(m_pDevGL);						// Lua Utilities

	LpLua::LscFont	::Create(m_pDevGL);						// Lua Font Class
	LpLua::LscTex	::Create(m_pDevGL);						// Lua Texture Class
	LpLua::LscSmd	::Create(m_pDevGL);						// Lua Sound Class

	LpLua::LscSys	::Create(m_pDevGL);						// Lua System
	LpLua::LscInput	::Create(m_pDevGL);						// Lua Input Class
	LpLua::LscUtil	::Create(m_pDevGL);						// Lua Utilities
	LpLua::LscFont	::Create(m_pDevGL);						// Lua Font Class
	LpLua::LscTex	::Create(m_pDevGL);						// Lua Texture Class
	LpLua::LscSmd	::Create(m_pDevGL);						// Lua Sound Class
	LpLua::LscEnt	::Create(m_pDevGL);						// Lua Entity Class

	LpLua::LspMap	::Create(m_pDevGL);						// Lua Map Class
	LpLua::LspMdl	::Create(m_pDevGL);						// Lua Model Class
	LpLua::LspObj	::Create(m_pDevGL);						// Lua Object Class



	// Setup Map data
	LpLua::LspMap::m_pCam = m_pCam;
	LpLua::LspMap::m_pEft = m_pEft;



	// Game Phase Creating
	this->Query("Get Script File Number", &m_nGmPhs);

	m_pGmPhs = (ILpApp**)new CGmPhase*[m_nGmPhs];
	memset(m_pGmPhs, 0, m_nGmPhs * sizeof(CGmPhase*));


	// Set Start Phase..
	CGmPhase* pPhase = new CGmPhase;
	
	if(FAILED(pPhase->Create(&m_ePhCur, this)))
		return -1;

	m_pGmPhs[m_ePhCur] = pPhase;


	// For Debug
	if(FAILED(LpDev_CreateFont(NULL, &m_pFont, m_pSprite, "Arial", 12)))
		return -1;

	if(FAILED(LpDev_CreateTex(NULL, &m_pTxArr, "Texture/arrow.tga", 0x00FFFFFF)))
		return -1;

	return 0;
}

INT CMain::Destroy()
{
	LpLua::LscSys	::Destroy();

	LpLua::LscFont	::StaticDestroy();
	LpLua::LscTex	::StaticDestroy();
	LpLua::LscSmd	::StaticDestroy();
	LpLua::LscEnt	::StaticDestroy();

	LpLua::LspMap	::StaticDestroy();
	LpLua::LspMdl	::StaticDestroy();
	LpLua::LspObj	::StaticDestroy();

	SAFE_DELETE(	m_pLsc		);

	INT i=0;

	if(m_pGmPhs)
	{
		for(i=0; i< m_nGmPhs;++i)
		{
			delete m_pGmPhs[i];
		}

		delete [] m_pGmPhs;

		m_pGmPhs	= NULL;
		m_nGmPhs	= 0;
	}


	SAFE_DELETE(	m_pCamM		);

	SAFE_DELETE(	m_pTxArr	);

	SAFE_DELETE(	m_pTbMdl	);
	SAFE_DELETE(	m_pEft		);

	SAFE_DELETE(	m_pFont		);
	SAFE_DELETE(	m_pInput	);
	SAFE_DELETE(	m_pSprite	);

	LpDev_EffectDestroy();

	return 0;
}


INT CMain::FrameMove()
{
	INT hr=0;
	SAFE_FRMOV(	m_pInput	);

	LCXVECTOR3	vcDelta(m_pInput->GetMouseDelta());
	LCXVECTOR3	vcPos(m_pCam->GetEye());

	float	fSpeed = 10.f;
	FLOAT	fSpeedRot  =  0.1f;


	if(m_pInput->ButtonPress(0))
	{
		LCXVECTOR3	vcDelta(m_pInput->GetMouseDelta());
		RECT	rcW={ 64,   0, 128,  64};	BOOL	bW=FALSE;
		RECT	rcS={ 64, 128, 128, 192};	BOOL	bS=FALSE;
		RECT	rcA={  0,  64,  64, 128};	BOOL	bA=FALSE;
		RECT	rcD={128,  64, 192, 128};	BOOL	bD=FALSE;

		bW = m_pInput->IsInRect(rcW.left, rcW.top, rcW.right, rcW.bottom);
		bS = m_pInput->IsInRect(rcS.left, rcS.top, rcS.right, rcS.bottom);
		bA = m_pInput->IsInRect(rcA.left, rcA.top, rcA.right, rcA.bottom);
		bD = m_pInput->IsInRect(rcD.left, rcD.top, rcD.right, rcD.bottom);

		if(bW)
			m_pCam->MoveForward(-fSpeed);

		if(bS)
			m_pCam->MoveForward(fSpeed);

		if(bA)
			m_pCam->MoveSideward(-fSpeed);

		if(bD)
			m_pCam->MoveSideward(fSpeed);


		if(!bW && !bS && !bA && !bD)
		{
			m_pCam->RotateYaw(vcDelta.x, fSpeedRot);
			m_pCam->RotatePitch(vcDelta.y, fSpeedRot);
		}
	}




	if(m_pGmPhs[m_ePhCur])
	{
		hr = m_pGmPhs[m_ePhCur]->FrameMove();

		if(FAILED(hr))
			return -1;
	}

	// 프로그램 종료
	if( m_pInput->ButtonDown(0) || m_pInput->ButtonPress(0))
	{
		LCXVECTOR3	vcMouse = m_pInput->GetMousePos();

		if(	760 <vcMouse.x && vcMouse.x<800)
			return -1;
	}


	return 0;
}



INT CMain::Render()
{
	HRESULT hr = 0;

	m_pDevGL->Clear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT, m_dClrCol);

	m_pDevGL->SetTransformIdentity(ILpDevGL::LPTS_WORLD);
	m_pDevGL->SetTransformIdentity(ILpDevGL::LPTS_VIEW);
	m_pDevGL->SetTransformIdentity(ILpDevGL::LPTS_PROJ);


	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);



	SAFE_RENDER(	m_pGmPhs[m_ePhCur]	);



	LCXVECTOR2	vcTrn;
	LCXVECTOR2	vcScl = LCXVECTOR2(1.f, 1.f);
	RECT rcW = {0, 0, 64, 64};
	RECT rcS = {64, 0, 128, 64};
	RECT rcA = {0, 64, 64, 128};
	RECT rcD = {64, 64, 128, 128};

	vcTrn = LCXVECTOR2( 64,   0);	m_pSprite->Draw(m_pTxArr, &rcW, NULL, NULL, 0, &vcTrn, 0xFFFF0000);
	vcTrn = LCXVECTOR2( 64, 128);	m_pSprite->Draw(m_pTxArr, &rcS, NULL, NULL, 0, &vcTrn, 0xFF00FF00);
	vcTrn = LCXVECTOR2(  0,  64);	m_pSprite->Draw(m_pTxArr, &rcA, NULL, NULL, 0, &vcTrn, 0xFF00FFFF);
	vcTrn = LCXVECTOR2(128,  64);	m_pSprite->Draw(m_pTxArr, &rcD, NULL, NULL, 0, &vcTrn, 0xFF0000FF);


	static char	sMsg[256];

	if(m_bShowStats)
	{
		LCXVECTOR3	vcMouse(m_pInput->GetMousePos());
		
		BOOL nL = m_pInput->ButtonState(0);
		BOOL nR = m_pInput->ButtonState(1);
		BOOL nM = m_pInput->ButtonState(2);

		static INT nUsed = 0;
		static DWORD dBgn = timeGetTime();
		DWORD dEnd = timeGetTime();

		if(dEnd - dBgn>400)
		{
			dBgn = dEnd;

			MEMORYSTATUS mmSt={0};
			GlobalMemoryStatus(&mmSt);
			nUsed = (m_mmSt.dwAvailPhys - mmSt.dwAvailPhys)/1024;				// KByte

			sprintf(sMsg, "(%d X %d) FPS:%4.f  use: %d KB, Mouse: (%.f,%.f)-Event(%d %d %d)"
				, m_nScnW, m_nScnH
				, m_TimeFPS
				, nUsed
				, vcMouse.x, vcMouse.y
				, nL, nR, nM
				);
		}

		

		m_pFont->SetColorDiffuse(&LCXCOLOR(1,1,1,1));
		m_pFont->SetString(sMsg);
		m_pFont->DrawTxt(NULL, NULL, 0, &LCXVECTOR2(0, 0), 0xFFFFFF00);
	}


	return 0;
}



INT CMain::SetPhase(INT nPhase)
{
	if(m_ePhOld == nPhase)														// if Phase changed... 
		return -1;

	m_ePhCur = nPhase;

	SAFE_DELETE(	m_pGmPhs[m_ePhOld]	);


	// Set Start Phase..
	CGmPhase* pPhase = new CGmPhase;
	
	if(FAILED(pPhase->Create(&m_ePhCur, this)))
		return -2;

	m_pGmPhs[m_ePhCur] = pPhase;

	return 0;
}


LRESULT CMain::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if(m_pInput)
	{
		if( FALSE == m_pInput->MsgProc(hWnd, uMsg, wParam, lParam))
			return 0;
	}


	//switch (uMsg) 
	//{
	//	case WM_PAINT:
	//	{
	//		HDC hDC;
	//		PAINTSTRUCT ps;
	//		RECT rt;
	//		hDC = BeginPaint(hWnd, &ps);
	//		GetClientRect(hWnd, &rt);

	//		EndPaint(hWnd, &ps);

	//		return 0;
	//	}
	//}

	return CLpApp::MsgProc(hWnd, uMsg, wParam, lParam);
}


