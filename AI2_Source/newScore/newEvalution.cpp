#include "../../AI2_Header/AI2.h"

bool AI2::Revalute()
{
    return false;
}
//若棋子被围死，则返回true，只要棋子周围有一个空位就返回false
bool AI2::Besieged(int RivalLine, int RivalColumn, int player, int rival)
{
    bool tie[4] = {false, false, false, false};
    // 设置Cross数组状态
    setStatus(RivalLine,RivalColumn);
    //若对方棋子的上方有对方的棋子且未到上边缘
    if(cross[RivalLine - 1][RivalColumn] == rival && RivalLine - 1 > 0
       && Cross[RivalLine - 1][RivalColumn] == false)
        tie[0] = Besieged(RivalLine - 1, RivalColumn, player, rival);
    //若对方棋子的上方没有棋子，直接返回false
    else if(cross[RivalLine - 1][RivalColumn] == 0 && RivalLine - 1 > 0) return false;
    //若对方棋子的上方有己方的棋子或已到边缘
    else tie[0] = true;
    //若对方棋子的下方有对方的棋子且未到下边缘
    if(cross[RivalLine + 1][RivalColumn] == rival && RivalLine + 1 < 10
       && Cross[RivalLine + 1][RivalColumn] == false)
        tie[1] = Besieged(RivalLine + 1, RivalColumn, player, rival);
    //若对方棋子的下方没有棋子
    else if(cross[RivalLine + 1][RivalColumn] == 0 && RivalLine + 1 < 10) return false;
    //若对方棋子的下方有己方的棋子或已到边缘
    else tie[1] = true;
    //若对方棋子的右方有对方的棋子且未到右边缘
    if(cross[RivalLine][RivalColumn + 1] == rival && RivalColumn + 1 < 10
       && Cross[RivalLine][RivalColumn + 1] == false)
        tie[2] = Besieged(RivalLine, RivalColumn + 1, player, rival);
    //若对方棋子的右方没有棋子
    else if(cross[RivalLine][RivalColumn + 1] == 0 && RivalColumn + 1 < 10) return false;
    //若对方棋子的右方有己方的棋子或已到边缘
    else tie[2] = true;

    //若对方棋子的左方有对方的棋子且未到左边缘
    if(cross[RivalLine][RivalColumn - 1] == rival && RivalColumn - 1 > 0
       && Cross[RivalLine][RivalColumn - 1] == false)
        tie[3] = Besieged(RivalLine, RivalColumn - 1, player, rival);
    //若对方棋子的左方没有棋子
    else if(cross[RivalLine][RivalColumn - 1] == 0 && RivalColumn - 1 > 0) return false;
    //若对方棋子的左方有己方的棋子或已到边缘
    else tie[3] = true;

    if(tie[0] && tie[1] && tie[2] && tie[3]) return true;
    return false;
}
