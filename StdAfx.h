
// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__A9DB83DB_A9FD_11D0_BFD1_444553540000__INCLUDED_)
#define AFX_STDAFX_H__A9DB83DB_A9FD_11D0_BFD1_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

# include <windows.h>
# include <string.h>

/// 这里定义宏变量

/// 在PaintChess中使用
#define isPlay1onTurn 1
#define isPlay2onTurn 2
#define isAI1onTurn -1
#define isAI2onTurn -2

/// 定义黑子和白子类型
#define isBlack 1
#define isWhite 2
#define noChess 0

/// 定义方向
#define up 0
#define down 1
#define right 2
#define left 3

// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__A9DB83DB_A9FD_11D0_BFD1_444553540000__INCLUDED_)
