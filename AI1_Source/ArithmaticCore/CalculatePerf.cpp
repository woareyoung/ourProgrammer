#include "../../AI1_Header/AI1.h"

void AI1::CalculatePerf(int line, int column)
{
    GetMaxScorePosition();
    AttackPerformance = Score[line][column] / MaxScore;
}
