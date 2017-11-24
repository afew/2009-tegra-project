// Interface for the ILpEnt class.
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _ILpEnt_H_
#define _ILpEnt_H_


#ifndef interface
#define interface struct
#endif


#ifndef LC_CLASS_DESTROYER
#define LC_CLASS_DESTROYER( CLASS_NAME )	\
	virtual ~CLASS_NAME(){}
#endif


interface ILpEnt
{
	LC_CLASS_DESTROYER(	ILpEnt	);

	virtual INT		Create(void* p1=0, void* p2=0, void* p3=0, void* p4=0)=0;
	virtual void	Destroy()=0;

	virtual INT		FrameMove()=0;
	virtual void	Render()=0;

	virtual	INT		Query(char* sCmd, void* pData) =0;
};


// Command - option:
//	"Axis" - max Length(float)
//	"Grid" - NULL

INT LpEnt_Create(char* sCmd
				, ILpEnt** pData
				, void* p1	= NULL
				, void* p2	= NULL
				, void* p3	= NULL
				, void* p4	= NULL
				);



#ifdef USE_LP_SDK_LIB

	#if defined(_DEBUG) || defined(DEBUG)
		#pragma comment(lib, "LpEnt_.lib")
	#else
		#pragma comment(lib, "LpEnt.lib")
	#endif

#endif


#endif


