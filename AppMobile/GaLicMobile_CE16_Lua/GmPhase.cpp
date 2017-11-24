// Implementation of the CGmPhase class.
//
////////////////////////////////////////////////////////////////////////////////

#include <Windows.h>

#include <Lp/LpUtil.h>
#include <Lp/ILpDev.h>

#include <LpLsc/ILpLsc.h>

#include "GmPhase.h"


CGmPhase::CGmPhase()
{
	m_nPhase	= 0		;
	m_pSys		= NULL	;
	m_pLsc		= NULL	;
}

CGmPhase::~CGmPhase()
{
	CGmPhase::Destroy();
}


INT CGmPhase::Create(void* p1, void* p2, void* p3, void* p4)
{
	m_nPhase	= *((INT*)p1);
	m_pSys		= (ILpDev*)p2;


	char	sFile[160]={0};

	memcpy(sFile, &m_nPhase, sizeof m_nPhase);

	if(FAILED(m_pSys->Query("Get Script File", sFile)))
		return -1;

	if(FAILED(LpDev_CreateLscPhase(NULL, &m_pLsc, sFile, m_pSys)))
		return -1;


	if(FAILED(m_pLsc->Lua_Init()))
		return -1;

	return 0;
}


void CGmPhase::Destroy()
{
	if(m_pLsc)
		m_pLsc->Lua_Destroy();

	SAFE_DELETE(	m_pLsc		);

	return;
}


INT CGmPhase::FrameMove()
{
	INT hr = 0;

	if(m_pLsc)
		hr = m_pLsc->Lua_FrameMove();

	if(FAILED(hr))
		return -1;

	else if(0==hr)
		return 0;

	if(-2 == m_pSys->SetPhase(hr))
		return -1;

	return 0;
}

INT CGmPhase::Render()
{
	if(m_pLsc)
		m_pLsc->Lua_Render();

	return 0;
}

INT CGmPhase::Query(char* sCmd, void* pData)
{
	return -1;
}

