// Interface for the ILpTbl class.
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _ILpTbl_H_
#define _ILpTbl_H_


#pragma warning(disable : 4786)
#include <vector>


#ifndef interface
#define interface struct
#endif


#ifndef LC_CLASS_DESTROYER
#define LC_CLASS_DESTROYER( CLASS_NAME )	\
virtual ~CLASS_NAME(){}
#endif


interface ILpTbl
{
	LC_CLASS_DESTROYER(	ILpTbl	);

	virtual INT		Create(void* p1=0, void* p2=0, void* p3=0, void* p4=0)=0;
	virtual void	Destroy()=0;

	virtual	INT		Select(void** pOut, INT nM/*In*/, INT nS/*In*/)=0;
	virtual	INT		Select(void** pOut, INT* nM/*Out*/, INT* nS/*Out*/, char* sFile)=0;
	virtual	INT		SelectInfo(void** pOut, INT nM/*In*/, INT nS/*In*/)=0;
};


typedef	std::vector<ILpTbl* >	lsILpTbl;
typedef lsILpTbl::iterator		itILpTbl;


INT LpTbl_Create(char* sCmd
				 , ILpTbl** pData
				 , void* p1			// File Name
				 , void* p2			// Device
				 , void* p3=NULL	// Etc
				 , void* p4=NULL	// No Use
				 );



#ifdef USE_LP_SDK_LIB

	#if defined(_DEBUG) || defined(DEBUG)
		#pragma comment(lib, "LpTbl_.lib")
	#else
		#pragma comment(lib, "LpTbl.lib")
	#endif

#endif


#endif



