// 不围棋.cpp : Defines the entry point for the application.
//
#include "../stdafx.h"
#include "../buweiqi.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);//声明窗口过程函数
bool HDCInitialize(HWND hwnd);//声明初始化设备环境句柄

ChessBoard CB;//创建对象
HCURSOR UPARROWcursor;//竖直向上箭头的光标图像
HCURSOR ARROWcursor;//一般的光标图像
HWND hwnd;
DWORD g_tPre=0,g_tNow=0;

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
    CB.hInstance = hInstance;
    UPARROWcursor = LoadCursor(NULL, IDC_UPARROW);
    ARROWcursor = LoadCursor(NULL, IDC_ARROW);

    //窗口的设计
    WNDCLASSEX winClass = {0}; //创建窗口类对象
    winClass.cbSize = sizeof(WNDCLASSEX); //窗口类字节数
    winClass.style = CS_HREDRAW | CS_VREDRAW;//窗口的风格样式
    winClass.lpfnWndProc = WndProc;//窗口过程函数名称
    winClass.cbClsExtra = 0;//窗口类附加内存
    winClass.cbWndExtra = 0;//窗口类附加内存
    winClass.hInstance = hInstance;//包含窗口过程的程序的实例句柄
    winClass.hIcon = (HICON)::LoadImage(NULL,"BACKGROUND.ico",IMAGE_ICON,0,0,LR_DEFAULTSIZE | LR_LOADFROMFILE);//窗口类的图标句柄，设置为NULL则为系统默认
    winClass.hCursor = ARROWcursor;//窗口类的图标句柄，若图标句柄为NULL，则LoadCursor第一个参数必须为NULL
    winClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);//窗口类的背景画刷句柄
    winClass.lpszMenuName = NULL;//菜单类的名称
    winClass.lpszClassName = "BuWeiQi";//窗口类的名称
    winClass.hIconSm = NULL;//窗口类的小图标句柄
    //初始化棋盘信息
    CB.Initialize();

    //窗口的注册
    RegisterClassEx( &winClass );

    //创建窗口，并接收返回的窗口句柄
    hwnd = CreateWindow("BuWeiQi", //窗口类的名称
                        "不围棋", //窗口的标题名称
                        WS_MINIMIZEBOX | WS_SYSMENU,//窗口样式
                        100, //窗口左上角的水平位置
                        100, //窗口左上角的竖直位置
                        CB.Width, //窗体的宽度
                        CB.Height, //窗体的高度
                        NULL, //被创建窗口的父窗口句柄
                        NULL, //窗口菜单的资源句柄
                        hInstance, //窗口所属的应用程序实例的句柄，与WinMain第一个参数相同
                        NULL//消息的附加参数
                       );
    /**
     * 窗口中用左边的500 × 500区域画棋盘，右边记录玩家信息
     */
    CB.ParentHwnd = hwnd;
    //设置窗口可视
    ShowWindow(hwnd, SW_SHOW);
    //更新窗口
    UpdateWindow(hwnd);
    //建立消息循环

    MSG msg = {0};   //定义消息对象msg
    while(msg.message != WM_QUIT)
    {
        if(PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);//将虚拟键消息转换为字符消息
            DispatchMessage(&msg);//分发一个消息到窗口程序
        }
        else
        {
            g_tNow=GetTickCount();
            if(g_tNow-g_tPre>=5)
               {
                   ValidateRect(hwnd,NULL);
               }
        }
    }
  //  KillTimer(CB.ParentHwnd, 2);//结束计时器
    //注销窗口
    UnregisterClass("BuWeiQi",winClass.hInstance);
    return 0;
}
/**
 * [WndProc 定义窗口过程函数，后两个参数“附加信息”]
 * @param  hwnd    [description]
 * @param  message [消息]
 * @param  wParam  [description]
 * @param  lParam  [description]
 * @return         [description]
 */
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
    case WM_PAINT: //客户区重绘消息
