#include "../AI2_Header/AI2.h"
#include "../AI1_Header/AI1.h"
/**
 * 棋盘中的玩家的信息
 */
class PlayerInfo {
public:
    /**
     * 1表示轮到玩家1下棋，2表示轮到玩家2下棋，-1表示电脑1，-2表示电脑2
     * isPlay1onTurn 1, 当轮到玩家1的时候为1
     * isPlay2onTurn 2，当轮到玩家2的时候为2
     * isAI1onTurn -1，当轮到AI1的时候为-1
     * isAI2onTurn -2，当轮到AI1的时候为-2
     */
    int onTurn;
    /**
     * 最终的赢家
     */
    int Winner;
    /**
     * 总时间
     */
    int AllTime1;//玩家1的剩余游戏总时间
    int AllTime2;//玩家2的剩余游戏总时间

    /**
     * 剩余时间
     */
    int Round1;//玩家1一回合的游戏剩余时间
    int Round2;//玩家2一回合的游戏剩余时间

    /**
     * 计时器
     */
    UINT_PTR PlayerTimer;//玩家的计时器

    /**
     * AI
     */
    bool Player1isAI;//记录玩家1是否是AI
    bool Player2isAI;//记录玩家2是否是AI

};
