#include "../../AI2_Header/AI2.h"

/**
 * [AI2::chessStatusShaped 十字围杀]
 * @return [无]
 */
void AI2::chessStatusShaped()
{
	for (int i = 2; i < 9; i++)
	{
		for (int j = 2; j < 9; j++)
		{
			JudgeCShape(i,j);
		}
	}
}

/**
 * [AI2::JudgeCShape 判断是否形成十字围杀]
 * @param line   [行]
 * @param column [列]
 */
void AI2::JudgeCShape(int line,int column)
{
	if (line < 1 || column < 1 || line > 9 || column > 9) {
		return ;
	}
	// 已经形成了十字围杀了
	if (cross[line - 1][column] == isWhite && cross[line + 1][column] == isWhite
		&& cross[line][column - 1] == isWhite && cross[line][column + 1] == isWhite) {
		chessScore[line][column] = min;
		chessStatus[line][column] = true;
 	}
 	if (cross[line - 1][column] == isBlack && cross[line + 1][column] == isBlack
		&& cross[line][column - 1] == isBlack && cross[line][column + 1] == isBlack) {
		chessScore[line][column] = min;
		chessStatus[line][column] = true;
 	}
 	// 缺一形成十字围杀-- 白子-- 中间没有棋子的情况
 	// ----------------------这里需要添加优先级，应该是以博弈树为阶层未标准
 	if (cross[line][column] == noChess &&
 		cross[line - 1][column] == noChess && cross[line + 1][column] == isWhite
		&& cross[line][column - 1] == isWhite && cross[line][column + 1] == isWhite) {
		chessScore[line - 1][column] += priority_score(crossShaped3, crossShaped4, isWhite);
		chessStatus[line - 1][column] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == isWhite && cross[line + 1][column] == noChess
		&& cross[line][column - 1] == isWhite && cross[line][column + 1] == isWhite) {
		chessScore[line + 1][column] += priority_score(crossShaped3, crossShaped4, isWhite);
		chessStatus[line + 1][column] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == isWhite && cross[line + 1][column] == isWhite
		&& cross[line][column - 1] == noChess && cross[line][column + 1] == isWhite) {
		chessScore[line][column - 1] += priority_score(crossShaped3, crossShaped4, isWhite);
		chessStatus[line][column - 1] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == isWhite && cross[line + 1][column] == isWhite
		&& cross[line][column - 1] == isWhite && cross[line][column + 1] == noChess) {
		chessScore[line][column + 1] += priority_score(crossShaped3, crossShaped4, isWhite);
		chessStatus[line][column + 1] = true;
 	}
 	// 缺一形成十字围杀-- 黑子-- 中间没有棋子的情况
 	// ----------------------这里需要添加优先级，应该是以博弈树为阶层未标准
 	if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == noChess && cross[line + 1][column] == isBlack
		&& cross[line][column - 1] == isBlack && cross[line][column + 1] == isBlack) {
		chessScore[line - 1][column] += priority_score(crossShaped3, crossShaped4, isBlack);
		chessStatus[line - 1][column] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == isBlack && cross[line + 1][column] == noChess
		&& cross[line][column - 1] == isBlack && cross[line][column + 1] == isBlack) {
		chessScore[line + 1][column] += priority_score(crossShaped3, crossShaped4, isBlack);
		chessStatus[line + 1][column] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == isBlack && cross[line + 1][column] == isBlack
		&& cross[line][column - 1] == noChess && cross[line][column + 1] == isBlack) {
		chessScore[line][column - 1] += priority_score(crossShaped3, crossShaped4, isBlack);
		chessStatus[line][column - 1] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == isBlack && cross[line + 1][column] == isBlack
		&& cross[line][column - 1] == isBlack && cross[line][column + 1] == noChess) {
		chessScore[line][column + 1] += priority_score(crossShaped3, crossShaped4, isBlack);
		chessStatus[line][column + 1] = true;
 	}

 	// 缺一形成十字围杀-- 白子-- 中间有棋子的情况
 	// ----------------------这里需要添加优先级，应该是以博弈树为阶层未标准
