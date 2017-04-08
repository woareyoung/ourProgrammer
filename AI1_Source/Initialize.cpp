#include "../stdafx.h"
#include "../AI1_Header/AI1.h"

///初始化数据
AI1::AI1()
{
    InitializeD();
    ///初始化特别点分值
    PointStyle[1] = -3;//死棋点设置为-3分
    PointStyle[2] = 50;//填充对方虎口，并向外跳级降低
    PointStyle[17] = 26;//填充对方缺口，并向外跳级降低
    PointStyle[13] = -2;//填充己方的眼设置为-2分
    PointStyle[3] = 6;//形成己方虎口，并向外逐级降低
    PointStyle[4] = 8;//形成己方眼，并向外逐级降低
    PointStyle[5] = 4;//形成己方缺口，并向外逐级降低
    PointStyle[6] = 33;//阻止对方形成虎口，并向外跳级降低
    PointStyle[7] = 45;//阻止对方形成眼，并向外逐级降低
    PointStyle[8] = 20;//阻止对方形成缺口、填充对方单点
    PointStyle[14] = -1;//填充己方虎口设置为-1分
    PointStyle[15] = 1;//填充己方单点，并向外逐级降低
    PointStyle[16] = -8;//填充己方缺口
    PointStyle[9] = -2;//对方下了会死的位置设置为-2分
    PointStyle[10] = -5;//有棋子的位置的分值

    PointStyle[11] = 5;//在对方剩下一个位置时己方还差1子集群围杀
    PointStyle[12] = 6;//在对方剩下一个位置时己方还差2子集群围杀
    ///初始化层差分
    RivalSinglePointPoor = 100;//对方单点
    RivalChipPoor = 20;//对方缺口
    RivalTigerMouthPoor = 13;//对方虎口

    RivalFormatChipPoor = 10;//对方形成缺口
    RivalFormatTigerMouthPoor = 14;//对方形成虎口
    RivalFormatEyePoor = 18;//对方形成眼

    MySinglePointPoor = 1;//己方单点
    MyChipPoor = 100;//己方缺口
    MyTigerMouthPoor = 100;//己方虎口

    MyFormatChipPoor = 1;//己方形成缺口
    MyFormatTigerMouthPoor = 1;//己方形成虎口
    MyFormatEyePoor = 1;//己方形成眼
}
///初始化数据
void AI1::InitializeD()
{
    int i, j;
    ///初始化数组
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
