// 8��-5.TYPE5.CPP  8.1 Ÿ�� ȣȯ�� ��Ģ  
// class�鿡 ���� pointer �������� ���� C++�� Ÿ�� ȣȯ�� ��Ģ�� ���� �ش�.
// ������ class�� ���� pointer ������ base class�� ���� pointer ������ 
// ġȯ�� �� ������, �� ���� �������� �ʴ´�.
// ���� : �� program�� �������� error�� ������ �ִ�.
#include <iostream>
using namespace std;

class TwoChars {
    char first;
    char second;
public:
    TwoChars (char f, char s) : first (f),  second (s)
    { }
};
class StateCode : public TwoChars { 
//class StateCode : protected TwoChars {//assign �� ���� �߻�
public:
    StateCode (char f, char s) : TwoChars (f, s)
    { }
    int show() {};
} ;
void main(){
    // �� ���� pointer���� �����Ѵ�.
    StateCode * pState1;
    TwoChars * pState2;
    // pointer���� �Ҵ�� �ʱ�ȭ
    pState1 = new StateCode ('C', 'A');
    pState2 = new TwoChars ('H', 'I');
    pState2->show();
    pState1->show();
    // superclass pointer�� ġȯ�ϴ� ���� �����ϴ�.
    pState2 = pState1;
    // �� �ݴ�� Ʋ����
    //pState1 = pState2; 
        // �ٸ� Ÿ���� ���ο� ���� ġȯ�ϴ� �͵� �����ϴ�.
    pState2 = new StateCode ('A', 'R');
	system("pause");
}