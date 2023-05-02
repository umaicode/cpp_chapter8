// 8-3.PUREVIRTUAL.CPP    8.6 virtual �Լ��� ���� binding�� ��� ��
/*
�ǽ����� 8.3
1)����
 �� source code�� ���� binding�� ���� binding ������ ���̸� �����ϴ� ���̴�.
2)���
 ��) �ּ� 1���� �����ϰ� ������ Ȯ���غ���.
 ��) class Polygon�� Perimeter �Լ��� class Rectangle���� �������ϰ� ȣ���Ͽ� ���� ����� Ȯ���غ���.
 ��) �ּ� 2���� �����ϰ� pure virtual �Լ��� ��� ���ǵǾ��� ���� �׷��� ���� ���� ���غ���.
 ��) ������ �ּ� ó���ϰ� ��� ����� ���ؼ� ��� class�� �Լ��� ȣ��Ǵ��� Ȯ�κ���.
 ��) �ּ� 3���� �����Ͽ� ��� ����� ���ؼ� �Լ��� ȣ��Ǵ� class�� �ٽ� �ѹ� Ȯ���غ���.
*/
#include <iostream>
using namespace std;
class Polygon{
public:
    int Creator(); // non-virtual(non-virtual) member �Լ�
    virtual void Moves(int delta_x, int delta_y); // virtual(virtual) member �Լ�    
    virtual int Perimeter()=0; // pure virtual(virtual) member �Լ�
    virtual int Color()=0; // pure virtual(virtual) member �Լ�

protected:
    int creator;
    int x_pos, y_pos;
};
//Creator()�� ������ class���� ������ ���� �ʴ´�.
int Polygon::Creator(){
    cout << "Polygon�� Creator() : " << creator << endl;
    return creator;
}
//Polygon�� member �Լ� Moves()�� ������ ���� �����ȴ�.
void Polygon::Moves(int delta_x, int delta_y){
    cout << "Polygon�� Moves()" << endl;
    cout << "���� �� x_pos : " << x_pos << "  y_pos : " << y_pos << endl;
    x_pos += delta_x;
    y_pos += delta_y;
    cout << "���� �� x_pos : " << x_pos << "  y_pos : " << y_pos << endl;
}
//class Rectangle : protected Polygon { //assign �������� ����
class Rectangle : public Polygon{
public:
    ///* �ּ� 2
    int Perimeter(){//Rectangle���� ���ǵ�
        cout << "Rectangle�� Perimeter() : " << 2*(height+base) << endl;
        return 2*(height+base);
    }//*/
    int Color(){//Rectangle���� ���ǵ�
        cout << "Rectangle�� Color() : " << color << endl;
        return color;
    }
    int Base(){
        cout << "Rectangle�� Base() : " << base << endl;
        return base;
    }
    int Height(){
        cout << "Rectangle�� Height() : " << height << endl;
        return height;
    }
private:       // Rectangle���� �߰��� ������ member��
    int base, height;
    int color;
};

class Square : public Rectangle {
public:
    ///* �ּ� 3
    int Perimeter(){
        cout << "Square�� Perimeter() : " << "0" << endl;
        return 0;
    }
    int Color(){
        cout << "Square�� Color() : " << color << endl;
        return color;
    }
    int Color(int c){

        color = c;
        cout << "Square�� Colorl(int c) : " << color << endl;
        return color;
    }//*/
	void Moves(int delta_x, int delta_y) {
		cout << "Square:: Moves() is called" << endl;
		Polygon::Moves(delta_x, delta_y);
	}
private:
    int color;
};

void main(){
    /*��ü ������ error�� �߻��� ��� pure virtual �Լ��� ������� �����غ���*/
    ///* �ּ�1
    //Polygon p1; //error!!
    //error!! �߻� class�� ��ü�� ������ �� ����
    //Polygon *p1 = new Polygon(); 

    //Polygon�� pure virtual �Լ��� ��� �������ϸ� ��ü�� ���� �����ϳ� ���     //���������� ������ �߻� class�� ó���ȴ�.
    Polygon *p2 = new Rectangle(); 
    cout << endl << "------ Polygon *p2 = new Rectangle() ------" << endl;
    p2->Creator();
    p2->Perimeter();
    p2->Color();
    p2->Moves(1, 2);
    //*/
    Polygon *p3 = new Square();
    cout << endl << "------ Polygon *p3 = new Square() ------"  << endl;
    p3->Creator();
    p3->Perimeter();
    p3->Color();
    //p3->Color(10);
    p3->Moves(10, 20);	
    //Polygon�� pure virtual �Լ��� ��� ������ �ϸ� ��ü�� ���� ����	
    Rectangle *r1 = new Rectangle(); 
    cout << endl << "------ Rectangle *r1 = new Rectangle() ------" << endl;
    r1->Creator();
    r1->Perimeter();
    r1->Color();
    //r1->Color(10); 
    r1->Moves(10, 20);
    r1->Base();
    r1->Height();

    Rectangle *r2 = new Square();
    cout << endl << "------ Rectangle *r2 = new Square() ------" << endl;
    r2->Creator();
    r2->Perimeter();
    r2->Color();
    //r2->Color(10); 
    r2->Moves(10, 20);
    r2->Base();
    r2->Height();

    Square *s = new Square();
    cout << endl << "------ Square *s = new Square() ------" << endl;
    s->Creator();
    s->Perimeter();
    s->Color(); 
    s->Color(20);
    s->Moves(20, 30);
    s->Base();
    s->Height();
    system("pause");
}