/* 	if (cross[line][column] != noChess &&
 		cross[line - 1][column] == noChess && cross[line + 1][column] == isWhite
		&& cross[line][column - 1] == isWhite && cross[line][column + 1] == isWhite) {
		chessScore[line - 1][column] = min;
		chessStatus[line - 1][column] = true;
 	} else if (cross[line][column] != noChess &&
 		 cross[line - 1][column] == isWhite && cross[line + 1][column] == noChess
		&& cross[line][column - 1] == isWhite && cross[line][column + 1] == isWhite) {
		chessScore[line + 1][column] = min;
		chessStatus[line + 1][column] = true;
 	} else if (cross[line][column] != noChess &&
 		 cross[line - 1][column] == isWhite && cross[line + 1][column] == isWhite
		&& cross[line][column - 1] == noChess && cross[line][column + 1] == isWhite) {
		chessScore[line][column - 1] = min;
		chessStatus[line][column - 1] = true;
 	} else if (cross[line][column] != noChess &&
 		 cross[line - 1][column] == isWhite && cross[line + 1][column] == isWhite
		&& cross[line][column - 1] == isWhite && cross[line][column + 1] == noChess) {
		chessScore[line][column + 1] = min;
		chessStatus[line][column + 1] = true;
 	}*/
 	// 缺一形成十字围杀-- 黑子-- 中间有棋子的情况
 	// ----------------------这里需要添加优先级，应该是以博弈树为阶层未标准
