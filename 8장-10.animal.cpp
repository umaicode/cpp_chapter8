// 8��-10.animal.cpp    8.8 ������ class�� ��ȭ 
// class Animal�� member �Լ���
#include <iostream> 
#include "8��-9.animal.h"
using namespace std;
Animal :: Animal (Point p): position (p)
{}
void Animal :: Speak (){
    cout << "Animal::The animal is making his verse" << endl;
}
void Animal :: JumpBy (int x, int y){
    position += Point (x,y);
}
void Animal :: MoveTo (Point newPosition){
    position = newPosition;
}

void Animal :: MoveOutput (){
    cout<<"Animal::\tposition.x() = "<<position.x()<<", position.y() = "<<position.y()<<endl;
}