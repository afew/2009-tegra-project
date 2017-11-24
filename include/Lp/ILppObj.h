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


// ���� ������Ʈ�� ���� ���࿡�� ��ȣ �ۿ��� �ϴ� ��� ��ü�̴�.
// �ؽ�ó, ��Ʈ, ����, ������ �� ���� ���� ��ü�� �����ϴ� ���Ҷ� �� �� �ִ�.
// ���� ��ü�� ��� �ִ� ��ü�̴�. ���ǿ��� ������ ������ ������ ���ӿ���
//  ��ȣ�ۿ��ϴ� ������ ����ü�� �ٸ��� ����.
// ���� �����ʹ� ������ ��ȥ���� ������ ��ü�� �����ϴ� ����̴�.
// �� ���� ��ü�� ȭ�鿡 �𵨸� ���� �̿��ؼ� ������ �Ѵ�.
// ���� ��ü�� �Ӽ��� �⺻������ ����ü�� �𵨷� �����Ѵ�. �� �Ӽ��� ����
//  �¶��� �⺻������ �̵��� �ϸ� ���ѵ� ���� �ð��� ���´�.



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

