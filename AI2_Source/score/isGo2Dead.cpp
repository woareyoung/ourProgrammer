#include "../../AI2_Header/isAI2.h"

/**
 * [isAI2::isGo2Dead �ж����ӵ��Ƿ�����ɱ����]
 */
void isAI2::isGo2Dead() {
	int stack[81][2] = {0}; //�洢ջԪ�أ�0Ϊx,1Ϊy
	int top = 0;// ջ��Ԫ��
	int treated = 0;// �������Ԫ��
	for (int i = 1;i < 10;i++) {
		for (int j = 1;j < 10;j++) {
			if (/*cross[i][j] != turn2Who || */ !chessStatus[i][j]) {
				continue;
			}
			chessStatus[i][j] = true;
			// ��ʼ��ջ��Ԫ��
			stack[top][0] = i;
			stack[top][1] = j;
			top++;
			// ��ջ��Ԫ�ص�������С�ڴ������Ԫ�ص�������ʱ��ѭ����ֹ
			while(treated < top) {
				int x = stack[treated][0];
                int y = stack[treated][1];
                //�����ǰԪ���ϱ���δ����Ԫ�أ��Ҹ�Ԫ���뵱ǰԪ��ͬ�࣬������ջ
                if(x > 0 && !chessStatus[x-1][y] && cross[i][j] == cross[x-1][y])
                {
                    chessStatus[x-1][y] = true;//��ǵ�ǰλ�õ����Ѿ��������
                    stack[top][0] = x-1;
                    stack[top][1] = y;
                    top++;
                }
                //�����ǰԪ���±���δ����Ԫ�أ��Ҹ�Ԫ���뵱ǰԪ��ͬ�࣬������ջ
                if(x < 10 && !chessStatus[x+1][y] && cross[i][j] == cross[x+1][y])
                {
                    chessStatus[x+1][y] = true;//��ǵ�ǰλ�õ����Ѿ��������
                    stack[top][0] = x+1;
                    stack[top][1] = y;
                    top++;
                }
                //�����ǰԪ�������δ����Ԫ�أ��Ҹ�Ԫ���뵱ǰԪ��ͬ�࣬������ջ
                if(y > 0 && !chessStatus[x][y-1] && cross[i][j] == cross[x][y-1])
                {
                    chessStatus[x][y-1] = true;//��ǵ�ǰλ�õ����Ѿ��������
                    stack[top][0] = x;
                    stack[top][1] = y-1;
                    top++;
                }
                //�����ǰԪ���ұ���δ����Ԫ�أ��Ҹ�Ԫ���뵱ǰԪ��ͬ�࣬������ջ
                if(y < 10 && !chessStatus[x][y+1] && cross[i][j] == cross[x][y+1])
                {
                    chessStatus[x][y+1] = true;//��ǵ�ǰλ�õ����Ѿ��������
                    stack[top][0] = x;
                    stack[top][1] = y+1;
                    top++;
                }
                treated++;//������һ��ջԪ��
            }
            // ��������ɱ��Ϊ���ͽ�������ӵ�ķ�������Ϊmin
            if(top > 0 && IsDeadChess(stack,top)) {
                AddDeadChessScore(stack,top);
            }
            top=treated=0;//���
		}
	}
}

/**
 * �ж�ջ��Ԫ������ɵĴ��Ƿ�����ɱ��Ϊ
 * @param stach[][2] ջ
 * @param len ջ��Ԫ��ռ�õĳ���
 */
bool isAI2::IsDeadChess(int stack[][2],int len)
{
    int x,y;
    for(int i=0; i<len; i++)
    {
        x=stack[i][0];
        y=stack[i][1];
        //�ϱ��пո�
        if(x > 0 && cross[x-1][y] == noChess) {
        	return false;
        }
        //�ϱ��пո�
        if(x < 10 && cross[x+1][y] == noChess) {
        	return false;
        }
        //����пո�
        if(y > 0 && cross[x][y-1] == noChess) {
        	 return false;
        }
        //�ұ��пո�
        if(y < 10 && cross[x][y+1] == noChess) {
        	return false;
        }
    }
    return true;
}

/**
 * Ϊ����λ�ӷ�
 * @param stach[][2] ջ
 * @param len ջ��Ԫ��ռ�õĳ���
 */
void isAI2::AddDeadChessScore(int stack[][2],int len)
{
    for(int i=0; i<len; i++) {
    	chessScore[stack[i][0]][stack[i][1]] = min;
       	chessStatus[stack[i][0]][stack[i][1]] = true;
    }
}
