#include "../AI1_Header/AI1.h"
///��ȡ����λ��
void AI1::GetPosition(int &line, int &column, int onTurn)
{
    PlayerNumber = (onTurn == 1 || onTurn == -1) ? 2 : 1;//���ø�AI����ұ��
    ///�ȸ���������Ϣ����
    cross[line][column] = (unsigned)onTurn;
    UpdateScore(line, column, (unsigned)onTurn);//���·�ֵ
    GetMaxScorePosition();
    line = MaxScorePosition / 10;
    column = MaxScorePosition % 10;
    cross[line][column] = PlayerNumber;
    UpdateScore(line, column, PlayerNumber);
}
