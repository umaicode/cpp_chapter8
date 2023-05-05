// 8장-6.FOREIGN.CPP   8.2 동적 Binding의 소개   
// 유도된 class의 polymorphism 예제 
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
    // 동적 binding을 사용하는 virtual 함수
    virtual void Print (){
	//void Print() {
        cout << "Person::Print() : 내 이름은 " << name << endl;
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
        // Foreigner을 위한 이름은 ...
        cout << "Foreigner::Print() : My name is " << name << endl;
    }
} ;
void main(){
    Person * man;
    Foreigner * woman;
    //------------------------------ 교수님 코드 ------------------------------------//
    // 포인터가 아니면 동적바인딩 안한다.
    Person p("박");
    Foreigner f("김");
    p.Print();
    f.Print();
    p = f;
    // f = p;
    p.Print();
    //------------------------------ 교수님 코드 ------------------------------------//
    // 초기화
    man = new Person ("John");
    woman = new Foreigner ("Paola");
    // 이름들을 인쇄한다.   
    cout << "Prints the name of the man:";
    man -> Print ();
    cout << "Prints the name of the woman (a foreigner):" ;
    woman -> Print ();
    man->show();
    woman->show();
    woman->Person::show();
    // 변수 man에 class Person에서 유도된 class Foreigner의
    // 한 객체에 대한 pointer를 치환하는 것은 가능하다.
    man = new Foreigner ("Mario");

    cout << endl;
    cout << "Re-prints the name of the man after the new assignment:";
    man -> Print ();
    man->show();
    woman->show();
    woman->Person::show();
	system("pause");
}