// Interface for the ILpSprite class.
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _ILpSprite_H_
#define _ILpSprite_H_


#ifndef interface
#define interface struct
#endif


#ifndef LN_CLASS_DESTROYER
#define LN_CLASS_DESTROYER( CLASS_NAME )	\
	virtual ~CLASS_NAME(){}
#endif


interface ILpSprite
{
	LN_CLASS_DESTROYER(	ILpSprite	);

	virtual INT		Create(void* p1=0, void* p2=0, void* p3=0, void* p4=0)=0;
	virtual void	Destroy()=0;

	virtual INT		Draw(	void*		pTexture	// CGLTexture Pointer
						,	RECT*		rc			// Image rect
						,	LCXVECTOR2*	vcScl		// Scaling
						,	LCXVECTOR2*	vcRot		// Rotation Center
						,	FLOAT		fRot		// Angle(Radian)
						,	LCXVECTOR2* vcTrn		// Position
						,	LCXCOLOR	dcolor		// color
						,	INT			nMono=0		// 0: Color 1: Mono 2: all Mono
						) = 0;
};


INT LpDev_CreateSprite(char* sCmd
					   , ILpSprite** pData
					   , void* p1			// Window Handle
					   , void* p2			// Vertex Shader ID
					   , void* p3			// Fragment Shader ID
					   , void* p4 = NULL	// No Use
					 );


#endif

