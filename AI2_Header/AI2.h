#ifndef AI2_H_INCLUDED
#define AI2_H_INCLUDED

#include <map>
#include <cmath>

#define duijiaoScore 60
#define sanjiaoScore 40
#define shiziScore 30


class isAI2
{
private:
    //��¼��������ֵ��������ʴӡ�1����ʼ������˳��Ϊ�����к��С���
    //��0����ʾû�����ӣ���1����ʾ���ӣ���2����ʾ����
    int cross[10][10];
    //�ж�ʤ��ʱ���ڱ����û�б�����
    bool Cross[10][10];
public:
    // ɨ�躯��
    void Scan(int cross[10][10], bool Cross[10][10]);
    // ͨ����������ʼ������
    void initDataFromArray();
    // ���ۺ���,��Ҫ����
    int Evaluation();
    // ����Сֵ�㷨
    void MaxAndMin();

    // ��ȡ������ӵ�λ��
    void GetPosition(int &line,int &column,int player, int rival,int cross[10][10], bool Cross[10][10]);

    // �������㺯��
    void Score();

    // �жϰ�Χ����ĺ���
    bool isBesieged(int RivalLine, int RivalColumn, int player, int rival);
};

#endif // AI2_H_INCLUDED
