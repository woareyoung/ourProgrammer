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

    Chess()
    {
        int temp[10][10] =
        {
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,1,0,1,0,0,0,2},
            {0,1,0,0,0,0,0,0,0,0},
            {0,1,0,0,0,0,0,0,0,0},
            {0,0,0,2,0,0,0,0,0,0},
            {0,0,0,0,2,1,2,0,0,0},
            {0,0,0,0,0,2,0,0,0,0},
            {0,0,0,0,2,1,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0}
        };
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cross[i][j] = temp[i][j];
                if (temp[i][j] != 0) {
                    Cross[i][j] = true;
                } else {
                    Cross[i][j] = false;
                }
            }

        }
    }
};


#endif // CHESS_H_INCLUDED
