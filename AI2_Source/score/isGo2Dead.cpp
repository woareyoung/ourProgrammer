#include "../../AI2_Header/isAI2.h"

/**
 * [isAI2::isGo2Dead 判断着子点是否有自杀倾向]
 */
void isAI2::isGo2Dead() {
	int stack[81][2] = {0}; //存储栈元素，0为x,1为y
	int top = 0;// 栈顶元素
	int treated = 0;// 处理过的元素
	for (int i = 1;i < 10;i++) {
		for (int j = 1;j < 10;j++) {
			if (/*cross[i][j] != turn2Who || */ !chessStatus[i][j]) {
				continue;
			}
			chessStatus[i][j] = true;
			// 初始化栈顶元素
			stack[top][0] = i;
			stack[top][1] = j;
			top++;
			// 当栈顶元素的数量级小于处理过的元素的数量的时候，循环终止
			while(treated < top) {
				int x = stack[treated][0];
                int y = stack[treated][1];
                //如果当前元素上边有未处理元素，且该元素与当前元素同类，则将其入栈
                if(x > 0 && !chessStatus[x-1][y] && cross[i][j] == cross[x-1][y])
                {
                    chessStatus[x-1][y] = true;//标记当前位置的子已经被处理过
                    stack[top][0] = x-1;
                    stack[top][1] = y;
                    top++;
                }
                //如果当前元素下边有未处理元素，且该元素与当前元素同类，则将其入栈
                if(x < 10 && !chessStatus[x+1][y] && cross[i][j] == cross[x+1][y])
                {
                    chessStatus[x+1][y] = true;//标记当前位置的子已经被处理过
                    stack[top][0] = x+1;
                    stack[top][1] = y;
                    top++;
                }
                //如果当前元素左边有未处理元素，且该元素与当前元素同类，则将其入栈
                if(y > 0 && !chessStatus[x][y-1] && cross[i][j] == cross[x][y-1])
                {
                    chessStatus[x][y-1] = true;//标记当前位置的子已经被处理过
                    stack[top][0] = x;
                    stack[top][1] = y-1;
                    top++;
                }
                //如果当前元素右边有未处理元素，且该元素与当前元素同类，则将其入栈
                if(y < 10 && !chessStatus[x][y+1] && cross[i][j] == cross[x][y+1])
                {
                    chessStatus[x][y+1] = true;//标记当前位置的子已经被处理过
                    stack[top][0] = x;
                    stack[top][1] = y+1;
                    top++;
                }
                treated++;//处理下一个栈元素
            }
            // 假如是自杀行为，就将这个着子点的分数设置为min
            if(top > 0 && IsDeadChess(stack,top)) {
                AddDeadChessScore(stack,top);
            }
            top=treated=0;//清空
		}
	}
}

/**
 * 判断栈内元素所组成的串是否是自杀行为
 * @param stach[][2] 栈
 * @param len 栈的元素占用的长度
 */
bool isAI2::IsDeadChess(int stack[][2],int len)
{
    int x,y;
    for(int i=0; i<len; i++)
    {
        x=stack[i][0];
        y=stack[i][1];
        //上边有空格
        if(x > 0 && cross[x-1][y] == noChess) {
        	return false;
        }
        //上边有空格
        if(x < 10 && cross[x+1][y] == noChess) {
        	return false;
        }
        //左边有空格
        if(y > 0 && cross[x][y-1] == noChess) {
        	 return false;
        }
        //右边有空格
        if(y < 10 && cross[x][y+1] == noChess) {
        	return false;
        }
    }
    return true;
}

/**
 * 为死棋位加分
 * @param stach[][2] 栈
 * @param len 栈的元素占用的长度
 */
void isAI2::AddDeadChessScore(int stack[][2],int len)
{
    for(int i=0; i<len; i++) {
    	chessScore[stack[i][0]][stack[i][1]] = min;
       	chessStatus[stack[i][0]][stack[i][1]] = true;
    }
}
