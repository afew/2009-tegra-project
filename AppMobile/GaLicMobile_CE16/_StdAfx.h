//
//
////////////////////////////////////////////////////////////////////////////////

#ifndef __StdAfx_H_
#define __StdAfx_H_


#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif


//#pragma comment(linker, "/NODEFAULTLIB:LIBCMTD.lib")
#pragma comment(linker, "/nodefaultlib:oldnames.lib")
#if	_WIN32_WCE
	#pragma comment(lib, "libEGL.lib")
	#pragma comment(lib, "libGLESv2.lib")
#else
	#pragma comment(linker, "/subsystem:console")
	#pragma comment(lib, "libGLES20.lib")
#endif


#if defined(_DEBUG) || defined(DEBUG)
	#pragma comment(lib, "LpBasic_.lib")
	#pragma comment(lib, "LpInput_.lib")
	#pragma comment(lib, "LpDev_.lib")
	#pragma comment(lib, "LpSmd_.lib")
	#pragma comment(lib, "LpEnt_.lib")
	#pragma comment(lib, "LpMdl_.lib")
	#pragma comment(lib, "LpTbl_.lib")
	#pragma comment(lib, "LpmFld_.lib")
#else
	#pragma comment(lib, "LpBasic.lib")
	#pragma comment(lib, "LpInput.lib")
	#pragma comment(lib, "LpDev.lib")
	#pragma comment(lib, "LpSmd.lib")
	#pragma comment(lib, "LpEnt.lib")
	#pragma comment(lib, "LpMdl.lib")
	#pragma comment(lib, "LpTbl.lib")
	#pragma comment(lib, "LpmFld.lib")
#endif


#include <Windows.h>
#include <tchar.h>

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <EGL/egl.h>

#if	_WIN32_WCE
	#include <Lp/LpEuclid.h>
	#include <Lp/LpString.h>
	#include <Lp/LpUtil.h>
	#include <Lp/ILpInput.h>

	#include <Lp/ILpDev.h>
	#include <Lp/ILpDevGL.h>
	#include <Lp/ILpSprite.h>
	#include <Lp/ILpTex.h>
	#include <Lp/ILpFont.h>
	#include <Lp/ILpEffect.h>
	#include <Lp/ILpSmd.h>
	#include <Lp/ILpEnt.h>
	#include <Lp/ILpCam.h>
	#include <Lp/ILpMdl.h>
	#include <Lp/ILpTbl.h>
	#include <Lp/ILpmFld.h>
#else
	#include "08LpBasic/LpEuclid.h"
	#include "08LpBasic/LpString.h"
	#include "08LpBasic/LpUtil.h"
	#include "08LpInput/ILpInput.h"
	#include "10LpDev/ILpSys.h"

	#include "10LpDev/ILpDevGL.h"
	#include "10LpDev/ILpSprite.h"
	#include "10LpDev/ILpTex.h"
	#include "10LpDev/ILpFont.h"
	#include "10LpDev/ILpEffect.h"
	#include "11LpSmd/ILpSmd.h"
	#include "12LpEnt/ILpEnt.h"
	#include "12LpEnt/ILpCam.h"
	#include "14LpMdl/ILpMdl.h"
	#include "28LpTbl/ILpTbl.h"
	#include "31LpxField/ILcxmFld.h"
#endif


#include "resource.h"
#include "LpApp.h"




#include "Main.h"


#endif


