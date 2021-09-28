#include<iostream>
#include<math.h>
using namespace std;

class Ctriangle{
    private:
        int a;
        int b;
        int c;
        double squre=0;
        int longth=0;
    public:
        Ctriangle(int A,int B,int C){
            if((A+B)>C && (A+C)>B && (B+C)>A){
                a=A;b=B;c=C;
            }
            else{
                a=0;b=0;c=0;
                cout<<"输入非法"<<endl;
            }
        }
        int getLongth(){
            longth=a+b+c;
            return longth;
        }
        int getSqure(){
            int s=a+b+c;
            double k=(s-a)*(s-b)*(s-c);
            double sq2=s*k;
            squre=pow(sq2,0.5);
            return squre;
        }

};
int main(){
    int a,b,c;
    cout<<"输入三角形的三边长"<<endl;
    cin>>a>>b>>c;
    Ctriangle san1(a,b,c);
    cout<<"周长:"<<san1.getLongth()<<endl;
    cout<<"面积:"<<san1.getSqure()<<endl;
    return 0;
}