/* 	if (cross[line][column] != noChess &&
 		 cross[line - 1][column] == noChess && cross[line + 1][column] == isBlack
		&& cross[line][column - 1] == isBlack && cross[line][column + 1] == isBlack) {
		chessScore[line - 1][column] = min;
		chessStatus[line - 1][column] = true;
 	} else if (cross[line][column] != noChess &&
 		 cross[line - 1][column] == isBlack && cross[line + 1][column] == noChess
		&& cross[line][column - 1] == isBlack && cross[line][column + 1] == isBlack) {
		chessScore[line + 1][column] = min;
		chessStatus[line + 1][column] = true;
 	} else if (cross[line][column] != noChess &&
 		 cross[line - 1][column] == isBlack && cross[line + 1][column] == isBlack
		&& cross[line][column - 1] == noChess && cross[line][column + 1] == isBlack) {
		chessScore[line][column - 1] = min;
		chessStatus[line][column - 1] = true;
 	} else if (cross[line][column] != noChess &&
 		 cross[line - 1][column] == isBlack && cross[line + 1][column] == isBlack
		&& cross[line][column - 1] == isBlack && cross[line][column + 1] == noChess) {
		chessScore[line][column + 1] = min;
		chessStatus[line][column + 1] = true;
 	}*/

 	// 缺二形成十字围杀-- 白子-- 中间没有棋子的情况
 	// ----------------------这里需要添加优先级，应该是以博弈树为阶层未标准
 	if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == noChess && cross[line + 1][column] == noChess
		&& cross[line][column - 1] == isWhite && cross[line][column + 1] == isWhite) {
		chessScore[line - 1][column] += priority_score(crossShaped2, crossShaped3, isWhite);
		chessStatus[line - 1][column] = true;
		chessScore[line + 1][column] += priority_score(crossShaped2, crossShaped3, isWhite);
		chessStatus[line + 1][column] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == noChess && cross[line + 1][column] == isWhite
		&& cross[line][column - 1] == noChess && cross[line][column + 1] == isWhite) {
		chessScore[line - 1][column] += priority_score(crossShaped2, crossShaped3, isWhite);
		chessStatus[line - 1][column] = true;
		chessScore[line][column - 1] += priority_score(crossShaped2, crossShaped3, isWhite);
		chessStatus[line][column - 1] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == noChess && cross[line + 1][column] == isWhite
		&& cross[line][column - 1] == isWhite && cross[line][column + 1] == noChess) {
		chessScore[line - 1][column] += priority_score(crossShaped2, crossShaped3, isWhite);
		chessStatus[line - 1][column] = true;
		chessScore[line][column + 1] += priority_score(crossShaped2, crossShaped3, isWhite);
		chessStatus[line][column + 1] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == isWhite && cross[line + 1][column] == noChess
		&& cross[line][column - 1] == noChess && cross[line][column + 1] == isWhite) {
		chessScore[line + 1][column] += priority_score(crossShaped2, crossShaped3, isWhite);
		chessStatus[line + 1][column] = true;
		chessScore[line][column - 1] += priority_score(crossShaped2, crossShaped3, isWhite);
		chessStatus[line][column - 1] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == isWhite && cross[line + 1][column] == noChess
		&& cross[line][column - 1] == isWhite && cross[line][column + 1] == noChess) {
		chessScore[line + 1][column] += priority_score(crossShaped2, crossShaped3, isWhite);
		chessStatus[line + 1][column] = true;
		chessScore[line][column + 1] += priority_score(crossShaped2, crossShaped3, isWhite);
		chessStatus[line][column + 1] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == isWhite && cross[line + 1][column] == isWhite
		&& cross[line][column - 1] == noChess && cross[line][column + 1] == noChess) {
		chessScore[line][column - 1] += priority_score(crossShaped2, crossShaped3, isWhite);
		chessStatus[line][column - 1] = true;
		chessScore[line][column + 1] += priority_score(crossShaped2, crossShaped3, isWhite);
		chessStatus[line][column + 1] = true;
 	}
	// 缺二形成十字围杀-- 黑子-- 中间没有棋子的情况
 	// ----------------------这里需要添加优先级，应该是以博弈树为阶层未标准
 	if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == noChess && cross[line + 1][column] == noChess
		&& cross[line][column - 1] == isBlack && cross[line][column + 1] == isBlack) {
		chessScore[line - 1][column] += priority_score(crossShaped2, crossShaped3, isBlack);
		chessStatus[line - 1][column] = true;
		chessScore[line + 1][column] += priority_score(crossShaped2, crossShaped3, isBlack);
		chessStatus[line + 1][column] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == noChess && cross[line + 1][column] == isBlack
		&& cross[line][column - 1] == noChess && cross[line][column + 1] == isBlack) {
		chessScore[line - 1][column] += priority_score(crossShaped2, crossShaped3, isBlack);
		chessStatus[line - 1][column] = true;
		chessScore[line][column - 1] += priority_score(crossShaped2, crossShaped3, isBlack);
		chessStatus[line][column - 1] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == noChess && cross[line + 1][column] == isBlack
		&& cross[line][column - 1] == isBlack && cross[line][column + 1] == noChess) {
		chessScore[line - 1][column] += priority_score(crossShaped2, crossShaped3, isBlack);
		chessStatus[line - 1][column] = true;
		chessScore[line][column + 1] += priority_score(crossShaped2, crossShaped3, isBlack);
		chessStatus[line][column + 1] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == isBlack && cross[line + 1][column] == noChess
		&& cross[line][column - 1] == noChess && cross[line][column + 1] == isBlack) {
		chessScore[line + 1][column] += priority_score(crossShaped2, crossShaped3, isBlack);
		chessStatus[line + 1][column] = true;
		chessScore[line][column - 1] += priority_score(crossShaped2, crossShaped3, isBlack);
		chessStatus[line][column - 1] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == isBlack && cross[line + 1][column] == noChess
		&& cross[line][column - 1] == isBlack && cross[line][column + 1] == noChess) {
		chessScore[line + 1][column] += priority_score(crossShaped2, crossShaped3, isBlack);
		chessStatus[line + 1][column] = true;
		chessScore[line][column + 1] += priority_score(crossShaped2, crossShaped3, isBlack);
		chessStatus[line][column + 1] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == isBlack && cross[line + 1][column] == isBlack
		&& cross[line][column - 1] == noChess && cross[line][column + 1] == noChess) {
		chessScore[line][column - 1] += priority_score(crossShaped2, crossShaped3, isBlack);
		chessStatus[line][column - 1] = true;
		chessScore[line][column + 1] += priority_score(crossShaped2, crossShaped3, isBlack);
		chessStatus[line][column + 1] = true;
 	}
 	// 缺三形成十字围杀
 	// ----------------------这里需要添加优先级，应该是以博弈树为阶层未标准
 	// 这玩意没有意义了吧，感觉
}



