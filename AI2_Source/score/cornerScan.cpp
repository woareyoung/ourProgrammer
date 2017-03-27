#include "../../AI2_Header/AI2.h"
/**
 * [AI2::AcrossCorners �߽�ɨ��]
 * @return [��]
 */
void AI2::AcrossCorners()
{
    // �ֵ�������ʱ��
    if (PlayerId == turn2Who)
    {
        for (int i = 0;i < 4;i += 3) {
        	ACScan(cornerArray[i]/100,cornerArray[i]%100,
                     cornerArray[i+1]/100,cornerArray[i+1]%100,
                     cornerArray[i+2]/100,cornerArray[i+2]%100);
        }
    }
}

/**
 * [AI2::ACScan ɨ�躯���������жϱ߽ǣ���߱ߣ��Ƿ�������]
 * @param line    [�߽����ӵ���]
 * @param column  [�߽����ӵ���]
 * @param line1   [�߽�������Χ�����ӵ���]
 * @param column1 [�߽�������Χ�����ӵ���]
 * @param line2   [�߽�������Χ�����ӵ���]
 * @param column2 [�߽�������Χ�����ӵ���]
 */
void AI2::ACScan(int line,int column,
	int line1,int column1,int line2,int column2)
{
    if (cross[line][column] == noChess) {
    	if ((cross[line1][column1] == isWhite && cross[line2][column2] == isWhite)
    		|| (cross[line1][column1] == isBlack && cross[line2][column2] == isBlack)) {
    		chessScore[line][column] = min;
    	} else if ((cross[line1][column1] == isWhite && cross[line2][column2] == noChess)
    		|| (cross[line1][column1] == isBlack && cross[line2][column2] == noChess)
    		|| (cross[line1][column1] == noChess && cross[line2][column2] == isBlack)
    		|| (cross[line1][column1] == noChess && cross[line2][column2] == isWhite)){
    		addScore(line,column,cornerScore);
    	}
    }// ע�⣺�߽�����������
}
