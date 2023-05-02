// 8��-7.BINDING.CPP  8.5 virtual �Լ�
// ���� binding�� ���� binding ������ ���̿� ����,
// �����μ� �ܼ� ���������� ���� ���� ���̴� 
#include <iostream>
using namespace std;
// class �̸��� ����ϴ� �� ���� �Լ��� ���� class A�� ���� �Ѵ� 
class A {
public:
    A ( ) { }
    virtual void Dynamic (){
        cout << "A::Dynamic function of class A" << endl;       
    }
    void Static (){
        cout << "A::Static function of class A" << endl;
    }
} ;
// class A�κ��� ������, class B�� �����ϴ� �� �� ���� �Լ��� �������Ѵ�.
class B : public A {
public:
    B ( ) { }
    void Dynamic () {
		//A::Dynamic();
        cout << "B::Dynamic function of class B" << endl;   
    }
    void Static () {
        cout << "B::Static function of class B" << endl;
    }
} ;

void main(){
    // �ΰ��� ������ pointer ������ �����ϰ� �ִ�
    A * a;
    B * b;
    // �ʱ�ȭ
    a = new A ();
    b = new B ();
    cout << "Functions of object a of class A" << endl;
    a -> Dynamic ();
    a -> Static ();
    cout << endl;
    cout << "Functions of object b of class B" << endl;
    b -> Dynamic ();
    b -> Static ();
    cout << endl;
    /* polymorphism ������, ���� a�� class B�� ��ü�� ����Ű��     pointer�� ������ ���� �� �ִ�.*/
    a = b;

    cout << "Functions of the object a of class A" << endl
          << "to which has been assigned a value of class B"<< endl;
    // B class�� virtual �Լ��� ȣ��
    a -> Dynamic ();
    // A class�� non-virtual �Լ��� ȣ��
    a -> Static ();
	system("pause");
}