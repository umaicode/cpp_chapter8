// 8��-3.TYPE3.CPP  8.1 Ÿ�� ȣȯ�� ��Ģ 
// �� file�� C++�� Ÿ�� ȣȯ�� ��Ģ�� �����Ѵ�.
// ���� �������� �� ���� ������ �����Ͽ�,
// �� �������� ���� Ÿ���� �������� �Ѵ�.(������, �̷��� ��Ģ�� // �����ϸ� �� �ȴ�)
#include <iostream>
using namespace std;
void main() {
	struct {
		char first;
		char second;
	} state1, state2;
	state1.first = 'M';
	state1.second = 'N';
	// OK: �� ���� ������ ���� Ÿ���̴�.  
	state2 = state1;
	state2.second++;
	cout << "Original structure: " << state1.first
		<< state1.second << endl
		<< "Changed structure: " << state2.first
		<< state2.second << endl;
	system("pause");
}