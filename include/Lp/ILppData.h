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


// ���� ������Ʈ�� ���� ���࿡�� ��ȣ �ۿ��� �ϴ� ��� ��ü�̴�.
// �ؽ�ó, ��Ʈ, ����, ������ �� ���� ���� ��ü�� �����ϴ� ���Ҷ� �� �� �ִ�.
// ���� ��ü�� ��� �ִ� ��ü�̴�. ���ǿ��� ������ ������ ������ ���ӿ���
//  ��ȣ�ۿ��ϴ� ������ ����ü�� �ٸ��� ����.
// ���� �����ʹ� ������ ��ȥ���� ������ ��ü�� �����ϴ� ����̴�.
// �� ���� ��ü�� ȭ�鿡 �𵨸� ���� �̿��ؼ� ������ �Ѵ�.
// ���� ��ü�� �Ӽ��� �⺻������ ����ü�� �𵨷� �����Ѵ�. �� �Ӽ��� ����
//  �¶��� �⺻������ �̵��� �ϸ� ���ѵ� ���� �ð��� ���´�.


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

