// 8��-2.TYPE2.CPP  8.1 Ÿ�� ȣȯ�� ��Ģ 
// �� file�� C++�� Ÿ�� ȣȯ�� ��Ģ�� �����ϱ� ���Ͽ� error�� �ִ� // program�̴�.
// struct�� ���� ��Ҵ� ������, �� ������ �ٸ� struct�鿡 ���� ���ǵ�.
// �� ���� struct�� ���Ͽ� compiler�� ���� �ӽ� Ÿ�Ը��� ���ǵǾ��ٰ� ���ƾ�     �Ѵ�.

//����: �� program�� �������� error�� �����ϰ� �ִ�.
#include <iostream>
using namespace std;

void main(){
    struct{
        char  first ;
        char  second ;
    } state1 ;
    
    struct{
        char  first ;
        char  second ;
    } state2 ;
    state1.first = 'M' ;
    state1.second = 'N' ;
    // error!  �� ������ ���� Ÿ���� �ƴϴ�.
	state2.first = 'S';
	state2.second = 'T';
    state2 = state1 ;
    state2.second ++ ;
    cout << "Original structure: "           << state1.first
          << state1.second << endl
          << "Changed structure: "                 << state2.first
          << state2.second << endl ;
	system("pause");
}