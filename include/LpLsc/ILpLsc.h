// Interface for the ILpLsc class.
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _ILpLsc_H_
#define _ILpLsc_H_


#ifndef interface
#define interface struct
#endif


#ifndef LC_CLASS_DESTROYER
#define LC_CLASS_DESTROYER( CLASS_NAME )	\
virtual ~CLASS_NAME(){}
#endif


struct LscH							// Lua Handle
{
	DWORD	nId;
	void*	pIns;					// Instance
	void*	pMsc;					// Miscellany data
	char	sName[160];				// Name

	LscH();
};


interface ILpLsc
{
	LC_CLASS_DESTROYER(	ILpLsc	);

	// General Member Functions.
	virtual INT		Create(void* p1=0, void* p2=0, void* p3=0, void* p4=0)=0;
	virtual void	Destroy()=0;
	virtual INT		Query(char* sCmd, void* pData)=0;

	// Lua Glue Functions.
	virtual INT		Lua_Init()=0;
	virtual INT		Lua_Destroy()=0;
	virtual INT		Lua_FrameMove()=0;
	virtual INT		Lua_Render()=0;
};


// For Program Start...
INT LpDev_CreateLscSys(char* sCmd
				   , ILpLsc** pData		// ILpDev**
				   , void* p1			// Window Handle
				   , void* p2 = NULL	// User Data(Option)
				   , void* p3 = NULL	// No Use
				   , void* p4 = NULL	// No Use
				   );


// For Game Phase
INT LpDev_CreateLscPhase(char* sCmd
						 , ILpLsc** pData	// ILpApp**
						 , void* p1			// Window Handle
						 , void* p2 = NULL	// User Data(Option)
						 , void* p3 = NULL	// No Use
						 , void* p4 = NULL	// No Use
						 );


#ifdef USE_LP_SDK_LIB

	#if defined(_DEBUG) || defined(DEBUG)
		#pragma comment(lib, "LpLsc_.lib")
	#else
		#pragma comment(lib, "LpLsc.lib")
	#endif

#endif


#endif

