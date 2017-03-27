#ifndef AI2_H_INCLUDED
#define AI2_H_INCLUDED

#include <map>
#include <cmath>
#include "AIPlayer.h"
#include <vector>
#include "../StdAfx.h"

#define cornerScore 60 // 边角分数
#define tirangleScore1 60 // 三角分数
#define tirangleScore2 60 // 三角分数
#define crossShaped 40 // 十字分数
#define goodTigersMouth 120  // 优虎口，表示被包围的敌方棋子中只有1~2个
#define badTigersMouth -120 // 劣虎口，表示被包围圈内都是敌方棋子
#define max 32767
#define min -32767

class AI2 : public AIPlayer
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
public:
    AI2();
    // 扫描函数
    void Scan(int cross[10][10], bool Cross[10][10]);
    // 通过数组来初始化数据
    void initDataFromArray();
    // 估价函数,主要用于
    int Evaluation();
    // 极大极小值算法
    void MaxAndMin();

    // 获取最后着子的位置
    void GetPosition(int &line,int &column,int player, int rival,int isExist[10][10], bool chessStatus[10][10]);

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

  	// 优虎口
  	void GoodTigersMouth();

  	// 加分函数
    void addScore(int line,int column, int score);

  	// 初始化数组
  	void copyArray(int isExist[10][10], bool chessStatus[10][10]);
};

#endif // AI2_H_INCLUDED

