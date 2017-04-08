#ifndef CHESSBASE_H_INCLUDED
#define CHESSBASE_H_INCLUDED

/**
 * æ£‹ç›˜Util
 * ä¸»è¦æ˜¯ä¸€äº›å¤„ç†å‡½æ•°
 */
class ChessBase
{
private:
    char string[2];//ÓÃÓÚ¸¨ÖúÕûĞÍ×ª»»×Ö·û´®
public :
    /**
     * ²ÎÊı
     */
    bool ChessBoardNumber;

	/**
	 * --------¹¦ÄÜº¯Êı²¿·Ö--------
	 */
	//ÕûĞÍ×ª»»Îª×Ö·û´®
	char* Int2String(int num);
	//ÕûĞÍ×ª»»Îª×Ö·û´®Ê±µÄ¸¨Öúº¯Êı
	void addChar(int mid);
};



#endif // CHESSBASE_H_INCLUDED
