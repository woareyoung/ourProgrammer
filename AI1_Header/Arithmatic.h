#ifndef ARITHMATIC_H_INCLUDED
#define ARITHMATIC_H_INCLUDED
///特殊点数量
struct SPECIALPOINTAMOUNT
{
    int Chip;//缺口数量
    int TigerMouth;//虎口数量
    int Eye;//眼数量
};
///记录对手历史下棋
struct STEP
{
    int Number;//第几步
    float ScoreRate;//该位置的分值百分比（与最大分值的比值）
    STEP *next;//指向下一步
};
///记录预测到的可能性链条
struct CHAIN
{
    ///预测的下棋位置
    int line;
    int column;

    CHAIN *next;//下一步
    CHAIN *parallel;//当前回合的其他可能性
};
///特殊点分值（用于预测）
enum POINTSCORE
{
    Chip = 1,
    TigerMouth = 3,
    Eye = 5
};
///算法支撑
class Arithmatic
{
public :
    int StepNumber;//记录对手下了多少步
    int MaxStepNumber;//当下够了MaxStepNumber步后构建回归方程
    float a;//回归方程常数项
    float b;//回归方程斜率
    float _x;//x平均值，x指代第几步
    float _y;//y平均值，y指代某一步下棋位置的分值
    float AttackPerformance;//记录对手的进攻性能（满值为1）
    float BoundryRate;//区域界限比例（满值为1）
    float CorrectRate;//修正系数
    SPECIALPOINTAMOUNT spa[3];//下标0没用，1、2对应玩家1、玩家2
    POINTSCORE PoS;//0表示缺口、1表示虎口、2表示眼
    STEP *Step;//静态记录头结点
    STEP *SSS;//动态尾结点记录
    CHAIN *HeadChain;//动态头结点
};

#endif // ARITHMATIC_H_INCLUDED
