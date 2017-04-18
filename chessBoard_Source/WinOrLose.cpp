#include "../ChessBoard_Header/ChessBoard.h"

/*ʤ������
* 1����ʱ���������ж��ɴ��ڹ��̺���ʵ��
* 2�����֡��Ⱥ���
* 3��Χ��������˼�룺���������һ�����ӣ����жϸú�����Χ���ĸ�λ������û�а��ӱ�Χ�������иú����Ƿ�Χ��
*/
//ע�����øú��������������ң����Ǹ��˻�AI�ǡ�������
bool ChessBoard::WinOrLose()
{
    bool Position[4] = {false, false, false, false};
    int player;//��¼�����ı�ţ���1����2��
    int rival;//��¼�Է��ı�ţ���1����2��
    //onTurn��ֵ���ȱ仯���ٵ��øú�����WinOrLose����
    if(onTurn == isPlay1onTurn || onTurn == isAI1onTurn)
    {
        player = isWhite;
        rival = isBlack;
    }
    else if(onTurn == isPlay2onTurn || onTurn == isAI2onTurn)
    {
        player = isBlack;
        rival = isWhite;
    }
    //�ж�����������û������
    //�����жԷ���һ������
    if(cross[line][column - 1] == rival)
    {
        reduceRecursionTimes();
        if(Besieged(line, column - 1, player, rival))
        {
            Winner = rival;
            return true;
        }
        Position[0] = true;
    }
    //�����������ѵ����Ե
    else if(column - 1 == 0) Position[0] = true;
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
            Winner = rival;
            return true;
        }
        Position[1] = true;
    }
    //�������������ѵ��ұ�Ե
    else if(column + 1 == 10) Position[1] = true;
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
            Winner = rival;
            return true;
        }
        Position[2] = true;
    }
    //�������������ѵ��ϱ�Ե
    else if(line - 1 == 0) Position[2] = true;
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
            Winner = rival;
            return true;
        }
        Position[3] = true;
    }
    //�������������ѵ��±�Ե
    else if(line + 1 == 10) Position[3] = true;
    //���·��м���������
    else if(cross[line + 1][column] == player)
    {
        reduceRecursionTimes();
        Position[3] = Besieged(line, column, rival, player);
    }
    if(Position[0] && Position[1] && Position[2] && Position[3])
    {
        Winner = rival;
        return true;
    }
    return false;
}
//�ж϶Է��������Ƿ�Χ��������������ʾ�Է����ӵ�λ��
//�ú�������һ�����ӱ�Χ����������õݹ�ķ������һ�����ӵ����
//�����ӱ�Χ�����򷵻�true��ֻҪ������Χ��һ����λ�ͷ���false
bool ChessBoard::Besieged(int RivalLine, int RivalColumn, int player, int rival)
{
    bool tie[4] = {false, false, false, false};
    // ����Cross����״̬
    setStatus(RivalLine,RivalColumn);
    //���Է����ӵ��Ϸ��жԷ���������δ���ϱ�Ե
    if(cross[RivalLine - 1][RivalColumn] == rival && RivalLine - 1 > 0
       && Cross[RivalLine - 1][RivalColumn] == false)
        tie[0] = Besieged(RivalLine - 1, RivalColumn, player, rival);
    //���Է����ӵ��Ϸ�û�����ӣ�ֱ�ӷ���false
    else if(cross[RivalLine - 1][RivalColumn] == 0 && RivalLine - 1 > 0) return false;
    //���Է����ӵ��Ϸ��м��������ӻ��ѵ���Ե
    else tie[0] = true;
    //���Է����ӵ��·��жԷ���������δ���±�Ե
    if(cross[RivalLine + 1][RivalColumn] == rival && RivalLine + 1 < 10
       && Cross[RivalLine + 1][RivalColumn] == false)
        tie[1] = Besieged(RivalLine + 1, RivalColumn, player, rival);
    //���Է����ӵ��·�û������
    else if(cross[RivalLine + 1][RivalColumn] == 0 && RivalLine + 1 < 10) return false;
    //���Է����ӵ��·��м��������ӻ��ѵ���Ե
    else tie[1] = true;
    //���Է����ӵ��ҷ��жԷ���������δ���ұ�Ե
    if(cross[RivalLine][RivalColumn + 1] == rival && RivalColumn + 1 < 10
       && Cross[RivalLine][RivalColumn + 1] == false)
        tie[2] = Besieged(RivalLine, RivalColumn + 1, player, rival);
    //���Է����ӵ��ҷ�û������
    else if(cross[RivalLine][RivalColumn + 1] == 0 && RivalColumn + 1 < 10) return false;
    //���Է����ӵ��ҷ��м��������ӻ��ѵ���Ե
    else tie[2] = true;
    //���Է����ӵ����жԷ���������δ�����Ե
    if(cross[RivalLine][RivalColumn - 1] == rival && RivalColumn - 1 > 0
       && Cross[RivalLine][RivalColumn - 1] == false)
        tie[3] = Besieged(RivalLine, RivalColumn - 1, player, rival);
    //���Է����ӵ���û������
    else if(cross[RivalLine][RivalColumn - 1] == 0 && RivalColumn - 1 > 0) return false;
    //���Է����ӵ����м��������ӻ��ѵ���Ե
    else tie[3] = true;
    if(tie[0] && tie[1] && tie[2] && tie[3]) return true;
    return false;
}
