#ifndef CHESSBASE_H_INCLUDED
#define CHESSBASE_H_INCLUDED

/**
 * 棋盘Util
 * 主要是一些处理函数
 */
class ChessBase
{
private:
    char string[2];//���ڸ�������ת���ַ���
public :
    /**
     * ����
     */
    bool ChessBoardNumber;

	/**
	 * --------���ܺ�������--------
	 */
	//����ת��Ϊ�ַ���
	char* Int2String(int num);
	//����ת��Ϊ�ַ���ʱ�ĸ�������
	void addChar(int mid);
};



#endif // CHESSBASE_H_INCLUDED
