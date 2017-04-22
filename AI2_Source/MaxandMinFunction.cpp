#include "../AI2_Header/AI2.h"

/**
 * [AI2::GetPosition AI对外接口]
 * @param line 			着子位置的行坐标
 * @param column 		着子位置的行坐标
 * @param onTurn 		当前轮到的玩家的ID
 * @param isExist[10][10]		棋盘着子情况数组
 */
void AI2::GetPosition(int& line,int& column,int onTurn)
{
    //用于响应主窗口对AI的检查
    if(onTurn == 0)
    {
        // 这里是重新开始游戏的数据重置过程
        line++;
        column++;
        resetGo2DeadStatus();
        initAllArray();
        return;
    }
    // 注意传递进来的onTurn参数是对方的，而不是己方的。
    Rival = (onTurn == isBlack || onTurn == isAI1onTurn) ? isBlack : isWhite;
    turn2Who = (Rival == isWhite ? isBlack : isWhite);
    cross[line][column] = Rival;
    chessScore[line][column] = minLimit;

    // 设置遍历的深度
    int temp = maxandmin(1);
    line = temp/100;
    column = temp%100;
    // 将计算出的位置的分数设为最小值
    chessScore[line][column] = minLimit;
    cross[line][column] = PlayerId;

    _cprintf("**************This is chess cross*******(%d, %d)***********\n", line, column);
    for(int i = 1; i < 10; i++)
    {
        for(int j = 1; j < 10; j++)
        {
            _cprintf("%d\t",cross[i][j]);
        }
        _cprintf("\n");
    }
}

/**
 * [AI2::maxandmin 极大极小函数]
 * @param depth 		执行的深度
 */
int AI2::maxandmin(int depth)
{
    int tempArray[10] =
    {
        2,1,2,1,2,1,2,1,2,1
    };
    int temp;
    for (int i = 0; i < depth; i++)
    {
        turn2Who = tempArray[i];
        Rival = (tempArray[i] == isWhite ?  isBlack : isWhite);
        temp = singleLayer();
    }
    return temp;
}

/**
 * [AI2::singleLayer 单层执行]
 */
int AI2::singleLayer()
{
    Revalute();
    if (turn2Who == PlayerId)
    {
        return MaxScore();
    }
    else
    {
        return MinScore();
    }
}

/**
 * [AI2::MaxScore 获取极大值]
 */
int AI2::MaxScore()
{
    this->chessCount++;
    bool isFirst = true;
    int tempLine = 0;
    int tempColumn = 0;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if (chessScore[i][j] == minLimit || !isGo2Dead(i, j , turn2Who))
            {
                continue;
            }
            if (isFirst)
            {
                tempLine = i;
                tempColumn = j;
                isFirst = false;
            }
            else if (!isFirst && chessScore[tempLine][tempColumn] < chessScore[i][j])
            {
                tempLine = i;
                tempColumn = j;
            }
        }
    }
    if (tempLine == 0 && 0 == tempColumn)
    {
        //_cprintf("-------------no FOUND(%d, %d)-------------\n", tempLine, tempColumn);
        for (int i = 1; i < 10; i++)
        {
            for (int j = 1; j < 10; j++)
            {
                if (chessScore[i][j] == minLimit || !isGo2Dead(i, j , turn2Who))
                {
                    continue;
                }
                if (!isGo2Dead(i,j, turn2Who) && cross[i][j] == noChess)
                {
                    tempLine = i;
                    tempColumn = j;
                    //_cprintf("**-------------FOUND(%d, %d)-------------**\n", tempLine, tempColumn);
                }
            }
        }
    }
B:
    //_cprintf("-----------count = %d---(%d,%d)-----------\n",this->chessCount,tempLine,tempColumn);
    return tempLine*100 + tempColumn;
}

/**
 * [AI2::MinScore 获取极小值]
 */
int AI2::MinScore()
{
    bool isFirst = true;
    int tempLine;
    int tempColumn;
    // 输出分数
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if (chessScore[i][j] == minLimit || cross[i][j] != noChess)
            {
                continue;
            }
            if (isFirst)
            {
                tempLine = i;
                tempColumn = j;
                isFirst = false;
            }
            else if (!isFirst && chessScore[tempLine][tempColumn] > chessScore[i][j])
            {
                tempLine = i;
                tempColumn = j;
            }
        }
    }
    return tempLine*100 + tempColumn;
}
/**
 * [AI2::Revalute 估值函数]
 */
void AI2::Revalute()
{
    // 初始化棋盘的分数
    initChessScore();
    // 估值并加分
    chessStatusShaped();
    AcrossCorners();
    Tirangle();
    isGo2Dead(isWhite);
    isGo2Dead(isBlack);
}
