#ifndef AI2_H_INCLUDED
#define AI2_H_INCLUDED

#include "../chessBoard_Header/AI.h"
#include "AIPlayer.h"
#include <vector>
using namespace std;
#include "../StdAfx.h"

#define cornerScore 120 // �߽Ƿ���
#define cornerScoreFull 160 // �������ɱ߽ǵķ���
#define tirangleScore1 60 // ���Ƿ���
#define tirangleScore2 120 // ���Ƿ���
#define tirangleScore3 140 // ���Ƿ���
#define crossShaped1 40 // ʮ�ַ���
#define crossShaped2 80 // ʮ�ַ���
#define crossShaped3  120// ʮ�ַ���
#define crossShaped4 160 // ʮ�ַ���
#define goodTigersMouth 120  // �Ż��ڣ���ʾ����Χ�ĵз�������ֻ��1~2��
#define badTigersMouth -120 // �ӻ��ڣ���ʾ����ΧȦ�ڶ��ǵз�����
#define max 32767
#define min -32767

#define isParent 1
#define isSiblings 2

#define isMax 0
#define isMin 1

class AI2 : public AIPlayer, public AI
{
private:
     //��¼��������ֵ��������ʴӡ�1����ʼ������˳��Ϊ�����к��С���
    //��0����ʾû�����ӣ���1����ʾ���ӣ���2����ʾ����
	int cross[10][10];
    //�ж�ʤ��ʱ���ڱ����û�б�����
	bool chessStatus[10][10];
    // ����
	int chessScore[10][10];
    // �߽�����
	int cornerArray[12];

	void setStatus(int RivalLine,int RivalColumn);
	void reduceRecursionTimes();

	std::vector<int> vec;
public:
    AI2();
    // ��ȡ������ӵ�λ��
    void GetPosition(int& line,int& column,int onTurn/*, int isExist[10][10]*/);

    // �Խ�
	void AcrossCorners();
	void ACScan(int line,int column,int line1,int column1,int line2,int column2);

  	// ����
	void Tirangle();
	void UTirangle();
	void LTirangle();
	void DTirangle();
	void RTirangle();

 	// ʮ��
	void chessStatusShaped();
	void JudgeCShape(int line,int column);

    // �Ƿ񹹳�����
	void isGo2Dead(int type);
	void AddDeadChessScore(int stack[][2], int len);
    bool IsDeadChess(int stack[][2], int len, int type);

    int priority_score(int scoreBase, int scorePRI, int type);

    // �Ż���
    void GoodTigersMouth();

    // ��ʼ������
    void copyArray(int isExist[10][10]);
    void initChessScore();

    //
	bool isBesieged(int line, int column);
	bool diffDirect(int line, int column);
	void Revalute();
	void JudgeScoreType();
	void addREScore(int score);
	int maxandmin(int depth);
	int MaxScore();
	int MinScore();
	int singleLayer();

};

#endif // AI2_H_INCLUDED

