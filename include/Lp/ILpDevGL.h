// Interface for the ILpDevGL class.
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _ILpDevGL_H_
#define _ILpDevGL_H_


typedef	unsigned char	BYTE;
typedef	unsigned short	WORD;
typedef	unsigned int	UINT;
typedef	unsigned long	DWORD;

#ifndef interface
#define interface struct
#endif


#ifndef LN_CLASS_DESTROYER
#define LN_CLASS_DESTROYER( CLASS_NAME )	\
	virtual ~CLASS_NAME(){}
#endif


interface ILpDevGL
{
	LN_CLASS_DESTROYER(	ILpDevGL	);

	// Vertex Format for Fixed Pipe Line
	enum ELpDevFVF
	{
		LPFVF_VTX			= 0x0001,	// Position
		LPFVF_VTXD			= 0x0004,	// Position, Diffuse
		LPFVF_VTXUV1		= 0x0005,	// Position, Texture 1 Layer
		LPFVF_VTXDUV1		= 0x0006,	// Position, Diffuse, Texture 1 Layer
	};

	enum ELpDevPrimitiveType
	{
		LPPT_POINTS         =  0x0000,
		LPPT_LINES          =  0x0001,
		LPPT_LINE_LOOP      =  0x0002,
		LPPT_LINE_STRIP     =  0x0003,
		LPPT_TRIANGLES      =  0x0004,
		LPPT_TRIANGLE_STRIP =  0x0005,
		LPPT_TRIANGLE_FAN   =  0x0006,
	};

	enum ELpDevTransform
	{
		LPTS_WORLD		= 0x0001,
		LPTS_VIEW		= 0x0002,
		LPTS_PROJ		= 0x0003,
	};

	enum ELpDevRenderingState
	{
		LPRS_ENABLE_STRREAM		= 0x0001,
		LPRS_DISABLE_STRREAM	= 0x0002,
	};

	// for System
	virtual INT		Create(void* p1=0, void* p2=0, void* p3=0, void* p4=0)=0;
	virtual void	Destroy()=0;
	virtual	INT		Present()=0;

	virtual void*	GetMainObject()=0;			// Main Program Object Pointer
	virtual void*	GetHwnd		()=0;			// Window Handle
	virtual void*	GetSprite	()=0;			// 2D Sprite Pointer
	virtual void*	GetInput	()=0;			// Input Pointer
	virtual void*	GetCamera	()=0;			// Camera Pointer
	virtual void*	GetNetwork	()=0;			// Network Pointer
	virtual void*	GetIme		()=0;			// IME Pointer
	virtual void*	GetCommand	()=0;			// Command Pointer

	virtual void*	GetUserData1()=0;			// User Data Pointer 1
	virtual void*	GetUserData2()=0;			// User Data Pointer 2
	virtual void*	GetUserData3()=0;			// User Data Pointer 3
	virtual void*	GetUserData4()=0;			// User Data Pointer 4

	virtual INT		SetMainObject(void*)=0;
	virtual INT		SetHwnd		(void*)=0;
	virtual INT		SetSprite	(void*)=0;
	virtual INT		SetInput	(void*)=0;
	virtual INT		SetCamera	(void*)=0;
	virtual INT		SetNetwork	(void*)=0;
	virtual INT		SetIme		(void*)=0;
	virtual INT		SetCommand	(void*)=0;

	virtual INT		SetUserData1(void*)=0;
	virtual INT		SetUserData2(void*)=0;
	virtual INT		SetUserData3(void*)=0;
	virtual INT		SetUserData4(void*)=0;


	// for Rendering
	virtual	INT		Setup3DShader(char* p1, char* p2, DWORD p3, DWORD p4)=0;

	virtual	INT		SetRenderState(int nCmd, int Val)=0;
	virtual	INT		GetRenderState(int nCmd, int* Val)=0;

	virtual	INT		SetTransform(int nCmd, const void* Val)=0;
	virtual	INT		GetTransform(int nCmd, void* Val)=0;
	virtual	INT		SetTransformIdentity(int nCmd)=0;

	virtual	INT		Begin()=0;
	virtual	INT		End()=0;
	virtual	INT		SetFVF(int nFVF)=0;
	virtual	INT		SetTexture(INT nStage, const void* Val)=0;

	virtual INT		SetStramSource(int nIndex, int nFloatCount, const void* pData, int nStride=0, int Offset=0, int bNormalize=FALSE)=0;
	virtual INT		DrawPrimitive(int nMode, int First, int VertexCount)=0;
	virtual INT		DrawIndexedPrimitive(int nMode, int nFaces, void* indices)=0;

	virtual INT		Clear(DWORD nMode, DWORD dColor)=0;
};


INT LpDev_CreateGL(char* sCmd
					   , ILpDevGL** pData
					   , void* p1			// Window Handle
					   , void* p2 = NULL	// User Data(Option)
					   , void* p3 = NULL	// No Use
					   , void* p4 = NULL	// No Use
					 );







//Query 대신 시스템 데이터를 함수로 편리하게 사용하기 위해서...
void* LpDev_GetUserMainObject(ILpDevGL*)	;
void* LpDev_GetUserHwnd		(ILpDevGL* )	;
void* LpDev_GetUserSprite	(ILpDevGL* )	;
void* LpDev_GetUserInput	(ILpDevGL* )	;
void* LpDev_GetUserCamera	(ILpDevGL* )	;
void* LpDev_GetUserNetwork	(ILpDevGL* )	;
void* LpDev_GetUserIme		(ILpDevGL* )	;
void* LpDev_GetUserCommand	(ILpDevGL* )	;

void* LpDev_GetUserData1	(ILpDevGL* )	;
void* LpDev_GetUserData2	(ILpDevGL* )	;
void* LpDev_GetUserData3	(ILpDevGL* )	;
void* LpDev_GetUserData4	(ILpDevGL* )	;

INT	LpDev_SetUserMainObject	(ILpDevGL*, void*);
INT	LpDev_SetUserHwnd		(ILpDevGL*, void*);
INT	LpDev_SetUserSprite		(ILpDevGL*, void*);
INT	LpDev_SetUserInput		(ILpDevGL*, void*);
INT	LpDev_SetUserCamera		(ILpDevGL*, void*);
INT	LpDev_SetUserNetwork	(ILpDevGL*, void*);
INT	LpDev_SetUserIme		(ILpDevGL*, void*);
INT	LpDev_SetUserCommand	(ILpDevGL*, void*);

INT	LpDev_SetUserData1		(ILpDevGL*, void*);
INT	LpDev_SetUserData2		(ILpDevGL*, void*);
INT	LpDev_SetUserData3		(ILpDevGL*, void*);
INT	LpDev_SetUserData4		(ILpDevGL*, void*);



#ifdef USE_LP_SDK_LIB

	#if defined(_DEBUG) || defined(DEBUG)
		#pragma comment(lib, "LpDev_.lib")
	#else
		#pragma comment(lib, "LpDev.lib")
	#endif

#endif


#endif


