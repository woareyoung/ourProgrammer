#ifndef STDAFX_H_INCLUDED
#define STDAFX_H_INCLUDED

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#include <tchar.h>
#include <windows.h>
#include <conio.h>

/// 在PaintChess中使用
#define isPlay1onTurn 1
#define isPlay2onTurn 2
#define isAI1onTurn -1
#define isAI2onTurn -2

/// 定义黑子和白子类型
#define isBlack 1
#define isWhite 2
#define noChess 0

#endif // STDAFX_H_INCLUDED
