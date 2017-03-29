#include "../AI1_Header/AI1.h"

///初始化数据
AI1::AI1()
{
    int i, j;
    ///初始化数组
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

    ///初始化特别点分值
    PointStyle[1] = -3;//死棋点
    PointStyle[2] = 9;//填充对方虎口，并向外跳级降低
    PointStyle[3] = 7;//形成己方虎口，并向外逐级降低
    PointStyle[4] = 8;//形成己方眼，并向外逐级降低
    PointStyle[5] = 5;//形成己方缺口，并向外逐级降低
    PointStyle[6] = 15;//阻止对方3子围杀，并向外跳级降低
    PointStyle[7] = 20;//阻止对方4子围杀，并向外逐级降低
    PointStyle[8] = 10;//阻止对方2子围杀，即对方单子
    PointStyle[9] = 4;//在己方剩下一个位置时对方还差1子集群围杀
    PointStyle[10] = 5;//在己方剩下一个位置时对方还差2子集群围杀
    PointStyle[11] = 5;//在对方剩下一个位置时己方还差1子集群围杀
    PointStyle[12] = 6;//在对方剩下一个位置时己方还差2子集群围杀
    PointStyle[13] = 1;//填充己方的眼
    PointStyle[14] = 2;//填充己方虎口
    PointStyle[15] = 3;//填充己方单点，并向外逐级降低
    PointStyle[16] = 3;//填充己方缺口
    PointStyle[17] = 6;//填充对方缺口，并向外跳级降低
}
