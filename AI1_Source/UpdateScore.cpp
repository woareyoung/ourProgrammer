#include "../AI1_Header/AI1.h"
///��������λ�÷�ֵ���������У���
void AI1::UpdateScore(int row1, int row2, int who)
{
    Score[row1][row2] = 0;//���������Ϊ0��
    if(row1 != 0 && row2 - 1 > -1 && cross[row1][row2 - 1] == 0) RecordSpecialPoint(row1, row2 - 1, who);//�鿴���������λ���ϵ������
    if(row1 != 0 && row2 + 1 < 10 && cross[row1][row2 + 1] == 0) RecordSpecialPoint(row1, row2 + 1, who);//�鿴�������ұ�λ���ϵ������
    if(row2 != 0 && row1 - 1 > -1 && cross[row1 - 1][row2] == 0) RecordSpecialPoint(row1 - 1, row2, who);//�鿴�������ϱ�λ���ϵ������
    if(row2 != 0 && row1 + 1 < 10 && cross[row1 + 1][row2] == 0) RecordSpecialPoint(row1 + 1, row2, who);//�鿴�������±�λ���ϵ������
    ///���ֵ��Լ�ʱ�ٸ��·�ֵ���Լ������ֻ��¼�����λ��
    if(who != PlayerNumber) Reset();//���Է��������ٸ���������Ϣ��ʼ����ֵ
}
///��������
void AI1::RecordSpecialPoint(int row1, int row2, int who)
{
    int n = row1 * 10 + row2;
    int sc = GetChessAmount(row1, row2, who);//�鿴�ض�λ����Χ�ж��ٸ��Է�������
    switch(sc)
    {
        //ֻ���ұ������ӣ�ǰ��������������
        case 1:AddRecord(sPoint[who].SinglePointPosition, sPoint[who].SinglePointPosition, sPoint[who].ChipFormatePosition, sPoint[who].SinglePointPosition, n, n + 10, n - 10, n - 1, 0, 5);break;
        //ֻ����������ӣ�ǰ��������������
        case 2:AddRecord(sPoint[who].SinglePointPosition, sPoint[who].SinglePointPosition, sPoint[who].ChipFormatePosition, sPoint[who].SinglePointPosition, n, n + 10, n + 1, n - 10, 0, 5);break;
        //���ұ߶�������
        case 3:AddRecord(sPoint[who].SinglePointPosition, sPoint[who].ChipFormatePosition, sPoint[who].TigerMouthFormatePosition, sPoint[who].ChipPosition, n, n + 10, n - 10, 0, 0, 2);break;
        //ֻ���±������ӣ�ǰ��������������
        case 4:AddRecord(sPoint[who].SinglePointPosition, sPoint[who].SinglePointPosition, sPoint[who].ChipFormatePosition, sPoint[who].SinglePointPosition, n, n - 10, n + 1, n - 1, 0, 5);break;
        //�¡��ұ߶�������
        case 5:AddRecord(sPoint[who].SinglePointPosition, sPoint[who].ChipFormatePosition, sPoint[who].TigerMouthFormatePosition, sPoint[who].ChipPosition, n, n + 10, n + 1, 0, 0, 2);break;
        //�¡���߶�������
        case 6:AddRecord(sPoint[who].SinglePointPosition, sPoint[who].ChipFormatePosition, sPoint[who].TigerMouthFormatePosition, sPoint[who].ChipPosition, n, n + 10, n - 1, 0, 0, 2);break;
        //�ҡ����¶�������
        case 7:AddRecord(sPoint[who].ChipPosition, sPoint[who].TigerMouthFormatePosition, sPoint[who].EyeFormatePosition, sPoint[who].TigerMouthPosition, n, n + 1, n - 1, n + 10, 0, 3);break;
        //ֻ���ϱ������ӣ�ǰ��������������
        case 8:AddRecord(sPoint[who].SinglePointPosition, sPoint[who].SinglePointPosition, sPoint[who].ChipFormatePosition, sPoint[who].SinglePointPosition, n, n + 10, n + 1, n - 1, 0, 5);break;
        //�ҡ��϶�������
        case 9:AddRecord(sPoint[who].SinglePointPosition, sPoint[who].ChipFormatePosition, sPoint[who].TigerMouthFormatePosition, sPoint[who].ChipPosition, n, n + 1, n - 10, 0, 0, 2);break;
        //���϶�������
        case 10:AddRecord(sPoint[who].SinglePointPosition, sPoint[who].ChipFormatePosition, sPoint[who].TigerMouthFormatePosition, sPoint[who].ChipPosition, n, n - 1, n - 10, 0, 0, 2);break;
        //���ҡ��϶�������
        case 11:AddRecord(sPoint[who].ChipPosition, sPoint[who].TigerMouthFormatePosition, sPoint[who].EyeFormatePosition, sPoint[who].TigerMouthPosition, n, n - 1, n + 1, n - 10, 0, 3);break;
        //�ϡ��¶�������
        case 12:AddRecord(sPoint[who].SinglePointPosition, sPoint[who].ChipFormatePosition, sPoint[who].TigerMouthFormatePosition, sPoint[who].ChipPosition, n, n + 10, n - 10, 0, 0, 2);break;
        //�ϡ��¡��Ҷ�������
        case 13:AddRecord(sPoint[who].ChipPosition, sPoint[who].TigerMouthFormatePosition, sPoint[who].EyeFormatePosition, sPoint[who].TigerMouthPosition, n, n - 10, n + 10, n + 1, 0, 3);break;
        //�ϡ��¡���������
        case 14:AddRecord(sPoint[who].ChipPosition, sPoint[who].TigerMouthFormatePosition, sPoint[who].EyeFormatePosition, sPoint[who].TigerMouthPosition, n, n - 10, n + 10, n - 1, 0, 3);break;
        //�ϡ��¡����Ҷ�������
        case 15:AddRecord(sPoint[who].TigerMouthPosition, sPoint[who].EyeFormatePosition, sPoint[who].EyeFormatePosition, sPoint[who].EyePosition, n, n - 1, n + 1, n - 10, n + 10, 4);break;
    }
}
///��������ͨ�ú���
void AI1::AddRecord(LIST *LastSpecialPoint, LIST *LastFormatePoint, LIST *ThisFormatePoint, LIST *ThisSpecialPoint, int n, int n1, int n2, int n3, int n4, int amo)
{
    ThisSpecialPoint->insert(n);
    if(amo < 5)
    {
        LastSpecialPoint->Delete(n);
        switch(amo)
        {
        case 4:LastFormatePoint->Delete(n4);
        case 3:LastFormatePoint->Delete(n3);
        case 2:LastFormatePoint->Delete(n2);
        case 1:LastFormatePoint->Delete(n1);break;
        }
    }
    switch(amo)
    {
        case 4:ThisFormatePoint->insert(n);break;
        case 5:;
        case 3:ThisFormatePoint->insert(n3);
        case 2:ThisFormatePoint->insert(n2);
        case 1:ThisFormatePoint->insert(n1);break;
    }
}
///����������Ϣ��ʼ����ֵ
void AI1::Reset()
{
    int i, j;
    int mi = PlayerNumber == 1 ? 2 : 1;
    for(i = 1; i < 10; i++)
    {
        for(j = 1; j < 10; j++)
        {
            if(Score[i][j] != 0) Score[i][j] = 1;
        }
    }
    ///���ü����������ӷ�ֵ
    if(sPoint[PlayerNumber].SinglePointPosition -> next != NULL)
        AddScore(sPoint[PlayerNumber].SinglePointPosition -> next, PointStyle[15], 1);
    ///���ü���ȱ�����ӷ�ֵ
    if(sPoint[PlayerNumber].ChipPosition -> next != NULL)
        AddScore(sPoint[PlayerNumber].ChipPosition -> next, PointStyle[16]);
    ///���ü����������ӷ�ֵ
    if(sPoint[PlayerNumber].TigerMouthPosition -> next != NULL)
        AddScore(sPoint[PlayerNumber].TigerMouthPosition -> next, PointStyle[14]);
    ///���ü��������ӷ�ֵ
    if(sPoint[PlayerNumber].EyePosition -> next != NULL)
        AddScore(sPoint[PlayerNumber].EyePosition -> next, PointStyle[13]);
    ///���ü����γ�ȱ�����ӷ�ֵ
    if(sPoint[PlayerNumber].ChipFormatePosition -> next != NULL)
        AddScore(sPoint[PlayerNumber].ChipFormatePosition -> next, PointStyle[5], 1);
    ///���ü����γɻ������ӷ�ֵ
    if(sPoint[PlayerNumber].TigerMouthFormatePosition -> next != NULL)
        AddScore(sPoint[PlayerNumber].TigerMouthFormatePosition -> next, PointStyle[3], 1);
    ///���ü����γ������ӷ�ֵ
    if(sPoint[PlayerNumber].EyeFormatePosition -> next != NULL)
        AddScore(sPoint[PlayerNumber].EyeFormatePosition -> next, PointStyle[4], 1);
    ///�������Է��������ӷ�ֵ
    if(sPoint[mi].SinglePointPosition -> next != NULL)
        AddScore(sPoint[mi].SinglePointPosition -> next, PointStyle[8]);
    ///�������Է�ȱ�����ӷ�ֵ
    if(sPoint[mi].ChipPosition -> next != NULL)
        AddScore(sPoint[mi].ChipPosition -> next, PointStyle[17], 2);
    ///�������Է��������ӷ�ֵ
    if(sPoint[mi].TigerMouthPosition -> next != NULL)
        AddScore(sPoint[mi].TigerMouthPosition -> next, PointStyle[2], 2);
    ///������϶Է��γ�ȱ�����ӷ�ֵ
    if(sPoint[mi].ChipFormatePosition -> next != NULL)
        AddScore(sPoint[mi].ChipFormatePosition -> next, PointStyle[8]);
    ///������϶Է��γɻ������ӷ�ֵ
    if(sPoint[mi].TigerMouthFormatePosition -> next != NULL)
        AddScore(sPoint[mi].TigerMouthFormatePosition -> next, PointStyle[6], 2);
    ///������϶Է��γ������ӷ�ֵ
    if(sPoint[mi].EyeFormatePosition -> next != NULL)
        AddScore(sPoint[mi].EyeFormatePosition -> next, PointStyle[7], 2);
    ///�������Է������ӷ�ֵ
    if(sPoint[mi].EyePosition -> next != NULL)
        for(LIST *Beg = sPoint[mi].EyePosition -> next; Beg != NULL; Beg = Beg->next)
        {
            Score[Beg->Position / 10][Beg->Position % 10] = PointStyle[1];
        }
}
///���ӷ�ֵ
void AI1::AddScore(LIST *Beg, int score, int NumberPoor)
{
    while(Beg != NULL)
    {
        ResetScore(Beg->Position / 10, Beg->Position % 10, score, NumberPoor);//�ӷ�
        if(Beg->next == NULL) break;
        else Beg = Beg->next;
    }
}
///���������Ӱ��ķ�ֵ
///�������С��С����ķ�ֵ�������
void AI1::ResetScore(int row1, int row2, int score, int NumberPoor)
{
    int angelx1, angelx2, angelx3, angelx4;//4���ǵĺ�����
    int angely1, angely2, angely3, angely4;//4���ǵ�������
    int level = 0;
    Score[row1][row2] += score;//�ȶ����ļӷ�
    ///��ɢ�ӷ�
    while(score - NumberPoor > 0)
    {
        score -= NumberPoor;//��������һ��
        level++;//������չһ��
        ///��һ�����Ͻ�����
        angelx1 = row1 - level == 0 ? 1 : row1 - level;
        angely1 = row2 - level == 0 ? 1 : row2 - level;
        ///��һ�����Ͻ�����
        angelx2 = row1 - level == 0 ? 1 : row1 - level;
        angely2 = row2 + level == 10 ? 9 : row2 + level;
        ///��һ�����½�����
        angelx3 = row1 + level == 10 ? 9 : row1 + level;
        angely3 = row2 + level == 10 ? 9 : row2 + level;
        ///��һ�����½�����
        angelx4 = row1 + level == 10 ? 9 : row1 + level;
        angely4 = row2 - level == 0 ? 1 : row2 - level;
        ///�ӷ�
        for(; angely1 < angely2; angely1++)
        {
            if(Score[angelx1][angely1] > 0)
                Score[angelx1][angely1] += score;
        }
        for(; angelx2 < angelx3; angelx2++)
        {
            if(Score[angelx2][angely2] > 0)
                Score[angelx2][angely2] += score;
        }
        for(; angely3 > angely4; angely3--)
        {
            if(Score[angelx3][angely3] > 0)
                Score[angelx3][angely3] += score;
        }
        for(; angelx4 > angelx1; angelx4--)
        {
            if(Score[angelx4][angely4] > 0)
                Score[angelx4][angely4] += score;
        }
    }
}
