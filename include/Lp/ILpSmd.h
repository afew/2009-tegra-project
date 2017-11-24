// Interface for the ILpSmd class.
// SMD(Sound, Music, Media, DShow)
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _ILpSmd_H_
#define _ILpSmd_H_


#ifndef interface
#define interface struct
#endif


#ifndef LC_CLASS_DESTROYER
#define LC_CLASS_DESTROYER( CLASS_NAME )	\
virtual ~CLASS_NAME(){}
#endif


interface ILpSmd
{
	LC_CLASS_DESTROYER(	ILpSmd	);

	enum EMediaType
	{
		LC_MDAFMT_WAVE_		= 0x0008,	// 0000 0000 1000
		LC_MDAFMT_WAVE_S	= 0x0009,	// 0000 0000 1001
		LC_MDAFMT_WAVE_3	= 0x000A,	// 0000 0000 1010

		LC_MDAFMT_MUSIC_	= 0x0080,	// 0000 1000 0000
		LC_MDAFMT_MUSICW_M	= 0x0081,	// 0000 1000 0001	: Music		Wave
		LC_MDAFMT_MUSICW_S	= 0x0084,	// 0000 1000 0100	: Music		Wave 3D

		LC_MDAFMT_MUSIC_M	= 0x0090,	// 0000 1001 0000
		LC_MDAFMT_MUSIC_3	= 0x00A0,	// 0000 1010 0000

		LC_MDAFMT_SHW_		= 0x0800,	// 1000 0000 0000
		LC_MDAFMT_SHW_MP3	= 0x0900,	// 1001 0000 0000
		LC_MDAFMT_SHW_AVI	= 0x0A00,	// 1010 0000 0000

		LP_MDAFMT_WAVE_		= 0xF008,	// 1111 0000 0000 1000	: PDA Wave
		LP_MDAFMT_WAVE_M	= 0xF009,	// 1111 0000 0000 1001	: PDA Wave		Mono and Stero
		LP_MDAFMT_WAVE_3	= 0xF00C,	// 1111 0000 0000 1100	: PDA 3d		Sound

		LC_MDAFMT_UNKNOWN	= 0xFFFFFFFF,
	};


	virtual INT		Create(void* p1=0, void* p2=0, void* p3=0, void* p4=0)=0;
	virtual void	Destroy()=0;
	virtual INT		FrameMove()=0;
	virtual void	Render()=0;

	virtual INT		Query(char* sCmd, void* pData)=0;

	virtual DWORD	GetType()=0;
	virtual void	Play()=0;
	virtual void	Stop()=0;
	virtual void	Reset()=0;
	virtual void	Pause()=0;
	virtual void	SetVolume(LONG dVol)=0;
	virtual LONG	GetVolume()=0;
	virtual void	SetRepeat(DWORD dRepeat= 0xFFFFFFFF/*INFINITE*/)=0;
	virtual DWORD	GetRepeat()=0;
	virtual DWORD	GetStatus()=0;


	virtual void*	GetTexture()=0;
	virtual INT		GetVideoW()=0;
	virtual INT		GetVideoH()=0;
};


INT		LpSmd_DeviceInit();
void	LpSmd_DeviceClose();


INT LpSmd_Create(char* sCmd
				, ILpSmd** pData
				, void* p1			// Wave File Name
				, void* p2=0		// No Use
				, void* p3=0		// No Use
				, void* p4=0		// No Use
				);



#if	_WIN32_WCE
	#pragma comment(lib, "mmtimer.lib")
#else
	#pragma comment(lib, "winmm.lib")
#endif


#ifdef USE_LP_SDK_LIB

	#if defined(_DEBUG) || defined(DEBUG)
		#pragma comment(lib, "LpSmd_.lib")
	#else
		#pragma comment(lib, "LpSmd.lib")
	#endif

#endif

	
#endif


