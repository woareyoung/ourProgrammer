#ifndef AI2_H_INCLUDED
#define AI2_H_INCLUDED

#include "../chessBoard_Header/AI.h"
#include "AIPlayer.h"
#include <vector>
using namespace std;
#include "../StdAfx.h"

#define cornerScore 120 // 边角分数
#define cornerScoreFull 160 // 完整构成边角的分数
#define tirangleScore1 60 // 三角分数
#define tirangleScore2 120 // 三角分数
#define tirangleScore3 140 // 三角分数
#define crossShaped1 40 // 十字分数
#define crossShaped2 80 // 十字分数
#define crossShaped3  120// 十字分数
#define crossShaped4 160 // 十字分数
#define goodTigersMouth 120  // 优虎口，表示被包围的敌方棋子中只有1~2个
#define badTigersMouth -120 // 劣虎口，表示被包围圈内都是敌方棋子
#define max 32767
#define min -32767

#define isParent 1
#define isSiblings 2

#define isMax 0
#define isMin 1

class AI2 : public AIPlayer, public AI
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
    AI2();
    // 获取最后着子的位置
    void GetPosition(int& line,int& column,int onTurn/*, int isExist[10][10]*/);

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
	void isGo2Dead(int type);
	void AddDeadChessScore(int stack[][2], int len);
    bool IsDeadChess(int stack[][2], int len, int type);

    int priority_score(int scoreBase, int scorePRI, int type);

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

#endif // AI2_H_INCLUDED

