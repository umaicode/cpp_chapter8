// 8-4.BAG_SET.CPP  8.9 ��Ӱ� virtual�� ����� container class�� ����
//[Howowitz, Sahni, Mehta, 2007]
#include <iostream>
#include "bagset.h"
using namespace std;
/*
�ǽ����� 8.4
1) ����
�� source code�� << overloading�� ���Ͽ� cout<<b(��ü ���)�� ���� �˾ƺ��� �����̴�.
2) ���
��. �ߺ��� ����ϴ� class Bag�� add �Լ��� �ߺ��� ������� �ʴ� class Set�� add�Լ��� code�� Ȯ���Ͽ� ���� ���̸� Ȯ���غ���.
��. program�� �����Ͽ� �� ������ �������� �����غ���, �ּ� 1�� �����Ͽ� << overloading�� �� ���� ���� ���� ����� ���̸� Ȯ���غ���.
*/
Bag::Bag(int MaxBagSize) : MaxSize(MaxBagSize) {
	arr = new int[MaxSize];
	top = 0;
}

Bag::~Bag() {
}

bool Bag::IsFull() {
	if (top == MaxSize - 1)
		return true;
	else
		return false;
}

bool Bag::IsEmpty() {
	if (top == 0)
		return true;
	else
		return false;
}

void Bag::Full() {
	cout << "Data structure is full" << endl;
}

void Bag::Empty() {
	cout << "Data structure is empty" << endl;
}

void Bag::Add(int x) {
	//���� á���� �� á������ Full() member �Լ��� ��� �迭 ���� ����
	if (IsFull())
		Full();
	else {
		arr[top] = x;
		cout << "BAG�� " << arr[top] << "�� �߰��Ǿ����ϴ�" << endl;
		top++;
	}
}

int* Bag::Delete(int& x) {
	//�������, �� ��������� Empty() member �Լ��� ���
	//������� 0�� ����

	//������ ���Ҹ� ����, ���� ���� ������ ���� algorithm�� ���� �ٸ���
	if (IsEmpty()) {
		Empty();
		return 0;
	}
	int deletePos = top / 2;
	x = arr[deletePos];
	for (int index = deletePos; index < top; index++)
		arr[index] = arr[index + 1];
	top--;
	return &x;
}

int Bag::Top() {
	return top;
}
//�ּ� 1
//
ostream& operator<<(ostream& stream, Bag b) {
	cout << "ostream& operator<<(ostream& stream, Bag b) " << endl;
	for (int i = 0; i < b.Top(); i++) {
		stream << b.arr[i] << endl;
	}
	return stream;
}
//

Set::Set(int MaxBagSize) : Bag(MaxBagSize) {}

Set::~Set() {
}

void Set::Add(int x) {
	//Bag::Add()�� �����Ͽ� coding�ϴ� �ǽ�
	if (IsFull())
		Full();
	else {
		for (int i = 0; i < MaxSize; i++) {
			// ù��° �ε����� �ߺ��˻縦 �ϰ� �������� ���ϰ� ������ -> �߸��� �ڵ�
			if (arr[i] != x) {
				arr[top] = x;
				cout << "SET�� " << arr[top] << "�� �߰��Ǿ����ϴ�" << endl;
				top++;
				return;
			}
			else {
				cout << "�ߺ��� �� �Դϴ�" << endl;
				return;
			}
		}
	}
}

int* Set::Delete(int& x) {
	if (IsEmpty()) {
		Empty();
		return 0;
	}
	int deletePos = top / 2;
	x = arr[deletePos];
	for (int index = deletePos; index < top; index++)
		arr[index] = arr[index + 1];
	top--;
	return &x;
}
//�ּ� 1
//
ostream& operator<<(ostream& stream, Set s) {
	cout << "ostream& operator<<(ostream& stream, Set s) " << endl;
	Bag b = (Bag)s;
	stream << b;//code reuse 19.5.23
	/*
	for(int i=0; i<s.Top(); i++){
		stream<<s.arr[i]<<endl;
	}
	*/
	return stream;
}
//

void main() {
	int x;

	Bag b;
	b.Add(20);
	b.Add(30);
	b.Add(40);
	b.Add(50);
	cout << endl << "ADD �� ��ü b ���" << endl;
	cout << b << endl;
	b.Delete(x);
	cout << "DELETE �� ��ü b ���" << endl;
	cout << b << endl;

	Set s;
	s.Add(20);
	s.Add(20);//check the duplicate
	s.Add(30);
	cout << endl << "ADD �� ��ü s ���" << endl;
	cout << s << endl;
	s.Delete(x);
	cout << "DELETE �� ��ü s ���" << endl;
	cout << s << endl;
	system("pause");
}