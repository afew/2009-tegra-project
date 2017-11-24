// Interface for the LpUtil functions.
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _LpUtil_H_
#define _LpUtil_H_


#pragma warning( disable : 4005)
#pragma warning( disable : 4786)
#pragma warning( disable : 4996)

#include <string>
#include <vector>

//	For Using SHGetSpecialFolderPath()
//	Defined ShlObj.h
//	#define CSIDL_DESKTOP                   0x0000
//	#define CSIDL_INTERNET                  0x0001
//	#define CSIDL_PROGRAMS                  0x0002
//	#define CSIDL_CONTROLS                  0x0003
//	#define CSIDL_PRINTERS                  0x0004
//	#define CSIDL_PERSONAL                  0x0005
//	#define CSIDL_FAVORITES                 0x0006
//	#define CSIDL_STARTUP                   0x0007
//	#define CSIDL_RECENT                    0x0008
//	#define CSIDL_SENDTO                    0x0009
//	#define CSIDL_BITBUCKET                 0x000a
//	#define CSIDL_STARTMENU                 0x000b
//	#define CSIDL_DESKTOPDIRECTORY          0x0010
//	#define CSIDL_DRIVES                    0x0011
//	#define CSIDL_NETWORK                   0x0012
//	#define CSIDL_NETHOOD                   0x0013
//	#define CSIDL_FONTS                     0x0014
//	#define CSIDL_TEMPLATES                 0x0015
//	#define CSIDL_COMMON_STARTMENU          0x0016
//	#define CSIDL_COMMON_PROGRAMS           0X0017
//	#define CSIDL_COMMON_STARTUP            0x0018
//	#define CSIDL_COMMON_DESKTOPDIRECTORY   0x0019
//	#define CSIDL_APPDATA                   0x001a
//	#define CSIDL_PRINTHOOD                 0x001b
//	#define CSIDL_ALTSTARTUP                0x001d
//	#define CSIDL_COMMON_ALTSTARTUP         0x001e
//	#define CSIDL_COMMON_FAVORITES          0x001f
//	#define CSIDL_INTERNET_CACHE            0x0020
//	#define CSIDL_COOKIES                   0x0021
//	#define CSIDL_HISTORY                   0x0022

// Not defined. So U'll make it.
#define CSIDL_COMMON_DESKTOPDIRECTORY	0x0019
#define CSIDL_LOCAL_APPDATA				0x001C

#define CSIDL_INTERNET_CACHE			0x0020
#define CSIDL_COOKIES					0x0021
#define CSIDL_HISTORY					0x0022
#define CSIDL_COMMON_APPDATA			0x0023
#define CSIDL_WINDOWS					0x0024
#define CSIDL_SYSTEM					0x0025
#define CSIDL_PROGRAM_FILES				0x0026
#define CSIDL_MYPICTURES				0x0027
#define CSIDL_PROFILE					0x0028
#define CSIDL_SYSTEMX86					0x0029
#define CSIDL_PROGRAM_FILESX86			0x002A
#define CSIDL_PROGRAM_FILES_COMMON		0x002B
#define CSIDL_PROGRAM_FILES_COMMONX86	0x002C
#define CSIDL_COMMON_TEMPLATES			0x002D
#define CSIDL_COMMON_DOCUMENTS			0x002E
#define CSIDL_COMMON_ADMINTOOLS			0x002F



// Not defined Virtual Keys. So U'll make it.
// - on main keyboard
#define VK_MINUS		0xBD
#define VK_EQUALS		0xBB
#define VK_BACKSLASH	0xDC

#define VK_LBRACKET		0xDB
#define VK_RBRACKET		0xDD

#define VK_SEMICOLON	0xBA
#define VK_APOSTROPHE	0xDE

#define VK_COMMA		0xBC

// . on main keyboard
#define VK_PERIOD		0xBE
#define VK_SLASH		0xBF

// Print Screen
#define VK_SYSRQ		VK_SNAPSHOT
#define VK_GRAVE		VK_SELECT

#define VK_0			0x30
#define VK_1			0x31
#define VK_2			0x32
#define VK_3			0x33
#define VK_4			0x34
#define VK_5			0x35
#define VK_6			0x36
#define VK_7			0x37
#define VK_8			0x38
#define VK_9			0x39

