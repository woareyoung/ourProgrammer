#include "../../AI1_Header/AI1.h"
///���Է�����λ�ü�����ʷ��¼
void AI1::RecordStep(int line, int column)
{
    if(line == 0 && column == 0) return;
    SSS->ScoreRate = Score[line][column] / MaxScore;//��¼��ֵ
    STEP *s = new STEP;//�������
    SSS->next = s;
    s->Number = SSS->Number + 1;//���ý���һ���Ĳ���
    SSS = s;//��¼��̬β���
}
