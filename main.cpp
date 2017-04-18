#include "stdafx.h"
#include "ChessBoard_Header/ChessBoard.h"
#include "AI1_Header/AI1.h"
#include "AI2_Header/AI2.h"
#include "AI3_Header/AI3.h"

#define MID_ONE 1
#define MID_TWO 2
#define MID_START 3
#define AI_1 4
#define AI_2 5
#define AI_3 6

ChessBoard CB;
HCURSOR UPARROWcursor;//��ֱ���ϼ�ͷ�Ĺ��ͼ��
HCURSOR ARROWcursor;//һ��Ĺ��ͼ��
MSG msg ;
int Type = 0;//���
int Num = 0;//�ڼ���AI
bool ShowSelect1 = false;//�Ƿ���ʾAI
bool ShowSelect2 = false;//�Ƿ���ʾAI
bool ShowSelect3 = false;//�Ƿ���ʾAI
LPARAM Param;

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;//���ڹ��̺���
LRESULT CALLBACK WndProcB (HWND, UINT, WPARAM, LPARAM) ;//���ڹ��̺���
void TimerProc();//��ʱ����������
void SelectFun();//ѡ��AI����
void Select();//ѡ��֮��Ĵ���
DWORD WINAPI ThreadProc (PVOID pParam) ;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
{
    CB.hInst = hInstance;
    TCHAR szAppName[] = TEXT ("NoGo") ;
    UPARROWcursor = LoadCursor(NULL, IDC_UPARROW);
    ARROWcursor = LoadCursor(NULL, IDC_ARROW);
    ///ע�������򴰿�
    WNDCLASS wndclass;

    wndclass.style = CS_HREDRAW | CS_VREDRAW ;
    wndclass.lpfnWndProc= WndProc ;
    wndclass.cbClsExtra = 0 ;
    wndclass.cbWndExtra = 0 ;
    wndclass.hInstance = hInstance ;
    wndclass.hIcon = LoadIcon (NULL, IDI_APPLICATION) ;
    wndclass.hCursor = LoadCursor (NULL, IDC_ARROW) ;
    wndclass.hbrBackground= (HBRUSH) GetStockObject (LTGRAY_BRUSH) ;
    wndclass.lpszMenuName = NULL ;
    wndclass.lpszClassName = szAppName ;
    ///ע��������ڣ�ѡ��AI�Ĵ��ڣ�
    WNDCLASS wndclassB;
    wndclassB.style = CS_HREDRAW | CS_VREDRAW ;
    wndclassB.lpfnWndProc= WndProcB ;
    wndclassB.cbClsExtra = 0 ;
    wndclassB.cbWndExtra = 0 ;
    wndclassB.hInstance = hInstance ;
    wndclassB.hIcon = LoadIcon (NULL, IDI_APPLICATION) ;
    wndclassB.hCursor = LoadCursor (NULL, IDC_ARROW) ;
    wndclassB.hbrBackground= (HBRUSH) GetStockObject (LTGRAY_BRUSH) ;
    wndclassB.lpszMenuName = NULL ;
    wndclassB.lpszClassName = _T("Select") ;

    if (!RegisterClass (&wndclass) || !RegisterClass(&wndclassB))
    {
        MessageBox ( NULL, _T("���г���ʧ��"),
                     szAppName, MB_ICONERROR) ;
        return 0 ;
    }

    CB.RootHwnd = CreateWindow ( szAppName, _T("��Χ��"),
                          WS_MINIMIZEBOX | WS_SYSMENU,
                          100, 100,
                          CB.RootWidth, CB.RootHeight + 15,
                          NULL, NULL, hInstance, NULL) ;
    ShowWindow (CB.RootHwnd, iCmdShow) ;
    UpdateWindow (CB.RootHwnd) ;

    while (GetMessage (&msg, NULL, 0, 0))
    {
        TranslateMessage (&msg) ;
        DispatchMessage (&msg) ;
    }
    return msg.wParam ;
}

