#include "../../AI2_Header/AI2.h"

/**
 * [AI2::addREScore 加分函数]
 * @param score [分数]
 */
void AI2::addREScore(int score)
{
	for (int i = 0;i < vec.size();i++) {
		int temp = vec[i];
		int line = temp / 100;
		int column = temp % 100;
		if (cross[line][column] == noChess) {
			chessScore[line][column] += score;
		}
	}
	vec.clear();
}

bool AI2::isBesieged(int line ,int column) {

	bool directionStatus[4] = {false, false, false, false};
	if (vec.size() > 3 || line < 1 || column < 1 || line > 9 || column > 9) {
		return false;
	}
	// -----------------------上--------------------------
	// if (cross[line - 1][column] == turn2Who) {
	// 	isBesieged(line - 1, column);
	// } else if (cross[line - 1][column] == noChess) {
	// 	vec.push_back((line - 1)*100 + column);
	// 	isBesieged(line - 1, column);
	// } else {
	// 	directionStatus[0] = true;
	// }

	// // -----------------------右--------------------------
	// if (cross[line][column + 1] == turn2Who) {
	// 	isBesieged(line, column + 1);
	// } else if (cross[line][column + 1] == noChess) {
	// 	vec.push_back(line*100 + column + 1);
	// 	isBesieged(line, column + 1);
	// } else {
	// 	directionStatus[1] = true;
	// }

	// // -----------------------下--------------------------
	// if (cross[line + 1][column] == turn2Who) {
	// 	isBesieged(line + 1, column);
	// } else if (cross[line + 1][column] == noChess) {
	// 	vec.push_back((line + 1)*100 + column);
	// 	isBesieged(line + 1, column);
	// } else {
	// 	directionStatus[2] = true;
	// }

	// // -----------------------左--------------------------
	// if (cross[line][column - 1] == turn2Who) {
	// 	isBesieged(line, column - 1);
	// } else if (cross[line][column - 1] == noChess) {
	// 	vec.push_back(line*100 + column - 1);
	// 	isBesieged(line, column - 1);
	// } else {
	// 	directionStatus[3] = true;
	// }

	directionStatus[0] = diffDirect(line - 1, column);
	directionStatus[1] = diffDirect(line + 1, column);
	directionStatus[2] = diffDirect(line, column - 1);
	directionStatus[3] = diffDirect(line, column + 1);

	return directionStatus[0] && directionStatus[1] && directionStatus[2] && directionStatus[3];
}

bool AI2::diffDirect(int line , int column) {
	if (vec.size() > 3 || line < 1 || column < 1 || line > 9 || column > 9) {
		return false;
	}
	if (cross[line][column] == turn2Who) {
		isBesieged(line, column);
	} else if (cross[line][column] == noChess) {
		vec.push_back(line*100 + column);
		isBesieged(line, column);
	} else {
		return true;
	}
	return false;
}

