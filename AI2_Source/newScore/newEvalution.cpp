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
                JudgeScoreType();// �жϷ����Ķ���
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

//ע�����øú��������������ң����Ǹ��˻�AI�ǡ�������
bool isAI2::isBesieged(int line, int column, int onTurn)
{
    int player = onTurn == isBlack ? isWhite : isBlack;//��¼�����ı�ţ���1����2��
    int rival = onTurn;//��¼�Է��ı�ţ���1����2��

    bool Position[4] = {false, false, false, false};

    //�ж�����������û������
    //�����жԷ���һ������
    if(cross[line][column - 1] == rival)
    {
        reduceRecursionTimes();
        if(Besieged(line, column - 1, player, rival))
        {
            return true;
        }
        Position[0] = true;
    }
    //�����������ѵ����Ե
    else if(column - 1 == 0)
    {
        Position[0] = true;
    }
    //�����м���������
    else if(cross[line][column - 1] == player)
    {
        reduceRecursionTimes();
        Position[0] = Besieged(line, column, rival, player);
    }
    //���ҷ��жԷ���һ������
    if(cross[line][column + 1] == rival)
    {
        reduceRecursionTimes();
        if(Besieged(line, column + 1, player, rival))
        {
            return true;
        }
        Position[1] = true;
    }
    //�������������ѵ��ұ�Ե
    else if(column + 1 == 10)
    {
        Position[1] = true;
    }
    //���ҷ��м���������
    else if(cross[line][column + 1] == player)
    {
        reduceRecursionTimes();
        Position[1] = Besieged(line, column, rival, player);
    }
    //���Ϸ��жԷ���һ������
    if(cross[line - 1][column] == rival)
    {
        reduceRecursionTimes();
        if(Besieged(line - 1, column, player, rival))
        {

            return true;
        }
        Position[2] = true;
    }
    //�������������ѵ��ϱ�Ե
    else if(line - 1 == 0)
    {
        Position[2] = true;
    }
    //���Ϸ��м���������
    else if(cross[line - 1][column] == player)
    {
        reduceRecursionTimes();
        Position[2] = Besieged(line, column, rival, player);
    }
    //���·��жԷ���һ������
    if(cross[line + 1][column] == rival)
    {
        reduceRecursionTimes();
        if(Besieged(line + 1, column, player, rival))
        {
            return true;
        }
        Position[3] = true;
    }
    //�������������ѵ��±�Ե
    else if(line + 1 == 10)
    {
        Position[3] = true;
    }
    //���·��м���������
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
//�����ӱ�Χ�����򷵻�true��ֻҪ������Χ��һ����λ�ͷ���false
bool isAI2::Besieged(int RivalLine, int RivalColumn, int player, int rival)
{
    bool tie[4] = {false, false, false, false};
    // ����Cross����״̬
    setStatus(RivalLine,RivalColumn);
    //���Է����ӵ��Ϸ��жԷ���������δ���ϱ�Ե
    if(cross[RivalLine - 1][RivalColumn] == rival && RivalLine - 1 > 0
            && Cross[RivalLine - 1][RivalColumn] == false)
    {
        tie[0] = Besieged(RivalLine - 1, RivalColumn, player, rival);
    }
    //���Է����ӵ��Ϸ�û�����ӣ�ֱ�ӷ���false
    else if(cross[RivalLine - 1][RivalColumn] == 0 && RivalLine - 1 > 0)
    {
        isAI2::blankList.push_back((RivalLine - 1)*100 + RivalColumn);
        return false;
    }
    //���Է����ӵ��Ϸ��м��������ӻ��ѵ���Ե
    else
    {
        tie[0] = true;
    }
    //���Է����ӵ��·��жԷ���������δ���±�Ե
    if(cross[RivalLine + 1][RivalColumn] == rival && RivalLine + 1 < 10
            && Cross[RivalLine + 1][RivalColumn] == false)
    {
        tie[1] = Besieged(RivalLine + 1, RivalColumn, player, rival);
    }
    //���Է����ӵ��·�û������
    else if(cross[RivalLine + 1][RivalColumn] == 0 && RivalLine + 1 < 10)
    {
        isAI2::blankList.push_back((RivalLine + 1)*100 + RivalColumn);
        return false;
    }
    //���Է����ӵ��·��м��������ӻ��ѵ���Ե
    else tie[1] = true;
    //���Է����ӵ��ҷ��жԷ���������δ���ұ�Ե
    if(cross[RivalLine][RivalColumn + 1] == rival && RivalColumn + 1 < 10
            && Cross[RivalLine][RivalColumn + 1] == false)
    {
        tie[2] = Besieged(RivalLine, RivalColumn + 1, player, rival);
    }
    //���Է����ӵ��ҷ�û������
    else if(cross[RivalLine][RivalColumn + 1] == 0 && RivalColumn + 1 < 10)
    {
        isAI2::blankList.push_back(RivalLine*100 + RivalColumn + 1);
        return false;
    }
    //���Է����ӵ��ҷ��м��������ӻ��ѵ���Ե
    else
    {
        tie[2] = true;
    }

    //���Է����ӵ����жԷ���������δ�����Ե
    if(cross[RivalLine][RivalColumn - 1] == rival && RivalColumn - 1 > 0
            && Cross[RivalLine][RivalColumn - 1] == false)
    {
        tie[3] = Besieged(RivalLine, RivalColumn - 1, player, rival);
    }
    //���Է����ӵ���û������
    else if(cross[RivalLine][RivalColumn - 1] == 0 && RivalColumn - 1 > 0)
    {
        isAI2::blankList.push_back(RivalLine*100 + RivalColumn - 1);
        return false;
    }
    //���Է����ӵ����м��������ӻ��ѵ���Ե
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