#define VK_A			0x41
#define VK_B			0x42
#define VK_C			0x43
#define VK_D			0x44
#define VK_E			0x45
#define VK_F			0x46
#define VK_G			0x47

#define VK_H			0x48
#define VK_I			0x49
#define VK_J			0x4A
#define VK_K			0x4B
#define VK_L			0x4C
#define VK_M			0x4D
#define VK_N			0x4E

#define VK_O			0x4F
#define VK_P			0x50
#define VK_Q			0x51
#define VK_R			0x52
#define VK_S			0x53
#define VK_T			0x54
#define VK_U			0x55
#define VK_V			0x56
#define VK_W			0x57
#define VK_X			0x58
#define VK_Y			0x59
#define VK_Z			0x5A


#include <windows.h>
#include <shellapi.h>
#include <shlobj.h>


#ifndef ONE_RADtoDEG
#	define ONE_RADtoDEG	57.295779513082321f
#endif

#ifndef ONE_DEGtoRAD
#	define ONE_DEGtoRAD	0.0174532925199433f
#endif

#ifndef PI_RAD
#	define PI_RAD		3.1415926535897932f
#endif

#ifndef DEG90toRAD
#	define DEG90toRAD	1.5707963267948966f
#endif

#ifndef RADtoDEG
#	define RADtoDEG(p) ( (p)*ONE_RADtoDEG)
#endif

#ifndef DEGtoRAD
#	define DEGtoRAD(p) ( (p)*ONE_DEGtoRAD)
#endif


#ifndef LC_ROUNDING_DELTA
#	define LC_ROUNDING_DELTA	0.0001f
#endif


#ifndef LC_ARRAY_SIZE
#	define LC_ARRAY_SIZE(p) sizeof(p)/sizeof((p)[0])
#endif

#ifndef LC_DEBUG_BREAK
#	define LC_DEBUG_BREAK(LC_CONDITION){ if(LC_CONDITION){ _asm int 3 } }
#endif



#define	SAFE_FREE(p)	{ if(p) { free(p);		(p)=NULL; } }

#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)	{	if(p){(p)->Release();p = NULL;	}}
#endif

#ifndef SAFE_DELETE
#define SAFE_DELETE(p)	{	if(p){delete (p);p = NULL;	}}
#endif

#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p){	if(p){delete [] (p);p = NULL;	}}
#endif



#define SAFE_NEW(p, CLASSTYPE)												\
{																			\
	if(NULL == (p))															\
	{																		\
		p = new CLASSTYPE;													\
	}																		\
}


#define _SAFE_NEWINIT(p, CLASSTYPE)											\
{																			\
	if(NULL == (p))															\
	{																		\
		p = new CLASSTYPE;													\
		if(!(p))	{	return;		}										\
		if(FAILED(((CLASSTYPE *)p)->Init())) { delete p; p = 0; return; }	\
	}																		\
}


#define SAFE_NEWINIT(p, CLASSTYPE)											\
{																			\
	if(0 == (p))															\
	{																		\
		p = new CLASSTYPE;													\
		if(!(p))	{	return -1;	}										\
																			\
		if(FAILED(((CLASSTYPE *)p)->Init()))								\
		{																	\
			delete p; p = 0; return -1;										\
		}																	\
	}																		\
}


#define SAFE_NEWCREATE1(p, CLASSTYPE, P1)									\
{																			\
	if(0 == (p))															\
	{																		\
		p = new CLASSTYPE;													\
		if(!(p))	{	return -1;	}										\
																			\
		if(FAILED(((CLASSTYPE *)p)->Create(P1)))							\
		{																	\
			delete p; p=0; return -1;										\
		}																	\
	}																		\
}


#define SAFE_NEWCREATE2(p, CLASSTYPE, P1, P2)								\
{																			\
	if(0 == (p))															\
	{																		\
		p = new CLASSTYPE;													\
		if(!(p))	{	return -1;	}										\
																			\
		if(FAILED(((CLASSTYPE *)p)->Create(P1, P2)))						\
		{																	\
			delete p; p=0; return -1;										\
		}																	\
	}																		\
}


