#ifndef ISAI2_H_INCLUDED
#define ISAI2_H_INCLUDED

#include "AIPlayer.h"
#include <vector>
using namespace std;
#include "../StdAfx.h"

#define cornerScore 60 // 边角分数
#define cornerScoreFull 120 // 完整构成边角的分数
#define tirangleScore1 60 // 三角分数
#define tirangleScore2 60 // 三角分数
#define crossShaped1 40 // 十字分数
#define crossShaped2 80 // 十字分数
#define crossShaped3 120 // 十字分数
#define goodTigersMouth 120  // 优虎口，表示被包围的敌方棋子中只有1~2个
#define badTigersMouth -120 // 劣虎口，表示被包围圈内都是敌方棋子
#define max 32766
#define min -32766

#define isParent 1
#define isSiblings 2

#define isMax 0
#define isMin 1

class isAI2 : public AIPlayer
{
private:
     //记录各交叉点的值，数组访问从“1”开始，访问顺序为“先行后列”，
    //“0”表示没有棋子，“1”表示黑子，“2”表示白子
	int cross[10][10];
    //判断胜负时用于标记有没有遍历过
	bool chessStatus[10][10];
    // 分数
	int chessScore[10][10];
    // 边角数组
	int cornerArray[12];

	void setStatus(int RivalLine,int RivalColumn);
	void reduceRecursionTimes();

	std::vector<int> vec;
public:
    isAI2();
    // 获取最后着子的位置
    void GetPosition(int& line,int& column,int player, int isExist[10][10]);

    // 对角
	void AcrossCorners();
	void ACScan(int line,int column,int line1,int column1,int line2,int column2);

  	// 三角
	void Tirangle();
	void UTirangle();
	void LTirangle();
	void DTirangle();
	void RTirangle();

 	// 十字
	void chessStatusShaped();
	void JudgeCShape(int line,int column);

    // 是否构成死棋
	void isGo2Dead();
	void AddDeadChessScore(int stack[][2],int len);
    bool IsDeadChess(int stack[][2],int len);

    // 优虎口
    void GoodTigersMouth();

    // 初始化数组
    void copyArray(int isExist[10][10]);
    void initChessScore();

    //
	bool isBesieged(int line, int column);
	bool diffDirect(int line, int column);
	void Revalute();
	void JudgeScoreType();
	void addREScore(int score);
	int maxandmin(int depth);
	int MaxScore();
	int MinScore();
	int singleLayer();
};


#endif // ISAI2_H_INCLUDED
