#include "../AI2_Header/AI2.h"
/**
 * ��һ������Ҫ��ʵ��AI2����Ҫ�㷨Max��Min�㷨��
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
 * [AI2::isBesieged �ж��Ƿ񱻰�Χ��]
 * @param  RivalLine   [��ǰ׼�����ӵ�λ�õ���]
 * @param  RivalColumn [��ǰ׼�����ӵ�λ�õ���]
 * @param  onTurn      [�ֵ�˭������������PlayerInfo.h�в鿴]
 * @return             [�Ƿ񱻰�Χ������Χ�ͷ���true��û�б���Χ�ͷ���false]
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
