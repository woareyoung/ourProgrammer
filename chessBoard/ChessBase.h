#ifndef CHESSBASE_H_INCLUDED
#define CHESSBASE_H_INCLUDED

/**
 * ����Util
 * ��Ҫ��һЩ������
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
