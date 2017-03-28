#include "../../AI2_Header/isAI2.h"

/**
 * [isAI2::CrossShaped ʮ��Χɱ]
 * @return [��]
 */
void isAI2::CrossShaped()
{
    for (int i = 2; i < 9; i++)
    {
        for (int j = 2; j < 9; j++)
        {
            JudgeCShape(i,j);
        }
    }
}

/**
 * [isAI2::JudgeCShape �ж��Ƿ��γ�ʮ��Χɱ]
 * @param line   [��]
 * @param column [��]
 */
void isAI2::JudgeCShape(int line,int column)
{
    int num = 0;
    if (cross[line][column] == (PlayerId == isWhite ? isBlack : isWhite))
    {
        FindBlank(line,column);
    }
}

/**
 * [isAI2::FindBlank �ҳ�ʮ��Χɱ�Ŀհ����ӵ�]
 * @param line   [��]
 * @param column [��]
 */
void isAI2::FindBlank(int line,int column)
{
    int temp[4];
    temp[0] = (line-1)*100 + column;
    temp[1] = line*100 + column + 1;
    temp[2] = (line + 1)*100 + column;
    temp[3] = line*100 + column - 1;

    int tempPos[4] = {0,0,0,0};
    for (int i=0; i < 4; i++)
    {
        tempPos[i] = cross[temp[i]/100][temp[i]%100];
    }

    int blacknum = 0;
    int whitenum = 0;
    int blanknum = 0;
    for (int i=0; i < 4; i++)
    {
        if (tempPos[i] == isWhite)
        {
            ++whitenum;
        }
        else if (tempPos[i] == isBlack)
        {
            ++blacknum;
        }
        else
        {
            ++blanknum;
        }
    }

    if (cross[line][column] == noChess)
    {
        if ((blacknum == 3 && whitenum == 0) || (whitenum == 3 && blacknum == 0))
        {
            addCSScore(line,column,crossShaped3,tempPos,temp);
        }
        else if ((blacknum == 2 && whitenum == 0) || (whitenum == 2 && blacknum == 0))
        {
            addCSScore(line,column,crossShaped2,tempPos,temp);
        }
        else if ((blacknum == 1 && whitenum == 0) || (whitenum == 1 && blacknum == 0))
        {
            addCSScore(line,column,crossShaped1,tempPos,temp);
        }
    }
}

/**
 * [isAI2::FindBlank �ҳ�ʮ��Χɱ�Ŀհ����ӵ�]
 * @param line          [��]
 * @param column        [��]
 * @param score         [����]
 * @param tempPos[4]    [λ�ñ�������]
 * @param temp[4]       [����λ��]
 */
void isAI2::addCSScore(int line,int column,int score,int tempPos[4],int temp[4])
{
    for (int i = 0; i < 4; i++)
    {
        if (tempPos[i] == noChess)
        {
            cross[temp[i]/100][temp[i]%100] = score;
        }
    }
}

