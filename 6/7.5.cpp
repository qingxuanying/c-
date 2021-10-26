#include<iostream>
#include<math.h>
using namespace std;

class Clock{
    private:
        int H=0;
        int Min=0;
        int S=0;//表示现在时间
    public:
        Clock(int h,int m, int s){
            if(h>24 ||m>=60 || s>=60){
                cout<<"非法输入"<<endl;
                exit(1);
            }
            H=s;
            Min=m;
            S=s;
        }
        int getH(){
            return H;
        }
        int getM(){
            return Min;
        }
        int getS(){
            return S;
        }

};
class NewClock:public Clock{
    public:
        NewClock(int h,int m,int s):Clock(h,m,s){

        }
        void getTime(){
            if(getH()>12){
                cout<<"PM. "<<getH()-12<<"时 "<<getM()<<"分 "<<getS()<<"秒"<<endl;
            }
            else{
                cout<<"AM. "<<getH()<<"时 "<<getM()<<"分 "<<getS()<<"秒"<<endl;
            }
        }
};

int main(){
    NewClock p(8,8,8);
    NewClock p2(14,3,9);
    p.getTime();
    p2.getTime();
    return 0;
}