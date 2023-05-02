// 8��-11.cow_dog.h    8.8 ������ class�� ��ȭ
// class Animal�κ��� ������ class Cow�� class Dog
#include <iostream> 
using namespace std;
class Cow : public Animal {
public:
    Cow (Point p = Point (10, 10));
	Cow(char*){}
    void Speak ();
};

class Dog : public Animal{
public:
    Dog (Point p = Point (20, 20));
	Dog(char*){}
    void Speak ();
};

Cow :: Cow (Point p): Animal (p)
{}
void Cow :: Speak (){
    MoveOutput ();
    cout << "Cow::Cow sounded:: moo ";
}

Dog :: Dog (Point p) : Animal (p)
{}

void Dog :: Speak (){
    MoveOutput ();
    cout << "Dog::Dog sounded::merngmerng ";
}