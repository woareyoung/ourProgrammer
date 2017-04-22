#include "../../AI2_Header/AI2.h"

/**
 * [AI2::Tirangle ����Χɱ]
 */
void AI2::Tirangle()
{
    UTirangle();
    RTirangle();
    DTirangle();
    LTirangle();
}

/**
 * [AI2::RTirangle �ҽ��������Χɱ]
 */
void AI2::RTirangle()
{
    for (int i = 1; i < 8; i++)
    {
        // --------------�ұ�--------------------
        if (cross[i+1][9] == noChess)
        {
            // ���ǵ���--�м�����
            if (cross[i][9] == turn2Who && cross[i+1][8] == noChess && cross[i+2][9] == noChess)
            {
                chessScore[i+1][8] += tirangleScore1;
                chessScore[i+2][9] += tirangleScore1;
                chessStatus[i+1][8] = true;
                chessStatus[i+2][9] = true;
            }
            else if (cross[i][9]== noChess && cross[i+1][8] == turn2Who && cross[i+2][9] == noChess)
            {
                chessScore[i][9]+= tirangleScore1;
                chessScore[i+2][9] += tirangleScore1;
                chessStatus[i][9]= true;
                chessStatus[i+2][9] = true;
            }
            else if (cross[i][9]== noChess && cross[i+1][8] == noChess && cross[i+2][9] == turn2Who)
            {
                chessScore[i][9]+= tirangleScore1;
                chessScore[i+1][8] += tirangleScore1;
                chessStatus[i][9]= true;
                chessStatus[i+1][8] = true;
            }
            // ����˫��
            else if (cross[i][9] != noChess && cross[i+1][8] != noChess && cross[i][9]==  cross[i+1][8] &&  cross[i+2][9] == noChess)
            {
                chessScore[i+2][9] += tirangleScore2;
                chessStatus[i+2][9] = true;
            }
            else if (cross[i][9] != noChess && cross[i+1][8] == noChess && cross[i][9]== cross[i+2][9] && cross[i+2][9] != noChess)
            {
                chessScore[i+1][8] += tirangleScore2;
                chessStatus[i+1][8] = true;
            }
            else if (cross[i][9] == noChess && cross[i+1][8] != noChess && cross[i+1][8] == cross[i+2][9] && cross[i+2][9] != noChess)
            {
                chessScore[i][9] += tirangleScore2;
                chessStatus[i][9] = true;
            }
            // ��������
            else
            {
                cross[i+1][9] = minLimit;
                chessStatus[i+1][9] = true;
            }
        }
        else if (cross[i+1][9] == Rival)
        {
            // ����˫��
            if (cross[i][9] == turn2Who && cross[i][9] == cross[i+1][8] && cross[i+2][9] == noChess)
            {
                chessScore[i+2][9] = minLimit;
                chessStatus[i+2][9] = true;
            }
            else if (cross[i][9] == turn2Who && cross[i+1][8] == noChess && cross[i][9]== cross[i+2][9] )
            {
                chessScore[i+1][8] = minLimit;
                chessStatus[i+1][8] = true;
            }
            else if (cross[i][9] == noChess && cross[i+1][8] == turn2Who && cross[i+1][8] == cross[i+2][9])
            {
                chessScore[i][9] = minLimit;
                chessStatus[i][9] = true;
            }
        }
    }
}

/**
 * [AI2::RTirangle ����������Χɱ]
 */
