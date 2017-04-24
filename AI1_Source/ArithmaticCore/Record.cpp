#include "../../AI1_Header/AI1.h"

void AI1::RecordStep(int line, int column)
{
    SSS->ScoreRate = Score[line][column] / MaxScore;//记录分值
    STEP *s = new STEP;//创建结点
    SSS->next = s;
    s->Number = SSS->Number + 1;//设置将下一步的步数
    SSS = s;//记录动态尾结点
}
