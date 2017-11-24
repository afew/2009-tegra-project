// Interface for the ILppObj class.
// Game Object.
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _ILppObj_H_
#define _ILppObj_H_


#ifndef LC_CLASS_DESTROYER
#define LC_CLASS_DESTROYER( CLASS_NAME )	\
virtual ~CLASS_NAME(){}
#endif


// 게임 오브젝트란 게임 진행에서 상호 작용을 하는 모든 객체이다.
// 텍스처, 폰트, 사운드, 폴리곤 모델 등은 게임 객체를 구성하는 원소라 할 수 있다.
// 게임 객체는 살아 있는 객체이다. 현실에서 바위는 무생물 이지만 게임에서
//  상호작용하는 바위는 생명체와 다름이 없다.
// 게임 데이터는 일종의 영혼으로 게임의 객체를 제어하는 요소이다.
// 이 게임 객체는 화면에 모델링 등을 이용해서 렌더링 한다.
// 게임 객체의 속성은 기본적으로 생명체를 모델로 구성한다. 이 속성은 또한
//  온라인 기본적으로 이동을 하며 제한된 생명 시간을 갖는다.



interface ILppObj
{
	enum EObjState
	{
		LCPOBJ_NONE_		= 0x00000000,
		LCPOBJ_BIT_NON_MOVE	= 0x00000001,
		LCPOBJ_BIT_MOVE		= 0x00010000,

		LCPOBJ_IDLE			= 0x00000011,
		LCPOBJ_ATTACK		= 0x00000021,
		LCPOBJ_DEATH		= 0x00000031,

		LCPOBJ_WORK			= 0x00110000,
		LCPOBJ_RUN			= 0x00210000,
	};

	LC_CLASS_DESTROYER(	ILppObj	);
	
	virtual INT		Create(void* =0, void* =0, void* =0, void* =0)=0;
	virtual void	Destroy()=0;
	virtual INT		FrameMove()=0;
	virtual void	Render()=0;

	virtual INT		Query(char* sCmd, void* pVal)=0;
	virtual INT		SetAttrib(char* sCmd, void* pVal)=0;
	virtual INT		GetAttrib(char* sCmd, void* pVal)=0;

	virtual INT		SetAnimation(char* sCmd, void* pVal)=0;
	virtual INT		GetAnimation(char* sCmd, void* pVal)=0;
};


INT LppObj_Create(char* sCmd
				 , ILppObj** pData
				 , void* p1=0			// Basic Data
				 , void* p2=0			// Extended Data
				 , void* p3=0			// Basic Model
				 , void* p4=0			// Extended Model
				 );



#ifdef USE_LP_SDK_LIB

	#if defined(_DEBUG) || defined(DEBUG)
		#pragma comment(lib, "LppObj_.lib")
	#else
		#pragma comment(lib, "LppObj.lib")
	#endif

#endif


#endif

