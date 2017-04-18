#include "../ChessBoard_Header/ChessBoard.h"

/*胜负条件
* 1、超时。该条件判断由窗口过程函数实现
* 2、空手。先忽略
* 3、围死。基本思想：假设黑子下一个棋子，则判断该黑子周围的四个位置上有没有白子被围死，还有该黑子是否被围死
*/
//注：调用该函数（即下棋的玩家）的那个人或AI是“己方”
bool ChessBoard::WinOrLose()
{
    bool Position[4] = {false, false, false, false};
    int player;//记录己方的编号（是1还是2）
    int rival;//记录对方的编号（是1还是2）
    //onTurn的值是先变化了再调用该函数（WinOrLose）的
    if(onTurn == isPlay1onTurn || onTurn == isAI1onTurn)
    {
        player = isWhite;
        rival = isBlack;
    }
    else if(onTurn == isPlay2onTurn || onTurn == isAI2onTurn)
    {
        player = isBlack;
        rival = isWhite;
    }
    //判断棋子四周有没有棋子
    //若左方有对方的一个棋子
    if(cross[line][column - 1] == rival)
    {
        reduceRecursionTimes();
        if(Besieged(line, column - 1, player, rival))
        {
            Winner = rival;
            return true;
        }
        Position[0] = true;
    }
    //若己方棋子已到左边缘
    else if(column - 1 == 0) Position[0] = true;
    //若左方有己方的棋子
    else if(cross[line][column - 1] == player)
    {
        reduceRecursionTimes();
        Position[0] = Besieged(line, column, rival, player);
    }
    //若右方有对方的一个棋子
    if(cross[line][column + 1] == rival)
    {
        reduceRecursionTimes();
        if(Besieged(line, column + 1, player, rival))
        {
            Winner = rival;
            return true;
        }
        Position[1] = true;
    }
    //若己方的棋子已到右边缘
    else if(column + 1 == 10) Position[1] = true;
    //若右方有己方的棋子
    else if(cross[line][column + 1] == player)
    {
        reduceRecursionTimes();
        Position[1] = Besieged(line, column, rival, player);
    }
    //若上方有对方的一个棋子
    if(cross[line - 1][column] == rival)
    {
        reduceRecursionTimes();
        if(Besieged(line - 1, column, player, rival))
        {
            Winner = rival;
            return true;
        }
        Position[2] = true;
    }
    //若己方的棋子已到上边缘
    else if(line - 1 == 0) Position[2] = true;
    //若上方有己方的棋子
    else if(cross[line - 1][column] == player)
    {
        reduceRecursionTimes();
        Position[2] = Besieged(line, column, rival, player);
    }
    //若下方有对方的一个棋子
    if(cross[line + 1][column] == rival)
    {
        reduceRecursionTimes();
        if(Besieged(line + 1, column, player, rival))
        {
            Winner = rival;
            return true;
        }
        Position[3] = true;
    }
    //若己方的棋子已到下边缘
    else if(line + 1 == 10) Position[3] = true;
    //若下方有己方的棋子
    else if(cross[line + 1][column] == player)
    {
        reduceRecursionTimes();
        Position[3] = Besieged(line, column, rival, player);
    }
    if(Position[0] && Position[1] && Position[2] && Position[3])
    {
        Winner = rival;
        return true;
    }
    return false;
}
//判断对方的棋子是否被围死，两个参数表示对方棋子的位置
//该函数用于一堆棋子被围死的情况，用递归的方法检查一堆棋子的情况
//若棋子被围死，则返回true，只要棋子周围有一个空位就返回false
bool ChessBoard::Besieged(int RivalLine, int RivalColumn, int player, int rival)
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
