#include "../stdafx.h"
#include "../buweiqi.h"

/**
 * [ChessBoard::PaintChess ��������]
 */
void ChessBoard::PaintChess()
{
    _cprintf("%d:  line=%d, column=%d\n", Round, line, column);
    // �ж��ֵ���һ��
    switch(onTurn)
    {
    case isPlay1onTurn://����ɫ����
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 10; j++)
                Cross[i][j] = false;
        if(cross[line][column] == 0)
        {
            if(Player2isAI == false)
                onTurn = isPlay2onTurn;
            else
                onTurn = isAI2onTurn;
            PaintAChess(1);
            //���ѷ�ʤ�����������Ϸ
            if(WinOrLose() == true)
            {
                Start = false;
                reStart(ParentHwnd);
            }
            else if(Player2isAI == true) PaintChess();
        };
        break;
    case isPlay2onTurn://����ɫ����
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 10; j++)
                Cross[i][j] = false;
        if(cross[line][column] == 0)
        {
            if(Player1isAI == false)
                onTurn = isPlay1onTurn;
            else
                onTurn = isAI1onTurn;
            PaintAChess(2);
            //���ѷ�ʤ�����������Ϸ
            if(WinOrLose() == true)
            {
                Start = false;
                reStart(ParentHwnd);
            }
            else if(Player1isAI == true) PaintChess();
        };
        break;
    //����ɫ����
    case isAI1onTurn:
    {
        if(Player2isAI == true)
            onTurn = isAI2onTurn;
        else
            onTurn = isPlay2onTurn;

        ///�ڴ˵���AI���򣬷��������λ�ã��ڼ��У��ڼ��У�
        Player1AI->GetPosition(line, column, onTurn);
        PaintAChess(isBlack);
        //���Է��ǵ��ԣ������ж���û�зֳ�ʤ��
        bool win = WinOrLose();
        if(Player2isAI == true && !win) PaintChess();//���Է��ǵ��ԣ���ݹ�
        else if(win)
        {
            Winner = 2;
            Start = false;
            reStart(ParentHwnd);
        }
    };
    break;
    //����ɫ����
    case isAI2onTurn:
    {
        if(Player1isAI == true)
            onTurn = isAI1onTurn;
        else
            onTurn = isPlay1onTurn;

        ///�ڴ˵���AI���򣬷��������λ�ã��ڼ��У��ڼ��У�
        Player2AI->GetPosition(line, column, onTurn);
        PaintAChess(isWhite);
        //���Է��ǵ��ԣ������ж���û�зֳ�ʤ��
        bool win = WinOrLose();
        if(Player1isAI == true && !win)
            PaintChess();//���Է��ǵ��ԣ���ݹ�
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
 * [ChessBoard::PaintAChess ����һ������]
 * @param type [����--���ӡ�����]
 */
void ChessBoard::PaintAChess(int type)
{
    HBRUSH rush;//��ˢ���
    cross[line][column] = type;//����AI�����ȡ�����к�������¼��line��column
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
    //������
    Ellipse(graphicsHdc, CrossCross[column] - ChessDiameter / 2, CrossCross[line] - ChessDiameter / 2,
            CrossCross[column] + ChessDiameter / 2, CrossCross[line] + ChessDiameter / 2);
    DeleteObject(rush);
    PostMessage(ParentHwnd, WM_PAINT, 0, 0);
}


/**
 * [ChessBoard::getPosition ��ȡ��������̵�λ�ã��ڼ��еڼ��У�]
 * @param  lParam [�޷��ų�����]
 * @return        [������λ��û��Խ���ʱ�򷵻�true����֮����false]
 */
bool ChessBoard::getPosition(DWORD lParam)
{
    point.x = LOWORD(lParam);// �õ�һ��32bit���ĵ�16bit
    point.y = HIWORD(lParam);// �õ�һ��32bit���ĸ�16bit
    int a, b;
    b = (point.x - ChessDiameter / 2) / ChessDiameter + 1;
    a = (point.y - ChessDiameter / 2) / ChessDiameter + 1;
    // �ж��Ƿ�Խ��
    if(a < 10 && b < 10 && a > 0 && b > 0)
    {
        line = a;
        column = b;
        return true;
    }
    return false;
}
