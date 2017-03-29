#ifndef ISAI2_H_INCLUDED
#define ISAI2_H_INCLUDED

#include <cmath>
#include "AIPlayer.h"
#include <list>
using namespace std;
#include "../StdAfx.h"


#define cornerScore 60 // �߽Ƿ���
#define tirangleScore1 60 // ���Ƿ���
#define tirangleScore2 60 // ���Ƿ���
#define crossShaped1 40 // ʮ�ַ���
#define crossShaped2 80 // ʮ�ַ���
#define crossShaped3 120 // ʮ�ַ���
#define goodTigersMouth 120  // �Ż��ڣ���ʾ����Χ�ĵз�������ֻ��1~2��
#define badTigersMouth -120 // �ӻ��ڣ���ʾ����ΧȦ�ڶ��ǵз�����
#define max 32767
#define min -32767

class isAI2 : public AIPlayer
{
private:
    //��¼��������ֵ��������ʴӡ�1����ʼ������˳��Ϊ�����к��С���
    //��0����ʾû�����ӣ���1����ʾ���ӣ���2����ʾ����
    int cross[10][10];
    //�ж�ʤ��ʱ���ڱ����û�б�����
    bool Cross[10][10];
    // ����
    int chessScore[10][10];
    // �߽�����
    int cornerArray[12];

    void setStatus(int RivalLine,int RivalColumn);
    void reduceRecursionTimes();

    list<int> blankList;
public:
    isAI2();
    // ͨ����������ʼ������
    void initDataFromArray();
    // ���ۺ���
    int Evaluation();
    // ����Сֵ�㷨
    void MaxAndMin(int& line,int& column);

    // ��ȡ������ӵ�λ��
    void GetPosition(int &line,int &column,int player,int isExist[10][10], bool chessStatus[10][10]);

    // �������㺯��
    void Score();

    // �жϰ�Χ����ĺ���
    bool isBesieged(int RivalLine, int RivalColumn, int player, int rival);

    // �Խ�
    void AcrossCorners();
    void ACScan(int line,int column,int line1,int column1,int line2,int column2);

    // ����
    void Tirangle();
    void ULTirangle();
    void DRTirangle();

    // ʮ��
    void CrossShaped();
    void JudgeCShape(int line,int column);
    void FindBlank(int line,int column);
    void addCSScore(int line,int column,int score,int tempPos[4],int temp[4]);

    // �Ż���
    void GoodTigersMouth();

    // �ӷֺ���
    void addScore(int line,int column, int score);

    // ��ʼ������
    void copyArray(int isExist[10][10], bool chessStatus[10][10]);
    void initChessScore();

    //
    bool Besieged(int RivalLine, int RivalColumn, int player, int rival);
    void Revalute();
    bool isBesieged(int line, int column, int onTurn);
    void JudgeScoreType();
    void addREScore(int score);
    int maxandmin(int depth);
    int MaxScore();
    int MinScore();
    int singleLayer();
};


#endif // ISAI2_H_INCLUDED
