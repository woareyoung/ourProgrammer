#include "../stdafx.h"
#include "../AI1_Header/AI1.h"

///��ʼ������
AI1::AI1()
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
    ///��ʼ���ر���ֵ
    PointStyle[1] = -3;//���������Ϊ-3��
    PointStyle[2] = 50;//���Է����ڣ���������������
    PointStyle[17] = 11;//���Է�ȱ�ڣ���������������
    PointStyle[13] = -2;//��伺����������Ϊ-2��
    PointStyle[3] = 6;//�γɼ������ڣ��������𼶽���
    PointStyle[4] = 8;//�γɼ����ۣ��������𼶽���
    PointStyle[5] = 4;//�γɼ���ȱ�ڣ��������𼶽���
    PointStyle[6] = 28;//��ֹ�Է��γɻ��ڣ���������������
    PointStyle[7] = 40;//��ֹ�Է��γ��ۣ��������𼶽���
    PointStyle[8] = 7;//��ֹ�Է��γ�ȱ�ڡ����Է�����
    PointStyle[14] = -1;//��伺����������Ϊ-1��
    PointStyle[15] = 1;//��伺�����㣬�������𼶽���
    PointStyle[16] = -8;//��伺��ȱ��
    PointStyle[9] = -2;//�Է����˻�����λ������Ϊ-2��
    PointStyle[10] = -5;//�����ӵ�λ�õķ�ֵ

    PointStyle[11] = 5;//�ڶԷ�ʣ��һ��λ��ʱ��������1�Ӽ�ȺΧɱ
    PointStyle[12] = 6;//�ڶԷ�ʣ��һ��λ��ʱ��������2�Ӽ�ȺΧɱ
    ///��ʼ������
    RivalSinglePointPoor = 100;
    RivalChipPoor = 2;
    RivalTigerMouthPoor = 2;

    RivalFormatChipPoor = 100;
    RivalFormatTigerMouthPoor = 2;
    RivalFormatEyePoor = 1;

    MySinglePointPoor = 1;
    MyChipPoor = 100;
    MyTigerMouthPoor = 100;

    MyFormatChipPoor = 1;
    MyFormatTigerMouthPoor = 1;
    MyFormatEyePoor = 1;
}
