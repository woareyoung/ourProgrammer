#include "../AI2_Header/AI2.h"

/**
 * [AI2::GetPosition AI����ӿ�]
 * @param line 			����λ�õ�������
 * @param column 		����λ�õ�������
 * @param onTurn 		��ǰ�ֵ�����ҵ�ID
 * @param isExist[10][10]		���������������
 */
void AI2::GetPosition(int& line,int& column,int onTurn/*, int isExist[10][10]*/)
{
    // ������Ҫ�ж��Ƿ�����ȷ����������
	if (line != 0 && column != 0) {
        cross[line][column] = onTurn == isWhite ? isBlack : isWhite;
        chessStatus[line][column] = true;
        chessScore[line][column] = min;
        copyArray(cross);
    }
	turn2Who = onTurn;
	Rival = turn2Who == isBlack ? isWhite : isBlack;
	// ���ñ��������
	int temp = maxandmin(1);
	line = temp/100;
	column = temp%100;
	// ���������λ�õķ�����Ϊ��Сֵ
	chessScore[line][column] = min;
	cross[line][column] = PlayerId;
}

/**
 * [AI2::maxandmin ����С����]
 * @param depth 		ִ�е����
 */
int AI2::maxandmin(int depth) {
	int tempArray[10] = {
		2,1,2,1,2,1,2,1,2,1
	};
	int temp;
	for (int i = 0;i < depth; i++) {
		turn2Who = tempArray[i];
		Rival = turn2Who == isBlack ? isWhite : isBlack;
		temp = singleLayer();
	}
	return temp;
}

/**
 * [AI2::singleLayer ����ִ��]
 */
int AI2::singleLayer() {
	Revalute();
	if (turn2Who == PlayerId) {
		return MaxScore();
	} else {
		return MinScore();
	}
}

/**
 * [AI2::MaxScore ��ȡ����ֵ]
 */
int AI2::MaxScore()
{
    bool isFirst = true;
	int temp;
	int tempLine = 1;
	int tempColumn = 1;
	for (int i = 1;i < 10; i++) {
		for (int j = 1;j < 10; j++) {
            if (isFirst && cross[i][j] == noChess) {
                temp = chessScore[i][j];
                isFirst = false;
            } else if (!isFirst && temp < chessScore[i][j] && cross[i][j] == noChess) {
				temp = chessScore[i][j];
				tempLine = i;
				tempColumn = j;
			}
		}
	}
	cross[tempLine][tempColumn] = turn2Who;
	return tempLine*100 + tempColumn;
}

/**
 * [AI2::MaxScore ��ȡ��Сֵ]
 */
int AI2::MinScore()
{
    bool isFirst = true;
	int temp;
	int tempLine = 1;
	int tempColumn = 1;
	// �������
	for (int i = 1;i < 10; i++) {
		for (int j = 1;j < 10; j++) {
            if (isFirst && cross[i][j] == noChess) {
                temp = chessScore[i][j];
                isFirst = false;
            } else if (!isFirst && temp > chessScore[i][j] && cross[i][j] == noChess) {
				temp = chessScore[i][j];
				tempLine = i;
				tempColumn = j;
			}
		}
	}
	cross[tempLine][tempColumn] = turn2Who;
	return tempLine*100 + tempColumn;
}

/**
 * [AI2::Revalute ��ֵ����]
 */
void AI2::Revalute()
{
    // ��ʼ�����̵ķ���
	initChessScore();
    // ��ֵ���ӷ�
	AcrossCorners();
	Tirangle();
	chessStatusShaped();
	isGo2Dead();

	// for (int i = 1; i < 10; i++)
	// {
	// 	for (int j = 1; j < 10; j++)
	// 	{
	// 		if (chessStatus[i][j] == noChess)
	// 		{
	// 			if (isBesieged(i, j)) {
	// 				chessScore[i][j] = min;
	// 			} else {
	// 				JudgeScoreType();// �жϷ����Ķ���
	// 			}
	// 		}
	// 	}
	// }
}
