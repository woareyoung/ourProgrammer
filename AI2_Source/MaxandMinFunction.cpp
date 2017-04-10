#include "../AI2_Header/AI2.h"

/**
 * [AI2::GetPosition AI对外接口]
 * @param line 			着子位置的行坐标
 * @param column 		着子位置的行坐标
 * @param onTurn 		当前轮到的玩家的ID
 * @param isExist[10][10]		棋盘着子情况数组
 */
void AI2::GetPosition(int& line,int& column,int onTurn/*, int isExist[10][10]*/)
{
    // 这里需要判断是否有正确传参数进来
	if (line != 0 && column != 0) {
        cross[line][column] = onTurn == isWhite ? isBlack : isWhite;
        chessStatus[line][column] = true;
        chessScore[line][column] = min;
        copyArray(cross);
    }
	turn2Who = onTurn;
	Rival = turn2Who == isBlack ? isWhite : isBlack;
	// 设置遍历的深度
	int temp = maxandmin(1);
	line = temp/100;
	column = temp%100;
	// 将计算出的位置的分数设为最小值
	chessScore[line][column] = min;
	cross[line][column] = PlayerId;
}

/**
 * [AI2::maxandmin 极大极小函数]
 * @param depth 		执行的深度
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
 * [AI2::singleLayer 单层执行]
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
 * [AI2::MaxScore 获取极大值]
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
 * [AI2::MaxScore 获取极小值]
 */
int AI2::MinScore()
{
    bool isFirst = true;
	int temp;
	int tempLine = 1;
	int tempColumn = 1;
	// 输出分数
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
 * [AI2::Revalute 估值函数]
 */
void AI2::Revalute()
{
    // 初始化棋盘的分数
	initChessScore();
    // 估值并加分
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
	// 				JudgeScoreType();// 判断分数的多少
	// 			}
	// 		}
	// 	}
	// }
}
