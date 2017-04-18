#ifndef AI3_H_INCLUDED
#define AI3_H_INCLUDED

#include "../chessBoard_Header/AI.h"

class AI3 : public AI
{
public:
    void GetPosition(int &line, int &column, int onTurn = 0);
};

#endif // AI3_H_INCLUDED
