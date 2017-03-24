#include "StdAfx.h"
#include "buweiqi.h"

/**
 * [ChessBoard::PaintBoard 画棋盘]
 */

void ChessBoard::PaintBoard()
{
    int i, j,k;
    char *Number;
    char buffer[2];
    buffer[0] = NULL,buffer[1] = NULL;//清除buffer内容
    //设置每个交叉点的情况，“0”表示没有棋子，“1”表示黑子，“2”表示白字
    if(Start == false)
    {
        for(i = 1; i < 10; i++)
        {
            for(j = 1; j < 10; j++)
            {
                cross[i][j] = 0;//棋盘上无子，所以设“0”
            }
        }
    }
    SetTextColor(graphicsHdc, RGB(0,0,0));//设置文本颜色为黑色

    pen = CreatePen(PS_SOLID, 10, RGB(0,0,0));//创建画笔，并设置为黑色细线条 —— 去掉这个感觉没什么问题，所以注释掉
    ChessBoardNumber = true;
    //画棋盘
    for(i = 1; i < 10; i++)
    {
        Number = Int2String(i);
        MoveToEx(graphicsHdc, CrossCross[i], CrossCross[1], NULL);//移动光标
        LineTo(graphicsHdc, CrossCross[i], CrossCross[9]);//画横线
        MoveToEx(graphicsHdc, CrossCross[1], CrossCross[i], NULL);//移动光标
        LineTo(graphicsHdc, CrossCross[9], CrossCross[i]);//画竖线
        TextOut(graphicsHdc, CrossCross[i] - 2, 0, Number, 1);//写文本，棋盘的行的数字标号
        TextOut(graphicsHdc, 0, CrossCross[i] - 5, Number, 1);//写文本，棋盘的列的数字标号
    }

//用于重绘
    //画棋子
    for(i = 0; i < 10; i++)
        for(j = 0; j < 10; j++)
        {
            // 黑子
            if(cross[i][j] == isBlack)
            {
                // 画笔
                HBRUSH rush = CreateSolidBrush(RGB(0, 0, 0));
                // 引入画笔到场景中
                SelectObject(graphicsHdc, rush);
                // 描绘一个椭圆
                // 第一个参数是HDC设备场景句柄，
                // 第二个参数是棋盘X1的位置-棋子X1的偏移量/2
                // 第三个参数是棋盘Y1的位置-棋子Y1的偏移量/2
                // 第四个参数是棋盘X2的位置-棋子X2的偏移量/2
                // 第五个参数是棋盘Y2的位置-棋子Y2的偏移量/2
                Ellipse(graphicsHdc, CrossCross[j] - ChessDiameter / 2, CrossCross[i] - ChessDiameter / 2,
                        CrossCross[j] + ChessDiameter / 2, CrossCross[i] + ChessDiameter / 2);
                // 释放GUI对象
                DeleteObject(rush);
            }
            // 白子
            else if(cross[i][j] == isWhite)
            {
                // 画笔
                HBRUSH rush = CreateSolidBrush(RGB(255, 255, 255));
                // 引入画笔到场景中
                SelectObject(graphicsHdc, rush);
                // 描绘一个椭圆
                // 第一个参数是HDC设备场景句柄，
                // 第二个参数是棋盘X1的位置-棋子X1的偏移量/2
                // 第三个参数是棋盘Y1的位置-棋子Y1的偏移量/2
                // 第四个参数是棋盘X2的位置-棋子X2的偏移量/2
                // 第五个参数是棋盘Y2的位置-棋子Y2的偏移量/2
                Ellipse(graphicsHdc, CrossCross[j] - ChessDiameter / 2, CrossCross[i] - ChessDiameter / 2,
                        CrossCross[j] + ChessDiameter / 2, CrossCross[i] + ChessDiameter / 2);
                // 释放GUI对象
                DeleteObject(rush);
            }
        }

    //标注玩家信息
    Number = "Player1";
    //HDC X Y 信息 信息长度
    TextOut(graphicsHdc, Base + ChessDiameter * 200 / 130, ChessDiameter, Number, strlen(Number));
    Number = "Player2";
    //HDC X Y 信息 信息长度
    TextOut(graphicsHdc, Base + ChessDiameter * 200 / 130, ChessDiameter + Base / 2, Number, strlen(Number));
}

void ChessBoard::PaintTimer()
{
    updateTime(AllTime1,Round1,0);
    updateTime(AllTime2,Round2,Base / 2);
   // BitBlt(graphicsHdc, 0, 0, Width, Height, hdcBuffer, 0, 0, SRCCOPY);
}

void ChessBoard::updateTime(int AllTime,int Round,int offset)
{
    //获取时间
    ChessBoardNumber = false;
    char buffer[2];
    buffer[0] = NULL,buffer[1] = NULL;//清除buffer内容
    lstrcat(buffer, Int2String(AllTime / 60));
    lstrcat(buffer, "：");
    lstrcat(buffer, Int2String(AllTime % 60));
    TextOut(graphicsHdc, Base, ChessDiameter * 3 + offset, "游戏总剩余时间  ", 14);
    TextOut(graphicsHdc, Base + 110, ChessDiameter * 3 + offset, buffer, strlen(buffer));//输出玩家1游戏总剩余时间
    TextOut(graphicsHdc, Base, ChessDiameter * 4 + offset, "回合剩余时间    ", 14);
    buffer[0] = NULL,buffer[1] = NULL;//清除buffer内容
    lstrcat(buffer, Int2String(Round / 60));
    lstrcat(buffer, "：");
    lstrcat(buffer, Int2String(Round % 60));
    TextOut(graphicsHdc, Base + 110, ChessDiameter * 4 + offset, buffer, strlen(buffer));//输出玩家1回合剩余时间
}

void ChessBoard::PrintInfo()//打印玩家的信息
{
    char *Number;
    if(AI1 == false)
    {
        Number = "    玩家1未使用AI，按F1键可使用AI    ";
        TextOut(graphicsHdc, Base, ChessDiameter * 2, Number, strlen(Number));
    }
    else
    {
        Number = "玩家1已使用AI，按F1键可取消使用AI";
        TextOut(graphicsHdc, Base, ChessDiameter * 2, Number, strlen(Number));
    }
    if(AI2 == false)
    {
        Number ="    玩家2未使用AI，按F2键可使用AI    ";
        TextOut(graphicsHdc, Base, ChessDiameter * 2 + Base / 2, Number, strlen(Number));
    }
    else
    {
        Number ="玩家2已使用AI，按F2键可取消使用AI";
        TextOut(graphicsHdc, Base, ChessDiameter * 2 + Base / 2, Number, strlen(Number));
    }
    if(Start == false)
    {
        Number = "按回车键开始游戏";
    }
    else
    {
        Number = "      已开始游戏      ";
    }
    TextOut(graphicsHdc, Base + ChessDiameter * 85 / 100, ChessDiameter * 5, Number, strlen(Number));
}
