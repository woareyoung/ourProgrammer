#ifndef AI2_H_INCLUDED
#define AI2_H_INCLUDED

#include "../chessBoard/AImessage.h"

class AI2 : public AI
{
public:
    void GetPosition(int &line, int &column, int onTurn = 0);
};

#endif // AI2_H_INCLUDED

