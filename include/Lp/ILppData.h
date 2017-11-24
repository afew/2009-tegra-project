// Interface for the ILppData class.
// Game Data.
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _ILppData_H_
#define _ILppData_H_


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


interface ILppData
{
	LC_CLASS_DESTROYER(	ILppData	);
	
	virtual INT		GetType()=0;
	virtual INT		Query(char* sCmd, void* pVal)=0;
	virtual INT		SetAttrib(char* sCmd, void* pVal)=0;
	virtual INT		GetAttrib(char* sCmd, void* pVal)=0;

	enum
	{
		LCP_TYPE_INTER	= 1,
		LCP_TYPE_OUTER	= 2,
		LCP_DATA_NAME	= 64,
	};
};


// Basic Data Create
INT LppData_CreateBasic(char* sCmd
				 , ILppData** pData
				 , void* p1=0		// No Use
				 , void* p2=0		// No Use
				 , void* p3=0		// No Use
				 , void* p4=0		// No Use
				 );



#ifdef USE_LP_SDK_LIB

	#if defined(_DEBUG) || defined(DEBUG)
		#pragma comment(lib, "LppData_.lib")
	#else
		#pragma comment(lib, "LppData.lib")
	#endif

#endif


#endif

