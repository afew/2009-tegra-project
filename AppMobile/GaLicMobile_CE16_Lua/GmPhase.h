// Interface for the CGmPhase class.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _GmPhase_H_
#define _GmPhase_H_

#pragma once

#pragma warning(disable : 4786)

#include <vector>

class CGmPhase : public ILpApp
{
protected:
	INT			m_nPhase	;
	ILpDev*		m_pSys		;
	ILpLsc*		m_pLsc		;

public:
	CGmPhase();
	virtual ~CGmPhase();

	virtual INT		Create(void* =0, void* =0, void* =0, void* =0);

	virtual INT		Init()		{	return 0;	}
	virtual void	Destroy();

	virtual INT		FrameMove();
	virtual INT		Render();

	virtual INT		Query(char* sCmd, void* pData);
};


#endif

