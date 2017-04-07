#include "../AI2_Header/isAI2.h"

/**
 * [isAI2::GetPosition AI����ӿ�]
 * @param line 			����λ�õ�������
 * @param column 		����λ�õ�������
 * @param player 		��ǰ�ֵ�����ҵ�ID
 * @param isExist[10][10]		���������������
 */
void isAI2::GetPosition(int& line,int& column,int player, int isExist[10][10])
{
    copyArray(isExist);
	turn2Who = player;
	Rival = turn2Who == isBlack ? isWhite : isBlack;
	// ���ñ��������
	int temp = maxandmin(1);
	line = temp/100;
	column = temp%100;
}

/**
 * [isAI2::maxandmin ����С����]
 * @param depth 		ִ�е����
 */
int isAI2::maxandmin(int depth) {
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
 * [isAI2::singleLayer ����ִ��]
 */
int isAI2::singleLayer() {
	Revalute();
	if (turn2Who == PlayerId) {
		return MaxScore();
	} else {
		return MinScore();
	}
}

/**
 * [isAI2::MaxScore ��ȡ����ֵ]
 */
int isAI2::MaxScore()
{
	int temp = chessScore[1][1];
	int tempLine = 1;
	int tempColumn = 1;
	for (int i = 1;i < 10; i++) {
		for (int j = 1;j < 10; j++) {
			if (temp < chessScore[i][j] && cross[i][j] == noChess) {
				temp = chessScore[i][j];
				tempLine = i;
				tempColumn = j;
			}
		}
	}
	cross[tempLine][tempColumn] = turn2Who;
	chessStatus[tempLine][tempColumn] = true;
	return tempLine*100 + tempColumn;
}

/**
 * [isAI2::MaxScore ��ȡ��Сֵ]
 */
int isAI2::MinScore()
{
	int temp = chessScore[1][1];
	int tempLine = 1;
	int tempColumn = 1;
	// �������
	for (int i = 1;i < 10; i++) {
		for (int j = 1;j < 10; j++) {
			if (temp > chessScore[i][j] && cross[i][j] == noChess) {
				temp = chessScore[i][j];
				tempLine = i;
				tempColumn = j;
			}
		}
	}
	cross[tempLine][tempColumn] = turn2Who;
	chessStatus[tempLine][tempColumn] = true;
	return tempLine*100 + tempColumn;
}

/**
 * [isAI2::Revalute ��ֵ����]
 */
void isAI2::Revalute()
{
	initChessScore();

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
