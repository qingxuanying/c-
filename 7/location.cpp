#include<iostream>
using namespace std;

class location{
    private:
        double x;
        double y;
    public:
        location(double ex,double ey){
            x=ex;y=ey;
        }
        location operator+(location P){
            return location(x+P.x,y+P.y);
        }
        location operator-(location P){
            return location(x-P.x,y-P.y);
        }
        void show(){
            cout<<"x:"<<x<<" "<<"y:"<<y<<endl;
        }
};
int main(){
    location p1(1,1);
    cout<<"p1:";
    p1.show();
    location p2(2,3);
    cout<<"p2:";
    p2.show();
    cout<<"p1+p2 :";
    (p1+p2).show();
    cout<<"p1-p2 :";
    (p1-p2).show();
}