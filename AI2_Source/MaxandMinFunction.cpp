#include "../AI2_Header/AI2.h"
/**
 * 这一个类主要是实现AI2的主要算法Max、Min算法的
 */

int AI2::Evaluation()
{

}

void AI2::initDataFromArray()
{

}

void AI2::MaxAndMin()
{

}

void AI2::Scan(int cross[10][10], bool Cross[10][10])
{

}

void AI2::GetPosition(int& line,int& column,int player, int rival,int isExist[10][10], bool chessStatus[10][10])
{
    copyArray(isExist,chessStatus);
    turn2Who = player;
}

void AI2::Score()
{

}

/**
 * [AI2::isBesieged 判断是否被包围了]
 * @param  RivalLine   [当前准备着子的位置的行]
 * @param  RivalColumn [当前准备着子的位置的列]
 * @param  onTurn      [轮到谁，参数可以在PlayerInfo.h中查看]
 * @return             [是否被包围，被包围就返回true，没有被包围就返回false]
 */
bool AI2::isBesieged(int RivalLine, int RivalColumn, int player, int rival)
{

}

void AI2::copyArray(int isExist[10][10], bool chessStatus[10][10])
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
