#include "../AI1_Header/AI1.h"
///������Ԥ������λ��
bool AI1::DeadCheck(int line, int column, int who)
{
    bool Position[4] = {false, false, false, false};
    int player = who;//��¼�����ı�ţ���1����2��
    int rival = player == 1 ? 2 : 1;//��¼�Է��ı�ţ���1����2��
    //�ж�����������û������
    //�����жԷ���һ������
    if(cross[line][column - 1] == rival)
    {
        reduceRecursionTimes();
        if(Besieg(line, column - 1, player, rival))
            return true;
        Position[0] = true;
    }
    //�����������ѵ����Ե
    else if(column - 1 == 0) Position[0] = true;
    //�����м���������
    else if(cross[line][column - 1] == player)
    {
        reduceRecursionTimes();
        Position[0] = Besieg(line, column, rival, player);
    }
    //���ҷ��жԷ���һ������
    if(cross[line][column + 1] == rival)
    {
        reduceRecursionTimes();
        if(Besieg(line, column + 1, player, rival))
            return true;
        Position[1] = true;
    }
    //�������������ѵ��ұ�Ե
    else if(column + 1 == 10) Position[1] = true;
    //���ҷ��м���������
    else if(cross[line][column + 1] == player)
    {
        reduceRecursionTimes();
        Position[1] = Besieg(line, column, rival, player);
    }
    //���Ϸ��жԷ���һ������
    if(cross[line - 1][column] == rival)
    {
        reduceRecursionTimes();
        if(Besieg(line - 1, column, player, rival))
            return true;
        Position[2] = true;
    }
    //�������������ѵ��ϱ�Ե
    else if(line - 1 == 0) Position[2] = true;
    //���Ϸ��м���������
    else if(cross[line - 1][column] == player)
    {
        reduceRecursionTimes();
        Position[2] = Besieg(line, column, rival, player);
    }
    //���·��жԷ���һ������
    if(cross[line + 1][column] == rival)
    {
        reduceRecursionTimes();
        if(Besieg(line + 1, column, player, rival))
            return true;
        Position[3] = true;
    }
    //�������������ѵ��±�Ե
    else if(line + 1 == 10) Position[3] = true;
    //���·��м���������
    else if(cross[line + 1][column] == player)
    {
        reduceRecursionTimes();
        Position[3] = Besieg(line, column, rival, player);
    }
    if(Position[0] && Position[1] && Position[2] && Position[3])
        return true;
    return false;
}

bool AI1::Besieg(int RivalLine, int RivalColumn, int player, int rival)
{
    bool tie[4] = {false, false, false, false};
    // ����Cross����״̬
    setStatus(RivalLine,RivalColumn);
    //���Է����ӵ��Ϸ��жԷ���������δ���ϱ�Ե
    if(cross[RivalLine - 1][RivalColumn] == rival && RivalLine - 1 > 0
       && Cross[RivalLine - 1][RivalColumn] == false)
        tie[0] = Besieg(RivalLine - 1, RivalColumn, player, rival);
    //���Է����ӵ��Ϸ�û�����ӣ�ֱ�ӷ���false
    else if(cross[RivalLine - 1][RivalColumn] == 0 && RivalLine - 1 > 0) return false;
    //���Է����ӵ��Ϸ��м��������ӻ��ѵ���Ե
    else tie[0] = true;
    //���Է����ӵ��·��жԷ���������δ���±�Ե
    if(cross[RivalLine + 1][RivalColumn] == rival && RivalLine + 1 < 10
       && Cross[RivalLine + 1][RivalColumn] == false)
        tie[1] = Besieg(RivalLine + 1, RivalColumn, player, rival);
    //���Է����ӵ��·�û������
    else if(cross[RivalLine + 1][RivalColumn] == 0 && RivalLine + 1 < 10) return false;
    //���Է����ӵ��·��м��������ӻ��ѵ���Ե
    else tie[1] = true;
    //���Է����ӵ��ҷ��жԷ���������δ���ұ�Ե
    if(cross[RivalLine][RivalColumn + 1] == rival && RivalColumn + 1 < 10
       && Cross[RivalLine][RivalColumn + 1] == false)
        tie[2] = Besieg(RivalLine, RivalColumn + 1, player, rival);
    //���Է����ӵ��ҷ�û������
    else if(cross[RivalLine][RivalColumn + 1] == 0 && RivalColumn + 1 < 10) return false;
    //���Է����ӵ��ҷ��м��������ӻ��ѵ���Ե
    else tie[2] = true;
    //���Է����ӵ����жԷ���������δ�����Ե
    if(cross[RivalLine][RivalColumn - 1] == rival && RivalColumn - 1 > 0
       && Cross[RivalLine][RivalColumn - 1] == false)
        tie[3] = Besieg(RivalLine, RivalColumn - 1, player, rival);
    //���Է����ӵ���û������
    else if(cross[RivalLine][RivalColumn - 1] == 0 && RivalColumn - 1 > 0) return false;
    //���Է����ӵ����м��������ӻ��ѵ���Ե
    else tie[3] = true;
    if(tie[0] && tie[1] && tie[2] && tie[3]) return true;
    return false;
}

void AI1::reduceRecursionTimes()
{
    for(int i = 0; i < 10; i++)
    {
        if(Cross[i][0] == true)
            for(int j = 0; j < 10; j++)
                Cross[i][j] = false;
    }
}

void AI1::setStatus(int RivalLine,int RivalColumn) {
    Cross[RivalLine][RivalColumn] = true;
    Cross[RivalLine][0] = true;//�±�Ϊ0����һ�����Ϊtrue���ʼ���������ó�ʼ��
}
