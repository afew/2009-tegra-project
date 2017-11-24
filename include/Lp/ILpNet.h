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
	
	virtual INT		Create(void* p1=0, void* p2=0, void* p3=0, void* p4=0)=0;	// 윈속을 초기화하고 소켓을 생성한다.
	virtual void	Destroy()=0;												// 소켓을 소멸시기키고 윈속을 해제한다.
	virtual INT		FrameMove()=0;												// 네트워크에서 필요한 부분으 데이터를 업데이트 시킨다.

	virtual INT		Query(char* sCmd, void* pData)=0;

	virtual INT		Close()=0;													// 소켓만 소멸시킨다.
	virtual INT		Listen()=0;													// 서버에서 사용되는 리슨
	virtual INT		Connect(char* sIp=NULL, char* sPort=NULL)=0;				// 클라이언트에서 사용. 소켓을 닫고 다시 연결할 때 사용한다. 아이피나 포트를 NULL로하면 이전 아이피와 포트 사용

	virtual INT		Send(char* sSrc, INT* iSnd, UINT* scH=NULL)=0;			// 패킷을 보낼 때
	virtual INT		Recv(char* sDst, INT* iRcv, UINT* scH=NULL)=0;			// 패킷을 받을 때

	virtual INT		IsConnect()=0;												// 호스트에 연결되어 있는지..
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


