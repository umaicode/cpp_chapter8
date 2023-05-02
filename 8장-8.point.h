// 8��-8.point.h    8.8 ������ class�� ��ȭ 
// class Point�� interface�� inline �Լ��� ���ǵȴ�
class Point{
public:
    Point (int xp = 0, int yp = 0) : xPos (xp), yPos (yp)
    {}
    int x (){ return xPos; }
    int y (){ return yPos; }
    void x (int px){ xPos = px; }
    void y (int py){ yPos = py; }
    void operator += (Point p){
        xPos += p.xPos;
        yPos += p.yPos;
    }
private:
    int xPos, yPos;
};