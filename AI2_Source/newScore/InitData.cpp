#include "../../AI2_Header/AI2.h"
/**
 * [AI2::setStatus ���õ�ǰ]
 * @param RivalLine   [description]
 * @param RivalColumn [description]
 */
void AI2::setStatus(int RivalLine,int RivalColumn) {
    Cross[RivalLine][RivalColumn] = true;
    Cross[RivalLine][0] = true;//�±�Ϊ0����һ�����Ϊtrue���ʼ���������ó�ʼ��
}

/**
 * [AI2::reduceRecursionTimes ���ٵݹ��ѭ������]
 * ˵����Cross[i][0]Ϊ״̬λ����Ϊtrue��ʱ���ʾ���������ӱ�����������֮��û��
 */
void AI2::reduceRecursionTimes()
{
    for(int i = 0; i < 10; i++)
    {
        if(Cross[i][0] == true)
            for(int j = 0; j < 10; j++)
                Cross[i][j] = false;
    }
}
