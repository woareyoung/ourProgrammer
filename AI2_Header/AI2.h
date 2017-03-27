#ifndef AI2_H_INCLUDED
#define AI2_H_INCLUDED

#include <map>
#include <cmath>
#include "AIPlayer.h"
#include <vector>
#include "../StdAfx.h"

#define cornerScore 60 // �߽Ƿ���
#define tirangleScore1 60 // ���Ƿ���
#define tirangleScore2 60 // ���Ƿ���
#define crossShaped 40 // ʮ�ַ���
#define goodTigersMouth 120  // �Ż��ڣ���ʾ����Χ�ĵз�������ֻ��1~2��
#define badTigersMouth -120 // �ӻ��ڣ���ʾ����ΧȦ�ڶ��ǵз�����
#define max 32767
#define min -32767

class AI2 : public AIPlayer
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
public:
    AI2();
    // ɨ�躯��
    void Scan(int cross[10][10], bool Cross[10][10]);
    // ͨ����������ʼ������
    void initDataFromArray();
    // ���ۺ���,��Ҫ����
    int Evaluation();
    // ����Сֵ�㷨
    void MaxAndMin();

    // ��ȡ������ӵ�λ��
    void GetPosition(int &line,int &column,int player, int rival,int isExist[10][10], bool chessStatus[10][10]);

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

  	// �Ż���
  	void GoodTigersMouth();

  	// �ӷֺ���
    void addScore(int line,int column, int score);

  	// ��ʼ������
  	void copyArray(int isExist[10][10], bool chessStatus[10][10]);
};

#endif // AI2_H_INCLUDED

