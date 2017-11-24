// Interface for the ILpEffect class.
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _ILpEffect_H_
#define _ILpEffect_H_

#ifndef interface
#define interface struct
#endif


#ifndef LC_CLASS_DESTROYER
#define LC_CLASS_DESTROYER( CLASS_NAME )	\
	virtual ~CLASS_NAME(){}
#endif


interface ILpEffect
{
	LC_CLASS_DESTROYER(	ILpEffect	);

	virtual	INT	Create(void* p1=0, void* p2=0, void* p3=0, void* p4=0)=0;
	virtual	INT	Destroy()=0;

	virtual INT	Begin() =0;
	virtual INT	End() =0;

	// Setup Attrribute Index
	virtual	INT	SetAttribIndex(char* attName, INT nIndex) =0;
	virtual	INT	SetAttribPointer(INT nIndex, INT size, INT stride, const void* pVtx, INT nOffset=0) =0;

	// Setup Uniform value
	virtual	INT	SetInt(const char* sHandle, INT pVal) =0;
	virtual	INT	SetIntArray(const char* sHandle, void* pVal, INT nCount) =0;
	virtual	INT	SetFloat(const char* sHandle, float pVal) =0;
	virtual	INT	SetFloatArray(const char* sHandle, void* pVal, INT nCount) =0;
	virtual	INT	SetVector2(const char* sHandle, void* pVal) =0;
	virtual	INT	SetVector3(const char* sHandle, void* pVal) =0;
	virtual	INT	SetVector4(const char* sHandle, void* pVal) =0;
	virtual	INT	SetMatrix2(const char* sHandle, void* pVal) =0;
	virtual	INT	SetMatrix3(const char* sHandle, void* pVal) =0;
	virtual	INT	SetMatrix4(const char* sHandle, void* pVal) =0;
	virtual	INT	SetColor(const char* sHandle, void* pVal) =0;
	virtual	INT	SetTexture(const char* sHandle, INT nStage, INT nTexID) =0;
};


INT		LpDev_EffectInit();						// Create Effect Manager
void	LpDev_EffectDestroy();					// Delete

INT		LpDev_CreateEffect(char* sCmd
						, ILpEffect** pData
						, void* p1				// Vertex Shader File Name
						, void* p2				// Fragment Shader File Name
						, void* p3=NULL			// Vertex Shader Resource Name
						, void* p4=NULL			// Fragment Shader Resource Name
						);


#endif




