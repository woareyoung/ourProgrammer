#include "../stdafx.h"
#include "../AI1_Header/AI1.h"
///��ȡ����λ��
void AI1::GetPosition(int &line, int &column, int onTurn)
{
    OT = (onTurn == 1 || onTurn == -1) ? 1 : 2;//OT = (unsigned)onTurn������ǿ������ת��������
    PlayerNumber = OT == 1 ? 2 : 1;//���ø�AI����ұ��
    cross[line][column] = OT;//�ȸ���������Ϣ����
    UpdateScore(line, column, OT);//���·�ֵ
    ///��������λ����һֱѭ����ֱ����������λ��
    while(true)
    {
        GetMaxScorePosition();
        line = MaxScorePosition / 10;
        column = MaxScorePosition % 10;
        if(cross[line][column] != 0) continue;//�����Ȼûʲô�ã����������
        cross[line][column] = OT;
        ///����λ�ö��ڶԷ���˵�����壬�����ѭ��
        if(DeadCheck(line, column, OT) == true && MaxScore > PointStyle[9])
        {
            Score[line][column] = PointStyle[9];
            cross[line][column] = 0;
            continue;
        }
        cross[line][column] = PlayerNumber;
        ///��������λ�ã��������ϻ���λ�ò������壬�����ѭ��
        if(DeadCheck(line, column, PlayerNumber) == true && MaxScore > PointStyle[1])
        {
            Score[line][column] = PointStyle[1];
            cross[line][column] = 0;
            continue;
        }
        else break;
    }
    UpdateScore(line, column, PlayerNumber);
}
