#ifndef CHESS_H_INCLUDED
#define CHESS_H_INCLUDED

class Chess
{
public:
    //��¼��������ֵ��������ʴӡ�1����ʼ������˳��Ϊ�����к��С���
    //��0����ʾû�����ӣ���1����ʾ���ӣ���2����ʾ����
    int cross[10][10];
    //�ж�ʤ��ʱ���ڱ����û�б�����
    bool Cross[10][10];
    //������ҵ������ʱ��¼λ��
    int line, column;

    // ���ٵݹ����
    void reduceRecursionTimes();
    // ����״̬
    void setStatus(int RivalLine,int RivalColumn);
};


#endif // CHESS_H_INCLUDED
