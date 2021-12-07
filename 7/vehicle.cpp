#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

class vehicle{
    private:
        double speed;
        int cantain;
    public:
        vehicle(double sd,int c){
            speed = sd;
            cantain = c;
        }
        virtual void show(){
            cout<<"速度:"<<speed<<endl;
            cout<<"最大容载量:"<<cantain<<endl;
        }
        
};
class car:virtual public vehicle{
    public:
        car(double sd,int c):vehicle(sd,c){};

};

class truck:virtual public vehicle{
    private:
        double Maxweight;
    public:
        truck(double sd,int c,double mt):vehicle(sd,c){
            Maxweight = mt; 
        }
        void show(){
            cout<<"最大载货数:"<<Maxweight<<"kg"<<endl;
            vehicle::show();
        }
};

class boat:virtual public vehicle{
    private:
        double paishui;
    public:
        boat(double sd,int c,double ps):vehicle(sd,c){
            paishui = ps;
        }
        void show(){
            cout<<"最大排水量:"<<paishui<<"kg"<<endl;
            vehicle::show();
        }
};

int main(){
    vehicle v1(100,4);
    car c1(600,2);
    truck t1(200,2,900);
    boat b1(150,40,3000);
    vehicle *p;
    p = &v1;
    p->show();
    cout<<endl;

    p=&c1;
    p->show();
    cout<<endl;

    p=&t1;
    p->show();
    cout<<endl;

    p=&b1;
    p->show();
}