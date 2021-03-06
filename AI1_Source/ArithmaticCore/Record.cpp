#include "../../AI1_Header/AI1.h"
///将对方下棋位置加入历史记录
void AI1::RecordStep(int line, int column)
{
    if(line == 0 && column == 0) return;
    SSS->ScoreRate = Score[line][column] / MaxScore;//记录分值
    STEP *s = new STEP;//创建结点
    SSS->next = s;
    s->Number = SSS->Number + 1;//设置将下一步的步数
    SSS = s;//记录动态尾结点
}
