#ifndef CHESSRULE_H_INCLUDED
#define CHESSRULE_H_INCLUDED

# include "Chess.h"
# include "PlayerInfo.h"
class ChessRule: public Chess, public PlayerInfo
{
public:
    bool Start;//��ʼ��Ϸ


    //�ж�ʤ���Ƿ��ѷ֣����ֳ�ʤ������true�����򷵻�false
    bool WinOrLose();
    //�ж϶Է���������û�б�Χ��������һ�����ӱ�Χ�������
    bool Besieged(int RivalLine, int RivalColumn, int player, int rival);
    //ʤ������֮��
    void reStart(HWND ParentHwnd);
};


#endif // CHESSRULE_H_INCLUDED
