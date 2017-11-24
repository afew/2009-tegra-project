// Interface for the ILpCam class.
//
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _ILpCam_H_
#define _ILpCam_H_


#ifndef interface
#define interface struct
#endif


#ifndef LC_CLASS_DESTROYER
#define LC_CLASS_DESTROYER( CLASS_NAME )	\
virtual ~CLASS_NAME(){}
#endif



struct LpCam
{
	// for Projection Matrix
	FLOAT	fScnW;			// Screen Width
	FLOAT	fScnH;			// Screen Height
	FLOAT	fFov;			// Field of View
	FLOAT	fNear;			// Near value
	FLOAT	fFar;			// Far value

	// for View Matrix
	FLOAT	vEye[3];		// Camera Initial Position X,Y,Z
	FLOAT	vLook[3];		// Camera Look At Position X,Y,Z
	FLOAT	vUp[3];			// Camera Up Vector X,Y,Z
};



////////////////////////////////////////////////////////////////////////////////
// Single Camera

interface ILpCam
{
	LC_CLASS_DESTROYER(	ILpCam	);
	
	enum ELpCam
	{
		LC_CAM_NONE	=0,		//
		LC_CAM_FIRST,		// 1 ÀÎÄª
		LC_CAM_THIRD,		// 3 ÀÎÄª
		LC_CAM_ALL,			// 1~3 ÀÎÄª
	};
	

	virtual INT		Create(void* p1=0, void* p2=0, void* p3=0, void* p4=0)=0;
	virtual void	Destroy()=0;
	virtual INT		FrameMove()=0;
	virtual INT		Query(char* sCmd, void* pData)=0;


	virtual void	SetName(char* sN)=0;
	virtual char*	GetName()=0;
	
	virtual void	SetType(INT	eType)=0;
	virtual ELpCam	GetType()=0;
	
	virtual const	LCXMATRIX*  const GetMatrixViw()	const=0;
	virtual const	LCXMATRIX*  const GetMatrixPrj()	const=0;
	virtual const	LCXMATRIX*  const GetMatrixViwI()	const=0;
	virtual const	LCXMATRIX*  const GetMatrixBill()	const=0;
	virtual const	LCXMATRIX*  const GetMatrixViwPrj()	const=0;
	virtual const	LCXMATRIX*  const GetMatrixViwPrjI()const=0;
	
	virtual const	LCXVECTOR3* const GetEye()	const=0;
	virtual const	LCXVECTOR3* const GetLook()const=0;
	virtual const	LCXVECTOR3* const GetUp()	const=0;

	virtual void	SetEye	(LCXVECTOR3*)=0;
	virtual void	SetLook	(LCXVECTOR3*)=0;
	virtual void	SetUp	(LCXVECTOR3*)=0;
	
	virtual FLOAT	GetYaw	()=0;
	virtual FLOAT	GetPitch()=0;
	
	virtual void	SetFov	(FLOAT)=0;
	virtual void	SetScnW	(FLOAT)=0;
	virtual void	SetScnH	(FLOAT)=0;
	virtual void	SetNear	(FLOAT)=0;
	virtual void	SetFar	(FLOAT)=0;

	virtual FLOAT	GetFov	()=0;
	virtual FLOAT	GetScnW	()=0;
	virtual FLOAT	GetScnH	()=0;
	virtual FLOAT	GetAspect()=0;
	virtual FLOAT	GetNear	()=0;
	virtual FLOAT	GetFar	()=0;

	virtual const	LCXVECTOR3* const GetAxisX()=0;
	virtual const	LCXVECTOR3* const GetAxisY()=0;
	virtual const	LCXVECTOR3* const GetAxisZ()=0;

	virtual const	LCXPLANE*   const GetFrustumPlanes()=0;
	virtual const	LCXVECTOR3* const GetFrustumPoints()=0;
		
