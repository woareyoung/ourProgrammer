
#include "../stdafx.h"
#include "../chessBoard/ChessBase.h"
/**
 * [ChessBase::Int2String 整型转换为字符串]
 * @param  num []
 * @return     []
 */
char* ChessBase::Int2String(int num)
{
	for(int i = 0; i < 2; i++) str[i] = NULL;
	int mid;
	if(num > 100 || num == 100)
	{
		mid = num / 100;
		addChar(mid);
		mid = (num % 100) / 10;
		addChar(mid);
	}
	else if(num < 100)
	{
		mid = num / 10;
		addChar(mid);
	}
	mid = num % 10;
	addChar(mid);
	return str;
}
/**
 * [ChessBoard::addChar 整型转换为字符串时的辅助函数]
 * @param mid [description]
 */
void ChessBase::addChar(int mid)
{
	switch(mid)
	{
	case 9:lstrcat(str, "9");break;
	case 8:lstrcat(str, "8");break;
	case 7:lstrcat(str, "7");break;
	case 6:lstrcat(str, "6");break;
	case 5:lstrcat(str, "5");break;
	case 4:lstrcat(str, "4");break;
	case 3:lstrcat(str, "3");break;
	case 2:lstrcat(str, "2");break;
	case 1:lstrcat(str, "1");break;
	case 0:if(ChessBoardNumber == false) lstrcat(str, "0");break;
	}
}
