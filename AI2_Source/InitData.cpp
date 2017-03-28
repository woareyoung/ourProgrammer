#include "../AI2_Header/isAI2.h"

struct pos
{
    int line;
    int column;
    int status;
};

isAI2::isAI2()
{
    this->PlayerId = isWhite;
    // 初始化对角数组
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
