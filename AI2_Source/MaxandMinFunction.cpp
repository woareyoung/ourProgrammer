#include "../AI2_Header/AI2.h"
/**
 * 这一个类主要是实现AI2的主要算法Max、Min算法的
 */


int isAI2::Evaluation() {

}

void isAI2::initDataFromArray() {

}

void isAI2::MaxAndMin(){

}

void isAI2::Scan(int cross[10][10], bool Cross[10][10]){

}

void isAI2::GetPosition(int& line,int& column,int player, int rival,int cross[10][10], bool Cross[10][10]) {

}

void isAI2::Score() {

}

/**
 * [isAI2::isBesieged 判断是否被包围了]
 * @param  RivalLine   [当前准备着子的位置的行]
 * @param  RivalColumn [当前准备着子的位置的列]
 * @param  onTurn      [轮到谁，参数可以在PlayerInfo.h中查看]
 * @return             [是否被包围，被包围就返回true，没有被包围就返回false]
 */
bool isAI2::isBesieged(int RivalLine, int RivalColumn, int player, int rival) {
    // -----------------初始化-----------------------

    // 判断是否被包围的标准数组
    bool tie[4] = {
        false, false, false, false
    };
    // 遍历状态矩阵，当遍历过的时候为true，当没有遍历过的时候为假。
    Cross[RivalLine][RivalColumn] = true;
    //下标为0的那一行如果为true则初始化，否则不用初始化
    Cross[RivalLine][0] = true;

    // -----------------初始化-----------------------

    // -----------------上方-----------------------
    //若对方棋子的上方有对方的棋子且未到上边缘
    if(cross[RivalLine - 1][RivalColumn] == rival && RivalLine - 1 > 0
       && Cross[RivalLine - 1][RivalColumn] == false) {
        tie[0] = isBesieged(RivalLine - 1, RivalColumn, player, rival);
    }
    //若对方棋子的上方没有棋子，直接返回false
    else if(cross[RivalLine - 1][RivalColumn] == 0 && RivalLine - 1 > 0) {
        return false;
    }
    //若对方棋子的上方有己方的棋子或已到边缘
    else tie[0] = true;
    // -----------------上方-----------------------

    // -----------------下方-----------------------
    //若对方棋子的下方有对方的棋子且未到下边缘
    if(cross[RivalLine + 1][RivalColumn] == rival && RivalLine + 1 < 10
       && Cross[RivalLine + 1][RivalColumn] == false) {
        tie[1] = isBesieged(RivalLine + 1, RivalColumn, player, rival);
    }
    //若对方棋子的下方没有棋子
    else if(cross[RivalLine + 1][RivalColumn] == 0 && RivalLine + 1 < 10) {
        return false;
    }
    //若对方棋子的下方有己方的棋子或已到边缘
    else tie[1] = true;
    // -----------------下方-----------------------

    // -----------------右方-----------------------
    //若对方棋子的右方有对方的棋子且未到右边缘
    if(cross[RivalLine][RivalColumn + 1] == rival && RivalColumn + 1 < 10
       && Cross[RivalLine][RivalColumn + 1] == false) {
        tie[2] = isBesieged(RivalLine, RivalColumn + 1, player, rival);
    }
    //若对方棋子的右方没有棋子
    else if(cross[RivalLine][RivalColumn + 1] == 0 && RivalColumn + 1 < 10) {
        return false;
    }
    //若对方棋子的右方有己方的棋子或已到边缘
    else tie[2] = true;
    // -----------------右方-----------------------

    // -----------------左方-----------------------
    //若对方棋子的左方有对方的棋子且未到左边缘
    if(cross[RivalLine][RivalColumn - 1] == rival && RivalColumn - 1 > 0
       && Cross[RivalLine][RivalColumn - 1] == false) {
        tie[3] = isBesieged(RivalLine, RivalColumn - 1, player, rival);
    }
    //若对方棋子的左方没有棋子
    else if(cross[RivalLine][RivalColumn - 1] == 0 && RivalColumn - 1 > 0) {
        return false;
    }
    //若对方棋子的左方有己方的棋子或已到边缘
    else {
        tie[3] = true;
    }
    // -----------------左方-----------------------

    // 这里是评定标准，当全部为true的时候，表示被围死了！
    if(tie[0] && tie[1] && tie[2] && tie[3]) {
        return true;
    }
    return false;
}

