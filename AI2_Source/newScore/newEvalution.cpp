#include "../../AI2_Header/AI2.h"

/**
 * [AI2::addREScore �ӷֺ���]
 * @param score [����]
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
	// -----------------------��--------------------------
	// if (cross[line - 1][column] == turn2Who) {
	// 	isBesieged(line - 1, column);
	// } else if (cross[line - 1][column] == noChess) {
	// 	vec.push_back((line - 1)*100 + column);
	// 	isBesieged(line - 1, column);
	// } else {
	// 	directionStatus[0] = true;
	// }

	// // -----------------------��--------------------------
	// if (cross[line][column + 1] == turn2Who) {
	// 	isBesieged(line, column + 1);
	// } else if (cross[line][column + 1] == noChess) {
	// 	vec.push_back(line*100 + column + 1);
	// 	isBesieged(line, column + 1);
	// } else {
	// 	directionStatus[1] = true;
	// }

	// // -----------------------��--------------------------
	// if (cross[line + 1][column] == turn2Who) {
	// 	isBesieged(line + 1, column);
	// } else if (cross[line + 1][column] == noChess) {
	// 	vec.push_back((line + 1)*100 + column);
	// 	isBesieged(line + 1, column);
	// } else {
	// 	directionStatus[2] = true;
	// }

	// // -----------------------��--------------------------
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

bool AI2::DeadCheck(int line, int column, int who)
{
    bool Position[4] = {false, false, false, false};
    int player = who;//��¼�����ı�ţ���1����2��
    int rival = player == 1 ? 2 : 1;//��¼�Է��ı�ţ���1����2��
    //�ж�����������û������
    //�����жԷ���һ������
    if(cross[line][column - 1] == rival)
    {
        reduceRecursionTimes();
        if(Besieg(line, column - 1, player, rival))
            return true;
        Position[0] = true;
    }
    //�����������ѵ����Ե
    else if(column - 1 == 0) Position[0] = true;
    //�����м���������
    else if(cross[line][column - 1] == player)
    {
        reduceRecursionTimes();
        Position[0] = Besieg(line, column, rival, player);
    }
    //���ҷ��жԷ���һ������
    if(cross[line][column + 1] == rival)
    {
        reduceRecursionTimes();
        if(Besieg(line, column + 1, player, rival))
            return true;
        Position[1] = true;
    }
    //�������������ѵ��ұ�Ե
    else if(column + 1 == 10) Position[1] = true;
    //���ҷ��м���������
    else if(cross[line][column + 1] == player)
    {
        reduceRecursionTimes();
        Position[1] = Besieg(line, column, rival, player);
    }
    //���Ϸ��жԷ���һ������
    if(cross[line - 1][column] == rival)
    {
        reduceRecursionTimes();
        if(Besieg(line - 1, column, player, rival))
            return true;
        Position[2] = true;
    }
    //�������������ѵ��ϱ�Ե
    else if(line - 1 == 0) Position[2] = true;
    //���Ϸ��м���������
    else if(cross[line - 1][column] == player)
    {
        reduceRecursionTimes();
        Position[2] = Besieg(line, column, rival, player);
    }
    //���·��жԷ���һ������
    if(cross[line + 1][column] == rival)
    {
        reduceRecursionTimes();
        if(Besieg(line + 1, column, player, rival))
            return true;
        Position[3] = true;
    }
    //�������������ѵ��±�Ե
    else if(line + 1 == 10) Position[3] = true;
    //���·��м���������
    else if(cross[line + 1][column] == player)
    {
        reduceRecursionTimes();
        Position[3] = Besieg(line, column, rival, player);
    }
    if(Position[0] && Position[1] && Position[2] && Position[3])
        return true;
    return false;
}

bool AI2::Besieg(int RivalLine, int RivalColumn, int player, int rival)
{
    bool tie[4] = {false, false, false, false};
    // ����chessStatus����״̬
    setStatus(RivalLine,RivalColumn);
    //���Է����ӵ��Ϸ��жԷ���������δ���ϱ�Ե
    if(cross[RivalLine - 1][RivalColumn] == rival && RivalLine - 1 > 0
       && chessStatus[RivalLine - 1][RivalColumn] == false)
        tie[0] = Besieg(RivalLine - 1, RivalColumn, player, rival);
    //���Է����ӵ��Ϸ�û�����ӣ�ֱ�ӷ���false
    else if(cross[RivalLine - 1][RivalColumn] == 0 && RivalLine - 1 > 0) return false;
    //���Է����ӵ��Ϸ��м��������ӻ��ѵ���Ե
    else tie[0] = true;
    //���Է����ӵ��·��жԷ���������δ���±�Ե
    if(cross[RivalLine + 1][RivalColumn] == rival && RivalLine + 1 < 10
       && chessStatus[RivalLine + 1][RivalColumn] == false)
        tie[1] = Besieg(RivalLine + 1, RivalColumn, player, rival);
    //���Է����ӵ��·�û������
    else if(cross[RivalLine + 1][RivalColumn] == 0 && RivalLine + 1 < 10) return false;
    //���Է����ӵ��·��м��������ӻ��ѵ���Ե
    else tie[1] = true;
    //���Է����ӵ��ҷ��жԷ���������δ���ұ�Ե
    if(cross[RivalLine][RivalColumn + 1] == rival && RivalColumn + 1 < 10
       && chessStatus[RivalLine][RivalColumn + 1] == false)
        tie[2] = Besieg(RivalLine, RivalColumn + 1, player, rival);
    //���Է����ӵ��ҷ�û������
    else if(cross[RivalLine][RivalColumn + 1] == 0 && RivalColumn + 1 < 10) return false;
    //���Է����ӵ��ҷ��м��������ӻ��ѵ���Ե
    else tie[2] = true;
    //���Է����ӵ����жԷ���������δ�����Ե
    if(cross[RivalLine][RivalColumn - 1] == rival && RivalColumn - 1 > 0
       && chessStatus[RivalLine][RivalColumn - 1] == false)
        tie[3] = Besieg(RivalLine, RivalColumn - 1, player, rival);
    //���Է����ӵ���û������
    else if(cross[RivalLine][RivalColumn - 1] == 0 && RivalColumn - 1 > 0) return false;
    //���Է����ӵ����м��������ӻ��ѵ���Ե
    else tie[3] = true;
    if(tie[0] && tie[1] && tie[2] && tie[3]) return true;
    return false;
}

void AI2::reduceRecursionTimes()
{
    for(int i = 0; i < 10; i++)
    {
        if(chessStatus[i][0] == true)
            for(int j = 0; j < 10; j++)
                chessStatus[i][j] = false;
    }
}

void AI2::setStatus(int RivalLine,int RivalColumn) {
    chessStatus[RivalLine][RivalColumn] = true;
    chessStatus[RivalLine][0] = true;//�±�Ϊ0����һ�����Ϊtrue���ʼ���������ó�ʼ��
}
