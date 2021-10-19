#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
#define Pi 3.1415;

class Point{
    private:
        int x=0;
        int y=0;
    public:
        Point(int px,int py){
            x=px;
            y=py;
        }
        Point(){
            x=0;
            y=0;
        }
        int getPiont_x(){
            return x;
        }
        int getPoint_y(){
            return y;
        }
        void setX(int px){
            x=px;
        }
        void setY(int py){
            y=py;
        }
};
class Rectangle:public Point{
    private:
        Point a;
        Point b;
        Point c;
        Point d;
        int len=0;
        int hei=0;
        int area=0;
    public:
        Rectangle(int ax,int ay,int bx,int by,int cx,int cy,int dx,int dy):Point(0,0){
            a.setX(ax);a.setY(ay);
            b.setX(bx);b.setY(by);
            c.setX(cx);c.setY(cy);
            d.setX(dx);d.setY(dy);
        }
        Rectangle(int length,int height,int x,int y):Point(x,y){
            len=length;
            hei=height;
        };
        Rectangle(int length,int height):Point(0,0){
            len=length;
            hei=height;
        };
        int getArea(){
            if(len != 0){
                return hei*len;
            }
            else{
                int l1= a.getPiont_x() -b.getPiont_x();l1=abs(l1);
                int l2= a.getPiont_x() -c.getPiont_x();l2=abs(l2);
                int l = l1>l2 ? l1:l2;
                int h1=a.getPoint_y() - b.getPoint_y();h1=abs(h1);
                int h2=a.getPoint_y() - c.getPoint_y();h2=abs(h2);
                int h=h1>h2?h1:h2;
                return h*l;
            }
        }

};
class Circle:public Point{
    private:
        int r;
        double area=0;
    public:
        Circle(int x,int y,int pr):Point(x,y){
            r=pr;
        }
        double getArea(){
            area=r*r*Pi;
            return area;
        }
};
int main(){
    Rectangle tan(3,6);
    cout<<tan.getArea()<<endl;
    Circle o1(0,0,3);
    cout<<o1.getArea()<<endl;
    return 0;
}