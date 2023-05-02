//8.2 dynamicBinding.cpp   8.5 virtual �Լ�
#include <iostream>
using namespace std;
/*
�ǽ����� 8.2
1) ����
�� source code�� virtual�� ���Ͽ� ���� binding�� ���Ͽ� �˾ƺ��� �����̴�.
2) ���
��. class Person�� Print()�Լ��� virtual�� �ִ� ���� ���� ��츦 ���� �����Ͽ� ���̸� Ȯ���غ���.
��. class Person�� Print()�Լ��� virtual�� ����� class Foreigner�� Print()�Լ��� virtual�� �߰����� �� wc->Print()�� ��� ���� ��� ��µǴ��� Ȯ���غ���.
��. class Person, Foreigner, China�� Print()�Լ��� ���� virtual�� �������� �� �����Ͽ� ��� ���� Ȯ���غ���.
*/
class Person{
protected:
    char* name;
public:
    Person(char* n):name(n){}
    virtual void Print(){
        cout<<"\tPerson::Print(): name is "<<name<<endl;
    }
    virtual void Print(char* ch){
        cout<<"\tPerson::Print(char*ch): name is "<<ch<<endl;
    }
};
//class Foreigner : protected Person { //assign�� �������� �ʴ´� 
class Foreigner : public Person{
    char *nation;
public:
    Foreigner(char* name, char *country):Person(name), nation(country){}
//�ּ�1   
//*
    void Print(){
        cout<<"\tForeigner::Print(): nation = "<<nation<<endl;
    }
//*/
//�ּ�2
/*
     virtual void Print(){
        cout<<"\tForeigner::virtual_Print():name = " <<name << endl;
    }
*/	 
    void Print(char* ch){
		Person::Print(ch);
        cout<<"\tForeigner::Print(char* ch):name = " << ch << endl;
    }
    virtual void show() {
        cout << "\tForeigner::virtual_Show():name = " << name << endl;
    }
};
class ChinaForeigner : public Foreigner{
    int level;
public:
    ChinaForeigner(char* n, char *country, int level):Foreigner(n, country), level(level){}
    void Print(){
        cout<<"\tChinaForeigner::Print():name - "<<name<<endl;
    }
    void show() {
    //virtual void show() { //virtual�� ������� �ʾƵ� ������ virtual �Լ������� readable
        cout << "\tChinaForeigner::virtual_Show():level = " << level << endl;
    }
};

void main(){
    Person* wp;
    Person* wf;
    Person* wc;

    wp = new Person("John");
    wf = new Foreigner("elintoo","Korea");
    wc = new ChinaForeigner("chailyn","China", 2);

    cout<<"Prints the name : "<<endl;
    wp->Print();
    wf->Print();
    wc->Print();
    wc->Person::Print();
	cout << "After wp = wf;" << endl;
    wp = wf;
    wp->Print();

	cout << "After wp = wc;" << endl;
    wp = wc;
    wp->Print();
    //wf, wc ��ü�� parameter�� �ִ� Print()�� ȣ���Ͽ��� ���� ����� ���غ���
	wf->Print("Sera"); 
    wc->Print("Sera"); 
    //���� wp�� class Person���� ������ class Foreigner��
    //�� ��ü�� ���� pointer�� ġȯ�ϴ� ���� �����ϴ�.
	cout << "wp = new Foreigner(Mario);" << endl;
    wp = new Foreigner("Mario","France");
    cout<<endl << "Re-prints the name of the man after the new assignment:"<<endl;
    wp->Print();
    Foreigner* foreigner;
    foreigner = new ChinaForeigner("Hong","china",1);
    foreigner->show();
    //wf->show();
    system("pause");
}


