// Interface for the ILpFont class.
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _ILpFont_H_
#define _ILpFont_H_


#ifndef interface
#define interface struct
#endif


#ifndef LC_CLASS_DESTROYER
#define LC_CLASS_DESTROYER( CLASS_NAME )	\
	virtual ~CLASS_NAME(){}
#endif


interface ILpFont
{
	struct TLpFont
	{
		INT		iHeight	;															// Height
		INT		iWeight	;															// Weight, Normal, Bold, thin...
		INT		iItalic	;															// Is Italic
		INT		iThckX	;															// Girth of thick X
		INT		iThckY	;															// Girth of thick Y
		DWORD	dString	;															// String color
		DWORD	dGirth	;															// Girth of Font color
		char	sName	[LF_FACESIZE];

		TLpFont();

		TLpFont(	char*	_sName								// Font Name
			,	INT		_iHeight=18							// Height
			,	INT		_iWeight=FW_NORMAL					// Weight, Normal, Bold, thin...
			,	INT		_iItalic=0							// Is Italic
			,	INT		_iThckX=1							// Girth of thick X
			,	INT		_iThckY=1							// Girth of thick Y
			,	DWORD	_dString=0xFFFFFFFF					// String color
			,	DWORD	_dGirth=0xFF000099					// Girth of Font color
			);


		const TLpFont& operator=(const TLpFont& r);	// r: right hand side(rhs)
		const TLpFont& operator=(const TLpFont* r);
	};


	LC_CLASS_DESTROYER(	ILpFont	);

	virtual INT			Create(void* p1=0, void* p2=0, void* p3=0, void* p4=0)=0;
	virtual void		Destroy()=0;

	virtual UINT		GetName()=0;
	virtual UINT		GetFMT()=0;
	virtual UINT		GetType()=0;

	virtual INT			GetImgW()=0;
	virtual INT			GetImgH()=0;
	
	virtual BYTE* const	GetPixel()=0;

	virtual void		SetString(char* sMsg)=0;
	virtual	void		SetColorDiffuse(LCXCOLOR*)=0;
	virtual	void		SetColorFore(LCXCOLOR*)=0;
	virtual	void		SetColorBack(LCXCOLOR*)=0;

	virtual void		SetPos(LCXVECTOR2*)=0;
	virtual void		SetPosAlign(DWORD)=0;

	virtual INT			DrawTxt()=0;

	virtual INT			DrawTxt(	LCXVECTOR2*	vcScl		// Scaling
								,	LCXVECTOR2*	vcRot		// Rotation Center
								,	FLOAT		fRot		// Angle(Radian)
								,	LCXVECTOR2* vcTrn		// Position
								,	LCXCOLOR	dcolor		// color
								,	INT			nMono=0		// 0: Color 1: Mono 2: all Mono
								)=0;
};


INT LpDev_CreateFont(char* sCmd
					, ILpFont** pData
					, void* p1					// LpSprite
					, void* p2					// Font Name
					, DWORD Height				// Font Height
					);



#endif


