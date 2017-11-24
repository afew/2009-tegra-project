// Interface for the ILpmFld class.
// Out Door Map
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _ILpmFld_H_
#define _ILpmFld_H_


#pragma warning(disable : 4786)
#include <vector>


#ifndef interface
#define interface struct
#endif


#ifndef LC_CLASS_DESTROYER
#define LC_CLASS_DESTROYER( CLASS_NAME )	\
virtual ~CLASS_NAME(){}
#endif


interface ILpmFld						// Outdoor Map
{
	LC_CLASS_DESTROYER(	ILpmFld	);

	virtual	INT		Create(void* p1=0, void* p2=0, void* p3=0, void* p4=0)=0;
	virtual	void	Destroy()=0;
	virtual	INT		FrameMove()=0;
	virtual	void	Render()=0;

	virtual INT		Query(char* sCmd, void* pData)=0;
	virtual	INT		GetHeight(float* vcOut, const float* vcIn)=0;
};



typedef std::vector<void* >		lsLcxHandle;
typedef lsLcxHandle::iterator	itLcxHandle;


INT LcMap_CreateOutdoor(char* sCmd
						, ILpmFld** pData
						, void* p1			// Device
						, void* p2			// Map File Name
						, void* p3			// Camera
						, void* p4			// Model Table
						, void* p5			// Shader
						, void* p6=0		// No Use
						);



#ifdef USE_LP_SDK_LIB

	#ifdef _DEBUG
		#pragma comment(lib, "LpmFld_.lib")
	#else
		#pragma comment(lib, "LpmFld.lib")
	#endif

#endif


#endif


