#include "../../AI2_Header/isAI2.h"
/**
 * [isAI2::AcrossCorners 边角扫描]
 * @return [无]
 */
void isAI2::AcrossCorners()
{
    // 轮到本方的时候
    //if (PlayerId == turn2Who)
    {
        for (int i = 0;i < 4;i += 3) {
            ACScan(cornerArray[i]/100,cornerArray[i]%100,
                     cornerArray[i+1]/100,cornerArray[i+1]%100,
                     cornerArray[i+2]/100,cornerArray[i+2]%100);
        }
    }
}

/**
 * [isAI2::ACScan 扫描函数，用于判断边角（最边边）是否有棋子]
 * @param line    [边角棋子的行]
 * @param column  [边角棋子的列]
 * @param line1   [边角棋子周围的棋子的行]
 * @param column1 [边角棋子周围的棋子的列]
 * @param line2   [边角棋子周围的棋子的行]
 * @param column2 [边角棋子周围的棋子的列]
 */
void isAI2::ACScan(int line,int column,
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

/**
 * [isAI2::addScore 边角加分]
 * @param line   [行]
 * @param column [列]
 * @param score  [分数]
 */
void isAI2::addScore(int line,int column, int score)
{
    if (line - 1 > 0)
    {
        chessScore[line - 1][column] += score;
    }
    if (column + 1 < 10)
    {
        chessScore[line][column + 1] += score;
    }
    if (line + 1 < 10)
    {
        chessScore[line + 1][column] += score;
    }
    if (column - 1 > 0)
    {
        chessScore[line][column - 1] += score;
    }
}
