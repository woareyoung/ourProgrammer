// ��Χ��.cpp : Defines the entry point for the application.
//
#include "../stdafx.h"
#include "../buweiqi.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);//�������ڹ��̺���
bool HDCInitialize(HWND hwnd);//������ʼ���豸�������

ChessBoard CB;//��������
HCURSOR UPARROWcursor;//��ֱ���ϼ�ͷ�Ĺ��ͼ��
HCURSOR ARROWcursor;//һ��Ĺ��ͼ��
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

    //���ڵ����
    WNDCLASSEX winClass = {0}; //�������������
    winClass.cbSize = sizeof(WNDCLASSEX); //�������ֽ���
    winClass.style = CS_HREDRAW | CS_VREDRAW;//���ڵķ����ʽ
    winClass.lpfnWndProc = WndProc;//���ڹ��̺�������
    winClass.cbClsExtra = 0;//�����฽���ڴ�
    winClass.cbWndExtra = 0;//�����฽���ڴ�
    winClass.hInstance = hInstance;//�������ڹ��̵ĳ����ʵ�����
    winClass.hIcon = (HICON)::LoadImage(NULL,"BACKGROUND.ico",IMAGE_ICON,0,0,LR_DEFAULTSIZE | LR_LOADFROMFILE);//�������ͼ����������ΪNULL��ΪϵͳĬ��
    winClass.hCursor = ARROWcursor;//�������ͼ��������ͼ����ΪNULL����LoadCursor��һ����������ΪNULL
    winClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);//������ı�����ˢ���
    winClass.lpszMenuName = NULL;//�˵��������
    winClass.lpszClassName = "BuWeiQi";//�����������
    winClass.hIconSm = NULL;//�������Сͼ����
    //��ʼ��������Ϣ
    CB.Initialize();

    //���ڵ�ע��
    RegisterClassEx( &winClass );

    //�������ڣ������շ��صĴ��ھ��
    hwnd = CreateWindow("BuWeiQi", //�����������
                        "��Χ��", //���ڵı�������
                        WS_MINIMIZEBOX | WS_SYSMENU,//������ʽ
                        100, //�������Ͻǵ�ˮƽλ��
                        100, //�������Ͻǵ���ֱλ��
                        CB.Width, //����Ŀ��
                        CB.Height, //����ĸ߶�
                        NULL, //���������ڵĸ����ھ��
                        NULL, //���ڲ˵�����Դ���
                        hInstance, //����������Ӧ�ó���ʵ���ľ������WinMain��һ��������ͬ
                        NULL//��Ϣ�ĸ��Ӳ���
                       );
    /**
     * ����������ߵ�500 �� 500�������̣��ұ߼�¼�����Ϣ
     */
    CB.ParentHwnd = hwnd;
    //���ô��ڿ���
    ShowWindow(hwnd, SW_SHOW);
    //���´���
    UpdateWindow(hwnd);
    //������Ϣѭ��

    MSG msg = {0};   //������Ϣ����msg
    while(msg.message != WM_QUIT)
    {
        if(PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);//���������Ϣת��Ϊ�ַ���Ϣ
            DispatchMessage(&msg);//�ַ�һ����Ϣ�����ڳ���
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
  //  KillTimer(CB.ParentHwnd, 2);//������ʱ��
    //ע������
    UnregisterClass("BuWeiQi",winClass.hInstance);
    return 0;
}
/**
 * [WndProc ���崰�ڹ��̺�����������������������Ϣ��]
 * @param  hwnd    [description]
 * @param  message [��Ϣ]
 * @param  wParam  [description]
 * @param  lParam  [description]
 * @return         [description]
 */
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
    case WM_PAINT: //�ͻ����ػ���Ϣ
//        if(wParam==1&&lParam==1)
//        CB.PaintTimer();
 //       else

        CB.graphicsHdc = BeginPaint(hwnd, &CB.paintStruct);//��ʼ��ͼ
        CB.HDCInitialize(hwnd);
        EndPaint(hwnd, &CB.paintStruct);//������ͼ
        ReleaseDC(hwnd, CB.graphicsHdc);
        ValidateRect(hwnd,NULL);
        break;


    case WM_MOUSEMOVE://����ƶ���Ϣ
        CB.point.x = LOWORD(lParam);//��ȡ���λ��
        CB.point.y = HIWORD(lParam);
        if(CB.point.x < CB.Base && CB.point.y < CB.Base)
            SetCursor(UPARROWcursor);
        else
            SetCursor(ARROWcursor);
        break;

    case WM_LBUTTONDOWN://����������������Ϣ
        if(CB.Start == true && CB.getPosition(lParam))
        {
            //������������
            CB.graphicsHdc = BeginPaint(hwnd, &CB.paintStruct);//��ʼ��ͼ
            CB.graphicsHdc = GetDC(CB.ParentHwnd);
            CB.PaintChess();
            EndPaint(hwnd, &CB.paintStruct);
            ReleaseDC(hwnd, CB.graphicsHdc);
            ValidateRect(hwnd,NULL);
       //     PostMessage(hwnd, WM_PAINT, 0, 0);
        }

        break;
    case WM_KEYDOWN://���Ǽ��̰�����Ϣ
        if(wParam == VK_F1) //��F1��
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

        else if(wParam == VK_F2) //����F2��
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

        else if(wParam == VK_RETURN) //���»س���
        {
            if(CB.Start == false)
            {
                CB.Start = true;
                CB.PlayerTimer = SetTimer(hwnd, 2, 1000, NULL);//��ʱ����ʼ
                PostMessage(hwnd, WM_PAINT, 0, 0);
                if(CB.AI1 == true)
                {
                    CB.onTurn = -1;
                    CB.PaintChess();
                }
            }
        }

        break;

    case WM_TIMER://��ʱ����ÿ1����ù���
        if(CB.onTurn == 1 || CB.onTurn == -1)
        {
            CB.Round1--;
            CB.AllTime1--;
            //��ʱ�и�����������ʱ��
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
            //��ʱ�и�����������ʱ��
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

    case WM_DESTROY://����������Ϣ
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, message, wParam, lParam);//����Ĭ�ϵĴ��ڹ���
    }
    g_tPre=GetTickCount();

    return 0;
}
