#include "../../AI2_Header/isAI2.h"

/**
 * [isAI2::chessStatusShaped ʮ��Χɱ]
 * @return [��]
 */
void isAI2::chessStatusShaped()
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
 * [isAI2::JudgeCShape �ж��Ƿ��γ�ʮ��Χɱ]
 * @param line   [��]
 * @param column [��]
 */
void isAI2::JudgeCShape(int line,int column)
{
	if (line < 1 || column < 1 || line > 9 || column > 9) {
		return ;
	}
	// �Ѿ��γ���ʮ��Χɱ��
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
 	// ȱһ�γ�ʮ��Χɱ-- ����-- �м�û�����ӵ����
 	// ----------------------������Ҫ������ȼ���Ӧ�����Բ�����Ϊ�ײ�δ��׼
 	if (cross[line][column] == noChess &&
 		cross[line - 1][column] == noChess && cross[line + 1][column] == isWhite
		&& cross[line][column - 1] == isWhite && cross[line][column + 1] == isWhite) {
		chessScore[line - 1][column] += crossShaped3;
		chessStatus[line - 1][column] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == isWhite && cross[line + 1][column] == noChess
		&& cross[line][column - 1] == isWhite && cross[line][column + 1] == isWhite) {
		chessScore[line + 1][column] += crossShaped3;
		chessStatus[line + 1][column] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == isWhite && cross[line + 1][column] == isWhite
		&& cross[line][column - 1] == noChess && cross[line][column + 1] == isWhite) {
		chessScore[line][column - 1] += crossShaped3;
		chessStatus[line][column - 1] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == isWhite && cross[line + 1][column] == isWhite
		&& cross[line][column - 1] == isWhite && cross[line][column + 1] == noChess) {
		chessScore[line][column + 1] += crossShaped3;
		chessStatus[line][column + 1] = true;
 	}
 	// ȱһ�γ�ʮ��Χɱ-- ����-- �м�û�����ӵ����
 	// ----------------------������Ҫ������ȼ���Ӧ�����Բ�����Ϊ�ײ�δ��׼
 	if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == noChess && cross[line + 1][column] == isBlack
		&& cross[line][column - 1] == isBlack && cross[line][column + 1] == isBlack) {
		chessScore[line - 1][column] += crossShaped3;
		chessStatus[line - 1][column] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == isBlack && cross[line + 1][column] == noChess
		&& cross[line][column - 1] == isBlack && cross[line][column + 1] == isBlack) {
		chessScore[line + 1][column] += crossShaped3;
		chessStatus[line + 1][column] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == isBlack && cross[line + 1][column] == isBlack
		&& cross[line][column - 1] == noChess && cross[line][column + 1] == isBlack) {
		chessScore[line][column - 1] += crossShaped3;
		chessStatus[line][column - 1] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == isBlack && cross[line + 1][column] == isBlack
		&& cross[line][column - 1] == isBlack && cross[line][column + 1] == noChess) {
		chessScore[line][column + 1] += crossShaped3;
		chessStatus[line][column + 1] = true;
 	}

 	// ȱһ�γ�ʮ��Χɱ-- ����-- �м������ӵ����
 	// ----------------------������Ҫ������ȼ���Ӧ�����Բ�����Ϊ�ײ�δ��׼
 	if (cross[line][column] != noChess &&
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
 	}
 	// ȱһ�γ�ʮ��Χɱ-- ����-- �м������ӵ����
 	// ----------------------������Ҫ������ȼ���Ӧ�����Բ�����Ϊ�ײ�δ��׼
 	if (cross[line][column] != noChess &&
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
 	}

 	// ȱ���γ�ʮ��Χɱ-- ����-- �м�û�����ӵ����
 	// ----------------------������Ҫ������ȼ���Ӧ�����Բ�����Ϊ�ײ�δ��׼
 	if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == noChess && cross[line + 1][column] == noChess
		&& cross[line][column - 1] == isWhite && cross[line][column + 1] == isWhite) {
		chessScore[line - 1][column] += crossShaped2;
		chessStatus[line - 1][column] = true;
		chessScore[line + 1][column] += crossShaped2;
		chessStatus[line + 1][column] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == noChess && cross[line + 1][column] == isWhite
		&& cross[line][column - 1] == noChess && cross[line][column + 1] == isWhite) {
		chessScore[line - 1][column] += crossShaped2;
		chessStatus[line - 1][column] = true;
		chessScore[line][column - 1] += crossShaped2;
		chessStatus[line][column - 1] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == noChess && cross[line + 1][column] == isWhite
		&& cross[line][column - 1] == isWhite && cross[line][column + 1] == noChess) {
		chessScore[line - 1][column] += crossShaped2;
		chessStatus[line - 1][column] = true;
		chessScore[line][column + 1] += crossShaped2;
		chessStatus[line][column + 1] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == isWhite && cross[line + 1][column] == noChess
		&& cross[line][column - 1] == noChess && cross[line][column + 1] == isWhite) {
		chessScore[line + 1][column] += crossShaped2;
		chessStatus[line + 1][column] = true;
		chessScore[line][column - 1] += crossShaped2;
		chessStatus[line][column - 1] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == isWhite && cross[line + 1][column] == noChess
		&& cross[line][column - 1] == isWhite && cross[line][column + 1] == noChess) {
		chessScore[line + 1][column] += crossShaped2;
		chessStatus[line + 1][column] = true;
		chessScore[line][column + 1] += crossShaped2;
		chessStatus[line][column + 1] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == isWhite && cross[line + 1][column] == isWhite
		&& cross[line][column - 1] == noChess && cross[line][column + 1] == noChess) {
		chessScore[line][column - 1] += crossShaped2;
		chessStatus[line][column - 1] = true;
		chessScore[line][column + 1] += crossShaped2;
		chessStatus[line][column + 1] = true;
 	}
	// ȱ���γ�ʮ��Χɱ-- ����-- �м�û�����ӵ����
 	// ----------------------������Ҫ������ȼ���Ӧ�����Բ�����Ϊ�ײ�δ��׼
 	if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == noChess && cross[line + 1][column] == noChess
		&& cross[line][column - 1] == isBlack && cross[line][column + 1] == isBlack) {
		chessScore[line - 1][column] += crossShaped2;
		chessStatus[line - 1][column] = true;
		chessScore[line + 1][column] += crossShaped2;
		chessStatus[line + 1][column] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == noChess && cross[line + 1][column] == isBlack
		&& cross[line][column - 1] == noChess && cross[line][column + 1] == isBlack) {
		chessScore[line - 1][column] += crossShaped2;
		chessStatus[line - 1][column] = true;
		chessScore[line][column - 1] += crossShaped2;
		chessStatus[line][column - 1] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == noChess && cross[line + 1][column] == isBlack
		&& cross[line][column - 1] == isBlack && cross[line][column + 1] == noChess) {
		chessScore[line - 1][column] += crossShaped2;
		chessStatus[line - 1][column] = true;
		chessScore[line][column + 1] += crossShaped2;
		chessStatus[line][column + 1] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == isBlack && cross[line + 1][column] == noChess
		&& cross[line][column - 1] == noChess && cross[line][column + 1] == isBlack) {
		chessScore[line + 1][column] += crossShaped2;
		chessStatus[line + 1][column] = true;
		chessScore[line][column - 1] += crossShaped2;
		chessStatus[line][column - 1] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == isBlack && cross[line + 1][column] == noChess
		&& cross[line][column - 1] == isBlack && cross[line][column + 1] == noChess) {
		chessScore[line + 1][column] += crossShaped2;
		chessStatus[line + 1][column] = true;
		chessScore[line][column + 1] += crossShaped2;
		chessStatus[line][column + 1] = true;
 	} else if (cross[line][column] == noChess &&
 		 cross[line - 1][column] == isBlack && cross[line + 1][column] == isBlack
		&& cross[line][column - 1] == noChess && cross[line][column + 1] == noChess) {
		chessScore[line][column - 1] += crossShaped2;
		chessStatus[line][column - 1] = true;
		chessScore[line][column + 1] += crossShaped2;
		chessStatus[line][column + 1] = true;
 	}
 	// ȱ���γ�ʮ��Χɱ
 	// ----------------------������Ҫ������ȼ���Ӧ�����Բ�����Ϊ�ײ�δ��׼
 	// ������û�������˰ɣ��о�
}



