#include "../AI2_Header/AI2.h"
#include "../AI1_Header/AI1.h"
/**
 * �����е���ҵ���Ϣ
 */
class PlayerInfo {
public:
    /**
     * 1��ʾ�ֵ����1���壬2��ʾ�ֵ����2���壬-1��ʾ����1��-2��ʾ����2
     * isPlay1onTurn 1, ���ֵ����1��ʱ��Ϊ1
     * isPlay2onTurn 2�����ֵ����2��ʱ��Ϊ2
     * isAI1onTurn -1�����ֵ�AI1��ʱ��Ϊ-1
     * isAI2onTurn -2�����ֵ�AI1��ʱ��Ϊ-2
     */
    int onTurn;
    /**
     * ���յ�Ӯ��
     */
    int Winner;
    /**
     * ��ʱ��
     */
    int AllTime1;//���1��ʣ����Ϸ��ʱ��
    int AllTime2;//���2��ʣ����Ϸ��ʱ��

    /**
     * ʣ��ʱ��
     */
    int Round1;//���1һ�غϵ���Ϸʣ��ʱ��
    int Round2;//���2һ�غϵ���Ϸʣ��ʱ��

    /**
     * ��ʱ��
     */
    UINT_PTR PlayerTimer;//��ҵļ�ʱ��

    /**
     * AI
     */
    bool Player1isAI;//��¼���1�Ƿ���AI
    bool Player2isAI;//��¼���2�Ƿ���AI

};
