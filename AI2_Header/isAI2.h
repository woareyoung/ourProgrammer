#ifndef ISAI2_H_INCLUDED
#define ISAI2_H_INCLUDED

#include <cmath>
#include "AIPlayer.h"
#include <list>
using namespace std;
#include "../StdAfx.h"


#define cornerScore 60 // 边角分数
#define tirangleScore1 60 // 三角分数
#define tirangleScore2 60 // 三角分数
#define crossShaped1 40 // 十字分数
#define crossShaped2 80 // 十字分数
#define crossShaped3 120 // 十字分数
#define goodTigersMouth 120  // 优虎口，表示被包围的敌方棋子中只有1~2个
#define badTigersMouth -120 // 劣虎口，表示被包围圈内都是敌方棋子
#define max 32767
#define min -32767

class isAI2 : public AIPlayer
{
private:
    //记录各交叉点的值，数组访问从“1”开始，访问顺序为“先行后列”，
    //“0”表示没有棋子，“1”表示黑子，“2”表示白子
    int cross[10][10];
    //判断胜负时用于标记有没有遍历过
    bool Cross[10][10];
    // 分数
    int chessScore[10][10];
    // 边角数组
    int cornerArray[12];

    void setStatus(int RivalLine,int RivalColumn);
    void reduceRecursionTimes();

    list<int> blankList;
public:
    isAI2();
    // 通过数组来初始化数据
    void initDataFromArray();
    // 估价函数
    int Evaluation();
    // 极大极小值算法
    void MaxAndMin(int& line,int& column);

    // 获取最后着子的位置
    void GetPosition(int &line,int &column,int player,int isExist[10][10], bool chessStatus[10][10]);

    // 分数计算函数
    void Score();

    // 判断包围情况的函数
    bool isBesieged(int RivalLine, int RivalColumn, int player, int rival);

    // 对角
    void AcrossCorners();
    void ACScan(int line,int column,int line1,int column1,int line2,int column2);

    // 三角
    void Tirangle();
    void ULTirangle();
    void DRTirangle();

    // 十字
    void CrossShaped();
    void JudgeCShape(int line,int column);
    void FindBlank(int line,int column);
    void addCSScore(int line,int column,int score,int tempPos[4],int temp[4]);

    // 优虎口
    void GoodTigersMouth();

    // 加分函数
    void addScore(int line,int column, int score);

    // 初始化数组
    void copyArray(int isExist[10][10], bool chessStatus[10][10]);
    void initChessScore();

    //
    bool Besieged(int RivalLine, int RivalColumn, int player, int rival);
    void Revalute();
    bool isBesieged(int line, int column, int onTurn);
    void JudgeScoreType();
    void addREScore(int score);
    int maxandmin(int depth);
    int MaxScore();
    int MinScore();
    int singleLayer();
};


#endif // ISAI2_H_INCLUDED
