#pragma once
// 8-16.BAG_SET.H
#define DefaultSize 10
#include <iostream>
using namespace std;
class Bag {
public:
	// �ִ� ũ���� �� bag�� �����
	Bag(int MaxSize = DefaultSize); //������
	~Bag(); // �Ҹ���
	virtual void Add(int); // ���� �ϳ��� bag�� ����
	virtual int *Delete(int&); //bag���� ���� �ϳ��� ����
	bool IsFull();
	// bag�� ��ȭ�����̸� true, �׷��� ������ false�� ��ȯ
	bool IsEmpty();
	// bag�� ���� �����̸� true, �׷��� ������ false�� ��ȯ
	int Top();
	friend ostream& operator<< (ostream& stream, Bag b);
protected:
	void Full(); // bag�� ��ȭ������ ���� ��ġ
	void Empty(); // bag�� ���� ������ ���� ��ġ
	int *arr;
	int MaxSize; // �迭�� ũ��
	int top; // �迭���� ���Ұ� ��� �ִ� ���� ���� ��ġ
};

class Set : public Bag {
public:
	Set(int MaxSize = DefaultSize);      //������
	~Set();      // �Ҹ���
				 //Set �ڷᱸ���� �°� Add(), Delete() �Լ� ������
	void Add(int);
	int *Delete(int&);
	friend ostream& operator<< (ostream& stream, Set s);
};