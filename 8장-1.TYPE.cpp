// 8��-1.TYPE1.CPP  8.1 Ÿ�� ȣȯ�� ��Ģ 
// �� file�� C++�� Ÿ�� ȣȯ�� ��Ģ�� �����Ѵ�.
// typedef�� struct�� ����Ͽ� Ÿ���� �����ϰ�, 
// ���ǵ� Ÿ�� �̸����� ������ �����Ѵ�.
#include <iostream> 
using namespace std;
void main (){
    // twoChars (��� �����Ͱ� public�� struct) Ÿ���� �����Ѵ�.
    typedef struct{
        char  first;
        char  second;
    } twoChars;
    // ���� Ÿ������ �� ���� ������ �����Ѵ�.
    twoChars state1;
    twoChars state2;
    // state1�� ���� �Ҵ��Ѵ�.
    state1.first = 'M';
    state1.second = 'N';
    // �� ������ ���� Ÿ���̴�.
    state2 = state1;//type compatible
    // �̰��� struct�� ������ �� �ִ� ���� �������̹Ƿ�
    // �׷��� ���� state2�� ���� ���� ���忡 ���� ���� �� �� �ִ�.
    state2.second ++;
    // �� struct�� ������ �μ��Ѵ�.
    cout << "Original structure: " << state1.first
          << state1.second << endl
          << "Changed structure: "  << state2.first
          << state2.second << endl;
	system("pause");
}