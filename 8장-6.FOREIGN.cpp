// 8��-6.FOREIGN.CPP   8.2 ���� Binding�� �Ұ�   
// ������ class�� polymorphism ���� 
#include <iostream>
using namespace std;
class Person{
protected:
    char * name;
public:
    Person (char* n) : name (n)
    { }
    void show() {
        cout << "Person::show()" << name<<endl;

    }
    // ���� binding�� ����ϴ� virtual �Լ�
    virtual void Print (){
	//void Print() {
        cout << "Person::Print() : �� �̸��� " << name << endl;
    }
};

class Foreigner : public Person{
public:
    Foreigner (char* n) : Person (n)
    { }    
    void show() {
        cout << "Foreigner::show()" << name << endl;

    }
    void Print (){
        // Foreigner�� ���� �̸��� ...
        cout << "Foreigner::Print() : My name is " << name << endl;
    }
} ;
void main(){
    Person * man;
    Foreigner * woman;
    //------------------------------ ������ �ڵ� ------------------------------------//
    // �����Ͱ� �ƴϸ� �������ε� ���Ѵ�.
    Person p("��");
    Foreigner f("��");
    p.Print();
    f.Print();
    p = f;
    // f = p;
    p.Print();
    //------------------------------ ������ �ڵ� ------------------------------------//
    // �ʱ�ȭ
    man = new Person ("John");
    woman = new Foreigner ("Paola");
    // �̸����� �μ��Ѵ�.   
    cout << "Prints the name of the man:";
    man -> Print ();
    cout << "Prints the name of the woman (a foreigner):" ;
    woman -> Print ();
    man->show();
    woman->show();
    woman->Person::show();
    // ���� man�� class Person���� ������ class Foreigner��
    // �� ��ü�� ���� pointer�� ġȯ�ϴ� ���� �����ϴ�.
    man = new Foreigner ("Mario");

    cout << endl;
    cout << "Re-prints the name of the man after the new assignment:";
    man -> Print ();
    man->show();
    woman->show();
    woman->Person::show();
	system("pause");
}