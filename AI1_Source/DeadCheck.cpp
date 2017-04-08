#include "../AI1_Header/AI1.h"
///参数：预备下棋位置
bool AI1::DeadCheck(int line, int column, int who)
{
    bool Position[4] = {false, false, false, false};
    int player = who;//记录己方的编号（是1还是2）
    int rival = player == 1 ? 2 : 1;//记录对方的编号（是1还是2）
    //判断棋子四周有没有棋子
    //若左方有对方的一个棋子
    if(cross[line][column - 1] == rival)
    {
        reduceRecursionTimes();
        if(Besieg(line, column - 1, player, rival))
            return true;
        Position[0] = true;
    }
    //若己方棋子已到左边缘
    else if(column - 1 == 0) Position[0] = true;
    //若左方有己方的棋子
    else if(cross[line][column - 1] == player)
    {
        reduceRecursionTimes();
        Position[0] = Besieg(line, column, rival, player);
    }
    //若右方有对方的一个棋子
    if(cross[line][column + 1] == rival)
    {
        reduceRecursionTimes();
        if(Besieg(line, column + 1, player, rival))
            return true;
        Position[1] = true;
    }
    //若己方的棋子已到右边缘
    else if(column + 1 == 10) Position[1] = true;
    //若右方有己方的棋子
    else if(cross[line][column + 1] == player)
    {
        reduceRecursionTimes();
        Position[1] = Besieg(line, column, rival, player);
    }
    //若上方有对方的一个棋子
    if(cross[line - 1][column] == rival)
    {
        reduceRecursionTimes();
        if(Besieg(line - 1, column, player, rival))
            return true;
        Position[2] = true;
    }
    //若己方的棋子已到上边缘
    else if(line - 1 == 0) Position[2] = true;
    //若上方有己方的棋子
    else if(cross[line - 1][column] == player)
    {
        reduceRecursionTimes();
        Position[2] = Besieg(line, column, rival, player);
    }
    //若下方有对方的一个棋子
    if(cross[line + 1][column] == rival)
    {
        reduceRecursionTimes();
        if(Besieg(line + 1, column, player, rival))
            return true;
        Position[3] = true;
    }
    //若己方的棋子已到下边缘
    else if(line + 1 == 10) Position[3] = true;
    //若下方有己方的棋子
    else if(cross[line + 1][column] == player)
    {
        reduceRecursionTimes();
        Position[3] = Besieg(line, column, rival, player);
    }
    if(Position[0] && Position[1] && Position[2] && Position[3])
        return true;
    return false;
}

bool AI1::Besieg(int RivalLine, int RivalColumn, int player, int rival)
{
    bool tie[4] = {false, false, false, false};
    // 设置Cross数组状态
    setStatus(RivalLine,RivalColumn);
    //若对方棋子的上方有对方的棋子且未到上边缘
    if(cross[RivalLine - 1][RivalColumn] == rival && RivalLine - 1 > 0
       && Cross[RivalLine - 1][RivalColumn] == false)
        tie[0] = Besieg(RivalLine - 1, RivalColumn, player, rival);
    //若对方棋子的上方没有棋子，直接返回false
    else if(cross[RivalLine - 1][RivalColumn] == 0 && RivalLine - 1 > 0) return false;
    //若对方棋子的上方有己方的棋子或已到边缘
    else tie[0] = true;
    //若对方棋子的下方有对方的棋子且未到下边缘
    if(cross[RivalLine + 1][RivalColumn] == rival && RivalLine + 1 < 10
       && Cross[RivalLine + 1][RivalColumn] == false)
        tie[1] = Besieg(RivalLine + 1, RivalColumn, player, rival);
    //若对方棋子的下方没有棋子
    else if(cross[RivalLine + 1][RivalColumn] == 0 && RivalLine + 1 < 10) return false;
    //若对方棋子的下方有己方的棋子或已到边缘
    else tie[1] = true;
    //若对方棋子的右方有对方的棋子且未到右边缘
    if(cross[RivalLine][RivalColumn + 1] == rival && RivalColumn + 1 < 10
       && Cross[RivalLine][RivalColumn + 1] == false)
        tie[2] = Besieg(RivalLine, RivalColumn + 1, player, rival);
    //若对方棋子的右方没有棋子
    else if(cross[RivalLine][RivalColumn + 1] == 0 && RivalColumn + 1 < 10) return false;
    //若对方棋子的右方有己方的棋子或已到边缘
    else tie[2] = true;
    //若对方棋子的左方有对方的棋子且未到左边缘
    if(cross[RivalLine][RivalColumn - 1] == rival && RivalColumn - 1 > 0
       && Cross[RivalLine][RivalColumn - 1] == false)
        tie[3] = Besieg(RivalLine, RivalColumn - 1, player, rival);
    //若对方棋子的左方没有棋子
    else if(cross[RivalLine][RivalColumn - 1] == 0 && RivalColumn - 1 > 0) return false;
    //若对方棋子的左方有己方的棋子或已到边缘
    else tie[3] = true;
    if(tie[0] && tie[1] && tie[2] && tie[3]) return true;
    return false;
}

void AI1::reduceRecursionTimes()
{
    for(int i = 0; i < 10; i++)
    {
        if(Cross[i][0] == true)
            for(int j = 0; j < 10; j++)
                Cross[i][j] = false;
    }
}

void AI1::setStatus(int RivalLine,int RivalColumn) {
    Cross[RivalLine][RivalColumn] = true;
    Cross[RivalLine][0] = true;//下标为0的那一行如果为true则初始化，否则不用初始化
}
