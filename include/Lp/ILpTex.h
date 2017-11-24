// Interface for the ILpTex class.
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _ILpTex_H_
#define _ILpTex_H_


#ifndef interface
#define interface struct
#endif


#ifndef LC_CLASS_DESTROYER
#define LC_CLASS_DESTROYER( CLASS_NAME )	\
	virtual ~CLASS_NAME(){}
#endif


interface ILpTex
{
	LC_CLASS_DESTROYER(	ILpTex	);

	virtual INT			Create(void* p1=0, void* p2=0, void* p3=0, void* p4=0)=0;
	virtual void		Destroy()=0;

	virtual UINT		GetId()=0;
	virtual UINT		GetFMT()=0;
	virtual UINT		GetType()=0;

	virtual INT			GetImgW()=0;
	virtual INT			GetImgH()=0;
	
	virtual BYTE* const	GetPixel() const =0;

	virtual void		SetBindTexture(BOOL b=TRUE)=0;
};


INT LpDev_CreateTex(char* sCmd
				, ILpTex** pData
				, void* FileName
				, DWORD dColorKey=0x00FFFFFF);


void LpDev_TextureBindNull();



#endif