#include "../../AI2_Header/AI2.h"
/**
 * [AI2::AcrossCorners 边角扫描]
 * @return [无]
 */
void AI2::AcrossCorners()
{
    // 轮到本方的时候
    if (PlayerId == turn2Who)
    {
        for (int i = 0;i < 4;i += 3) {
        	ACScan(cornerArray[i]/100,cornerArray[i]%100,
                     cornerArray[i+1]/100,cornerArray[i+1]%100,
                     cornerArray[i+2]/100,cornerArray[i+2]%100);
        }
    }
}

/**
 * [AI2::ACScan 扫描函数，用于判断边角（最边边）是否有棋子]
 * @param line    [边角棋子的行]
 * @param column  [边角棋子的列]
 * @param line1   [边角棋子周围的棋子的行]
 * @param column1 [边角棋子周围的棋子的列]
 * @param line2   [边角棋子周围的棋子的行]
 * @param column2 [边角棋子周围的棋子的列]
 */
void AI2::ACScan(int line,int column,
	int line1,int column1,int line2,int column2)
{
    if (cross[line][column] == noChess) {
    	if ((cross[line1][column1] == isWhite && cross[line2][column2] == isWhite)
    		|| (cross[line1][column1] == isBlack && cross[line2][column2] == isBlack)) {
    		chessScore[line][column] = min;
    	} else if ((cross[line1][column1] == isWhite && cross[line2][column2] == noChess)
    		|| (cross[line1][column1] == isBlack && cross[line2][column2] == noChess)
    		|| (cross[line1][column1] == noChess && cross[line2][column2] == isBlack)
    		|| (cross[line1][column1] == noChess && cross[line2][column2] == isWhite)){
    		addScore(line,column,cornerScore);
    	}
    }// 注意：边角有子无意义
}
