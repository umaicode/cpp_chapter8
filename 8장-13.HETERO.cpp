// 8��-13.HETERO.CPP   8.10 �������� ������ ���� 
// �������� ������ ������ ��
#include <iostream> 
#include <stdlib.h>
#include <conio.h>
#include "8��-9.animal.h"
#include "8��-11.cow_dog.h"
using namespace std;
void main(){
    //pointer�� �迭
    Animal* mixedFlock[10];	  
    //pointer�� �ʱ�ȭ
    mixedFlock[0] = new Cow("Tom");
    mixedFlock[1] = new Dog("Thomas");
    mixedFlock[2] = new Dog("Ashley");
    mixedFlock[3] = new Dog("Ryan");
    mixedFlock[4] = new Dog("Daniel");
    mixedFlock[5] = new Cow("Matthew");
    mixedFlock[6] = new Cow("Samuel");
    mixedFlock[7] = new Cow("William");
    mixedFlock[8] = new Animal("Sophie");// �߻� ��ü�� ������ ������ ���� �ʴ´� - �ذ� ���
    mixedFlock[9] = new Dog("Jessica");
    for(int i=0; i< 10;i++) mixedFlock[i]->Speak();
    system("pause");
}