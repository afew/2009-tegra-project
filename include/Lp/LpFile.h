// interface for the LpUtilFile Files.
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _LpUtilFile_H_
#define _LpUtilFile_H_


#pragma warning( disable : 4786)
#pragma warning( disable : 4996)

#include <string>
#include <vector>

#include <windows.h>



DWORD	LpFile_Err();
void	LpFile_Err(DWORD dError);

INT		LpFile_FileFind(char* sFile);
long	LpFile_FileSize(FILE* &fp);												// Get File Size


// For WinAPI File Management From C Style Functions
HANDLE	LpFile_fopen(char* sFile, char* sT);									// Fail: return INVALID_HANDLE_VALUE, append Mode일 경우 파일 포인터는 마지막에 있다.
INT		LpFile_fclose(HANDLE hFile);
DWORD	LpFile_fsize(HANDLE hFile);

INT		LpFile_fread(HANDLE hFile, void* p, INT bufSize, INT nCount=1);
INT		LpFile_fwrite(HANDLE hFile, void* p, INT bufSize, INT nCount=1);
INT		LpFile_fprintf(HANDLE hFile, char *format,...);
INT		LpFile_fgets(HANDLE hFile, char* sLine, int iMax, BOOL bFillEndLineZero=TRUE);
DWORD	LpFile_fseek(HANDLE hFile, LONG lOff, DWORD nFrom=FILE_BEGIN /*FILE_BEGIN, FILE_CURRENT, FILE_END*/);
DWORD	LpFile_fseekBegin(HANDLE hFile);
DWORD	LpFile_fseekEnd(HANDLE hFile);

void	LpFile_fsetLength(HANDLE hFile, DWORD dwNewLen);
DWORD	LpFile_fsetLength(HANDLE hFile);

DWORD	LpFile_ftell(HANDLE hFile);
BOOL	LpFile_feof(HANDLE hFile=INVALID_HANDLE_VALUE);							// return EOF is TRUE, others FALSE

void	LpFile_ReadFileLineH(HANDLE hFile, char* sLine);
void	LpFile_ReadFileLineF(FILE *fp, char* sLine);


#endif


