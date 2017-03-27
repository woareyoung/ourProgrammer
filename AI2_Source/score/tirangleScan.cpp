#include "../../AI2_Header/AI2.h"

/**
 * [AI2::Tirangle ����Χɱ]
 */
void AI2::Tirangle()
{
    ULTirangle();
    DRTirangle();
}

/**
 * [AI2::ULTirangle �ϱߺ���ߵ�����Χɱ�ӷ�]
 */
void AI2::ULTirangle()
{
    for (int i = 1; i < 10; i++)
    {
        // �ϱ�
        if (cross[1][i] != noChess && i+2 < 10)
        {
            if (cross[1][i+1] == (PlayerId == isBlack ? isWhite : isBlack))
            {
                // �����м�����������
                continue;
            }
            // ���ǵ���
            if (cross[2][i+1] == noChess && cross[1][i+2] == noChess)
            {
                addScore(2,i+1,tirangleScore1);
                addScore(1,i+2,tirangleScore1);
            }// ����˫��
            else if ((cross[2][i+1] != noChess && cross[1][i+1] == cross[2][i+1]
                      && cross[1][i+2] == noChess)
                     || (cross[2][i+1] == noChess && cross[1][i+1] == cross[2][i+1]
                         && cross[1][i+2] != noChess))
            {
                addScore(2,i+1,tirangleScore2);
                addScore(1,i+2,tirangleScore2);
            }// ��������
            else
            {
                cross[1][i+1] = min;
            }
        }
        // ���
        if (cross[i][1] != noChess && i+2 < 10)
        {
            if (cross[i+1][1] == (PlayerId == isBlack ? isWhite : isBlack))
            {
                // �����м�����������
                continue;
            }
            // ���ǵ���
            if (cross[i+1][2] == noChess && cross[i+2][1] == noChess)
            {
                addScore(i+1,2,tirangleScore1);
                addScore(i+2,1,tirangleScore1);
            }// ����˫��
            else if ((cross[i+1][2] != noChess && cross[i+1][1] == cross[i+1][2]
                      && cross[i+2][1] == noChess)
                     || (cross[i+1][2] == noChess && cross[i+1][1] == cross[i+1][2]
                         && cross[i+2][1] != noChess))
            {
                addScore(i+1,2,tirangleScore2);
                addScore(i+2,1,tirangleScore2);
            }// ��������
            else
            {
                cross[i+1][1] = min;
            }
        }
    }
}

/**
 * [AI2::DRTirangle �±ߺ��ұߵ�����Χɱ�ӷ�]
 */
void AI2::DRTirangle()
{
    for (int i = 1; i < 10; i++)
    {
        // �±�
        if (cross[9][i] != noChess && i+2 < 10)
        {
            if (cross[9][i+1] == (PlayerId == isBlack ? isWhite : isBlack))
            {
                // �����м�����������
                continue;
            }
            // ���ǵ���
            if (cross[8][i+1] == noChess && cross[9][i+2] == noChess)
            {
                addScore(8,i+1,tirangleScore1);
                addScore(9,i+2,tirangleScore1);
            }// ����˫��
            else if ((cross[8][i+1] != noChess && cross[9][i+1] == cross[8][i+1]
                      && cross[9][i+2] == noChess)
                     || (cross[8][i+1] == noChess && cross[9][i+1] == cross[8][i+1]
                         && cross[9][i+2] != noChess))
            {
                addScore(8,i+1,tirangleScore2);
                addScore(9,i+2,tirangleScore2);
            }// ��������
            else
            {
                cross[9][i+1] = min;
            }
        }
        // �ұ�
        if (cross[i][9]= noChess && i+2 < 10)
        {
            if (cross[i+1][9] == (PlayerId == isBlack ? isWhite : isBlack))
            {
                // �����м�����������
                continue;
            }
            // ���ǵ���
            if (cross[8][i+1] == noChess && cross[i+2][9] == noChess)
            {
                addScore(i+1,8,tirangleScore1);
                addScore(i+2,9,tirangleScore1);
            }// ����˫��
            else if ((cross[8][i+1] != noChess && cross[i+1][9] == cross[8][i+1]
                      && cross[i+2][9] == noChess)
                     || (cross[8][i+1] == noChess && cross[i+1][9] == cross[8][i+1]
                         && cross[i+2][9] != noChess))
            {
                addScore(i+1,8,tirangleScore2);
                addScore(i+2,9,tirangleScore2);
            }// ��������
            else
            {
                cross[i+1][9] = min;
            }
        }
    }
}


