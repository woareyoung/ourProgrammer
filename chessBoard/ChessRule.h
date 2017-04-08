#ifndef CHESSRULE_H_INCLUDED
#define CHESSRULE_H_INCLUDED

# include "Chess.h"
# include "PlayerInfo.h"
class ChessRule: public Chess, public PlayerInfo
{
public:
    bool Start;//开始游戏


    //判断胜负是否已分，若分出胜负返回true，否则返回false
    bool WinOrLose();
    //判断对方的棋子有没有被围死，用于一堆棋子被围死的情况
    bool Besieged(int RivalLine, int RivalColumn, int player, int rival);
    //胜负决出之后
    void reStart(HWND ParentHwnd);
};


#endif // CHESSRULE_H_INCLUDED