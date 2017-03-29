#include "../AI1_Header/AI1.h"
///更新棋盘位置分值，参数：行，列
void AI1::UpdateScore(int row1, int row2, int who)
{
    Score[row1][row2] = 0;//设置下棋点为0分
    if(row1 != 0 && row2 - 1 > -1 && cross[row1][row2 - 1] == 0) RecordSpecialPoint(row1, row2 - 1, who);//查看下棋点的左边位置上的特殊点
    if(row1 != 0 && row2 + 1 < 10 && cross[row1][row2 + 1] == 0) RecordSpecialPoint(row1, row2 + 1, who);//查看下棋点的右边位置上的特殊点
    if(row2 != 0 && row1 - 1 > -1 && cross[row1 - 1][row2] == 0) RecordSpecialPoint(row1 - 1, row2, who);//查看下棋点的上边位置上的特殊点
    if(row2 != 0 && row1 + 1 < 10 && cross[row1 + 1][row2] == 0) RecordSpecialPoint(row1 + 1, row2, who);//查看下棋点的下边位置上的特殊点
    ///当轮到自己时再更新分值，自己下棋后只记录特殊点位置
    if(who != PlayerNumber) Reset();//仅对方下完棋再根据已有信息初始化分值
}
///添加特殊点
void AI1::RecordSpecialPoint(int row1, int row2, int who)
{
    int n = row1 * 10 + row2;
    int sc = GetChessAmount(row1, row2, who);//查看特定位置周围有多少个对方的棋子
    switch(sc)
    {
        //只有右边有棋子，前两个参数无意义
        case 1:AddRecord(sPoint[who].SinglePointPosition, sPoint[who].SinglePointPosition, sPoint[who].ChipFormatePosition, sPoint[who].SinglePointPosition, n, n + 10, n - 10, n - 1, 0, 5);break;
        //只有左边有棋子，前两个参数无意义
        case 2:AddRecord(sPoint[who].SinglePointPosition, sPoint[who].SinglePointPosition, sPoint[who].ChipFormatePosition, sPoint[who].SinglePointPosition, n, n + 10, n + 1, n - 10, 0, 5);break;
        //左、右边都有棋子
        case 3:AddRecord(sPoint[who].SinglePointPosition, sPoint[who].ChipFormatePosition, sPoint[who].TigerMouthFormatePosition, sPoint[who].ChipPosition, n, n + 10, n - 10, 0, 0, 2);break;
        //只有下边有棋子，前两个参数无意义
        case 4:AddRecord(sPoint[who].SinglePointPosition, sPoint[who].SinglePointPosition, sPoint[who].ChipFormatePosition, sPoint[who].SinglePointPosition, n, n - 10, n + 1, n - 1, 0, 5);break;
        //下、右边都有棋子
        case 5:AddRecord(sPoint[who].SinglePointPosition, sPoint[who].ChipFormatePosition, sPoint[who].TigerMouthFormatePosition, sPoint[who].ChipPosition, n, n + 10, n + 1, 0, 0, 2);break;
        //下、左边都有棋子
        case 6:AddRecord(sPoint[who].SinglePointPosition, sPoint[who].ChipFormatePosition, sPoint[who].TigerMouthFormatePosition, sPoint[who].ChipPosition, n, n + 10, n - 1, 0, 0, 2);break;
        //右、左、下都有棋子
        case 7:AddRecord(sPoint[who].ChipPosition, sPoint[who].TigerMouthFormatePosition, sPoint[who].EyeFormatePosition, sPoint[who].TigerMouthPosition, n, n + 1, n - 1, n + 10, 0, 3);break;
        //只有上边有棋子，前两个参数无意义
        case 8:AddRecord(sPoint[who].SinglePointPosition, sPoint[who].SinglePointPosition, sPoint[who].ChipFormatePosition, sPoint[who].SinglePointPosition, n, n + 10, n + 1, n - 1, 0, 5);break;
        //右、上都有棋子
        case 9:AddRecord(sPoint[who].SinglePointPosition, sPoint[who].ChipFormatePosition, sPoint[who].TigerMouthFormatePosition, sPoint[who].ChipPosition, n, n + 1, n - 10, 0, 0, 2);break;
        //左、上都有棋子
        case 10:AddRecord(sPoint[who].SinglePointPosition, sPoint[who].ChipFormatePosition, sPoint[who].TigerMouthFormatePosition, sPoint[who].ChipPosition, n, n - 1, n - 10, 0, 0, 2);break;
        //左、右、上都有棋子
        case 11:AddRecord(sPoint[who].ChipPosition, sPoint[who].TigerMouthFormatePosition, sPoint[who].EyeFormatePosition, sPoint[who].TigerMouthPosition, n, n - 1, n + 1, n - 10, 0, 3);break;
        //上、下都有棋子
        case 12:AddRecord(sPoint[who].SinglePointPosition, sPoint[who].ChipFormatePosition, sPoint[who].TigerMouthFormatePosition, sPoint[who].ChipPosition, n, n + 10, n - 10, 0, 0, 2);break;
        //上、下、右都有棋子
        case 13:AddRecord(sPoint[who].ChipPosition, sPoint[who].TigerMouthFormatePosition, sPoint[who].EyeFormatePosition, sPoint[who].TigerMouthPosition, n, n - 10, n + 10, n + 1, 0, 3);break;
        //上、下、左都有棋子
        case 14:AddRecord(sPoint[who].ChipPosition, sPoint[who].TigerMouthFormatePosition, sPoint[who].EyeFormatePosition, sPoint[who].TigerMouthPosition, n, n - 10, n + 10, n - 1, 0, 3);break;
        //上、下、左、右都有棋子
        case 15:AddRecord(sPoint[who].TigerMouthPosition, sPoint[who].EyeFormatePosition, sPoint[who].EyeFormatePosition, sPoint[who].EyePosition, n, n - 1, n + 1, n - 10, n + 10, 4);break;
    }
}
///添加特殊点通用函数
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
///根据已有信息初始化分值
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
    ///设置己方单点增加分值
    if(sPoint[PlayerNumber].SinglePointPosition -> next != NULL)
        AddScore(sPoint[PlayerNumber].SinglePointPosition -> next, PointStyle[15], 1);
    ///设置己方缺口增加分值
    if(sPoint[PlayerNumber].ChipPosition -> next != NULL)
        AddScore(sPoint[PlayerNumber].ChipPosition -> next, PointStyle[16]);
    ///设置己方虎口增加分值
    if(sPoint[PlayerNumber].TigerMouthPosition -> next != NULL)
        AddScore(sPoint[PlayerNumber].TigerMouthPosition -> next, PointStyle[14]);
    ///设置己方眼增加分值
    if(sPoint[PlayerNumber].EyePosition -> next != NULL)
        AddScore(sPoint[PlayerNumber].EyePosition -> next, PointStyle[13]);
    ///设置己方形成缺口增加分值
    if(sPoint[PlayerNumber].ChipFormatePosition -> next != NULL)
        AddScore(sPoint[PlayerNumber].ChipFormatePosition -> next, PointStyle[5], 1);
    ///设置己方形成虎口增加分值
    if(sPoint[PlayerNumber].TigerMouthFormatePosition -> next != NULL)
        AddScore(sPoint[PlayerNumber].TigerMouthFormatePosition -> next, PointStyle[3], 1);
    ///设置己方形成眼增加分值
    if(sPoint[PlayerNumber].EyeFormatePosition -> next != NULL)
        AddScore(sPoint[PlayerNumber].EyeFormatePosition -> next, PointStyle[4], 1);
    ///设置填充对方单点增加分值
    if(sPoint[mi].SinglePointPosition -> next != NULL)
        AddScore(sPoint[mi].SinglePointPosition -> next, PointStyle[8]);
    ///设置填充对方缺口增加分值
    if(sPoint[mi].ChipPosition -> next != NULL)
        AddScore(sPoint[mi].ChipPosition -> next, PointStyle[17], 2);
    ///设置填充对方虎口增加分值
    if(sPoint[mi].TigerMouthPosition -> next != NULL)
        AddScore(sPoint[mi].TigerMouthPosition -> next, PointStyle[2], 2);
    ///设置阻断对方形成缺口增加分值
    if(sPoint[mi].ChipFormatePosition -> next != NULL)
        AddScore(sPoint[mi].ChipFormatePosition -> next, PointStyle[8]);
    ///设置阻断对方形成虎口增加分值
    if(sPoint[mi].TigerMouthFormatePosition -> next != NULL)
        AddScore(sPoint[mi].TigerMouthFormatePosition -> next, PointStyle[6], 2);
    ///设置阻断对方形成眼增加分值
    if(sPoint[mi].EyeFormatePosition -> next != NULL)
        AddScore(sPoint[mi].EyeFormatePosition -> next, PointStyle[7], 2);
    ///设置填充对方眼增加分值
    if(sPoint[mi].EyePosition -> next != NULL)
        for(LIST *Beg = sPoint[mi].EyePosition -> next; Beg != NULL; Beg = Beg->next)
        {
            Score[Beg->Position / 10][Beg->Position % 10] = PointStyle[1];
        }
}
///增加分值
void AI1::AddScore(LIST *Beg, int score, int NumberPoor)
{
    while(Beg != NULL)
    {
        ResetScore(Beg->Position / 10, Beg->Position % 10, score, NumberPoor);//加分
        if(Beg->next == NULL) break;
        else Beg = Beg->next;
    }
}
///设置特殊点影响的分值
///特殊点的行、列、中心分值、级差分
void AI1::ResetScore(int row1, int row2, int score, int NumberPoor)
{
    int angelx1, angelx2, angelx3, angelx4;//4个角的横坐标
    int angely1, angely2, angely3, angely4;//4个角的纵坐标
    int level = 0;
    Score[row1][row2] += score;//先对中心加分
    ///扩散加分
    while(score - NumberPoor > 0)
    {
        score -= NumberPoor;//分数减少一级
        level++;//对外扩展一层
        ///下一层左上角坐标
        angelx1 = row1 - level == 0 ? 1 : row1 - level;
        angely1 = row2 - level == 0 ? 1 : row2 - level;
        ///下一层右上角坐标
        angelx2 = row1 - level == 0 ? 1 : row1 - level;
        angely2 = row2 + level == 10 ? 9 : row2 + level;
        ///下一层右下角坐标
        angelx3 = row1 + level == 10 ? 9 : row1 + level;
        angely3 = row2 + level == 10 ? 9 : row2 + level;
        ///下一层左下角坐标
        angelx4 = row1 + level == 10 ? 9 : row1 + level;
        angely4 = row2 - level == 0 ? 1 : row2 - level;
        ///加分
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