void AI2::LTirangle()
{
    for (int i = 1; i < 8; i++)
    {
        // --------------���--------------------
        if (cross[i+1][1] == noChess)
        {
            // ���ǵ���
            if (cross[i][1] == turn2Who && cross[i+1][2] == noChess && cross[i+2][1] == noChess)
            {
                chessScore[i+1][2] += tirangleScore1;
                chessScore[i+2][1] += tirangleScore1;
                chessStatus[i+1][2] = true;
                chessStatus[i+2][1] = true;
            }
            else if (cross[i][1]== noChess && cross[i+1][2] == turn2Who && cross[i+2][1] == noChess)
            {
                chessScore[i][1]+= tirangleScore1;
                chessScore[i+2][1] += tirangleScore1;
                chessStatus[i][1]= true;
                chessStatus[i+2][1] = true;
            }
            else if (cross[i][1]== noChess && cross[i+1][2] == noChess && cross[i+2][1]  == turn2Who)
            {
                chessScore[i][1]+= tirangleScore1;
                chessScore[i+1][2] += tirangleScore1;
                chessStatus[i][1]= true;
                chessStatus[i+1][2] = true;
            }
            // ����˫��
            else if (cross[i][1] != noChess && cross[i+1][2] != noChess && cross[i][1] == cross[i+1][2] &&  cross[i+2][1] == noChess)
            {
                chessScore[i+2][1] += tirangleScore2;
                chessStatus[i+2][1] = true;
            }
            else if (cross[i][1] != noChess && cross[i+1][2] == noChess && cross[i][1] == cross[i+2][1] && cross[i+2][1] != noChess)
            {
                chessScore[i+1][2] += tirangleScore2;
                chessStatus[i+1][2] = true;
            }
            else if (cross[i][1] == noChess && cross[i+1][2] != noChess && cross[i+1][2] == cross[i+2][1] && cross[i+2][1] != noChess)
            {
                chessScore[i][1]+= tirangleScore2;
                chessStatus[i][1]= true;
            }
            // ��������
            else
            {
                cross[i+1][1] = minLimit;
                chessStatus[i+1][1] = true;
            }
        }
        else if (cross[i+1][1] == Rival)
        {
            // ����˫��
            if (cross[i][1] == turn2Who && cross[i][1] == cross[i+1][2] && cross[i+2][1] == noChess)
            {
                chessScore[i+2][1] = minLimit;
                chessStatus[i+2][1] = true;
            }
            else if (cross[i][1] == turn2Who && cross[i+1][2] == noChess && cross[i][1] == cross[i+2][1])
            {
                chessScore[i+1][2] = minLimit;
                chessStatus[i+1][2] = true;
            }
            else if (cross[i][1] == noChess && cross[i+1][2] == turn2Who && cross[i+1][2] == cross[i+2][1])
            {
                chessScore[i][1] = minLimit;
                chessStatus[i][1]= true;
            }
        }
    }
}

/**
 * [AI2::RTirangle �Ͻ��������Χɱ]
 */
void AI2::UTirangle()
{
    for (int i = 1; i < 8; i++)
    {
        // --------------�ϱ�--------------------
        if (cross[1][i+1] == noChess)
        {
            // ���ǵ���
            if (cross[1][i] == turn2Who && cross[2][i+1] == noChess && cross[1][i+2] == noChess)
            {
                chessScore[2][i+1] += tirangleScore1;
                chessScore[1][i+2] += tirangleScore1;
                chessStatus[2][i+1] = true;
                chessStatus[1][i+2] = true;
            }
            else if (cross[1][i] == noChess && cross[2][i+1]  == turn2Who && cross[1][i+2] == noChess)
            {
                chessScore[1][i] += tirangleScore1;
                chessScore[1][i+2] += tirangleScore1;
                chessStatus[1][i] = true;
                chessStatus[1][i+2] = true;
            }
            else if (cross[1][i] == noChess && cross[2][i+1] == noChess && cross[1][i+2]  == turn2Who)
            {
                chessScore[1][i] += tirangleScore1;
                chessScore[2][i+1] += tirangleScore1;
                chessStatus[1][i] = true;
                chessStatus[2][i+1] = true;
            }
            // ����˫��
            else if (cross[1][i] != noChess && cross[2][i+1] != noChess && cross[1][i] == cross[2][i+1] && cross[1][i+2] == noChess)
            {
                chessScore[1][i+2] += tirangleScore2;
                chessStatus[1][i+2] = true;
            }
            else if (cross[1][i] != noChess && cross[2][i+1] == noChess && cross[1][i] == cross[1][i+2] && cross[1][i+2] != noChess)
            {
                chessScore[2][i+1] += tirangleScore2;
                chessStatus[2][i+1] = true;
            }
            else if (cross[1][i] == noChess && cross[2][i+1] != noChess && cross[1][i+2] == cross[2][i+1] && cross[1][i+2] != noChess)
            {
                chessScore[1][i] += tirangleScore2;
                chessStatus[1][i] = true;
            } // ��������
            else
            {
                cross[1][i+1] = minLimit;
                chessStatus[1][i+1] = true;
            }
        }
        else if (cross[1][i+1] == Rival)
        {
            // ����˫��
            if (cross[2][i+1] == turn2Who && cross[1][i] == cross[2][i+1] && cross[1][i+2] == noChess)
            {
                chessScore[1][i+2] = minLimit;
                chessStatus[1][i+2] = true;
            }
            else if (cross[1][i] == turn2Who && cross[2][i+1] == noChess && cross[1][i] == cross[1][i+2])
            {
                chessScore[2][i+1] = minLimit;
                chessStatus[2][i+1] = true;
            }
            else if (cross[1][i] == noChess && cross[2][i+1] == turn2Who && cross[1][i+2] == cross[2][i+1])
            {
                chessScore[1][i] = minLimit;
                chessStatus[1][i] = true;
            }
        }
    }
}

