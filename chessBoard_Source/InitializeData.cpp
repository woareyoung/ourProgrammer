#include "../stdafx.h"
#include "../buweiqi.h"

/**
 * ���캯��
 */
ChessBoard::ChessBoard()
{
    Round = 0;
    AllTime1 = 900;//��ʱ��15����
    AllTime2 = 900;
    Round1 = 60;//��ʱ60��
    Round2 = 60;
    Start = false;
    Player1isAI = false;
    Player2isAI = false;
    onTurn = 1;//���1������
}
/**
 * [ChessBoard::Initialize ��ʼ����ά������Ϣ]
 */
void ChessBoard::Initialize()
{
    int i;//������������
    Width = 1366 * 800 / GetSystemMetrics(SM_CXSCREEN);//��ȡ��Ļ��Ȳ����ô�����
    Height = 768 * 550 / GetSystemMetrics(SM_CYSCREEN);//��ȡ��Ļ�߶Ȳ����ô���߶�
    Base = Width > Height ? Height : Width;//���ô������ݹ�ģ����Ӧ��ͬƽ̨
    ChessDiameter = Base / 10;//��������ֱ����Ҳ��������ÿ�����ӵı߳�
    //����ÿ������������ֵ
    for(i = 1; i < 10; i++)
    {
        CrossCross[i] = i * ChessDiameter;
    }

}

/**
 * [ChessBoard::HDCInitialize ��ʼ���豸�������]
 * @param hwnd [���ھ��]
*/
void ChessBoard::HDCInitialize(HWND hwnd)
{
    graphicsHdc = GetDC(ParentHwnd);//��ȡ�豸�������
    // hdcBuffer = CreateCompatibleDC(graphicsHdc);//������grapgicsHdc���ݵ��ڴ�DC
    // bitmap = CreateCompatibleBitmap(hdcBuffer, Width, Height);//����һ���ʹ��ڼ��ݵĿյ�λͼ����

    PrintInfo();
    PaintTimer();
    PaintBoard();
    SelectObject(hdcBuffer, bitmap);//����λͼ����ŵ�hdcBuffer��
    ReleaseDC(ParentHwnd, graphicsHdc);//�ͷŻ������
}
