#include "../AI2_Header/AI2.h"
/**
 * ��һ������Ҫ��ʵ��AI2����Ҫ�㷨Max��Min�㷨��
 */


int isAI2::Evaluation() {

}

void isAI2::initDataFromArray() {

}

void isAI2::MaxAndMin(){

}

void isAI2::Scan(int cross[10][10], bool Cross[10][10]){

}

void isAI2::GetPosition(int& line,int& column,int player, int rival,int cross[10][10], bool Cross[10][10]) {

}

void isAI2::Score() {

}

/**
 * [isAI2::isBesieged �ж��Ƿ񱻰�Χ��]
 * @param  RivalLine   [��ǰ׼�����ӵ�λ�õ���]
 * @param  RivalColumn [��ǰ׼�����ӵ�λ�õ���]
 * @param  onTurn      [�ֵ�˭������������PlayerInfo.h�в鿴]
 * @return             [�Ƿ񱻰�Χ������Χ�ͷ���true��û�б���Χ�ͷ���false]
 */
bool isAI2::isBesieged(int RivalLine, int RivalColumn, int player, int rival) {
    // -----------------��ʼ��-----------------------

    // �ж��Ƿ񱻰�Χ�ı�׼����
    bool tie[4] = {
        false, false, false, false
    };
    // ����״̬���󣬵���������ʱ��Ϊtrue����û�б�������ʱ��Ϊ�١�
    Cross[RivalLine][RivalColumn] = true;
    //�±�Ϊ0����һ�����Ϊtrue���ʼ���������ó�ʼ��
    Cross[RivalLine][0] = true;

    // -----------------��ʼ��-----------------------

    // -----------------�Ϸ�-----------------------
    //���Է����ӵ��Ϸ��жԷ���������δ���ϱ�Ե
    if(cross[RivalLine - 1][RivalColumn] == rival && RivalLine - 1 > 0
       && Cross[RivalLine - 1][RivalColumn] == false) {
        tie[0] = isBesieged(RivalLine - 1, RivalColumn, player, rival);
    }
    //���Է����ӵ��Ϸ�û�����ӣ�ֱ�ӷ���false
    else if(cross[RivalLine - 1][RivalColumn] == 0 && RivalLine - 1 > 0) {
        return false;
    }
    //���Է����ӵ��Ϸ��м��������ӻ��ѵ���Ե
    else tie[0] = true;
    // -----------------�Ϸ�-----------------------

    // -----------------�·�-----------------------
    //���Է����ӵ��·��жԷ���������δ���±�Ե
    if(cross[RivalLine + 1][RivalColumn] == rival && RivalLine + 1 < 10
       && Cross[RivalLine + 1][RivalColumn] == false) {
        tie[1] = isBesieged(RivalLine + 1, RivalColumn, player, rival);
    }
    //���Է����ӵ��·�û������
    else if(cross[RivalLine + 1][RivalColumn] == 0 && RivalLine + 1 < 10) {
        return false;
    }
    //���Է����ӵ��·��м��������ӻ��ѵ���Ե
    else tie[1] = true;
    // -----------------�·�-----------------------

    // -----------------�ҷ�-----------------------
    //���Է����ӵ��ҷ��жԷ���������δ���ұ�Ե
    if(cross[RivalLine][RivalColumn + 1] == rival && RivalColumn + 1 < 10
       && Cross[RivalLine][RivalColumn + 1] == false) {
        tie[2] = isBesieged(RivalLine, RivalColumn + 1, player, rival);
    }
    //���Է����ӵ��ҷ�û������
    else if(cross[RivalLine][RivalColumn + 1] == 0 && RivalColumn + 1 < 10) {
        return false;
    }
    //���Է����ӵ��ҷ��м��������ӻ��ѵ���Ե
    else tie[2] = true;
    // -----------------�ҷ�-----------------------

    // -----------------��-----------------------
    //���Է����ӵ����жԷ���������δ�����Ե
    if(cross[RivalLine][RivalColumn - 1] == rival && RivalColumn - 1 > 0
       && Cross[RivalLine][RivalColumn - 1] == false) {
        tie[3] = isBesieged(RivalLine, RivalColumn - 1, player, rival);
    }
    //���Է����ӵ���û������
    else if(cross[RivalLine][RivalColumn - 1] == 0 && RivalColumn - 1 > 0) {
        return false;
    }
    //���Է����ӵ����м��������ӻ��ѵ���Ե
    else {
        tie[3] = true;
    }
    // -----------------��-----------------------

    // ������������׼����ȫ��Ϊtrue��ʱ�򣬱�ʾ��Χ���ˣ�
    if(tie[0] && tie[1] && tie[2] && tie[3]) {
        return true;
    }
    return false;
}

