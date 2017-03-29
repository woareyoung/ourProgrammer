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
        }
    }
    for(i = 1; i < 3; i++)
    {
        sPoint[i].ChipFormatePosition = new LIST;
        sPoint[i].ChipPosition = new LIST;
        sPoint[i].EyeFormatePosition = new LIST;
        sPoint[i].EyePosition = new LIST;
        sPoint[i].SinglePointPosition = new LIST;
        sPoint[i].TigerMouthFormatePosition = new LIST;
        sPoint[i].TigerMouthPosition = new LIST;

        sPoint[i].ChipFormatePosition -> next = NULL;
        sPoint[i].ChipPosition -> next = NULL;
        sPoint[i].EyeFormatePosition -> next = NULL;
        sPoint[i].EyePosition -> next = NULL;
        sPoint[i].SinglePointPosition -> next = NULL;
        sPoint[i].TigerMouthFormatePosition -> next = NULL;
        sPoint[i].TigerMouthPosition -> next = NULL;

        sPoint[i].ChipFormatePosition -> prior = NULL;
        sPoint[i].ChipPosition -> prior = NULL;
        sPoint[i].EyeFormatePosition -> prior = NULL;
        sPoint[i].EyePosition -> prior = NULL;
        sPoint[i].SinglePointPosition -> prior = NULL;
        sPoint[i].TigerMouthFormatePosition -> prior = NULL;
        sPoint[i].TigerMouthPosition -> prior = NULL;
    }

    ///��ʼ���ر���ֵ
    PointStyle[1] = -3;//�����
    PointStyle[2] = 9;//���Է����ڣ���������������
    PointStyle[3] = 7;//�γɼ������ڣ��������𼶽���
    PointStyle[4] = 8;//�γɼ����ۣ��������𼶽���
    PointStyle[5] = 5;//�γɼ���ȱ�ڣ��������𼶽���
    PointStyle[6] = 15;//��ֹ�Է�3��Χɱ����������������
    PointStyle[7] = 20;//��ֹ�Է�4��Χɱ���������𼶽���
    PointStyle[8] = 10;//��ֹ�Է�2��Χɱ�����Է�����
    PointStyle[9] = 4;//�ڼ���ʣ��һ��λ��ʱ�Է�����1�Ӽ�ȺΧɱ
    PointStyle[10] = 5;//�ڼ���ʣ��һ��λ��ʱ�Է�����2�Ӽ�ȺΧɱ
    PointStyle[11] = 5;//�ڶԷ�ʣ��һ��λ��ʱ��������1�Ӽ�ȺΧɱ
    PointStyle[12] = 6;//�ڶԷ�ʣ��һ��λ��ʱ��������2�Ӽ�ȺΧɱ
    PointStyle[13] = 1;//��伺������
    PointStyle[14] = 2;//��伺������
    PointStyle[15] = 3;//��伺�����㣬�������𼶽���
    PointStyle[16] = 3;//��伺��ȱ��
    PointStyle[17] = 6;//���Է�ȱ�ڣ���������������
}
