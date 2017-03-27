#include "../AI2_Header/AI2.h"

AI2::AI2()
{
    this->PlayerId = isWhite;
    // 向分数数组中填充0
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            chessScore[i][j] = 0;
        }
    }

    this->cornerArray[0] = 101;
    this->cornerArray[1] = 102;
    this->cornerArray[2] = 201;
    this->cornerArray[3] = 109;
    this->cornerArray[4] = 108;
    this->cornerArray[5] = 209;
    this->cornerArray[6] = 901;
    this->cornerArray[7] = 801;
    this->cornerArray[8] = 902;
    this->cornerArray[9] = 909;
    this->cornerArray[10] = 809;
    this->cornerArray[11] = 908;
}
