#include "../ChessBoard_Header/ChessBoard.h"
#include "../stdafx.h"

void ChessBoard::PaintBoard()
{
    int i, j;
    SelectObject(hdcBuffer, Board);
    StretchBlt(hdc, 0, 0, Base, Base, hdcBuffer, 0, 0, 500, 500, SRCCOPY);//�������豸���Ƶ���ʾ�豸��
    //�����ػ�
    //������
    for(i = 1; i < 10; i++)
    {
        for(j = 1; j < 10; j++)
        {
            // ����
            if(cross[i][j] == isBlack)
            {
                SelectObject(hdcBuffer, BlackChess);
                StretchBlt(hdc, CrossCross[j] - ChessDiameter / 2, CrossCross[i] - ChessDiameter / 2, ChessDiameter, ChessDiameter, hdcBuffer, 0, 0, 200, 200, SRCCOPY);//�������豸���Ƶ���ʾ�豸��
            }
            // ����
            else if(cross[i][j] == isWhite)
            {
                SelectObject(hdcBuffer, WhiteChess);
                StretchBlt(hdc, CrossCross[j] - ChessDiameter / 2, CrossCross[i] - ChessDiameter / 2, ChessDiameter, ChessDiameter, hdcBuffer, 0, 0, 200, 200, SRCCOPY);//�������豸���Ƶ���ʾ�豸��
            }
        }
    }
    if(Start == true && line != 0 && column != 0)
    {
        SelectObject(hdcBuffer, Tips);
        StretchBlt(hdc, CrossCross[column] - ChessDiameter / 5, CrossCross[line] - ChessDiameter / 5, ChessDiameter * 2 / 5, ChessDiameter * 2 / 5, hdcBuffer, 0, 0, 126, 126, SRCCOPY);//�������豸���Ƶ���ʾ�豸��
    }
}
