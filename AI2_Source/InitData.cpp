#include "../AI2_Header/AI2.h"

AI2::AI2()
{
	initAllArray();
}

void AI2::initAllArray() {
    this->chessCount = 0;
    this->PlayerId = isWhite;
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			cross[i][j] = 0;
			chessStatus[i][j] = false;
		}
	}
	initChessScore();
    // 初始化对角数组
	this->cornerArray[0] = 101;
	this->cornerArray[1] = 201;
	this->cornerArray[2] = 102;
	this->cornerArray[3] = 109;
	this->cornerArray[4] = 209;
	this->cornerArray[5] = 108;
	this->cornerArray[6] = 901;
	this->cornerArray[7] = 801;
	this->cornerArray[8] = 902;
	this->cornerArray[9] = 909;
	this->cornerArray[10] = 809;
	this->cornerArray[11] = 908;
}

void AI2::initChessScore()
{
	int temp[10][10] =
	{
		{0,0,0,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,1,1,1},
		{0,1,2,2,2,2,2,2,2,1},
		{0,1,2,3,3,3,3,3,2,1},
		{0,1,2,3,4,4,4,3,2,1},
		{0,1,2,3,4,5,4,3,2,1},
		{0,1,2,3,4,4,4,3,2,1},
		{0,1,2,3,3,3,3,3,2,1},
		{0,1,2,2,2,2,2,2,2,1},
		{0,1,1,1,1,1,1,1,1,1}
	};
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			chessScore[i][j] = temp[i][j];
		}
	}
}

void AI2::copyArray(int isExist[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			//this->cross[i][j] = isExist[i][j];
			if (isExist[i][j] != noChess) {
				this->chessStatus[i][j] = true;
			} else {
				this->chessStatus[i][j] = false;
			}
		}
	}
}

