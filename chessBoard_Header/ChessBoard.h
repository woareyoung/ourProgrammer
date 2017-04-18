#ifndef CHESSBOARD_H_INCLUDED
#define CHESSBOARD_H_INCLUDED
#include "../stdafx.h"
#include "WindowSize.h"
#include "WindowHwnd.h"
#include "PlayerInfo.h"
#include "Chess.h"
#include "AI.h"
#include "../AI1_Header/AI1.h"
#include "../AI2_Header/AI2.h"
#include "../AI3_Header/AI3.h"
#include<tchar.h>

class ChessBoard : public WindowSize, public WindowHwnd, public PlayerInfo, public Chess
{
public:
    ///��InitData.cpp�ļ���
    ChessBoard();//���캯��
    void Init_cross();//��ʼ������״̬����
    ///��PaintBoard.cpp�ļ���
    void PaintBoard();//������
    ///��PaintTimer.cpp�ļ���
    void PaintTimer(HWND All, HWND Round, int Player, bool FirstPrint = false);//���ʱ����Ϣ
    ///��PaintChess.cpp�ļ���
    void PaintChess();//�����Ӻ���
    void PaintAChess(int type);//ʵ�л�����
    bool GetPointPosition(DWORD lParam);//��ȡ����λ��

    ///��WinOrLose.cpp�ļ���
    bool WinOrLose();//�ж�ʤ��
    bool Besieged(int RivalLine, int RivalColumn, int player, int rival);//�ж��Ƿ�Χ��
    ///��ReStart.cpp�ļ���
    void ReStart();
    ///��RePaint.cpp�ļ���
    void RePaint();//��Ӧ�����ػ���Ϣ
    void SetHandle();//���û�����
    void DelHandle();//�ͷŻ�����

    POINT point;//���ڱ������λ��
    int onTurn;//�ֵ�˭

    AI *Player1AI;
    AI *Player2AI;
    AI1 ai1;
    AI2 ai2;
    AI3 ai3;

    int line;//����λ�õ�����
    int column;//����λ�õ�����
private:
    int CrossCross[10];//�������õ�����ֵ

    ///����ת�� ��int2String.cpp�ļ���
    bool TheFirstNumber;
    char string[2];//��������ת��
    char* Int2String(int num);//���ͻ���Ϊ�ַ���
    void addChar(int mid);//���ڸ���ת��

};

#endif // CHESSBOARD_H_INCLUDED
