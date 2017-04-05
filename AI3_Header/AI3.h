#ifndef AI3_H_INCLUDED
#define AI3_H_INCLUDED

#include "../chessBoard/AImessage.h"

class AI3 : public AI
{
public:
    void GetPosition(int &line, int &column, int onTurn = 0);
};

#endif // AI3_H_INCLUDED
