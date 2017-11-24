// Interface for the ILpIme class.
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _ILpIme_H_
#define _ILpIme_H_


#ifndef interface
#define interface struct
#endif


#ifndef LN_CLASS_DESTROYER
#define LN_CLASS_DESTROYER( CLASS_NAME )	\
virtual ~CLASS_NAME(){}
#endif


interface ILpIme
{
	LN_CLASS_DESTROYER(	ILpIme	);
	
	virtual INT		Create(void* p1=0, void* p2=0, void* p3=0, void* p4=0)=0;
	virtual	INT		Init()=0;
	virtual void	Destroy()=0;

	virtual INT		Query(char* sCmd, void* pData)=0;
	virtual INT		MsgProc(HWND,UINT,WPARAM,LPARAM)=0;

	virtual void	SetState(BOOL)=0;
	virtual INT		GetState()=0;

	virtual	void	OutString(char*)=0;
	virtual	void	OutStringBeam(char*)=0;
};


INT LpIme_Create(char* sCmd
				 , ILpIme** pData
				 , void* p1			// HWND
				 , void* p2=0		// No Use
				 , void* p3=0		// No Use
				 , void* p4=0		// No Use
				 );


#ifdef _DEBUG
	#pragma comment(lib, "LpIme_.lib")
#else
	#pragma comment(lib, "LpIme.lib")
#endif


#endif

