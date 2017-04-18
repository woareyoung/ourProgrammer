#ifndef ARITHMATIC_H_INCLUDED
#define ARITHMATIC_H_INCLUDED
///特殊点数量
struct SPECIALPOINTAMOUNT
{
    int Chip;//缺口数量
    int TigerMouth;//虎口数量
    int Eye;//眼数量
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
    float AttackPerformance;//记录对手的进攻性能（满值为1）
    float BoundryRate;//区域界限比例（满值为1）
    SPECIALPOINTAMOUNT spa[3];//下标0没用，1、2对应玩家1、玩家2
    POINTSCORE PoS;//0表示缺口、1表示虎口、2表示眼
};

#endif // ARITHMATIC_H_INCLUDED
