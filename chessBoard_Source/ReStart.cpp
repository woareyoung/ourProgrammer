#include "../ChessBoard_Header/ChessBoard.h"
///��Ϸ����
void ChessBoard::ReStart()
{
    if(Winner == isBlack) MessageBox(RootHwnd, "��ϲ���1�����ӣ�ʤ��", "����", MB_OK);
    else MessageBox(RootHwnd, "��ϲ���2�����ӣ�ʤ��", "����", MB_OK);
    Init_cross();
    AllTime1 = 900;//��ʱ��15����
    AllTime2 = 900;
    Round1 = 60;//��ʱ60��
    Round2 = 60;
    Start = false;
    Player1isAI = false;
    Player2isAI = false;
    line = 0;
    column = 0;
}
