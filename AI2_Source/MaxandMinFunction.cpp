#include "../AI2_Header/isAI2.h"
#include <stdlib.h>
/**
 * 这一个类主要是实现isAI2的主要算法Max、Min算法的
 */

int isAI2::Evaluation()
{
    AcrossCorners();
    Tirangle();
    CrossShaped();
}

void isAI2::initDataFromArray()
{

}

void isAI2::MaxAndMin(int& line,int& column)
{
    int temp = chessScore[1][1];
    int tempLine = 1;
    int tempColumn = 1;
    for (int i = 1;i < 10;i++) {
        for (int j = 1;j < 10;j++) {
            if (chessScore[i][j] > temp) {
                temp = chessScore[i][j];
                tempLine = i;
                tempColumn = j;
            }
        }
    }
    line = tempLine;
    column = tempColumn;
}

void isAI2::GetPosition(int& line,int& column,int player,
                         int isExist[10][10], bool chessStatus[10][10])
{
    copyArray(isExist, chessStatus);
    turn2Who = player;
//    initChessScore();
//    Evaluation();
//    MaxAndMin(line,column);
    int temp = maxandmin(5);
    line = temp/100;
    column = temp%100;
}

void isAI2::Score()
{

}

/**
 * [isAI2::isBesieged 判断是否被包围了]
 * @param  RivalLine   [当前准备着子的位置的行]
 * @param  RivalColumn [当前准备着子的位置的列]
 * @param  onTurn      [轮到谁，参数可以在PlayerInfo.h中查看]
 * @return             [是否被包围，被包围就返回true，没有被包围就返回false]
 */
bool isAI2::isBesieged(int RivalLine, int RivalColumn, int player, int rival)
{
    return true;
}

void isAI2::copyArray(int isExist[10][10], bool chessStatus[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            this->cross[i][j] = isExist[i][j];
            this->Cross[i][j] = chessStatus[i][j];
        }
    }
}

void isAI2::initChessScore()
{
    int temp[10][10] =
    {
        {0,0,0,0,0,0,0,0,0,0},
        {0,1,1,1,1,1,1,1,1,1},
        {0,1,2,2,2,2,2,2,2,1},
        {0,1,2,3,3,3,3,3,2,1},
        {0,1,2,3,4,4,4,3,2,1},
        {0,1,2,3,4,5,4,3,2,1},
        {0,1,2,3,4,4,4,3,2,1},
        {0,1,2,3,3,3,3,3,2,1},
        {0,1,2,2,2,2,2,2,2,1},
        {0,1,1,1,1,1,1,1,1,1}
    };
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            chessScore[i][j] = temp[i][j];
        }

    }
}
