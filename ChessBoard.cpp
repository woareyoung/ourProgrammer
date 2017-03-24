#include "StdAfx.h"
#include "buweiqi.h"

/**
 * [ChessBoard::PaintBoard ������]
 */

void ChessBoard::PaintBoard()
{
    int i, j,k;
    char *Number;
    char buffer[2];
    buffer[0] = NULL,buffer[1] = NULL;//���buffer����
    //����ÿ���������������0����ʾû�����ӣ���1����ʾ���ӣ���2����ʾ����
    if(Start == false)
    {
        for(i = 1; i < 10; i++)
        {
            for(j = 1; j < 10; j++)
            {
                cross[i][j] = 0;//���������ӣ������衰0��
            }
        }
    }
    SetTextColor(graphicsHdc, RGB(0,0,0));//�����ı���ɫΪ��ɫ

    pen = CreatePen(PS_SOLID, 10, RGB(0,0,0));//�������ʣ�������Ϊ��ɫϸ���� ���� ȥ������о�ûʲô���⣬����ע�͵�
    ChessBoardNumber = true;
    //������
    for(i = 1; i < 10; i++)
    {
        Number = Int2String(i);
        MoveToEx(graphicsHdc, CrossCross[i], CrossCross[1], NULL);//�ƶ����
        LineTo(graphicsHdc, CrossCross[i], CrossCross[9]);//������
        MoveToEx(graphicsHdc, CrossCross[1], CrossCross[i], NULL);//�ƶ����
        LineTo(graphicsHdc, CrossCross[9], CrossCross[i]);//������
        TextOut(graphicsHdc, CrossCross[i] - 2, 0, Number, 1);//д�ı������̵��е����ֱ��
        TextOut(graphicsHdc, 0, CrossCross[i] - 5, Number, 1);//д�ı������̵��е����ֱ��
    }

//�����ػ�
    //������
    for(i = 0; i < 10; i++)
        for(j = 0; j < 10; j++)
        {
            // ����
            if(cross[i][j] == isBlack)
            {
                // ����
                HBRUSH rush = CreateSolidBrush(RGB(0, 0, 0));
                // ���뻭�ʵ�������
                SelectObject(graphicsHdc, rush);
                // ���һ����Բ
                // ��һ��������HDC�豸���������
                // �ڶ�������������X1��λ��-����X1��ƫ����/2
                // ����������������Y1��λ��-����Y1��ƫ����/2
                // ���ĸ�����������X2��λ��-����X2��ƫ����/2
                // ���������������Y2��λ��-����Y2��ƫ����/2
                Ellipse(graphicsHdc, CrossCross[j] - ChessDiameter / 2, CrossCross[i] - ChessDiameter / 2,
                        CrossCross[j] + ChessDiameter / 2, CrossCross[i] + ChessDiameter / 2);
                // �ͷ�GUI����
                DeleteObject(rush);
            }
            // ����
            else if(cross[i][j] == isWhite)
            {
                // ����
                HBRUSH rush = CreateSolidBrush(RGB(255, 255, 255));
                // ���뻭�ʵ�������
                SelectObject(graphicsHdc, rush);
                // ���һ����Բ
                // ��һ��������HDC�豸���������
                // �ڶ�������������X1��λ��-����X1��ƫ����/2
                // ����������������Y1��λ��-����Y1��ƫ����/2
                // ���ĸ�����������X2��λ��-����X2��ƫ����/2
                // ���������������Y2��λ��-����Y2��ƫ����/2
                Ellipse(graphicsHdc, CrossCross[j] - ChessDiameter / 2, CrossCross[i] - ChessDiameter / 2,
                        CrossCross[j] + ChessDiameter / 2, CrossCross[i] + ChessDiameter / 2);
                // �ͷ�GUI����
                DeleteObject(rush);
            }
        }

    //��ע�����Ϣ
    Number = "Player1";
    //HDC X Y ��Ϣ ��Ϣ����
    TextOut(graphicsHdc, Base + ChessDiameter * 200 / 130, ChessDiameter, Number, strlen(Number));
    Number = "Player2";
    //HDC X Y ��Ϣ ��Ϣ����
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
    //��ȡʱ��
    ChessBoardNumber = false;
    char buffer[2];
    buffer[0] = NULL,buffer[1] = NULL;//���buffer����
    lstrcat(buffer, Int2String(AllTime / 60));
    lstrcat(buffer, "��");
    lstrcat(buffer, Int2String(AllTime % 60));
    TextOut(graphicsHdc, Base, ChessDiameter * 3 + offset, "��Ϸ��ʣ��ʱ��  ", 14);
    TextOut(graphicsHdc, Base + 110, ChessDiameter * 3 + offset, buffer, strlen(buffer));//������1��Ϸ��ʣ��ʱ��
    TextOut(graphicsHdc, Base, ChessDiameter * 4 + offset, "�غ�ʣ��ʱ��    ", 14);
    buffer[0] = NULL,buffer[1] = NULL;//���buffer����
    lstrcat(buffer, Int2String(Round / 60));
    lstrcat(buffer, "��");
    lstrcat(buffer, Int2String(Round % 60));
    TextOut(graphicsHdc, Base + 110, ChessDiameter * 4 + offset, buffer, strlen(buffer));//������1�غ�ʣ��ʱ��
}

void ChessBoard::PrintInfo()//��ӡ��ҵ���Ϣ
{
    char *Number;
    if(AI1 == false)
    {
        Number = "    ���1δʹ��AI����F1����ʹ��AI    ";
        TextOut(graphicsHdc, Base, ChessDiameter * 2, Number, strlen(Number));
    }
    else
    {
        Number = "���1��ʹ��AI����F1����ȡ��ʹ��AI";
        TextOut(graphicsHdc, Base, ChessDiameter * 2, Number, strlen(Number));
    }
    if(AI2 == false)
    {
        Number ="    ���2δʹ��AI����F2����ʹ��AI    ";
        TextOut(graphicsHdc, Base, ChessDiameter * 2 + Base / 2, Number, strlen(Number));
    }
    else
    {
        Number ="���2��ʹ��AI����F2����ȡ��ʹ��AI";
        TextOut(graphicsHdc, Base, ChessDiameter * 2 + Base / 2, Number, strlen(Number));
    }
    if(Start == false)
    {
        Number = "���س�����ʼ��Ϸ";
    }
    else
    {
        Number = "      �ѿ�ʼ��Ϸ      ";
    }
    TextOut(graphicsHdc, Base + ChessDiameter * 85 / 100, ChessDiameter * 5, Number, strlen(Number));
}