/**
 * [AI2::DTirangle �±߽������Χɱ]
 */
void AI2::DTirangle()
{
    for (int i = 1; i < 8; i++)
    {
        // -------------�±�--------------------
        if (cross[9][i+1] == noChess)
        {
            // ���ǵ���
            if (cross[9][i] == turn2Who && cross[8][i+1] == noChess && cross[9][i+2] == noChess)
            {
                chessScore[8][i+1] += tirangleScore1;
                chessScore[9][i+2] += tirangleScore1;
                chessStatus[8][i+1] = true;
                chessStatus[9][i+2] = true;
            }
            else if (cross[9][i] == noChess && cross[8][i+1] == turn2Who && cross[9][i+2] == noChess)
            {
                chessScore[9][i] += tirangleScore1;
                chessScore[9][i+2] += tirangleScore1;
                chessStatus[9][i] = true;
                chessStatus[9][i+2] = true;
            }
            else if (cross[9][i] == noChess && cross[8][i+1] == noChess && cross[9][i+2] == turn2Who)
            {
                chessScore[9][i] += tirangleScore1;
                chessScore[8][i+1] += tirangleScore1;
                chessStatus[9][i] = true;
                chessStatus[8][i+1] = true;
            }
            // ����˫��
            else if (cross[9][i] != noChess && cross[8][i+1] != noChess && cross[9][i] ==  cross[8][i+1] &&  cross[9][i+2] == noChess)
            {
                chessScore[9][i+2] += tirangleScore2;
                chessStatus[9][i+2] = true;
            }
            else if (cross[9][i] != noChess && cross[8][i+1] == noChess && cross[9][i] == cross[9][i+2] && cross[9][i+2] != noChess)
            {
                chessScore[8][i+1] += tirangleScore2;
                chessStatus[8][i+1] = true;
            }
            else if (cross[9][i] == noChess && cross[8][i+1] != noChess && cross[8][i+1] == cross[9][i+2] && cross[9][i+2] != noChess)
            {
                chessScore[9][i] += tirangleScore2;
                chessStatus[9][i] = true;
            }
            // ��������
            else
            {
                cross[9][i+1] = minLimit;
                chessStatus[9][i+1] = true;
            }
        }
        else if (cross[9][i+1] == Rival)
        {
            _cprintf("------------------------Hello World-----------------------------\n");
            // ����˫��
            if (cross[9][i] == turn2Who && cross[9][i] == cross[8][i+1] && cross[9][i+2] == noChess)
            {
                chessScore[9][i+2] = minLimit;
                chessStatus[9][i+2] = true;
                _cprintf("**************DEAD TRI********(%d,%d)**********\n",9,i+2);
            }
            else if (cross[9][i] == turn2Who && cross[8][i+1] == noChess && cross[9][i] == cross[9][i+2])
            {
                chessScore[8][i+1] = minLimit;
                chessStatus[8][i+1] = true;
                _cprintf("**************DEAD TRI********(%d,%d)**********\n",8,i+1);
            }
            else if (cross[9][i] == noChess && cross[8][i+1] == turn2Who && cross[8][i+1] == cross[9][i+2])
            {
                chessScore[9][i] = minLimit;
                chessStatus[9][i] = true;
                _cprintf("**************DEAD TRI********(%d,%d)**********\n",9,i);
            }
        }
    }
}
