#ifndef CHESS_H_INCLUDED
#define CHESS_H_INCLUDED

class Chess
{
public:
    //记录各交叉点的值，数组访问从“1”开始，访问顺序为“先行后列”，
    //“0”表示没有棋子，“1”表示黑子，“2”表示白子
    int cross[10][10];
    //判断胜负时用于标记有没有遍历过
    bool Cross[10][10];
    //用于玩家点击棋盘时记录位置
    int line, column;

    // 减少递归次数
    void reduceRecursionTimes();
    // 设置状态
    void setStatus(int RivalLine,int RivalColumn);
};


#endif // CHESS_H_INCLUDED
