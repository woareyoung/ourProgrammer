# include "chessBoard/ChessBase.h"
# include "chessBoard/ChessRule.h"
/**
 * 棋盘界面类
 * 主要负责棋盘的绘制工作
 */
class ChessBoard : public ChessBase, public ChessRule
{
private :

    // 记录棋盘每列的 每一行或每一列 坐标值，数组访问从“1”开始
    // 这个是棋盘的相对位置
    int CrossCross[10];
    // 行列位置
    int ChessDiameter;//棋子的直径
    // 画笔工具
    HPEN pen;


    void updateTime(int AllTime,int Round,int offset);
public :
    int Width;//窗口的宽度
    int Height;//窗口的高度
    int Base;//窗口内容规模的基准

    /**
     * --------界面生成必须参数---------
     */
    POINT point;//鼠标句柄
    // 矩形对象类，用于绘制矩形窗口
    HINSTANCE hInstance;//应用程序实例的句柄
    HDC graphicsHdc;//设备环境句柄
    PAINTSTRUCT paintStruct;//PAINTSTRUCT结构体
    HWND ParentHwnd;//游戏的窗口
    HDC hdcBuffer;//环境句柄缓冲区
    // 位图
    HBITMAP bitmap;//用于缓冲的位图

    /**
     * --------功能函数部分--------
     */
    //初始化二维数组信息
    void Initialize();
    //画棋盘
    void PaintBoard();
    //初始化设备环境句柄
    void HDCInitialize(HWND hwnd);
    //画棋子
    void PaintChess();
    //获取鼠标在棋盘的位置（第几行第几列）
    bool getPosition(DWORD lpParam);
    // 绘制棋子
    void PaintAChess(int type);
    //绘制倒计时
    void PaintTimer();
    // 构造函数
    ChessBoard();
    // 输出时间信息
    void PrintInfo();
};

