#include "../ChessBoard_Header/ChessBoard.h"
///��Ϸ����
void ChessBoard::ReStart()
{
    if(Winner == isBlack)
        MessageBox(RootHwnd, _T("��ϲ���1�����ӣ�ʤ��"), _T("����"), MB_OK);
    else MessageBox(RootHwnd, _T("��ϲ���2�����ӣ�ʤ��"), _T("����"), MB_OK);

    Init_cross();
    onTurn = 1;
    Winner = 0;
    AllTime1 = 900;//��ʱ��15����
    AllTime2 = 900;
    Round1 = 60;//��ʱ60��
    Round2 = 60;
    Start = false;
    Player1isAI = false;
    Player2isAI = false;
    line = 0;
    column = 0;

    PostMessage(RootHwnd, WM_PAINT, (WPARAM)NULL, (LPARAM)NULL);

    SendMessage(StartGame, WM_SETTEXT, (WPARAM)NULL, LPARAM("��ʼ��Ϸ"));
    ShowWindow(TurnToWhite, SW_HIDE);
    ShowWindow(TurnToBlack, SW_SHOW);

}