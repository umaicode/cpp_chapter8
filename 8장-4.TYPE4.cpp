// 8��-4.TYPE4.CPP  8.1 Ÿ�� ȣȯ�� ��Ģ 
// �� file�� class�鿡 ���� ������ ����� �� C++�� Ÿ�� ȣȯ�� ��Ģ�� �����ش�
// �� ������ ���� ��ü���� ������ member�� ������,
// ����� class�� �ٸ��Ƿ�, ���� �ٸ� Ÿ������ �����Ѵ�.
// ���� : �� program�� �������� error�� ������ �ִ�.
#include <iostream>
using namespace std;
class TwoChars {
	char first;
	char second;
public:
	TwoChars(char f, char s) : first(f), second(s)
	{ }
	TwoChars() {
		first = 0; second = 0;
	}
};

class StateCode {
	char first;
	char second;
public:
	StateCode(char f, char s) : first(f), second(s)
	{ }
	StateCode() {
		first = 0; second = 0;
	}
};

void main() {
	// �� ���� pointer�� �����Ѵ�.
	StateCode* pState1;
	TwoChars* pState2;
	StateCode s;
	TwoChars t = s;
	s = t;
	// pointer���� �Ҵ�� �ʱ�ȭ
	pState1 = new StateCode('C', 'A');
	pState2 = new TwoChars('H', 'I');
	TwoChars* tx = pState1;
	// ������ ���� ġȯ�� �Ұ����ϴ�.
	pState2 = pState1; // error !
	pState1 = pState2; // error !
	system("pause");
}