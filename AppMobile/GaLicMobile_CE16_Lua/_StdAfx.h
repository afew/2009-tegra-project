//
//
////////////////////////////////////////////////////////////////////////////////

#ifndef __StdAfx_H_
#define __StdAfx_H_


#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif


#define	USE_LP_SDK_LIB



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
	#pragma comment(lib, "LpLua_.lib")
#else
	#pragma comment(lib, "LpBasic.lib")
	#pragma comment(lib, "LpLua.lib")
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
	#include <Lp/ILppData.h>
	#include <Lp/ILppObj.h>
	
	#include <LpLua/Lua.h>
	#include <LpLua/Lualib.h>
	#include <LpLua/Lauxlib.h>

	#include <LpLsc/ILpLsc.h>
	#include <LpLsc/LscSys.h>				// Lua System
	#include <LpLsc/LscUtil.h>				// Lua Utilities
	#include <LpLsc/LscInput.h>				// Lua Input Class
	#include <LpLsc/LscFont.h>				// Lua Font Class
	#include <LpLsc/LscTex.h>				// Lua Texture Class
	#include <LpLsc/LscSmd.h>				// Lua Sound Class
	#include <LpLsc/LscEnt.h>				// Lua Entity Class

	#include <LpLsc/LspMdl.h>				// Lua Model Class
	#include <LpLsc/LspMap.h>				// Lua Map Class
	#include <LpLsc/LspObj.h>				// Lua Game Object class
#endif


#include "resource.h"
#include "LpApp.h"

#include "GmPhase.h"




#include "Main.h"


#endif


