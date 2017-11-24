// Interface for the ILpNet class.
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _ILpNet_H_
#define _ILpNet_H_


#ifndef interface
#define interface struct
#endif


#ifndef LC_CLASS_DESTROYER
#define LC_CLASS_DESTROYER( CLASS_NAME )	\
virtual ~CLASS_NAME(){}
#endif


interface ILpNet
{
	LC_CLASS_DESTROYER(	ILpNet	);
	
	virtual INT		Create(void* p1=0, void* p2=0, void* p3=0, void* p4=0)=0;	// ������ �ʱ�ȭ�ϰ� ������ �����Ѵ�.
	virtual void	Destroy()=0;												// ������ �Ҹ�ñ�Ű�� ������ �����Ѵ�.
	virtual INT		FrameMove()=0;												// ��Ʈ��ũ���� �ʿ��� �κ��� �����͸� ������Ʈ ��Ų��.

	virtual INT		Query(char* sCmd, void* pData)=0;

	virtual INT		Close()=0;													// ���ϸ� �Ҹ��Ų��.
	virtual INT		Listen()=0;													// �������� ���Ǵ� ����
	virtual INT		Connect(char* sIp=NULL, char* sPort=NULL)=0;				// Ŭ���̾�Ʈ���� ���. ������ �ݰ� �ٽ� ������ �� ����Ѵ�. �����ǳ� ��Ʈ�� NULL���ϸ� ���� �����ǿ� ��Ʈ ���

	virtual INT		Send(char* sSrc, INT* iSnd, UINT* scH=NULL)=0;			// ��Ŷ�� ���� ��
	virtual INT		Recv(char* sDst, INT* iRcv, UINT* scH=NULL)=0;			// ��Ŷ�� ���� ��

	virtual INT		IsConnect()=0;												// ȣ��Ʈ�� ����Ǿ� �ִ���..
};


INT		LpNet_WinSockCreate();
void	LpNet_WinsockDestroy();

INT		LpNet_CreateTcpServer(char* sCmd
							 , ILpNet** pData
							 , void* p1			// IP
							 , void* p2			// Port
							 );

INT		LpNet_CreateTcpClient(char* sCmd
							 , ILpNet** pData
							 , void* p1			// IP
							 , void* p2			// Port
							 );


INT		LpNet_CreateTcpServerEx(char* sCmd
							 , ILpNet** pData
							 , void* p1			// IP
							 , void* p2			// Port
							 , void* v1			// Ex Value1
							 , void* v2			// Ex Value2
							 );

INT		LpNet_CreateTcpClientEx(char* sCmd
							 , ILpNet** pData
							 , void* p1			// IP
							 , void* p2			// Port
							 , void* v1			// Ex Value1
							 , void* v2			// Ex Value2
							 );



// WinSock Library
#if !defined(_WIN32_WCE)
	#pragma comment(lib, "WS2_32.LIB")
#endif


#ifdef USE_LP_SDK_LIB

	#if defined(_DEBUG) || defined(DEBUG)
		#pragma comment(lib, "LpNet_.lib")
	#else
		#pragma comment(lib, "LpNet.lib")
	#endif

#endif


#endif


