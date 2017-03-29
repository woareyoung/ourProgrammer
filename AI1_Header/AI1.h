#ifndef AI1_H_INCLUDED
#define AI1_H_INCLUDED

#include <time.h>
#include <stdlib.h>
struct LIST
{
    int Position;
    LIST *next;
    LIST *prior;
    void insert(int position);
    void Delete(int position);
};
///记录特殊点位置的结构体
struct SPECIFICIALPOINT
{
    LIST *SinglePointPosition;//单点位置
    LIST *ChipPosition;//缺口位置
    LIST *TigerMouthPosition;//虎口位置
    LIST *EyePosition;//眼的位置

    LIST *ChipFormatePosition;//可形成缺口的位置
    LIST *TigerMouthFormatePosition;//可形成虎口的位置
    LIST *EyeFormatePosition;//可形成眼的位置
};

///AI类
class AI1
{
public:

    AI1();//构造函数
    void GetPosition(int &line, int &column, int onTurn);//获取下棋位置

private:

    //记录各交叉点的值，数组访问从“1”开始，访问顺序为“先行后列”，
    //“0”表示没有棋子，“1”表示黑子，“2”表示白子
    int cross[10][10];

    int PointStyle[18];//记录每种特殊点类型的分值
    ///所处玩家位置
    int PlayerNumber;//记录该AI是玩家1还是玩家2

    int Score[10][10];//记录每个位置上的分值

    ///结构体对象
    SPECIFICIALPOINT sPoint[3];//记录特殊点位置，下标1表示玩家1，下标2表示玩家2

    int MaxScorePosition;//最大分值的位置

    ///各功能函数
    int GetChessAmount(int row1, int row2, int rival);//查看特定位置的四个方向有多少个棋子
    void GetMaxScorePosition();//获取最大分值的位置

    ///更新位置分值所用函数
    void UpdateScore(int row1, int row2, int who);//更新棋盘位置分值，参数：行，列，附加参数
    void Reset();//根据已有信息初始化分值
    void ResetScore(int row1, int row2, int score, int NumberPoor = 100);//设置特殊点影响的分值
    void AddScore(LIST *Beg, int score, int NumberPoor = 20);//增加分数
    void RecordSpecialPoint(int row1, int row2, int who);//添加特殊点
    void AddRecord(LIST *LastSpecialPoint, LIST *LastFormatePoint, LIST *ThisFormatePoint, LIST *ThisSpecialPoint, int n, int n1, int n2, int n3, int n4, int amo);
};


#endif // AI1_H_INCLUDED
