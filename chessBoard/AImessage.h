#ifndef AIMESSAGE_H_INCLUDED
#define AIMESSAGE_H_INCLUDED

///当3个AI都写完时就统一起来，弄成可选择AI的功能
class AI
{
public:
    virtual void GetPosition(int &line, int &column, int onTurn){};
};

#endif // AIMESSAGE_H_INCLUDED
