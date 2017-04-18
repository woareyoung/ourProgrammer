#include"../../ChessBoard_Header/ChessBoard.h"
/**
 * [ChessBoard::Int2String 整型转换为字符串]
 * @param  num []
 * @return     []
 */
char* ChessBoard::Int2String(int num)
{
	for(int i = 0; i < 2; i++) string[i] = '\0';
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
	return string;
}
/**
 * [ChessBoard::addChar 整型转换为字符串时的辅助函数]
 * @param mid [description]
 */
void ChessBoard::addChar(int mid)
{
	switch(mid)
	{
	case 9:lstrcat(string, "9");break;
	case 8:lstrcat(string, "8");break;
	case 7:lstrcat(string, "7");break;
	case 6:lstrcat(string, "6");break;
	case 5:lstrcat(string, "5");break;
	case 4:lstrcat(string, "4");break;
	case 3:lstrcat(string, "3");break;
	case 2:lstrcat(string, "2");break;
	case 1:lstrcat(string, "1");break;
	case 0:if(TheFirstNumber == false) lstrcat(string, "0");break;
	}
}
