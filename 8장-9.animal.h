// 8��-9.animal.h   8.8 ������ class�� ��ȭ 
#include "8��-8.point.h"
class Animal{
public:
    Animal (Point p = Point ());
	Animal(char*) {}
    // �Լ� "speak"�� �� ������ class�� ���� �����ǵȴ�
    virtual void Speak ();
    void JumpBy (int x, int y);
    void MoveTo (Point newPosition);

protected:
    // ������ ���� ��ġ
    Point position;
    // ���� ��� ������ ���� ��ġ�� �����Ѵ�
    void MoveOutput ();
};