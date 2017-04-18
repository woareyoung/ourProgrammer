#ifndef AI1_H_INCLUDED
#define AI1_H_INCLUDED

#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include "../chessBoard_Header/AI.h"
#include "PointStyle.h"
#include "Arithmatic.h"
///AI类
class AI1 : public AI, private PointStyle, private Arithmatic
{
public:
    AI1();//构造函数
    void GetPosition(int &line, int &column, int onTurn);//获取下棋位置
    void InitializeD();

private:
    int OT;//不想再想名字了，在GetPosition.cpp文件中使用

    //记录各交叉点的值，数组访问从“1”开始，访问顺序为“先行后列”，
    //“0”表示没有棋子，“1”表示黑子，“2”表示白子
    int cross[10][10];//棋盘状态
    bool Cross[10][10];//遍历标识
    float PointStyle[18];//记录每种特殊点类型的分值
    int PlayerNumber;//记录该AI是玩家1还是玩家2
    float Score[10][10];//记录每个位置上的分值
    int MaxScorePosition;//最大分值的位置
    float MaxScore;//记录最大分值

    void Display(int n, int line, int column);
    ///各功能函数 集中在FunctionPart.cpp文件中
    int GetChessAmount(int row1, int row2, int who);//查看特定位置的四个方向有多少个棋子
    void GetMaxScorePosition();//获取最大分值的位置

    ///更新位置分值所用函数 集中在UpdateScore.cpp文件中
    //更新棋盘位置分值，参数：行，列，附加参数
    void UpdateScore(int row1, int row2, int who);//调用RecordSpecialPoint()函数
    //设置特殊点影响的分值
    void ResetScore(int row1, int row2, int score, int NumberPoor = 100, bool isAddScore = true);//实行加分的函数
    //添加特殊点
    void RecordSpecialPoint(int row1, int row2, int who);//用SetCurrentPoint()设置当前点，再调用AddRecord
    void AddRecord(int n, int n1, int n2, int n3, int n4, int amo);
    void SetCurrentPoint(int ThisFormatStyle, int ThisFormatScorePoor, int ThisSpecialStyle, int ThisSpecialScorePoorint, int LastFormatStyle = 0, int LastFormatScorePoore = 0, int LastSpecialPointStyle = 0, int LastSpecialScorePoor = 0);

    ///判断是否是死棋位置   集中在DeadCheck.cpp文件中
    bool DeadCheck(int line, int column, int who);
    bool Besieg(int RivalLine, int RivalColumn, int player, int rival);
    void reduceRecursionTimes();
    void setStatus(int RivalLine,int RivalColumn);

    ///在RateResetScore.cpp文件中
    void RateResetScore(float ResetRate);//按比例缩小分值，减少分差，精确定位

    /* 预测系统 */
    ///在CalculatePerf.cpp文件中
    void CalculatePerf(int line, int column);//计算对手进攻性能
    ///在Forecast.cpp文件中
    void Forecast(int player);
};


#endif // AI1_H_INCLUDED
