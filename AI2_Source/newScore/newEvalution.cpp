#include "../../AI2_Header/isAI2.h"

int isAI2::maxandmin(int depth) {
    int tempArray[10] = {
        2,1,2,1,2,1,2,1,2,1
    };
    for (int i = 0;i < depth; i++) {
        turn2Who = tempArray[i];
        return singleLayer();
    }

}

int isAI2::singleLayer() {
    Revalute();
    if (turn2Who == PlayerId) {
        return MaxScore();
    } else {
        return MinScore();
    }
}

void isAI2::Revalute()
{
    initChessScore();
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if (Cross[i][j] != noChess && !isBesieged(i,j,turn2Who))
            {
                JudgeScoreType();// 判断分数的多少
            }
        }
    }
}

int isAI2::MaxScore()
{
    int temp = chessScore[1][1];
    int tempPos = 101;
    for (int i = 1;i < 10; i++) {
        for (int j = 1;j < 10; j++) {
            if (temp > chessScore[i][j]) {
                temp = chessScore[i][j];
                tempPos = i*100 + j;
            }
        }
    }
    cross[tempPos/100][tempPos%100] = turn2Who;
    Cross[tempPos/100][tempPos%100] = true;
    return tempPos;
}

int isAI2::MinScore()
{
    int temp = chessScore[1][1];
    int tempPos = 101;
    for (int i = 1;i < 10; i++) {
        for (int j = 1;j < 10; j++) {
            if (temp < chessScore[i][j]) {
                temp = chessScore[i][j];
                tempPos = i*100 + j;
            }
        }
    }
    cross[tempPos/100][tempPos%100] = turn2Who;
    Cross[tempPos/100][tempPos%100] = true;
    return tempPos;
}

void isAI2::JudgeScoreType()
{
    if (isAI2::blankList.size() == 3)
    {
        addREScore(40);
    }
    else if (isAI2::blankList.size() == 2)
    {
        addREScore(80);
    }
    else if (isAI2::blankList.size() == 1)
    {
        addREScore(120);
    }
    else if (isAI2::blankList.size() == 0)
    {
        addREScore(min);
    }
}
void isAI2::addREScore(int score)
{
    std::list<int>::iterator blankIterator;
    for (blankIterator = blankList.begin(); blankIterator!=isAI2::blankList.end(); ++blankIterator)
    {
        int temp = *blankIterator;
        chessScore[temp/100][temp%100] += score;
    }
}

