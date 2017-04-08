#include "../stdafx.h"
#include "../AI1_Header/AI1.h"
///获取下棋位置
void AI1::GetPosition(int &line, int &column, int onTurn)
{
    OT = (onTurn == 1 || onTurn == -1) ? 1 : 2;//OT = (unsigned)onTurn，但是强制类型转换出问题
    PlayerNumber = OT == 1 ? 2 : 1;//设置该AI的玩家编号
    cross[line][column] = OT;//先更新棋盘信息数组
    UpdateScore(line, column, OT);//更新分值
    ///若是死棋位置则一直循环，直到不是死棋位置
    while(true)
    {
        GetMaxScorePosition();
        line = MaxScorePosition / 10;
        column = MaxScorePosition % 10;
        if(cross[line][column] != 0) continue;//这句虽然没什么用，但保险起见
        cross[line][column] = OT;
        ///若该位置对于对方来说是死棋，则继续循环
        if(DeadCheck(line, column, OT) == true && MaxScore > PointStyle[9])
        {
            Score[line][column] = PointStyle[9];
            cross[line][column] = 0;
            continue;
        }
        cross[line][column] = PlayerNumber;
        ///若是死棋位置，且棋盘上还有位置不是死棋，则继续循环
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
