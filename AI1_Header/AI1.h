#ifndef AI1_H_INCLUDED
#define AI1_H_INCLUDED

#include <time.h>
#include <stdlib.h>
#include "../chessBoard/AImessage.h"
///AI类
class AI1 : public AI
{
public:
    AI1();//构造函数
    void GetPosition(int &line, int &column, int onTurn);//获取下棋位置

private:
    int OT;//不想再想名字了，在GetPosition.cpp文件中使用
    int AttackPerformance;//记录对手的进攻性能（满值为100）
    int Winner;//用来记录模拟下棋时的胜负结果
    ///记录“当前点”的特殊点类型与级差分
    //加分
    int CurrentFormatPointStyle;
    int CurrentFormatScorePoor;
    int CurrentPointStyle;
    int CurrentScorePoor;
    //减分
    int LastFormatPointStyle;
    int LastFormatScorePoor;
    int LastSpecialPointStyle;
    int LastSpecialScorePoor;
    //层差分
    int RivalSinglePointPoor;//对方单点
    int RivalChipPoor;//对方缺口
    int RivalTigerMouthPoor;//对方虎口

    int RivalFormatChipPoor;//对方形成缺口
    int RivalFormatTigerMouthPoor;//对方形成虎口
    int RivalFormatEyePoor;//对方形成眼

    int MySinglePointPoor;//己方单点
    int MyChipPoor;//己方缺口
    int MyTigerMouthPoor;//己方虎口

    int MyFormatChipPoor;//己方形成缺口
    int MyFormatTigerMouthPoor;//己方形成虎口
    int MyFormatEyePoor;//己方形成眼

    //记录各交叉点的值，数组访问从“1”开始，访问顺序为“先行后列”，
    //“0”表示没有棋子，“1”表示黑子，“2”表示白子
    int cross[10][10];
    bool Cross[10][10];
    int PointStyle[18];//记录每种特殊点类型的分值
    int PlayerNumber;//记录该AI是玩家1还是玩家2
    int Score[10][10];//记录每个位置上的分值
    int MaxScorePosition;//最大分值的位置
    int MaxScore;//记录最大分值

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
};


#endif // AI1_H_INCLUDED
