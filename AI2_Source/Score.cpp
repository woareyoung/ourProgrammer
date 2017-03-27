#include "../AI2_Header/AI2.h"

// Ê®×Ö
void  AI2::CrossShaped()
{

}

// ÓÅ»¢¿Ú
void  AI2::GoodTigersMouth()
{

}

void AI2::addScore(int line,int column, int score)
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