#define SAFE_NEWCREATE3(p, CLASSTYPE, P1, P2, P3)							\
{																			\
	if(0 == (p))															\
	{																		\
		p = new CLASSTYPE;													\
		if(!(p))	{	return -1;	}										\
																			\
		if(FAILED(((CLASSTYPE *)p)->Create(P1, P2, P3)))					\
		{																	\
			delete p; p=0; return -1;										\
		}																	\
	}																		\
}


#define SAFE_NEWCREATE4(p, CLASSTYPE, P1, P2, P3, P4)						\
{																			\
	if(0 == (p))															\
	{																		\
		p = new CLASSTYPE;													\
		if(!(p))	{	return -1;	}										\
																			\
		if(FAILED(((CLASSTYPE *)p)->Create(P1, P2, P3, P4)))				\
		{																	\
			delete p; p=0; return -1;										\
		}																	\
	}																		\
}



#define _SAFE_NEWCREATE1(p, CLASSTYPE, P1)									\
{																			\
	if(0 == (p))															\
	{																		\
		p = new CLASSTYPE;													\
																			\
		if((p))																\
		{																	\
			if(FAILED(((CLASSTYPE *)p)->Create(P1)))						\
			{																\
				delete p; p=0;												\
			}																\
		}																	\
	}																		\
}



#define _SAFE_NEWCREATE2(p, CLASSTYPE, P1, P2)								\
{																			\
	if(0 == (p))															\
	{																		\
		p = new CLASSTYPE;													\
																			\
		if((p))																\
		{																	\
			if(FAILED(((CLASSTYPE *)p)->Create( P1, P2)))					\
			{																\
				delete p; p=0;												\
			}																\
		}																	\
	}																		\
}


#define _SAFE_NEWCREATE3(p, CLASSTYPE, P1, P2, P3)							\
{																			\
	if(0 == (p))															\
	{																		\
		p = new CLASSTYPE;													\
																			\
		if((p))																\
		{																	\
			if(FAILED(((CLASSTYPE *)p)->Create( P1, P2, P3)))				\
			{																\
				delete p; p=0;												\
			}																\
		}																	\
	}																		\
}


#define _SAFE_NEWCREATE4(p, CLASSTYPE, P1, P2, P3, P4)						\
{																			\
	if(0 == (p))															\
	{																		\
		p = new CLASSTYPE;													\
																			\
		if((p))																\
		{																	\
			if(FAILED(((CLASSTYPE *)p)->Create( P1, P2, P3, P4)))			\
			{																\
				delete p; p=0;												\
			}																\
		}																	\
	}																		\
}



#define SAFE_RESTORE(p)	{ if(p){ if(FAILED((p)->Restore())){ return -1;	}}}
#define SAFE_FRMOV(p)	{ if(p){ if(FAILED((p)->FrameMove())){return -1;}}}
#define SAFE_UPDATE(p)	{ if(p){ if(FAILED((p)->Update())){ return -1;	}}}

#define SAFE_DESTROY(p)	{ if(p){(p)->Destroy();			}}
#define SAFE_INVALID(p)	{ if(p){(p)->Invalidate();		}}
#define SAFE_RENDER(p)	{ if(p){(p)->Render();			}}
#define SAFE_RENDERS(p)	{ if(p){(p)->RenderS();			}}

#define SAFE_ONFRMMOV(p){ if(p){(p)->OnFrmMov();		}}
#define SAFE_ONRENDER(p){ if(p){(p)->OnRender();		}}


#define	SAFE_DESTROY_WIN(p){ if(p){DestroyWindow(p);	}}



#define SAFE_DEL_OBJ_ARRAY(p, iSIZE)										\
{																			\
	int i_IDX_OBJ_=0;														\
																			\
	for(i_IDX_OBJ_=0; i_IDX_OBJ_ < (iSIZE) ; ++i_IDX_OBJ_)					\
	{																		\
		if(p[i_IDX_OBJ_])													\
		{																	\
			DeleteObject( p[i_IDX_OBJ_] );									\
			p[i_IDX_OBJ_] = NULL;											\
		}																	\
	}																		\
}


