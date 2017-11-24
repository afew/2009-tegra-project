// Interface for the ILpMdl class.
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _ILpMdl_H_
#define _ILpMdl_H_


#pragma warning( disable : 4786)
#include <vector>


#ifndef interface
#define interface struct
#endif


#ifndef LC_CLASS_DESTROYER
#define LC_CLASS_DESTROYER( CLASS_NAME )	\
virtual ~CLASS_NAME(){}
#endif


struct TbndAB;


interface ILpMdl
{
	LC_CLASS_DESTROYER(	ILpMdl	);

	virtual	INT		Create(void* p1=NULL, void* p2=NULL, void* p3=NULL, void* p4=NULL)=0;
	virtual	void	Destroy()=0;
	virtual	INT		FrameMove()=0;
	virtual	void	Render()=0;

	virtual INT		Query(char* sCmd, void* pVal)=0;
	virtual INT		GetType()=0;
	virtual const char*	const GetName()const=0;
	virtual ILpMdl* GetOriginal()=0;

	virtual INT		SetAttrib(char* sCmd, void* pVal)=0;
	virtual INT		GetAttrib(char* sCmd, void* pVal)=0;

	virtual INT		SetPosition(FLOAT* float3)=0;
	virtual INT		SetRotation(FLOAT* float4, INT nOpt=LCM_ROT_XYZ)=0;
	virtual INT		SetScaling(FLOAT* float3)=0;

	virtual INT		GetPosition(FLOAT* float3)=0;
	virtual INT		GetRotation(FLOAT* float4)=0;
	virtual INT		GetScaling(FLOAT* float3)=0;
	virtual	FLOAT	GetSortValue()=0;
	virtual	const TbndAB* const	GetBndInf() const=0;

	enum ELcmConst
	{
		// Model Type
		LCM_NONE	= 0x00000000,
		LCM_BILL	= 0x00000001,
		LCM_SOLID	= 0x00000002,
		LCM_ACM		= 0x00000004,
		LCM_ASE		= 0x00000008,
		LCM_XFILE	= 0x00010000,

		// for Info...
		LCM_TEX_NAME	= 128,
		LCM_HEADER_SIZE = 256,
		LCM_FILE_NAME	= 128,

		// Rotation Type
		LCM_ROT_XYZ		= 0x00000000,
		LCM_ROT_AXIS	= 0x00000001,

		// Rendering Level
		LCM_RND_NONE	= 0x00000000,	// No Update and No Rendering
		LCM_RND_UPDATE	= 0x00000001,	// Only for Update
		LCM_RND_RENDER	= 0x00000002,	// Update and Rendering
		LCM_RND_ALL		= 0x000000FF,	// No Limit

		// Format
		LCFVF_XYZ		=	0x002,
		LCFVF_NORMAL	=	0x010,
		LCFVF_DIFFUSE	=	0x040,
		LCFVF_TEX1		=	0x100,
		LCFVF_TEX2		=	0x200,

		D3DFVF_XYZ		=	0x002,
		D3DFVF_NORMAL	=	0x010,
		D3DFVF_DIFFUSE	=	0x040,
		D3DFVF_TEX1		=	0x100,
		D3DFVF_TEX2		=	0x200,
	};

	struct _Tattach
	{
		INT		nI	;					// Geometry Index
		char*	sN	;					// Name
		FLOAT*	tm	;					// Transformation Matrix Pointer
		INT		nM	;					// Material
	};

	struct _Tframe
	{
		char	sN[64];					// Phase Name
		INT		nB	;					// Begin Frame
		INT		nE	;					// End Frame
		_Tframe();
		_Tframe(char* s, INT B, INT E);
	};
};


INT LpMdl_Create(char* sCmd
				 , ILpMdl** pData
				 , void* p1			// ILpDevGL*
				 , void* p2			// Model File Name
				 , void* p3=NULL	// No Use
				 , void* p4=NULL	// No Use
				 );


typedef std::vector<ILpMdl* >	lsLpMdl;
typedef lsLpMdl::iterator		itLpMdl;