	virtual void	SetParamView(LCXVECTOR3* Eye, LCXVECTOR3* Look, LCXVECTOR3* Up)=0;
	virtual void	SetParamProj(FLOAT fFov, FLOAT fScnW, FLOAT fScnH, FLOAT fNear, FLOAT fFar)=0;
	
	virtual void	SetTransformViw()=0;
	virtual void	SetTransformPrj()=0;

	// Pick Ray direction
	virtual LCXVECTOR3	GetDirectionOfMouse(FLOAT fMouseX, FLOAT fMouseY)=0;

	// Individual Camera
	virtual void	SetMatrixViw(LCXMATRIX*)=0;
	virtual void	SetMatrixPrj(LCXMATRIX*)=0;

	virtual void	MoveSideward(FLOAT fSpeed)=0;
	virtual void	MoveForward	(FLOAT fSpeed, FLOAT fY=1)=0;
	virtual void	RotateYaw	(FLOAT fDelta, FLOAT fSpeed)=0;
	virtual void	RotatePitch	(FLOAT fDelta, FLOAT fSpeed)=0;
	virtual	void	Zoom(FLOAT)	= 0;


	// For Third Person Camera
	virtual void	SetBasis(LCXVECTOR3*) =0;
	virtual const	LCXVECTOR3* const GetBasis() const=0;

	virtual void	SetEpsilonY(FLOAT)	=0;
	virtual FLOAT	GetEpsilonY()		=0;

	virtual void	SetGap(FLOAT)	=0;
	virtual FLOAT	GetGap()		=0;
};




INT LpEnt_CreateCamera(char* sCmd
				, ILpCam** pData
				, void* p1=0		// Camera name
				, void* p2=0		// ILpDevGL*
				, void* p3=0		// Camera Initial Value
				, void* p4=0		// No Use
				);







////////////////////////////////////////////////////////////////////////////////
// Multi Camera

#define LC_MUTI_CAMERA_MAX	16


interface ILpCamM
{
	LC_CLASS_DESTROYER(	ILpCamM	);
	
	virtual INT		Create(void* p1=0, void* p2=0, void* p3=0, void* p4=0)=0;
	virtual void	Destroy()=0;
	virtual INT		FrameMove()=0;
	virtual INT		Query(char* sCmd, void* pData)=0;


	virtual void	SetName(INT nIdx, char* sN)=0;
	virtual char*	GetName(INT nIdx)=0;
	
	virtual void	SetType(INT nIdx, INT	eType)=0;
	virtual INT		GetType(INT nIdx)=0;
	
	virtual const	LCXMATRIX*  const GetMatrixViw		(INT nIdx) const=0;
	virtual const	LCXMATRIX*  const GetMatrixPrj		(INT nIdx) const=0;
	virtual const	LCXMATRIX*  const GetMatrixViwI	(INT nIdx) const=0;
	virtual const	LCXMATRIX*  const GetMatrixBill	(INT nIdx) const=0;
	virtual const	LCXMATRIX*  const GetMatrixViwPrj	(INT nIdx) const=0;
	virtual const	LCXMATRIX*  const GetMatrixViwPrjI	(INT nIdx) const=0;
	
	virtual const	LCXVECTOR3* const GetEye (INT nIdx) const=0;
	virtual const	LCXVECTOR3* const GetLook(INT nIdx) const=0;
	virtual const	LCXVECTOR3* const GetUp  (INT nIdx) const=0;

	virtual void	SetEye	(INT nIdx, LCXVECTOR3*)=0;
	virtual void	SetLook	(INT nIdx, LCXVECTOR3*)=0;
	virtual void	SetUp	(INT nIdx, LCXVECTOR3*)=0;
	
	virtual FLOAT	GetYaw	(INT nIdx)=0;
	virtual FLOAT	GetPitch(INT nIdx)=0;
	
