# include "chessBoard/ChessBase.h"
# include "chessBoard/ChessRule.h"
# include "AI2_Header/AI2.h"
# include "AI1_Header/AI1.h"
# include "AI3_Header/AI3.h"
# include "chessBoard/AImessage.h"
/**
 * ���̽�����
 * ��Ҫ�������̵Ļ��ƹ���
 */
class ChessBoard : public ChessBase, public ChessRule
{
private :

    // ��¼����ÿ�е� ÿһ�л�ÿһ�� ����ֵ��������ʴӡ�1����ʼ
    // ��������̵����λ��
    int CrossCross[10];
    // ����λ��
    int ChessDiameter;//���ӵ�ֱ��
    // ���ʹ���
    HPEN pen;
    void updateTime(int AllTime,int Round,int offset);
public :
    int Width;//���ڵĿ��
    int Height;//���ڵĸ߶�
    int Base;//�������ݹ�ģ�Ļ�׼
    AI1 ai1;
    AI2 ai2;
    AI3 ai3;
    AI *Player1AI;
    AI *Player2AI;
    /**
     * --------�������ɱ������---------
     */
    POINT point;//�����
    // ���ζ����࣬���ڻ��ƾ��δ���
    HINSTANCE hInstance;//Ӧ�ó���ʵ���ľ��
    HDC graphicsHdc;//�豸�������
    PAINTSTRUCT paintStruct;//PAINTSTRUCT�ṹ��
    HWND ParentHwnd;//��Ϸ�Ĵ���
    HDC hdcBuffer;//�������������
    // λͼ
    HBITMAP bitmap;//���ڻ����λͼ

    /**
     * --------���ܺ�������--------
     */
    //��ʼ����ά������Ϣ
    void Initialize();
    //������
    void PaintBoard();
    //��ʼ���豸�������
    void HDCInitialize(HWND hwnd);
    //������
    void PaintChess();
    //��ȡ��������̵�λ�ã��ڼ��еڼ��У�
    bool getPosition(DWORD lpParam);
    // ��������
    void PaintAChess(int type);
    //���Ƶ���ʱ
    void PaintTimer();
    // ���캯��
    ChessBoard();
    // ���ʱ����Ϣ
    void PrintInfo();
};