// Cuboid Axis Aligned Bounding Box
//
//	Edges
//
//		5------------7(Max)
//	y  /|           /|
//	| / |   z      / |
//	|/  |  /      /  |
//	1------------3   |
//	|   |/       |   |
//	|   4--------|---6
//	|  /         |  /
//	| /          | /
//	|/           |/
//	0(Min)-------2----- x


struct TbndAB
{
	struct _Tvtx
	{
		LCXVECTOR3	p;
		DWORD		d;
//		enum { FVF = (D3DFVF_XYZ|D3DFVF_DIFFUSE) };

		_Tvtx() : d(0xFFFFFFFF){}

	};

	TbndAB::_Tvtx vcE[8];	// Edge

	LCXVECTOR3	vcM;	// Max
	LCXVECTOR3	vcN;	// Min
	LCXVECTOR3	vcC;	// Center

	FLOAT		fX;		// Width
	FLOAT		fY;		// Height
	FLOAT		fZ;		// Depth
	FLOAT		fR;		// Radius
	void*		pOwner;	// Owner of Bound Box

	TbndAB();
	TbndAB(const LCXVECTOR3& Min, const LCXVECTOR3& Max, void* pOwn=NULL);


	void			Set(const LCXVECTOR3& Min, const LCXVECTOR3& Max, void* pOwn=NULL);

	void			RenderBox(void* pDev);
	void			SetOwner(void* pOwn);
	void*			GetOwner();
	void			SetColor(DWORD dColor);

	LCXVECTOR3*	GetMin() const;
	LCXVECTOR3*	GetMax() const;
	LCXVECTOR3*	GetCenter() const;
	FLOAT			GetWidth();
	FLOAT			GetHeight();
	FLOAT			GetDepth();
	FLOAT			GetRadius();
};


struct TbndAABB																	// Picking AABB
{
	LCXVECTOR3	vPck;															// Get Position
	TbndAB*		pBnd;															// Bound Box Pointer
	FLOAT		fStlSrtR;														// Distance From Camera

	TbndAABB();
	TbndAABB(const LCXVECTOR3& vcP, TbndAB* _pBnd, FLOAT _fD);
};

typedef std::vector<TbndAABB >	lsPkBndA;
typedef lsPkBndA::iterator		itPkBndA;





// Packages : 모델들 리스트 자료구조.
interface ILpmPack
{
	LC_CLASS_DESTROYER(	ILpmPack	);

	virtual	INT		Create(void* =0, void* =0, void* =0, void* =0)=0;
	virtual	void	Destroy()=0;
	virtual	INT		FrameMove()=0;
	virtual	void	Render()=0;

	virtual INT		Query(char* sCmd, void* pVal)=0;

	virtual void	SetLcl(void* pLcl)=0;
	virtual void	AddObj(ILpMdl* pSrc
		, LCXVECTOR3 vcP		// Position
		, void* p1		// Camera
		, void* p2		// Field
		, void* p3		// Field Local
		, void* p4		// Parent Package
		)=0;

	// For STL
	virtual	void	Push_Back(ILpMdl* pMdB)=0;
	virtual	INT		Size()=0;
	virtual	ILpMdl*	GetObj(int n)=0;
	virtual	INT		Erase(int n)=0;	
	virtual	INT		Erase(ILpMdl*)=0;	
};


typedef std::vector<ILpmPack* >	lsLcmPack;
typedef lsLcmPack::iterator		itLcmPack;


INT LpMdl_CreatePack(char* sCmd
				   , ILpmPack** pData
				   , void* p1			// LPDIRECT3DDEVICE9
				   , void* p2=NULL	// Local Field
				   , void* p3=NULL	// No Use
				   , void* p4=NULL	// No Use
				   );





#ifdef USE_LP_SDK_LIB

	#if defined(_DEBUG) || defined(DEBUG)
		#pragma comment(lib, "LpMdl_.lib")
	#else
		#pragma comment(lib, "LpMdl.lib")
	#endif

#endif


#endif



