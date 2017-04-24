#ifndef ARITHMATIC_H_INCLUDED
#define ARITHMATIC_H_INCLUDED
///���������
struct SPECIALPOINTAMOUNT
{
    int Chip;//ȱ������
    int TigerMouth;//��������
    int Eye;//������
};
///��¼������ʷ����
struct STEP
{
    int Number;//�ڼ���
    int ScoreRate;//��λ�õķ�ֵ�ٷֱȣ�������ֵ�ı�ֵ��
    STEP *next;//ָ����һ��
};
///��¼Ԥ�⵽�Ŀ���������
struct CHAIN
{
    ///Ԥ�������λ��
    int line;
    int column;

    CHAIN *next;//��һ��
    CHAIN *parallel;//��ǰ�غϵ�����������
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
    int StepNumber;//��¼�������˶��ٲ�
    int MaxStepNumber;//���¹���MaxStepNumber���󹹽��ع鷽��
    float a;//�ع鷽�̳�����
    float b;//�ع鷽��б��
    float _x;//xƽ��ֵ��xָ���ڼ���
    float _y;//yƽ��ֵ��yָ��ĳһ������λ�õķ�ֵ
    float AttackPerformance;//��¼���ֵĽ������ܣ���ֵΪ1��
    float BoundryRate;//������ޱ�������ֵΪ1��
    float CorrectRate;//����ϵ��
    SPECIALPOINTAMOUNT spa[3];//�±�0û�ã�1��2��Ӧ���1�����2
    POINTSCORE PoS;//0��ʾȱ�ڡ�1��ʾ���ڡ�2��ʾ��
    STEP *Step;//��̬��¼ͷ���
    STEP *SSS;//��̬β����¼
    CHAIN *HeadChain;//��̬ͷ���
};

#endif // ARITHMATIC_H_INCLUDED
