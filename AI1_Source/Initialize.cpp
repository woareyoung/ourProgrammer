#include "../stdafx.h"
#include "../AI1_Header/AI1.h"

///��ʼ������
AI1::AI1()
{
    InitializeD();
    ///��ʼ���ر���ֵ
    PointStyle[1] = -3;//���������Ϊ-3��
    PointStyle[2] = 50;//���Է����ڣ���������������
    PointStyle[17] = 26;//���Է�ȱ�ڣ���������������
    PointStyle[13] = -2;//��伺����������Ϊ-2��
    PointStyle[3] = 6;//�γɼ������ڣ��������𼶽���
    PointStyle[4] = 8;//�γɼ����ۣ��������𼶽���
    PointStyle[5] = 4;//�γɼ���ȱ�ڣ��������𼶽���
    PointStyle[6] = 33;//��ֹ�Է��γɻ��ڣ���������������
    PointStyle[7] = 45;//��ֹ�Է��γ��ۣ��������𼶽���
    PointStyle[8] = 20;//��ֹ�Է��γ�ȱ�ڡ����Է�����
    PointStyle[14] = -1;//��伺����������Ϊ-1��
    PointStyle[15] = 1;//��伺�����㣬�������𼶽���
    PointStyle[16] = -8;//��伺��ȱ��
    PointStyle[9] = -2;//�Է����˻�����λ������Ϊ-2��
    PointStyle[10] = -5;//�����ӵ�λ�õķ�ֵ

    PointStyle[11] = 5;//�ڶԷ�ʣ��һ��λ��ʱ��������1�Ӽ�ȺΧɱ
    PointStyle[12] = 6;//�ڶԷ�ʣ��һ��λ��ʱ��������2�Ӽ�ȺΧɱ
    ///��ʼ������
    RivalSinglePointPoor = 100;//�Է�����
    RivalChipPoor = 20;//�Է�ȱ��
    RivalTigerMouthPoor = 13;//�Է�����

    RivalFormatChipPoor = 10;//�Է��γ�ȱ��
    RivalFormatTigerMouthPoor = 14;//�Է��γɻ���
    RivalFormatEyePoor = 18;//�Է��γ���

    MySinglePointPoor = 1;//��������
    MyChipPoor = 100;//����ȱ��
    MyTigerMouthPoor = 100;//��������

    MyFormatChipPoor = 1;//�����γ�ȱ��
    MyFormatTigerMouthPoor = 1;//�����γɻ���
    MyFormatEyePoor = 1;//�����γ���
}
///��ʼ������
void AI1::InitializeD()
{
    int i, j;
    ///��ʼ������
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            Score[i][j] = 1;
            cross[i][j] = 0;
            Cross[i][j] = false;
        }
    }
    Score[0][0] = -3;
}
