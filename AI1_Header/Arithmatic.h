#ifndef ARITHMATIC_H_INCLUDED
#define ARITHMATIC_H_INCLUDED
///���������
struct SPECIALPOINTAMOUNT
{
    int Chip;//ȱ������
    int TigerMouth;//��������
    int Eye;//������
};
///������ֵ������Ԥ�⣩
enum POINTSCORE
{
    Chip = 1,
    TigerMouth = 3,
    Eye = 5
};
///�㷨֧��
class Arithmatic
{
public :
    float AttackPerformance;//��¼���ֵĽ������ܣ���ֵΪ1��
    float BoundryRate;//������ޱ�������ֵΪ1��
    SPECIALPOINTAMOUNT spa[3];//�±�0û�ã�1��2��Ӧ���1�����2
    POINTSCORE PoS;//0��ʾȱ�ڡ�1��ʾ���ڡ�2��ʾ��
};

#endif // ARITHMATIC_H_INCLUDED
