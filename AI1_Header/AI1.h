#ifndef AI1_H_INCLUDED
#define AI1_H_INCLUDED

#include <time.h>
#include <stdlib.h>
#include "../chessBoard/AImessage.h"
///AI��
class AI1 : public AI
{
public:
    AI1();//���캯��
    void GetPosition(int &line, int &column, int onTurn);//��ȡ����λ��

private:
    int OT;//�������������ˣ���GetPosition.cpp�ļ���ʹ��
    int AttackPerformance;//��¼���ֵĽ������ܣ���ֵΪ100��
    int Winner;//������¼ģ������ʱ��ʤ�����
    ///��¼����ǰ�㡱������������뼶���
    //�ӷ�
    int CurrentFormatPointStyle;
    int CurrentFormatScorePoor;
    int CurrentPointStyle;
    int CurrentScorePoor;
    //����
    int LastFormatPointStyle;
    int LastFormatScorePoor;
    int LastSpecialPointStyle;
    int LastSpecialScorePoor;
    //����
    int RivalSinglePointPoor;//�Է�����
    int RivalChipPoor;//�Է�ȱ��
    int RivalTigerMouthPoor;//�Է�����

    int RivalFormatChipPoor;//�Է��γ�ȱ��
    int RivalFormatTigerMouthPoor;//�Է��γɻ���
    int RivalFormatEyePoor;//�Է��γ���

    int MySinglePointPoor;//��������
    int MyChipPoor;//����ȱ��
    int MyTigerMouthPoor;//��������

    int MyFormatChipPoor;//�����γ�ȱ��
    int MyFormatTigerMouthPoor;//�����γɻ���
    int MyFormatEyePoor;//�����γ���

    //��¼��������ֵ��������ʴӡ�1����ʼ������˳��Ϊ�����к��С���
    //��0����ʾû�����ӣ���1����ʾ���ӣ���2����ʾ����
    int cross[10][10];
    bool Cross[10][10];
    int PointStyle[18];//��¼ÿ����������͵ķ�ֵ
    int PlayerNumber;//��¼��AI�����1�������2
    int Score[10][10];//��¼ÿ��λ���ϵķ�ֵ
    int MaxScorePosition;//����ֵ��λ��
    int MaxScore;//��¼����ֵ

    ///�����ܺ��� ������FunctionPart.cpp�ļ���
    int GetChessAmount(int row1, int row2, int who);//�鿴�ض�λ�õ��ĸ������ж��ٸ�����
    void GetMaxScorePosition();//��ȡ����ֵ��λ��

    ///����λ�÷�ֵ���ú��� ������UpdateScore.cpp�ļ���
    //��������λ�÷�ֵ���������У��У����Ӳ���
    void UpdateScore(int row1, int row2, int who);//����RecordSpecialPoint()����
    //���������Ӱ��ķ�ֵ
    void ResetScore(int row1, int row2, int score, int NumberPoor = 100, bool isAddScore = true);//ʵ�мӷֵĺ���
    //��������
    void RecordSpecialPoint(int row1, int row2, int who);//��SetCurrentPoint()���õ�ǰ�㣬�ٵ���AddRecord
    void AddRecord(int n, int n1, int n2, int n3, int n4, int amo);
    void SetCurrentPoint(int ThisFormatStyle, int ThisFormatScorePoor, int ThisSpecialStyle, int ThisSpecialScorePoorint, int LastFormatStyle = 0, int LastFormatScorePoore = 0, int LastSpecialPointStyle = 0, int LastSpecialScorePoor = 0);

    ///�ж��Ƿ�������λ��   ������DeadCheck.cpp�ļ���
    bool DeadCheck(int line, int column, int who);
    bool Besieg(int RivalLine, int RivalColumn, int player, int rival);
    void reduceRecursionTimes();
    void setStatus(int RivalLine,int RivalColumn);
};


#endif // AI1_H_INCLUDED
