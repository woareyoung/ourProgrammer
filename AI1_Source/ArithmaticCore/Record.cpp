#include "../../AI1_Header/AI1.h"

void AI1::RecordStep(int line, int column)
{
    SSS->ScoreRate = Score[line][column] / MaxScore;//��¼��ֵ
    STEP *s = new STEP;//�������
    SSS->next = s;
    s->Number = SSS->Number + 1;//���ý���һ���Ĳ���
    SSS = s;//��¼��̬β���
}
