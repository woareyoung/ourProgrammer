#include "../../AI2_Header/AI2.h"

bool AI2::Revalute()
{
    return false;
}
//�����ӱ�Χ�����򷵻�true��ֻҪ������Χ��һ����λ�ͷ���false
bool AI2::Besieged(int RivalLine, int RivalColumn, int player, int rival)
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