// Vector delete all in list
#define SAFE_DEL_LST(p)															\
{																				\
	if(!p.empty())																\
	{																			\
		int iSizeList##p = p.size();											\
		for(int indexList##p=0; indexList##p < iSizeList##p ; ++indexList##p )	\
		{																		\
			if( p[ indexList##p ]	)											\
				delete p[ indexList##p ];										\
																				\
			p[ indexList##p ] = NULL;											\
		}																		\
		p.clear();																\
	}																			\
}



// Vector delete [] all in list
#define SAFE_DEL_ARR_LST(p)														\
{																				\
	if(!p.empty())																\
	{																			\
		int iSizeList##p = p.size();											\
		for(int indexList##p=0; indexList##p < iSizeList##p ; ++indexList##p )	\
		{																		\
			if( p[ indexList##p ]	)											\
				delete [] p[ indexList##p ];									\
																				\
			p[ indexList##p ] = NULL;											\
		}																		\
		p.clear();																\
	}																			\
}



#define SAFE_ERASE_PT(p, nIdx, ITERATOR)										\
{																				\
	ITERATOR ITERATOR##_it = p.begin() + nIdx;									\
	SAFE_DELETE( (* ITERATOR##_it) );											\
																				\
	p.erase((ITERATOR##_it));													\
}



#define  SAFE_DELETE_ARRAY2(p, iSize)											\
{																				\
	if(p)																		\
	{																			\
		for(int iSizeList##p = 0;  iSizeList##p < iSize; ++iSizeList##p )		\
		{																		\
			if( p[ iSizeList##p ]	)											\
				delete [] ( p[ iSizeList##p ]	);								\
																				\
			p[ iSizeList##p ] = NULL;											\
		}																		\
																				\
		delete [] (p);															\
		(p) = NULL;																\
	}																			\
}


#define  SAFE_RELEASE_ARRAY(p, iSize)											\
{																				\
	if(p)																		\
	{																			\
		for(int iSizeList##p = 0;  iSizeList##p < iSize; ++iSizeList##p )		\
		{																		\
			if( p[ iSizeList##p ]	)											\
				(p[ iSizeList##p ])->Release();									\
																				\
			p[ iSizeList##p ] = NULL;											\
		}																		\
																				\
		delete [] (p);															\
		(p) = NULL;																\
	}																			\
}


// Release Vector
#define  SAFE_RELEASE_LST(p)													\
{																				\
	if(!p.empty())																\
	{																			\
		int iSizeList##p = p.size();											\
		for(int indexList##p=0; indexList##p < iSizeList##p ; ++indexList##p )	\
		{																		\
			if( p[ indexList##p ]	)											\
				(p[ indexList##p ])->Release();									\
																				\
			p[ indexList##p ] = NULL;											\
		}																		\
																				\
		p.clear();																\
	}																			\
}



// Vector delete [] all in list
#define SAFE_DEL_ARR_LST(p)														\
{																				\
	if(!p.empty())																\
	{																			\
		int iSizeList##p = p.size();											\
		for(int indexList##p=0; indexList##p < iSizeList##p ; ++indexList##p )	\
		{																		\
			if( p[ indexList##p ]	)											\
				delete [] p[ indexList##p ];									\
																				\
			p[ indexList##p ] = NULL;											\
		}																		\
		p.clear();																\
	}																			\
}



// Vector FrameMove
#define SAFE_FRMOV_LST(p)											\
{																	\
	if(!p.empty())													\
	{																\
		int iSizeList = p.size();									\
		for(int indexList=0; indexList<iSizeList; ++indexList)		\
		{															\
			SAFE_FRMOV(p[indexList]);								\
		}															\
	}																\
}

// Vector Rendering
#define SAFE_REN_LST(p)												\
{																	\
	if(!p.empty())													\
	{																\
		int iSizeList = p.size();									\
		for(int indexList=0; indexList<iSizeList; ++indexList)		\
		{															\
			SAFE_RENDER(p[indexList]);								\
		}															\
	}																\
}




#define CLASS_DESTROY(CLASS_NAME)									\
CLASS_NAME::~CLASS_NAME()											\
{																	\
	Destroy();														\
}



#define CLASS_CLEAN_ALL(CLASS_NAME)									\
CLASS_NAME::~CLASS_NAME()											\
{																	\
	Invalidate();													\
	Destroy();														\
}




#define	GAME_LOOP_FR(	PhaseName	)								\
INT CMain::OnFrm##PhaseName ()										\
{																	\
	strcat(m_sMsg, " " #PhaseName "");								\
	SAFE_FRMOV(	m_pGm##PhaseName	);								\
	return 0;														\
}																	\
																	\
void CMain::OnRnd##PhaseName ()										\
{																	\
	SAFE_RENDER(	m_pGm##PhaseName	);							\
}																	\
																	\
void CMain::OnRns##PhaseName ()										\
{																	\
	SAFE_RENDERS(	m_pGm##PhaseName	);							\
}



#define CLSS_DLG_DECLEAR(CLASS)											\
CLASS ();																\
virtual ~CLASS ();														\
static INT_PTR	CLASS##WndPrc (HWND hW, UINT uM, WPARAM wP, LPARAM lP);

#define CLSS_DLG_DEFINE(CLASS, MSGPROC)									\
static CLASS*	g_pWndDialog##CLASS;									\
INT_PTR CLASS :: CLASS##WndPrc (HWND hW, UINT uM, WPARAM wP, LPARAM lP)	\
{																		\
	return (g_pWndDialog##CLASS)-> MSGPROC (hW, uM, wP, lP);			\
}																		\
																		\
CLASS :: CLASS ()		{	g_pWndDialog##CLASS = this;	Init();	}		\
CLASS:: ~ CLASS (){}

#define CLSS_DLG_WNDPROC( CLASS )	(LPDLGPROC)((CLASS##WndPrc))





void	LpUtil_ControlInit();

void	LpUtil_MessageBox(HWND hWnd , char* sText, char* sCaption, UINT uType);
void	LpUtil_ErrMsgBox(char *format,...);
void	LpUtil_GetLastError(HWND hWnd=NULL);

void	LpUtil_SetWindowTitle(HWND hWnd, const char *format, ...);

DOUBLE	LpUtil_TimeGetTime();			// return Second After Program start..( 0.001 * timeGetTime())

char*	LpUtil_GetSmallTime();


void	LpUtil_TextOut(HDC hDC, float x, float y, DWORD color, const char *format, ...);
void	LpUtil_OutputDebug(const char *Format, ...);


DWORD	LpUtil_VectorToRGB(FLOAT* NormalVector);


inline DWORD	FtoDW(FLOAT v)			{ return *((DWORD*)&v); }
inline DWORD	LpUtil_FtoDW(FLOAT v)	{ return *((DWORD*)&v); }

inline FLOAT	DWtoF(DWORD v)			{ return *((FLOAT*)&v); }
inline FLOAT	LpUtil_DWtoF(DWORD v)	{ return *((FLOAT*)&v); }
#define FLOATP(p)	((FLOAT*)&(p))



void	LpUtil_GetFullPath(TCHAR* stPath, const char* sFile);
void	LpUtil_GetModulePath(TCHAR* sPath, int MaxPath=MAX_PATH);

void	LpUtil_MemoryCheckSet();												// Used Memory Set
DWORD	LpUtil_MemoryCheckGet();												// Used Memory Get

void	LpUtil_RandSet(DWORD dSeed=0);											// rand seed set: if dSeed = 0 , It calls timeGetTime()

FLOAT	LpUtil_GetLinearWg(FLOAT f1,FLOAT f2,FLOAT f);							// Linear Interpolation


DWORD	LpUtil_GetFileVersion();

INT		LpUtil_GetWindowsVersion(OSVERSIONINFO* pVer);							// Windows version
void	LpUtil_GetWindowsInfo(SYSTEM_INFO* pSys);								// Windows Information
void	LpUtil_GetClientRect(HWND hWnd, RECT* rc);								// Client Widow RECT Information. rc: widdow Rect PosX, PosY, Window Width, Height



// for Test...
void	LpUtil_Rectangle(HDC hDC,INT x0,INT y0,INT x1,INT y1,DWORD color=RGB(255,255,255));


// ARGB <--> BGR
//
BYTE*	LpUtil_GetColorFromARGB(DWORD& argb);
BYTE*	LpUtil_GetColorFromBGR(DWORD& argb);



INT		LpUtil_CoInitializeEx(LPVOID pvReserved=NULL, DWORD dwCoInit =COINIT_APARTMENTTHREADED);
void	LpUtil_CoUninitialize();




INT	LpUtil_MemoryLoadFromResource(												// Memory Load from Resource. return value Success:1 Fail:-1
									void** pOut									// You must be free pOut
								  , INT* iSize									// pOut Size
								  , INT nResourceId
								  , const TCHAR* sType);










template<class T>
UINT LpUtil_Vector4fCount(const T &t)
{
	return sizeof(t)/sizeof(VEC4);
}








// for memory

template<class T>
void LpUtil_Calloc(T* &p, INT count)
{
	INT		iSize = sizeof(*p);
	p = (T*) malloc(count * iSize);
	memset(p, 0, count * sizeof(*p));
}


template<class T>
void LpUtil_Malloc(T* &p, INT count)
{
	INT		iSize = sizeof(*p);
	p = (T*) malloc(count * iSize);
}


template<class T>
void LpUtil_Free(T* &p)
{
	if(p)
	{
		free(p);
		p = NULL;
	}
}



template<class T>
void LpUtil_Lock(T& pDst, INT nSize, void* pSrc)
{
	void* p;

	if( FAILED( pDst->Lock( 0, 0, &p, 0 )))
		return;

	memcpy(p, pSrc, nSize);
	pDst->Unlock();
}



////////////////////////////////////////////////////////////////////////////////
//
// for sorting
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
struct TsrtG																	// For sort... descendent Sort
{
	BOOL operator()(const T& t1,const T& t2) const	{ return t1.fStlSrtR > t2.fStlSrtR; }
};

template<class T>
struct TsrtGp																	// For sort... ascendent Sort
{
	BOOL operator()(const T& t1,const T& t2) const	{ return t1->fStlSrtR > t2->fStlSrtR; }
};

template<class T>
struct TsrtL																	// For sort... ascendent Sort
{
	BOOL operator()(const T& t1,const T& t2) const	{ return t1.fStlSrtR < t2.fStlSrtR; }
};

template<class T>
struct TsrtLp
{
	BOOL operator()(const T& t1,const T& t2) const	{ return t1->fStlSrtR < t2->fStlSrtR; }
};


template<class T>
struct TsrtGpf																	// For sort... ascendent Sort
{
	BOOL operator()(const T& t1,const T& t2) const
	{
		return t1->GetSortValue() > t2->GetSortValue();
	}
};


template<class T>
struct Tfind																	// For Find
{
	T* c;

	Tfind(T* &_c)
	{
		c=_c;
	}
	BOOL operator()(T* &t) const
	{
		return c->wId == t->wId;
	}

};


template<class T1, class T2> inline
T2 * LpUtil_Find_If(T1 t1, T2* &t2)
{
	T2 ** t;

	t = 0;
	t = find_if(t1.begin(), t1.end(), Tfind<T2>(t2));

	if(t ==t1.end())
		return 0;

	else
		return (*t);
}


template<class T> inline
T LpUtil_Find_Id(T _F, T _L, WORD wId)
{
	for (; _F != _L; ++_F)
	{
		if (wId  == (*_F)->wId)
			return (_F);
	}

	return 0;
}



template<class T>
inline void	LC_MEMSET(T* p, int iSize)
{
	memset( (void*)p, 0, iSize);
}


template<class T>
inline void	LC_MEMCPY(T* p1, T* p2, int iSize)
{
	memcpy( (void*)p1, (void*)p2, iSize);
}




template<class T>
inline INT LpUtil_FindIdxFromLsStr(T& t, TCHAR* s)
{
	int iN =0;
	T::iterator _F= t.begin();
	T::iterator _L= t.end();

	for( ; _F!= _L; ++_F, ++iN)
	{
		if(0==_stricmp(s, (*_F).c_str()))
			return iN;
	}

	return -1;
}




// WIAPi Intem Info
struct TitmInf
{
	INT			nM;
	INT			nS;
	HTREEITEM	hT;

	TitmInf():	nM(-1),	nS(-1),	hT(0){}
	TitmInf(INT M, INT S, HTREEITEM T):	nM(M), nS(S),hT(T){}

	BOOL HasParent()	{	return (nM<0)? FALSE : TRUE;	}

};

typedef std::vector<TitmInf>	lsHItem;
typedef lsHItem::iterator		itHItem;


void	LpUtil_TreeExpand(lsHItem& ls, HWND& hTree, INT iM, INT iS);






////////////////////////////////////////////////////////////////////////////////
//
// Interface for the Tskip class.
//
////////////////////////////////////////////////////////////////////////////////

class Tskip
{
protected:
	INT iB;
	INT iC;
	INT	iS;

public:
	Tskip();
	INT		FrameMove();

	void	SetStep(INT _iS);
	INT		GetStep();

	INT		IsEnd();
	INT		SetStart();
};



////////////////////////////////////////////////////////////////////////////////
//
// For Exec and game play Option...
//
////////////////////////////////////////////////////////////////////////////////

struct TexcInf
{
	TCHAR		sExcPath	[512];
	TCHAR		sVersion	[ 32];
	TCHAR		SvrIP		[ 32];
	TCHAR		SvrPt		[ 32];
	TCHAR		FileFont	[512];

	DWORD		m_dwScnW		;												// Screen Width
	DWORD		m_dwScnH		;												// Screen Height

	FLOAT		m_fSpdMouse		;												// Mouse Speed
	FLOAT		m_fSpdDClick	;												// Doublic Speed
	FLOAT		m_fSpdWheel		;												// Wheel Speed

	FLOAT		m_fLod[10]		;												// Lod Data

	TexcInf();
	FLOAT*		GetLod();
	void		SetLod(FLOAT* pLod);

};




INT		LpUtil_WindowExeName(TCHAR* sName, int nSize);				// Get Execute File Full Name
INT		LpUtil_WindowClassName(HWND hWnd, TCHAR* sName, int nSize);	// Window Class Name
INT		LpUtil_WindowObject(HGDIOBJ hObj, void* pData, int nSize);	// Get Object Info.. FONT, Pen, Brush....
INT		LpUtil_WindowObjectType(HGDIOBJ hObj);						// Get Object Type: PEN: 1, BRUSH: 2, DC: 3, METADC: 4, PAL: 5, FONT: 6, BITMAP: 7, REGION: 8, METAFILE: 9, MEMDC: 10, EXTPEN: 11, ENHMETADC: 12, ENHMETAFILE: 13


#endif




////////////////////////////////////////////////////////////////////////////////
// Windows Version                                                            //
////////////////////////////////////////////////////////////////////////////////
//
//	Windows "Longhorn"		_WIN32_WINNT>=0x0600
//	WINVER>=0x0600
//
//	Windows Server 2003		_WIN32_WINNT>=0x0502
//	WINVER>=0x0502
//
//	Windows XP				_WIN32_WINNT>=0x0501
//	WINVER>=0x0501
//
//	Windows 2000			_WIN32_WINNT>=0x0500
//	WINVER>=0x0500
//
//	Windows NT 4.0			_WIN32_WINNT>=0x0400
//	WINVER>=0x0400
//
//	Windows Me				_WIN32_WINDOWS=0x0500
//	WINVER>=0x0500
//
//	Windows 98				_WIN32_WINDOWS>=0x0410
//	WINVER>=0x0410
//
//	Windows 95				_WIN32_WINDOWS>=0x0400
//	WINVER>=0x0400
//
//	Internet Explorer 7.0				_WIN32_IE>=0x0700
//	Internet Explorer 6.0 SP2			_WIN32_IE>=0x0603
//	Internet Explorer 6.0 SP1			_WIN32_IE>=0x0601
//	Internet Explorer 6.0				_WIN32_IE>=0x0600
//	Internet Explorer 5.5				_WIN32_IE>=0x0550
//	Internet Explorer 5.01				_WIN32_IE>=0x0501
//	Internet Explorer 5.0, 5.0a, 5.0b	_WIN32_IE>=0x0500
//	Internet Explorer 4.01				_WIN32_IE>=0x0401
//	Internet Explorer 4.0				_WIN32_IE>=0x0400
//	Internet Explorer 3.0, 3.01, 3.02	_WIN32_IE>=0x0300
//
////////////////////////////////////////////////////////////////////////////////




