#include "../AI1_Header/AI1.h"
///获取下棋位置
void AI1::GetPosition(int &line, int &column, int onTurn)
{
    PlayerNumber = (onTurn == 1 || onTurn == -1) ? 2 : 1;//设置该AI的玩家编号
    ///先更新棋盘信息数组
    cross[line][column] = (unsigned)onTurn;
    UpdateScore(line, column, (unsigned)onTurn);//更新分值
    GetMaxScorePosition();
    line = MaxScorePosition / 10;
    column = MaxScorePosition % 10;
    cross[line][column] = PlayerNumber;
    UpdateScore(line, column, PlayerNumber);
}
