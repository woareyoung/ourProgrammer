#ifndef AI2_H_INCLUDED
#define AI2_H_INCLUDED

#include <map>
#include <cmath>

#define duijiaoScore 60
#define sanjiaoScore 40
#define shiziScore 30


class isAI2
{
private:
    //记录各交叉点的值，数组访问从“1”开始，访问顺序为“先行后列”，
    //“0”表示没有棋子，“1”表示黑子，“2”表示白子
    int cross[10][10];
    //判断胜负时用于标记有没有遍历过
    bool Cross[10][10];
public:
    // 扫描函数
    void Scan(int cross[10][10], bool Cross[10][10]);
    // 通过数组来初始化数据
    void initDataFromArray();
    // 估价函数,主要用于
    int Evaluation();
    // 极大极小值算法
    void MaxAndMin();

    // 获取最后着子的位置
    void GetPosition(int &line,int &column,int player, int rival,int cross[10][10], bool Cross[10][10]);

    // 分数计算函数
    void Score();

    // 判断包围情况的函数
    bool isBesieged(int RivalLine, int RivalColumn, int player, int rival);
};

#endif // AI2_H_INCLUDED
