#include "../../AI2_Header/AI2.h"

/**
 * [AI2::isGo2Dead 判断着子点是否有自杀倾向]
 */
void AI2::isGo2Dead(int type)
{
    int stack[81][2] = {0}; //存储栈元素，0为x,1为y
    int top = 0;// 栈顶元素
    int treated = 0;// 处理过的元素

    // 重置所有的状态位
    bool tempChess[10][10]= {0}; //用来存储当前位置的子是否被处理过
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if (cross[i][j] != type || !tempChess[i][j])
            {
                continue;
            }
            tempChess[i][j] = true;
            // 初始化栈顶元素
            stack[top][0] = i;
            stack[top][1] = j;
            top++;
            // 当栈顶元素的数量级小于处理过的元素的数量的时候，循环终止
            while(treated < top)
            {
                int x = stack[treated][0];
                int y = stack[treated][1];
                //如果当前元素上边有未处理元素，且该元素与当前元素同类，则将其入栈
                if(x > 0 && !tempChess[x-1][y] && type == cross[x-1][y])
                {
                    tempChess[x-1][y] = true;//标记当前位置的子已经被处理过
                    stack[top][0] = x-1;
                    stack[top][1] = y;
                    top++;
                }
                //如果当前元素下边有未处理元素，且该元素与当前元素同类，则将其入栈
                if(x < 10 && !tempChess[x+1][y] && type == cross[x+1][y])
                {
                    tempChess[x+1][y] = true;//标记当前位置的子已经被处理过
                    stack[top][0] = x+1;
                    stack[top][1] = y;
                    top++;
                }
                //如果当前元素左边有未处理元素，且该元素与当前元素同类，则将其入栈
                if(y > 0 && !tempChess[x][y-1] && type == cross[x][y-1])
                {
                    tempChess[x][y-1] = true;//标记当前位置的子已经被处理过
                    stack[top][0] = x;
                    stack[top][1] = y-1;
                    top++;
                }
                //如果当前元素右边有未处理元素，且该元素与当前元素同类，则将其入栈
                if(y < 10 && !tempChess[x][y+1] && type == cross[x][y+1])
                {
                    tempChess[x][y+1] = true;//标记当前位置的子已经被处理过
                    stack[top][0] = x;
                    stack[top][1] = y+1;
                    top++;
                }
                treated++;//处理下一个栈元素
            }
            // 假如是自杀行为，就将这个着子点的分数设置为min
            if(top > 0 && IsDeadChess(stack,top,type))
            {
                AddDeadChessScore(stack,top);
            }
            top=treated=0;//清空
        }
    }
}

/**
 * [AI2::isGo2Dead 判断着子点是否有自杀倾向]
 */
bool AI2::isGo2Dead(int line, int column ,int type)
{
    int stack[81][2] = {0}; //存储栈元素，0为x,1为y
    int top = 0;// 栈顶元素
    int treated = 0;// 处理过的元素
    int tempcross[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tempcross[i][j] = cross[i][j];
        }
    }
    tempcross[line][column] = type;

    // 重置所有的状态位
    bool tempChess[10][10]= {0}; //用来存储当前位置的子是否被处理过
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if (tempcross[i][j] != type || !tempChess[i][j])
            {
                continue;
            }
            tempChess[i][j] = true;
            // 初始化栈顶元素
            stack[top][0] = i;
            stack[top][1] = j;
            top++;
            // 当栈顶元素的数量级小于处理过的元素的数量的时候，循环终止
            while(treated < top)
            {
                int x = stack[treated][0];
                int y = stack[treated][1];
                //如果当前元素上边有未处理元素，且该元素与当前元素同类，则将其入栈
                if(x > 0 && !tempChess[x-1][y] && type == tempcross[x-1][y])
                {
                    tempChess[x-1][y] = true;//标记当前位置的子已经被处理过
                    stack[top][0] = x-1;
                    stack[top][1] = y;
                    top++;
                }
                //如果当前元素下边有未处理元素，且该元素与当前元素同类，则将其入栈
                if(x < 10 && !tempChess[x+1][y] && type == tempcross[x+1][y])
                {
                    tempChess[x+1][y] = true;//标记当前位置的子已经被处理过
                    stack[top][0] = x+1;
                    stack[top][1] = y;
                    top++;
                }
                //如果当前元素左边有未处理元素，且该元素与当前元素同类，则将其入栈
                if(y > 0 && !tempChess[x][y-1] && type == tempcross[x][y-1])
                {
                    tempChess[x][y-1] = true;//标记当前位置的子已经被处理过
                    stack[top][0] = x;
                    stack[top][1] = y-1;
                    top++;
                }
                //如果当前元素右边有未处理元素，且该元素与当前元素同类，则将其入栈
                if(y < 10 && !tempChess[x][y+1] && type == tempcross[x][y+1])
                {
                    tempChess[x][y+1] = true;//标记当前位置的子已经被处理过
                    stack[top][0] = x;
                    stack[top][1] = y+1;
                    top++;
                }
                treated++;//处理下一个栈元素
            }
            // 假如是自杀行为，就将这个着子点的分数设置为min
            if(top > 0 && IsDeadChess(stack,top,type))
            {
                AddDeadChessScore(stack,top);
            }
            top=treated=0;//清空
        }
    }
    return chessScore[line][column] == min;
}

/**
 * 判断栈内元素所组成的串是否是自杀行为
 * @param stach[][2] 栈
 * @param len 栈的元素占用的长度
 */
bool AI2::IsDeadChess(int stack[][2],int len, int type)
{
    int x,y;
    int tempCount = 0;
    int tie[4] = {false,false,false,false};
    for(int i=0; i<len; i++)
    {
        x=stack[i][0];
        y=stack[i][1];
        //上边有空格
        if(x > 1 && cross[x-1][y] == Rival)
        {
            tempCount++;
        }
        else if (x > 1 && cross[x-1][y] == noChess)
        {
            return false;
        }
        else
        {
            tie[0] = true;
        }
        //下边有空格
        if(x < 9 && cross[x+1][y] == Rival)
        {
            tempCount++;
        }
        else if (x < 9 && cross[x+1][y] == noChess)
        {
            return false;
        }
        else
        {
            tie[1] = true;
        }
        //左边有空格
        if(y > 1 && cross[x][y-1] == Rival)
        {
            tempCount++;
        }
        else if(y > 1 && cross[x][y-1] == noChess)
        {
            return false;
        }
        else
        {
            tie[2] = true;
        }
        //右边有空格
        if(y < 9 && cross[x][y+1] == Rival)
        {
            tempCount++;
        }
        else if (y < 9 && cross[x][y+1] == noChess)
        {
            return false;
        }
        else
        {
            tie[3] = true;
        }

        if (tempCount == 4)
        {
            return true;
        }

        if(tie[0] && tie[1] && tie[2] && tie[3])
        {
            return true;
        }

    }
    return true;
}

/**
 * 为死棋位加分
 * @param stach[][2] 栈
 * @param len 栈的元素占用的长度
 */
void AI2::AddDeadChessScore(int stack[][2],int len)
{
    for(int i=0; i<len; i++)
    {
        chessScore[stack[i][0]][stack[i][1]] = min;
        chessStatus[stack[i][0]][stack[i][1]] = true;
        _cprintf("----------dead chess position:  line=%d, column=%d\n", stack[i][0], stack[i][1]);
    }
}
