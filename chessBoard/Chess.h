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

    Chess()
    {
        int temp[10][10] =
        {
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,1,0,1,0,0,0,2},
            {0,1,0,0,0,0,0,0,0,0},
            {0,1,0,0,0,0,0,0,0,0},
            {0,0,0,2,0,0,0,0,0,0},
            {0,0,0,0,2,1,2,0,0,0},
            {0,0,0,0,0,2,0,0,0,0},
            {0,0,0,0,2,1,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0}
        };
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cross[i][j] = temp[i][j];
                if (temp[i][j] != 0) {
                    Cross[i][j] = true;
                } else {
                    Cross[i][j] = false;
                }
            }

        }
    }
};


#endif // CHESS_H_INCLUDED