///�����ڹ��̺���
LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT://�ػ���Ϣ
        BeginPaint(hwnd, &CB.ps);
//        HANDLE handle;
//        handle = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
        CB.RePaint();
//        CloseHandle(handle);
//        Sleep(80);
        EndPaint(hwnd, &CB.ps);
        return 0;
    case WM_COMMAND://������������¼�
        switch(LOWORD(wParam))
        {
            //���1ʹ����AI
            case MID_ONE:
                if(!CB.Player1isAI)
                {
                    Type = 1;
                    SelectFun();
                    Param = lParam;
                }
                else
                {
                    SendMessage((HWND)lParam, WM_SETTEXT, (WPARAM)NULL, LPARAM("ʹ��AI"));
                    CB.Player1isAI = false;
                }
                break;
            //���2ʹ����AI
            case MID_TWO:
                if(!CB.Player2isAI)
                {
                    Type = 2;
                    SelectFun();
                    Param = lParam;
                }
                else
                {
                    SendMessage((HWND)lParam, WM_SETTEXT, (WPARAM)NULL, LPARAM("ʹ��AI"));
                    CB.Player2isAI = false;
                }
                break;
            //��ʼ��Ϸ��ť����
            case MID_START:
                if(!CB.Start)
                {
                    ShowWindow(CB.TurnToBlack, SW_SHOW);
                    UpdateWindow (CB.TurnToBlack);
                    CB.PrintTime = true;
                    SendMessage((HWND)lParam, WM_SETTEXT, (WPARAM)NULL, LPARAM("������Ϸ��"));
                    CB.Start = true;
                    if(CB.Player1isAI)
                    {
                        CB.onTurn = isAI1onTurn;
                        CB.PaintChess();
                    }
                    TimerProc();
                }
                break;
        }
        break;
    case WM_CREATE://�����������
        CB.TimerAll1Hwnd = CreateWindow("Static", _T("��Ϸ��ʣ��ʱ��"), WS_CHILD | WS_VISIBLE | ES_CENTER, CB.Base + CB.ChessDiameter * 50 / 130, CB.ChessDiameter * 520 / 200, 120, 17, hwnd, NULL, CB.hInst, NULL);
        CB.TimerRound1Hwnd = CreateWindow("Static", _T("�غ�ʣ��ʱ��"), WS_CHILD | WS_VISIBLE | ES_CENTER, CB.Base + CB.ChessDiameter * 50 / 130, CB.ChessDiameter * 650 / 200, 120, 17, hwnd, NULL, CB.hInst, NULL);
        CB.TimerAll2Hwnd = CreateWindow("Static", _T("��Ϸ��ʣ��ʱ��"), WS_CHILD | WS_VISIBLE | ES_CENTER, CB.Base + CB.ChessDiameter * 50 / 130, CB.ChessDiameter * 1490 / 200, 120, 17, hwnd, NULL, CB.hInst, NULL);
        CB.TimerRound2Hwnd = CreateWindow("Static", _T("�غ�ʣ��ʱ��"), WS_CHILD | WS_VISIBLE | ES_CENTER, CB.Base + CB.ChessDiameter * 50 / 130, CB.ChessDiameter * 1610 / 200, 120, 17, hwnd, NULL, CB.hInst, NULL);
        CB.Player1Hwnd = CreateWindow("Static", _T("Player1"), WS_CHILD | WS_VISIBLE | ES_CENTER, CB.Base + CB.ChessDiameter * 50 / 130, CB.ChessDiameter * 250 / 200 , 200, 20, hwnd, NULL, CB.hInst, NULL);
        CB.Player2Hwnd = CreateWindow("Static", _T("Player2"), WS_CHILD | WS_VISIBLE | ES_CENTER, CB.Base + CB.ChessDiameter * 50 / 130, CB.ChessDiameter * 1195 / 200, 200, 20, hwnd, NULL, CB.hInst, NULL);
        CB.Player1UseAI = CreateWindow("Button", _T("ʹ��AI"), WS_CHILD | WS_VISIBLE | ES_CENTER, CB.Base + CB.ChessDiameter * 155 / 120, CB.ChessDiameter * 365 / 200, 100, 30, hwnd, (HMENU)MID_ONE, CB.hInst, NULL);
        CB.Player2UseAI = CreateWindow("Button", _T("ʹ��AI"), WS_CHILD | WS_VISIBLE | ES_CENTER, CB.Base + CB.ChessDiameter * 155 / 120, CB.ChessDiameter * 1335 / 200, 100, 30, hwnd, (HMENU)MID_TWO, CB.hInst, NULL);
        CB.ChessBoardHwnd = CreateWindow("Static", NULL, WS_CHILD | WS_VISIBLE | ES_CENTER, 0, 0, CB.Base, CB.Base, hwnd, NULL, CB.hInst, NULL);
        CB.StartGame = CreateWindow("Button", _T("��ʼ��Ϸ"), WS_CHILD | WS_VISIBLE | ES_CENTER, CB.Base + CB.ChessDiameter * 125 / 120, CB.ChessDiameter * 895 / 200, 130, 30, hwnd, (HMENU)MID_START, CB.hInst, NULL);
        CB.Timer1A = CreateWindow("Button", NULL, WS_CHILD | WS_VISIBLE | ES_CENTER, CB.Base + CB.ChessDiameter * 50 / 125 + 130, CB.ChessDiameter * 520 / 200, 60, 20, hwnd, NULL, CB.hInst, NULL);
        CB.Timer2A = CreateWindow("Button", NULL, WS_CHILD | WS_VISIBLE | ES_CENTER, CB.Base + CB.ChessDiameter * 50 / 125 + 130, CB.ChessDiameter * 1490 / 200, 60, 20, hwnd, NULL, CB.hInst, NULL);
        CB.Timer1R = CreateWindow("Button", NULL, WS_CHILD | WS_VISIBLE | ES_CENTER, CB.Base + CB.ChessDiameter * 50 / 125 + 130, CB.ChessDiameter * 650 / 200, 60, 20, hwnd, NULL, CB.hInst, NULL);
        CB.Timer2R = CreateWindow("Button", NULL, WS_CHILD | WS_VISIBLE | ES_CENTER, CB.Base + CB.ChessDiameter * 50 / 125 + 130, CB.ChessDiameter * 1610 / 200, 60, 20, hwnd, NULL, CB.hInst, NULL);
        CB.TurnToBlack = CreateWindow("Static", _T("�ֵ����1�º���"), WS_CHILD | WS_VISIBLE | ES_CENTER, CB.Base + CB.ChessDiameter * 150 / 130, CB.ChessDiameter * 780 / 200, 120, 17, hwnd, NULL, CB.hInst, NULL);
        CB.TurnToWhite = CreateWindow("Static", _T("�ֵ����2�°���"), WS_CHILD | ES_CENTER, CB.Base + CB.ChessDiameter * 150 / 130, CB.ChessDiameter * 1060 / 200, 120, 17, hwnd, NULL, CB.hInst, NULL);
        CB.PaintTimer(CB.Timer1A, CB.Timer1R, 1, true);
        CB.PaintTimer(CB.Timer2A, CB.Timer2R, 2, true);
        CB.Board = (HBITMAP)LoadImage(NULL, _T("Image/Board.bmp"), IMAGE_BITMAP, 500, 500, LR_LOADFROMFILE);
        CB.BlackChess = (HBITMAP)LoadImage(NULL, _T("Image/BlackChess.bmp"), IMAGE_BITMAP, 200, 200, LR_LOADFROMFILE);
        CB.WhiteChess = (HBITMAP)LoadImage(NULL, _T("Image/WhiteChess.bmp"), IMAGE_BITMAP, 200, 200, LR_LOADFROMFILE);//LR_LOADMAP3DCOLORS
        CB.Tips = (HBITMAP)LoadImage(NULL, _T("Image/Tips.bmp"), IMAGE_BITMAP, 126, 126, LR_LOADFROMFILE);
        PostMessage(hwnd, WM_PAINT, (WPARAM)NULL, (LPARAM)NULL);
        break;
    case WM_MOUSEMOVE://����ƶ���Ϣ
        CB.point.x = LOWORD(lParam);//��ȡ���λ��
        CB.point.y = HIWORD(lParam);
        if(CB.point.x < CB.Base && CB.point.y < CB.Base)
            SetCursor(UPARROWcursor);
        else
            SetCursor(ARROWcursor);
        break;
    case WM_LBUTTONDOWN://�������¼�
        if(CB.Start == true && CB.GetPointPosition(lParam)) CB.PaintChess();
        break;
    case WM_DESTROY:
        DeleteObject(CB.Board);
        DeleteObject(CB.BlackChess);
        DeleteObject(CB.WhiteChess);
        DeleteObject(CB.Tips);
        PostQuitMessage (0) ;
        return 0 ;
    }
    return DefWindowProc (hwnd, message, wParam, lParam) ;
}
///��ʱ������
void TimerProc()
{
    double Count = GetTickCount();//���ڵļ���
    double Interval = 1000;//ʱ��������λ��ms��
    double Now = Count;//�����Ѽ�¼��ʱ��
    while (GetMessage (&msg, NULL, 0, 0))
    {
        Now = GetTickCount();//��ȡ��ǰ��ʱ
        if(Now - Count > Interval)
        {
            Count = Now;
            if(CB.onTurn == isPlay1onTurn || CB.onTurn == isAI1onTurn)
            {
                CB.AllTime1--;
                CB.Round1--;
                if(CB.AllTime1 == 0)
                {
                    CB.Winner = 2;
                    CB.ReStart();
                    break;
                }
                CB.PaintTimer(CB.Timer1A, CB.Timer1R, 1);
            }
            else if(CB.onTurn == isPlay2onTurn || CB.onTurn == isAI2onTurn)
            {
                CB.AllTime2--;
                CB.Round2--;
                if(CB.AllTime2 == 0)
                {
                    CB.Winner = 1;
                    CB.ReStart();
                    break;
                }
                CB.PaintTimer(CB.Timer2A, CB.Timer2R, 2);
            }
        }
        if(!CB.Start) break;//����Ϸ����ʱ�Ͽ�ѭ��
        ///��������ͨ�Ľ�����Ϣ�ĺ���
        TranslateMessage (&msg) ;
        DispatchMessage (&msg) ;
    }
}
///��Ӧѡ��AI
void SelectFun()
{
    CB.SelectAI = CreateWindow(_T("Select"), _T("��ѡ��һ��AI"), WS_MINIMIZEBOX | WS_SYSMENU, CB.RootWidth / 2 - 125, CB.RootHeight / 2 - 150, 250, 300, CB.RootHwnd, NULL, CB.hInst, NULL);
    GetWindowRect(CB.RootHwnd, &CB.MainWinRect);//��ȡ����������Ļ�е�λ��
    MoveWindow(CB.SelectAI, CB.MainWinRect.left + (CB.RootWidth - 250) / 2, CB.MainWinRect.top + (CB.RootHeight - 300) / 2, 250, 300, false);//�ı䴰��λ�úʹ�С
    ShowWindow(CB.SelectAI, SW_SHOW);//���ô��ڿ���
    int line, column;//���ڼ��AI�Ƿ�����ɣ������Խ��������ˣ�
    ///���AI1
    line = CB.line;
    column = CB.column;
    CB.ai1.GetPosition(CB.line, CB.column, 0);
    if(line != CB.line && column != CB.column)
    {
        ShowWindow(CB.SelectAI1, SW_SHOW);
        ShowSelect1 = true;
    }
    ///���AI2
    CB.line = line;
    CB.column = column;
    CB.ai2.GetPosition(CB.line, CB.column, 0);
    if(line != CB.line && column != CB.column)
    {
        ShowWindow(CB.SelectAI2, SW_SHOW);
        ShowSelect2 = true;
    }
    ///���AI3
    CB.line = line;
    CB.column = column;
    CB.ai3.GetPosition(CB.line, CB.column, 0);
    if(line != CB.line && column != CB.column)
    {
        ShowWindow(CB.SelectAI3, SW_SHOW);
        ShowSelect3 = true;
    }
    //-------//
    CB.line = line;
    CB.column = column;
    UpdateWindow(CB.SelectAI);
}
///ѡ��AI֮��Ĵ���
void Select()
{
    ShowWindow(CB.SelectAI1, SW_HIDE);
    ShowWindow(CB.SelectAI2, SW_HIDE);
    ShowWindow(CB.SelectAI3, SW_HIDE);
    ShowWindow(CB.SelectAI, SW_HIDE);
    DestroyWindow(CB.SelectAI);//ɾ������
    switch(Type)
    {
    case 1:
        switch(Num)
        {
            case 1:CB.Player1AI = &CB.ai1;break;
            case 2:CB.Player1AI = &CB.ai2;break;
            case 3:CB.Player1AI = &CB.ai3;break;
        }
        CB.Player1isAI = true;
        SendMessage((HWND)Param, WM_SETTEXT, (WPARAM)NULL, LPARAM("��ʹ����AI"));
        break;
    case 2:
        switch(Num)
        {
            case 1:CB.Player2AI = &CB.ai1;break;
            case 2:CB.Player2AI = &CB.ai2;break;
            case 3:CB.Player2AI = &CB.ai3;break;
        }
        CB.Player2isAI = true;
        SendMessage((HWND)Param, WM_SETTEXT, (WPARAM)NULL, LPARAM("��ʹ����AI"));
        break;
    }
    ShowSelect1 = false;//�Ƿ���ʾAI
    ShowSelect2 = false;//�Ƿ���ʾAI
    ShowSelect3 = false;//�Ƿ���ʾAI
    if(Type == isPlay1onTurn) CB.onTurn = isAI1onTurn;
    else if(Type == isPlay2onTurn) CB.onTurn = isAI2onTurn;
    if(CB.Start == true && (CB.onTurn == isAI1onTurn ? 1 : 2)== Type) CB.PaintChess();
}
LRESULT CALLBACK WndProcB (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
    case WM_PAINT:
        if(ShowSelect1) ShowWindow(CB.SelectAI1, SW_SHOW);
        if(ShowSelect2) ShowWindow(CB.SelectAI2, SW_SHOW);
        if(ShowSelect3) ShowWindow(CB.SelectAI3, SW_SHOW);
        break;
    case WM_CREATE:
            CB.SelectAI1 = CreateWindow("Button", _T("AI1"), WS_CHILD | ES_CENTER, 45, 20, 160, 50, hwnd, (HMENU)AI_1, CB.hInst, NULL);
            CB.SelectAI2 = CreateWindow("Button", _T("AI2"), WS_CHILD | ES_CENTER, 45, 100, 160, 50, hwnd, (HMENU)AI_2, CB.hInst, NULL);
            CB.SelectAI3 = CreateWindow("Button", _T("AI3"), WS_CHILD | ES_CENTER, 45, 180, 160, 50, hwnd, (HMENU)AI_3, CB.hInst, NULL);
        break;
    case WM_COMMAND:
        switch(LOWORD(wParam))
        {
            //��ѡ����AI1
        case AI_1:
            Num = 1;
            Select();
            break;
            //��ѡ����AI2
        case AI_2:
            Num = 2;
            Select();
            break;
            //��ѡ����AI3
        case AI_3:
            Num = 3;
            Select();
            break;
        }
        break;
    case WM_DESTROY:
        DestroyWindow(CB.SelectAI);//ɾ������
            break;
    }
    return DefWindowProc (hwnd, message, wParam, lParam) ;
}
DWORD WINAPI ThreadProc (PVOID pParam)
{
    CB.RePaint();
    return 0;
}