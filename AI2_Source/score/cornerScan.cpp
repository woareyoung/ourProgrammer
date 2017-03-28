#include "../../AI2_Header/isAI2.h"
/**
 * [isAI2::AcrossCorners �߽�ɨ��]
 * @return [��]
 */
void isAI2::AcrossCorners()
{
    // �ֵ�������ʱ��
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
 * [isAI2::ACScan ɨ�躯���������жϱ߽ǣ���߱ߣ��Ƿ�������]
 * @param line    [�߽����ӵ���]
 * @param column  [�߽����ӵ���]
 * @param line1   [�߽�������Χ�����ӵ���]
 * @param column1 [�߽�������Χ�����ӵ���]
 * @param line2   [�߽�������Χ�����ӵ���]
 * @param column2 [�߽�������Χ�����ӵ���]
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
    }// ע�⣺�߽�����������
}

/**
 * [isAI2::addScore �߽Ǽӷ�]
 * @param line   [��]
 * @param column [��]
 * @param score  [����]
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
