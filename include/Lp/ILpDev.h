// Interface for the ILpDev class.
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _ILpDev_H_
#define _ILpDev_H_


#ifndef interface
#define interface struct
#endif


#ifndef LC_CLASS_DESTROYER
#define LC_CLASS_DESTROYER( CLASS_NAME )	\
	virtual ~CLASS_NAME(){}
#endif


// Application or Game Phase(Stage) Interface
interface ILpApp
{
	LC_CLASS_DESTROYER(	ILpApp	);

	virtual INT		Create(void* =0, void* =0, void* =0, void* =0)=0;	

	virtual INT		Init()=0;
	virtual void	Destroy()=0;
	virtual INT		FrameMove()=0;
	virtual	INT		Render()=0;
	virtual INT		Query(char* sCmd, void* pData)=0;
};


interface ILpDev
{
	LC_CLASS_DESTROYER(	ILpDev	);

	virtual INT		Create(void* p1=0, void* p2=0, void* p3=0, void* p4=0)=0;
	
	virtual INT		Init()=0;
	virtual INT		Destroy()=0;
	virtual INT		FrameMove()=0;
	virtual INT		Render()=0;
	virtual	INT		Run()=0;
	virtual INT		Query(char* sCmd, void* pData)=0;

	virtual INT		Clear(DWORD Flags,DWORD Color)=0;
	virtual void*	GetHinst()=0;
	virtual void*	GetHwnd()=0;
	virtual void*	GetGLDevice()=0;
	virtual INT		SetPhase(INT)=0;	// For change Game System Phase.
};


#endif

