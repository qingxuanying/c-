#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
#define Pi 3.1415;

class Point
{
private:
    int x = 0;
    int y = 0;

public:
    Point(int px, int py)
    {
        x = px;
        y = py;
    }
    Point()
    {
        x = 0;
        y = 0;
    }
    int getPiont_x()
    {
        return x;
    }
    int getPoint_y()
    {
        return y;
    }
    void setX(int px)
    {
        x = px;
    }
    void setY(int py)
    {
        y = py;
    }
};
class Circle : public Point
{
private:
    double r;

public:
    Circle(int x, int y, double range) : Point(x, y)
    {
        r = range;
    }
    double getCircleS()
    {
        return r * r * Pi;
    }
    void fixRange(double range)
    {
        r = range;
    }
    double getRange()
    {
        return r;
    }
};
class Cylinder : public Circle
{
private:
    double height;

public:
    Cylinder(int x, int y, double range, double h) : Circle(x, y, range)
    {
        height = h;
    }
    double getCylinderS()
    {
        double c = getRange() * 2 * Pi;
        double s;
        s = getCircleS() * 2 + c * height;
        return s;
    }
    double getHeight()
    {
        return height;
    }
    void fixHeight(double h)
    {
        height = h;
    }
};
int main()
{
    Circle s(0, 0, 3);
    Cylinder cy1(0, 0, 1, 1);
    cout << s.getCircleS() << endl;
    cout << cy1.getCylinderS() << endl;
}