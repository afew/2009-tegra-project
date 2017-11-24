// Interface for the LpString functions.
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _LpString_H_
#define _LpString_H_


#pragma warning( disable : 4786)
#pragma warning( disable : 4996)


#include <vector>


#if _MSC_VER < 2200
// 이부분은 6.0과 구분해서 사용해야함
#include <string>

#else

#include <string>

#endif





char*	LpStr_Format(const char *format, ...);									// String Formating. Like a sprintf

void	LpStr_ReadLineQuot(char *strOut, char *strIn, INT iC='\"');
char*	LpStr_GetWord(char* s, INT nIdx);										// Get Word from 1 or 2 Byte code
char*	LpStr_DWtoStr(DWORD dwA);

void	LpStr_StrList(															// Token Seperator
					  std::vector<std::string>& vStr
					  , char* sIn
					  , char* sSpes=" ,\t/\'\"\\\n");


char*	LpStr_EnumValueQuotation(char* sVal, char* s, INT ch='\"');

void	LpStr_Replace(char* sInOut, INT origin, INT dest);						// To Replace origin to dest in string sInOut.
void	LpStr_Replaces(char* sInOut, const char* origin, INT count, INT dest);	// To Replace origin to dest in string sInOut.


INT		LpStr_Sgets(const char* sSrc, char* sLine, INT iMax, BOOL bFillEndLineZero=TRUE);


INT		vsscanf(const char* sBuf, const char* format, va_list ap);
INT		LpStr_Scanf(char* sBuf, char* format, ...);								// if Failed then returned -1. succeeded then returned Argument count.

INT		LpStr_AnsiToUnicode(WCHAR* sDst, const char* sSrc, INT iLen );			// ANSI to UNICODE
INT		LpStr_UnicodeToAnsi(char* sDst, const WCHAR* sSrc, INT iLen );			// UNICODE to ANSI

void	LcStr_SplitPath(const char *path,char *drive,char *dir,char *fname,char *ext);

#endif