//        if(wParam==1&&lParam==1)
//        CB.PaintTimer();
 //       else

        CB.graphicsHdc = BeginPaint(hwnd, &CB.paintStruct);//开始画图
        CB.HDCInitialize(hwnd);
        EndPaint(hwnd, &CB.paintStruct);//结束画图
        ReleaseDC(hwnd, CB.graphicsHdc);
        ValidateRect(hwnd,NULL);
        break;


    case WM_MOUSEMOVE://鼠标移动消息
        CB.point.x = LOWORD(lParam);//获取鼠标位置
        CB.point.y = HIWORD(lParam);
        if(CB.point.x < CB.Base && CB.point.y < CB.Base)
            SetCursor(UPARROWcursor);
        else
            SetCursor(ARROWcursor);
        break;

    case WM_LBUTTONDOWN://若是鼠标左键按下消息
        if(CB.Start == true && CB.getPosition(lParam))
        {
            //若鼠标点中棋盘
            CB.graphicsHdc = BeginPaint(hwnd, &CB.paintStruct);//开始画图
            CB.graphicsHdc = GetDC(CB.ParentHwnd);
            CB.PaintChess();
            EndPaint(hwnd, &CB.paintStruct);
            ReleaseDC(hwnd, CB.graphicsHdc);
            ValidateRect(hwnd,NULL);
       //     PostMessage(hwnd, WM_PAINT, 0, 0);
        }

        break;
    case WM_KEYDOWN://若是键盘按下消息
        if(wParam == VK_F1) //按F1键
        {
            if(CB.AI1 == false)
            {
                CB.AI1 = true;
                if(CB.onTurn == 1)
                {
                    CB.onTurn = -1;
                    CB.PaintChess();
                }
                PostMessage(hwnd, WM_PAINT, 0, 0);
            }
            else
            {
                CB.AI1 = false;
                PostMessage(hwnd, WM_PAINT, 0, 0);
            }
        }

        else if(wParam == VK_F2) //按下F2键
        {
            if(CB.AI2 == false)
            {
                CB.AI2 = true;
                if(CB.onTurn == 2)
                {
                    CB.onTurn = -2;
                    CB.PaintChess();
                }
                PostMessage(hwnd, WM_PAINT, 0, 0);
            }
            else
            {
                CB.AI2 = false;
                PostMessage(hwnd, WM_PAINT, 0, 0);
            }
        }

        else if(wParam == VK_RETURN) //按下回车键
        {
            if(CB.Start == false)
            {
                CB.Start = true;
                CB.PlayerTimer = SetTimer(hwnd, 2, 1000, NULL);//计时器开始
                PostMessage(hwnd, WM_PAINT, 0, 0);
                if(CB.AI1 == true)
                {
                    CB.onTurn = -1;
                    CB.PaintChess();
                }
            }
        }

        break;

    case WM_TIMER://定时器，每1秒调用过来
        if(CB.onTurn == 1 || CB.onTurn == -1)
        {
            CB.Round1--;
            CB.AllTime1--;
            //超时判负，并结束计时器
            if(CB.AllTime1 == 0)
            {
                CB.Winner = 2;
                CB.Start = false;
                CB.reStart(hwnd);
            }
             PostMessage(hwnd, WM_PAINT, 1, 1);
        }
        else if(CB.onTurn == 2 || CB.onTurn == -2)
        {
            CB.Round2--;
            CB.AllTime2--;
            //超时判负，并结束计时器
            if(CB.AllTime2 == 0)
            {
                CB.Winner = 1;
                CB.Start = false;
                CB.reStart(hwnd);

            }
           // CB.PaintTimer();
            PostMessage(hwnd, WM_PAINT, 1, 1);
        }

        break;

    case WM_DESTROY://窗口销毁消息
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, message, wParam, lParam);//调用默认的窗口过程
    }
    g_tPre=GetTickCount();

    return 0;
}
