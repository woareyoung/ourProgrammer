#include "../stdafx.h"
#include "../buweiqi.h"

/**
 * 构造函数
 */
ChessBoard::ChessBoard()
{
    Round = 0;
    AllTime1 = 900;//总时长15分钟
    AllTime2 = 900;
    Round1 = 60;//步时60秒
    Round2 = 60;
    Start = false;
    Player1isAI = false;
    Player2isAI = false;
    onTurn = 1;//玩家1先下棋
}
/**
 * [ChessBoard::Initialize 初始化二维数组信息]
 */
void ChessBoard::Initialize()
{
    int i;//遍历辅助变量
    Width = 1366 * 800 / GetSystemMetrics(SM_CXSCREEN);//获取屏幕宽度并设置窗体宽度
    Height = 768 * 550 / GetSystemMetrics(SM_CYSCREEN);//获取屏幕高度并设置窗体高度
    Base = Width > Height ? Height : Width;//设置窗体内容规模以适应不同平台
    ChessDiameter = Base / 10;//设置棋子直径，也是棋盘中每个格子的边长
    //设置每个交叉点的坐标值
    for(i = 1; i < 10; i++)
    {
        CrossCross[i] = i * ChessDiameter;
    }

}

/**
 * [ChessBoard::HDCInitialize 初始化设备环境句柄]
 * @param hwnd [窗口句柄]
*/
void ChessBoard::HDCInitialize(HWND hwnd)
{
    graphicsHdc = GetDC(ParentHwnd);//获取设备环境句柄
    // hdcBuffer = CreateCompatibleDC(graphicsHdc);//建立和grapgicsHdc兼容的内存DC
    // bitmap = CreateCompatibleBitmap(hdcBuffer, Width, Height);//建立一个和窗口兼容的空的位图对象

    PrintInfo();
    PaintTimer();
    PaintBoard();
    SelectObject(hdcBuffer, bitmap);//将空位图对象放到hdcBuffer中
    ReleaseDC(ParentHwnd, graphicsHdc);//释放环境句柄
}
