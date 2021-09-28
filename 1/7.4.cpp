#include<iostream>
#include<math.h>
using namespace std;

class Clock{
    private:
        int H=0;
        int Min=0;
        int S=0;//表示现在时间
        int ch=0;
        int cm=0;
        int cs=0;//表示定时
    public:
        void SetAlarm(int h,int m, int s){
            ch=h;
            cm=m;
            cs=s;
        };
        int run(){
            while(1){
                if( H==ch && Min==cm && S==cs){
                cout<<"响铃"<<endl;
                return 1;
            }
            else{
                S++;
                if(S==60){
                    S=0;
                    Min++;
                    if(Min==60){
                        Min=0;
                        H++;
                        if(H==24){
                            H=0;
                            cout<<"过了一天"<<endl;
                        }
                    }
                }
            }
            }
        };
        Clock(int h,int m, int s){
            H=s;
            Min=m;
            S=s;
        }

};

int main(){
    Clock p(8,8,8);
    p.SetAlarm(7,9,9);
    p.run();
    return 0;
}