#include "../ChessBoard_Header/ChessBoard.h"
///游戏结束
void ChessBoard::ReStart()
{
    if(Winner == isBlack) MessageBox(RootHwnd, "恭喜玩家1（黑子）胜出", "凯旋", MB_OK);
    else MessageBox(RootHwnd, "恭喜玩家2（白子）胜出", "凯旋", MB_OK);
    Init_cross();
    AllTime1 = 900;//总时长15分钟
    AllTime2 = 900;
    Round1 = 60;//步时60秒
    Round2 = 60;
    Start = false;
    Player1isAI = false;
    Player2isAI = false;
    line = 0;
    column = 0;
}