//注：调用该函数（即下棋的玩家）的那个人或AI是“己方”
bool isAI2::isBesieged(int line, int column, int onTurn)
{
    int player = onTurn == isBlack ? isWhite : isBlack;//记录己方的编号（是1还是2）
    int rival = onTurn;//记录对方的编号（是1还是2）

    bool Position[4] = {false, false, false, false};

    //判断棋子四周有没有棋子
    //若左方有对方的一个棋子
    if(cross[line][column - 1] == rival)
    {
        reduceRecursionTimes();
        if(Besieged(line, column - 1, player, rival))
        {
            return true;
        }
        Position[0] = true;
    }
    //若己方棋子已到左边缘
    else if(column - 1 == 0)
    {
        Position[0] = true;
    }
    //若左方有己方的棋子
    else if(cross[line][column - 1] == player)
    {
        reduceRecursionTimes();
        Position[0] = Besieged(line, column, rival, player);
    }
    //若右方有对方的一个棋子
    if(cross[line][column + 1] == rival)
    {
        reduceRecursionTimes();
        if(Besieged(line, column + 1, player, rival))
        {
            return true;
        }
        Position[1] = true;
    }
    //若己方的棋子已到右边缘
    else if(column + 1 == 10)
    {
        Position[1] = true;
    }
    //若右方有己方的棋子
    else if(cross[line][column + 1] == player)
    {
        reduceRecursionTimes();
        Position[1] = Besieged(line, column, rival, player);
    }
    //若上方有对方的一个棋子
    if(cross[line - 1][column] == rival)
    {
        reduceRecursionTimes();
        if(Besieged(line - 1, column, player, rival))
        {

            return true;
        }
        Position[2] = true;
    }
    //若己方的棋子已到上边缘
    else if(line - 1 == 0)
    {
        Position[2] = true;
    }
    //若上方有己方的棋子
    else if(cross[line - 1][column] == player)
    {
        reduceRecursionTimes();
        Position[2] = Besieged(line, column, rival, player);
    }
    //若下方有对方的一个棋子
    if(cross[line + 1][column] == rival)
    {
        reduceRecursionTimes();
        if(Besieged(line + 1, column, player, rival))
        {
            return true;
        }
        Position[3] = true;
    }
    //若己方的棋子已到下边缘
    else if(line + 1 == 10)
    {
        Position[3] = true;
    }
    //若下方有己方的棋子
    else if(cross[line + 1][column] == player)
    {
        reduceRecursionTimes();
        Position[3] = Besieged(line, column, rival, player);
    }
    if(Position[0] && Position[1] && Position[2] && Position[3])
    {
        return true;
    }
    return false;
}
//若棋子被围死，则返回true，只要棋子周围有一个空位就返回false
bool isAI2::Besieged(int RivalLine, int RivalColumn, int player, int rival)
{
    bool tie[4] = {false, false, false, false};
    // 设置Cross数组状态
    setStatus(RivalLine,RivalColumn);
    //若对方棋子的上方有对方的棋子且未到上边缘
    if(cross[RivalLine - 1][RivalColumn] == rival && RivalLine - 1 > 0
            && Cross[RivalLine - 1][RivalColumn] == false)
    {
        tie[0] = Besieged(RivalLine - 1, RivalColumn, player, rival);
    }
    //若对方棋子的上方没有棋子，直接返回false
    else if(cross[RivalLine - 1][RivalColumn] == 0 && RivalLine - 1 > 0)
    {
        isAI2::blankList.push_back((RivalLine - 1)*100 + RivalColumn);
        return false;
    }
    //若对方棋子的上方有己方的棋子或已到边缘
    else
    {
        tie[0] = true;
    }
    //若对方棋子的下方有对方的棋子且未到下边缘
    if(cross[RivalLine + 1][RivalColumn] == rival && RivalLine + 1 < 10
            && Cross[RivalLine + 1][RivalColumn] == false)
    {
        tie[1] = Besieged(RivalLine + 1, RivalColumn, player, rival);
    }
    //若对方棋子的下方没有棋子
    else if(cross[RivalLine + 1][RivalColumn] == 0 && RivalLine + 1 < 10)
    {
        isAI2::blankList.push_back((RivalLine + 1)*100 + RivalColumn);
        return false;
    }
    //若对方棋子的下方有己方的棋子或已到边缘
    else tie[1] = true;
    //若对方棋子的右方有对方的棋子且未到右边缘
    if(cross[RivalLine][RivalColumn + 1] == rival && RivalColumn + 1 < 10
            && Cross[RivalLine][RivalColumn + 1] == false)
    {
        tie[2] = Besieged(RivalLine, RivalColumn + 1, player, rival);
    }
    //若对方棋子的右方没有棋子
    else if(cross[RivalLine][RivalColumn + 1] == 0 && RivalColumn + 1 < 10)
    {
        isAI2::blankList.push_back(RivalLine*100 + RivalColumn + 1);
        return false;
    }
    //若对方棋子的右方有己方的棋子或已到边缘
    else
    {
        tie[2] = true;
    }

    //若对方棋子的左方有对方的棋子且未到左边缘
    if(cross[RivalLine][RivalColumn - 1] == rival && RivalColumn - 1 > 0
            && Cross[RivalLine][RivalColumn - 1] == false)
    {
        tie[3] = Besieged(RivalLine, RivalColumn - 1, player, rival);
    }
    //若对方棋子的左方没有棋子
    else if(cross[RivalLine][RivalColumn - 1] == 0 && RivalColumn - 1 > 0)
    {
        isAI2::blankList.push_back(RivalLine*100 + RivalColumn - 1);
        return false;
    }
    //若对方棋子的左方有己方的棋子或已到边缘
    else
    {
        tie[3] = true;
    }

    if(tie[0] && tie[1] && tie[2] && tie[3])
    {
        return true;
    }
    return false;
}