	virtual void	SetFov	(INT nIdx, FLOAT)=0;
	virtual void	SetScnW	(INT nIdx, FLOAT)=0;
	virtual void	SetScnH	(INT nIdx, FLOAT)=0;
	virtual void	SetNear	(INT nIdx, FLOAT)=0;
	virtual void	SetFar	(INT nIdx, FLOAT)=0;

	virtual FLOAT	GetFov	 (INT nIdx)=0;
	virtual FLOAT	GetScnW	 (INT nIdx)=0;
	virtual FLOAT	GetScnH	 (INT nIdx)=0;
	virtual FLOAT	GetAspect(INT nIdx)=0;
	virtual FLOAT	GetNear	 (INT nIdx)=0;
	virtual FLOAT	GetFar	 (INT nIdx)=0;

	virtual const	LCXVECTOR3* const GetAxisX(INT nIdx)=0;
	virtual const	LCXVECTOR3* const GetAxisY(INT nIdx)=0;
	virtual const	LCXVECTOR3* const GetAxisZ(INT nIdx)=0;

	virtual const	LCXPLANE*   const GetFrustumPlanes(INT nIdx)=0;
	virtual const	LCXVECTOR3* const GetFrustumPoints(INT nIdx)=0;
		
	virtual void	SetParamView(INT nIdx, LCXVECTOR3* Eye, LCXVECTOR3* Look, LCXVECTOR3* Up)=0;
	virtual void	SetParamProj(INT nIdx, FLOAT fFov, FLOAT fScnW, FLOAT fScnH, FLOAT fNear, FLOAT fFar)=0;
	
	virtual void	SetTransformViw(INT nIdx)=0;
	virtual void	SetTransformPrj(INT nIdx)=0;

	virtual LCXVECTOR3	GetDirectionOfMouse(INT nIdx, FLOAT fMouseX, FLOAT fMouseY)=0;

	virtual void	SetMatrixViw(INT nIdx, LCXMATRIX*)=0;
	virtual void	SetMatrixPrj(INT nIdx, LCXMATRIX*)=0;

	virtual void	MoveSideward(INT nIdx, FLOAT fSpeed)=0;
	virtual void	MoveForward	(INT nIdx, FLOAT fSpeed, FLOAT fY=1)=0;
	virtual void	RotateYaw	(INT nIdx, FLOAT fDelta, FLOAT fSpeed)=0;
	virtual void	RotatePitch	(INT nIdx, FLOAT fDelta, FLOAT fSpeed)=0;
	virtual void	Zoom		(INT nIdx, FLOAT fDelta)=0;


	// For Third Person Camera
	virtual void	SetBasis(INT nIdx, LCXVECTOR3*)=0;
	virtual const	LCXVECTOR3* const GetBasis(INT nIdx) const=0;

	virtual void	SetEpsilonY(INT nIdx, FLOAT)=0;
	virtual FLOAT	GetEpsilonY(INT nIdx)		=0;

	virtual void	SetGap(INT nIdx, FLOAT)	=0;
	virtual FLOAT	GetGap(INT nIdx)		=0;

	// Camera Pointer
	virtual	ILpCam*	GetCameraPointer(INT nIdx) =0;
};




INT LpEnt_CreateMutiCamera(char* sCmd
				, ILpCamM** pData
				, void* p1			// ILpDevGL*
				, void* p2=0		// Camera Number. NULLÀÌ¸é LC_MUTI_CAMERA_MAX¸¸Å­ ¸¸µê
				, void* p3=0		// No Use
				, void* p4=0		// No Use
				);



//#ifdef USE_LP_SDK_LIB
//
//	#if defined(_DEBUG) || defined(DEBUG)
//		#pragma comment(lib, "LpCam_.lib")
//	#else
//		#pragma comment(lib, "LpCam.lib")
//	#endif
//
//#endif

#ifdef USE_LP_SDK_LIB

	#if defined(_DEBUG) || defined(DEBUG)
		#pragma comment(lib, "LpEnt_.lib")
	#else
		#pragma comment(lib, "LpEnt.lib")
	#endif

#endif

	
#endif



