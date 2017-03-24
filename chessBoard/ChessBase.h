#ifndef CHESSBASE_H_INCLUDED
#define CHESSBASE_H_INCLUDED

/**
 * 棋盘Util
 * 主要是一些处理函数
 */
class ChessBase
{
private:
    char string[2];//用于辅助整型转换字符串
public :
    /**
     * 参数
     */
    bool ChessBoardNumber;

	/**
	 * --------功能函数部分--------
	 */
	//整型转换为字符串
	char* Int2String(int num);
	//整型转换为字符串时的辅助函数
	void addChar(int mid);
};



#endif // CHESSBASE_H_INCLUDED
