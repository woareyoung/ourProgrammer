#include "stdafx.h"
#include "buweiqi.h"

/**
 * [ChessBoard::PaintChess 绘制棋子]
 */
void ChessBoard::PaintChess()
{
    // 判断轮到哪一方
    switch(onTurn)
    {
    case isPlay1onTurn://画黑色棋子
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 10; j++)
                Cross[i][j] = false;
        if(cross[line][column] == 0)
        {
            if(AI2 == false)
                onTurn = isPlay2onTurn;
            else
                onTurn = isAI2onTurn;
            PaintAChess(1);
            //若已分胜负，则结束游戏
            if(WinOrLose() == true)
            {
                Start = false;
                reStart(ParentHwnd);
            }
        };
        break;
    case isPlay2onTurn://画白色棋子
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 10; j++)
                Cross[i][j] = false;
        if(cross[line][column] == 0)
        {
            if(AI1 == false)
                onTurn = isPlay1onTurn;
            else
                onTurn = isAI1onTurn;
            PaintAChess(2);
            //若已分胜负，则结束游戏
            if(WinOrLose() == true)
            {
                Start = false;
                reStart(ParentHwnd);
            }
        };
        break;
    //画黑色棋子
    case isAI1onTurn:
    {
        if(AI2 == true)
            onTurn = isAI2onTurn;
        else
            onTurn = isPlay2onTurn;

        ///在此调用AI程序，返回下棋的位置（第几行，第几列）
        PaintAChess(isBlack);
        //若对方是电脑，则先判断有没有分出胜负
        bool win = WinOrLose();
        if(AI2 == true && !win) PaintChess();//若对方是电脑，则递归
        else if(win)
        {
            Winner = 2;
            Start = false;
            reStart(ParentHwnd);
        }
    };
    break;
    //画白色棋子
    case isAI2onTurn:
    {
        if(AI1 == true)
            onTurn = isAI1onTurn;
        else
            onTurn = isPlay1onTurn;
        ///在此调用AI程序，返回下棋的位置（第几行，第几列）

        PaintAChess(isWhite);
        //若对方是电脑，则先判断有没有分出胜负
        bool win = WinOrLose();
        if(AI1 == true && !win)
            PaintChess();//若对方是电脑，则递归
        else if(win)
        {
            Winner = 1;
            Start = false;
            reStart(ParentHwnd);
        }
    };
    break;
    }
}

/**
 * [ChessBoard::PaintAChess 绘制一个棋子]
 * @param type [类型--白子、黑子]
 */
void ChessBoard::PaintAChess(int type)
{
    HBRUSH rush;//画刷句柄
    // KillTimer(ParentHwnd, 2);//结束计时器
    //  PlayerTimer = SetTimer(ParentHwnd, 1, 1000, NULL);//计时器开始
    cross[line][column] = type;//将从AI程序获取到的行和列数记录到line和column
    if (type == isBlack)
    {
        Round2 = 60;
        rush = CreateSolidBrush(RGB(0, 0, 0));
    }
    else if (type == isWhite)
    {
        Round1 = 60;
        rush = CreateSolidBrush(RGB(255, 255, 255));
    }
    SelectObject(graphicsHdc, rush);
    //画棋子
    Ellipse(graphicsHdc, CrossCross[column] - ChessDiameter / 2, CrossCross[line] - ChessDiameter / 2,
            CrossCross[column] + ChessDiameter / 2, CrossCross[line] + ChessDiameter / 2);
    DeleteObject(rush);
}


/**
 * [ChessBoard::getPosition 获取鼠标在棋盘的位置（第几行第几列）]
 * @param  lParam [无符号长整型]
 * @return        [当鼠标的位置没有越界的时候返回true，反之返回false]
 */
bool ChessBoard::getPosition(DWORD lParam)
{
    point.x = LOWORD(lParam);// 得到一个32bit数的低16bit
    point.y = HIWORD(lParam);// 得到一个32bit数的高16bit
    int a, b;
    b = (point.x - ChessDiameter / 2) / ChessDiameter + 1;
    a = (point.y - ChessDiameter / 2) / ChessDiameter + 1;
    // 判断是否越界
    if(a < 10 && b < 10 && a > 0 && b > 0)
    {
        line = a;
        column = b;
        return true;
    }
    return false;
}
