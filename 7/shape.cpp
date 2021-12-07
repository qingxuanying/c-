#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
#define Pi 3.1415;

class point{
    public:
        double x;
        double y;
        point(){
            x=0;y=0;
        }
        point(double ex,double ey){
            x=ex;
            y=ey;
        }
        void setpoint(double ex,double ey){
            x=ex;y=ey;
        }
};

class shape{
    private:
        point centerPoint;
    public:
        shape(double ex,double ey){
            centerPoint.setpoint(ex,ey);
        }
        virtual double Area(){
            cout<<"0"<<endl;
            return 0;
        }
};

class Rctangle:virtual public shape{
    private:
        double s;
        double h;
        double area;
    public:
        Rctangle(double es,double eh,double earea):shape(0,0){
            s=es;
            h=eh;
            area=es*eh/2;
            if(earea != es*eh/2){
                cout<<"输入的面积有误，已更正"<<endl;
            }
        }
        Rctangle(double es,double eh):shape(0,0){
            s=es;
            h=eh;
            area=es*eh/2;
        }
        Rctangle(double es,double eh,double ex,double ey):shape(ex,ey){
            s=es;
            h=eh;
            area=es*eh/2;
        }

        Rctangle(double es,double eh,double earea,double ex,double ey):shape(ex,ey){
            s=es;
            h=eh;
            area=es*eh/2;
            if(earea != es*eh/2){
                cout<<"输入的面积有误，已更正"<<endl;
            }
        }

        double Area(){
            cout<<area<<endl;
            return area;
        }
};

class Circle:virtual public shape{
    private:
        double r;
        double area;
    public:
        Circle(double ex,double ey,double er):shape(ex,ey){
            r=er;
            area=r*r*Pi;
        }
        double Area(){
            cout<<area<<endl;
            return area;
        }
};

int main(){
    shape *p;
    shape s1(0,0);
    Rctangle tan1(3,6);
    Circle c1(0,0,6);

    p = &s1;
    p->Area();

    p = &tan1;
    p->Area();

    p = &c1;
    p->Area();
}