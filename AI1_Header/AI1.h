#ifndef AI1_H_INCLUDED
#define AI1_H_INCLUDED

#include <time.h>
#include <stdlib.h>
struct LIST
{
    int Position;
    LIST *next;
    LIST *prior;
    void insert(int position);
    void Delete(int position);
};
///��¼�����λ�õĽṹ��
struct SPECIFICIALPOINT
{
    LIST *SinglePointPosition;//����λ��
    LIST *ChipPosition;//ȱ��λ��
    LIST *TigerMouthPosition;//����λ��
    LIST *EyePosition;//�۵�λ��

    LIST *ChipFormatePosition;//���γ�ȱ�ڵ�λ��
    LIST *TigerMouthFormatePosition;//���γɻ��ڵ�λ��
    LIST *EyeFormatePosition;//���γ��۵�λ��
};

///AI��
class AI1
{
public:

    AI1();//���캯��
    void GetPosition(int &line, int &column, int onTurn);//��ȡ����λ��

private:

    //��¼��������ֵ��������ʴӡ�1����ʼ������˳��Ϊ�����к��С���
    //��0����ʾû�����ӣ���1����ʾ���ӣ���2����ʾ����
    int cross[10][10];

    int PointStyle[18];//��¼ÿ����������͵ķ�ֵ
    ///�������λ��
    int PlayerNumber;//��¼��AI�����1�������2

    int Score[10][10];//��¼ÿ��λ���ϵķ�ֵ

    ///�ṹ�����
    SPECIFICIALPOINT sPoint[3];//��¼�����λ�ã��±�1��ʾ���1���±�2��ʾ���2

    int MaxScorePosition;//����ֵ��λ��

    ///�����ܺ���
    int GetChessAmount(int row1, int row2, int rival);//�鿴�ض�λ�õ��ĸ������ж��ٸ�����
    void GetMaxScorePosition();//��ȡ����ֵ��λ��

    ///����λ�÷�ֵ���ú���
    void UpdateScore(int row1, int row2, int who);//��������λ�÷�ֵ���������У��У����Ӳ���
    void Reset();//����������Ϣ��ʼ����ֵ
    void ResetScore(int row1, int row2, int score, int NumberPoor = 100);//���������Ӱ��ķ�ֵ
    void AddScore(LIST *Beg, int score, int NumberPoor = 20);//���ӷ���
    void RecordSpecialPoint(int row1, int row2, int who);//��������
    void AddRecord(LIST *LastSpecialPoint, LIST *LastFormatePoint, LIST *ThisFormatePoint, LIST *ThisSpecialPoint, int n, int n1, int n2, int n3, int n4, int amo);
};


#endif // AI1_H_INCLUDED
