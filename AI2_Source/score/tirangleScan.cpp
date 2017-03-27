#include "../../AI2_Header/AI2.h"

/**
 * [AI2::Tirangle 三角围杀]
 */
void AI2::Tirangle()
{
    ULTirangle();
    DRTirangle();
}

/**
 * [AI2::ULTirangle 上边和左边的三角围杀加分]
 */
void AI2::ULTirangle()
{
    for (int i = 1; i < 10; i++)
    {
        // 上边
        if (cross[1][i] != noChess && i+2 < 10)
        {
            if (cross[1][i+1] == (PlayerId == isBlack ? isWhite : isBlack))
            {
                // 三角中间有子无意义
                continue;
            }
            // 三角单子
            if (cross[2][i+1] == noChess && cross[1][i+2] == noChess)
            {
                addScore(2,i+1,tirangleScore1);
                addScore(1,i+2,tirangleScore1);
            }// 三角双子
            else if ((cross[2][i+1] != noChess && cross[1][i+1] == cross[2][i+1]
                      && cross[1][i+2] == noChess)
                     || (cross[2][i+1] == noChess && cross[1][i+1] == cross[2][i+1]
                         && cross[1][i+2] != noChess))
            {
                addScore(2,i+1,tirangleScore2);
                addScore(1,i+2,tirangleScore2);
            }// 三角三子
            else
            {
                cross[1][i+1] = min;
            }
        }
        // 左边
        if (cross[i][1] != noChess && i+2 < 10)
        {
            if (cross[i+1][1] == (PlayerId == isBlack ? isWhite : isBlack))
            {
                // 三角中间有子无意义
                continue;
            }
            // 三角单子
            if (cross[i+1][2] == noChess && cross[i+2][1] == noChess)
            {
                addScore(i+1,2,tirangleScore1);
                addScore(i+2,1,tirangleScore1);
            }// 三角双子
            else if ((cross[i+1][2] != noChess && cross[i+1][1] == cross[i+1][2]
                      && cross[i+2][1] == noChess)
                     || (cross[i+1][2] == noChess && cross[i+1][1] == cross[i+1][2]
                         && cross[i+2][1] != noChess))
            {
                addScore(i+1,2,tirangleScore2);
                addScore(i+2,1,tirangleScore2);
            }// 三角三子
            else
            {
                cross[i+1][1] = min;
            }
        }
    }
}

/**
 * [AI2::DRTirangle 下边和右边的三角围杀加分]
 */
void AI2::DRTirangle()
{
    for (int i = 1; i < 10; i++)
    {
        // 下边
        if (cross[9][i] != noChess && i+2 < 10)
        {
            if (cross[9][i+1] == (PlayerId == isBlack ? isWhite : isBlack))
            {
                // 三角中间有子无意义
                continue;
            }
            // 三角单子
            if (cross[8][i+1] == noChess && cross[9][i+2] == noChess)
            {
                addScore(8,i+1,tirangleScore1);
                addScore(9,i+2,tirangleScore1);
            }// 三角双子
            else if ((cross[8][i+1] != noChess && cross[9][i+1] == cross[8][i+1]
                      && cross[9][i+2] == noChess)
                     || (cross[8][i+1] == noChess && cross[9][i+1] == cross[8][i+1]
                         && cross[9][i+2] != noChess))
            {
                addScore(8,i+1,tirangleScore2);
                addScore(9,i+2,tirangleScore2);
            }// 三角三子
            else
            {
                cross[9][i+1] = min;
            }
        }
        // 右边
        if (cross[i][9]= noChess && i+2 < 10)
        {
            if (cross[i+1][9] == (PlayerId == isBlack ? isWhite : isBlack))
            {
                // 三角中间有子无意义
                continue;
            }
            // 三角单子
            if (cross[8][i+1] == noChess && cross[i+2][9] == noChess)
            {
                addScore(i+1,8,tirangleScore1);
                addScore(i+2,9,tirangleScore1);
            }// 三角双子
            else if ((cross[8][i+1] != noChess && cross[i+1][9] == cross[8][i+1]
                      && cross[i+2][9] == noChess)
                     || (cross[8][i+1] == noChess && cross[i+1][9] == cross[8][i+1]
                         && cross[i+2][9] != noChess))
            {
                addScore(i+1,8,tirangleScore2);
                addScore(i+2,9,tirangleScore2);
            }// 三角三子
            else
            {
                cross[i+1][9] = min;
            }
        }
    }
}


