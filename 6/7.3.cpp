#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
#define PI 3.1415;
class Table{
    private:
        int theight;
        char *color;
        char *mater;
    public:
        Table(int h,char *c,char *m){
            theight=h;
            int l1=strlen(c);
            int l2=strlen(m);
            color=new char[l1+1];
            strcpy(color,c);color[l1]='\0';
            mater=new char[l2+1];
            strcpy(mater,m);
        }
        Table(){
            theight=0;
        }
        char *getColor(){
            return color;
        }
        char *getMater(){
            return mater;
        }
        int getHeight(){
            return theight;
        }
};
class Circle{
    private:
        int x;
        int y;
        int r;
        double area;
    public:
        Circle(int px,int py,int pr){
            x=px;
            y=py;
            r=pr;
            area=r*r*PI;
        }
        Circle(){
            x=y=r=0;
            area=0;
        }
        double getArea(){
            return area;
        }
};
class RoundTable:public Circle,public Table{
    private:
        int tid;
    public:
        RoundTable(int h,char *c,char *m,int px,int py,int pr,int id):Table(h,c,m),Circle(px,py,pr){
            tid=id;
        };
};
int main(){
    char color[20];char mater[10];
    strcpy(color,"lightBlue");strcpy(mater,"iron");
    RoundTable rt2(3,color,mater,3,6,2,1);
    cout<<rt2.getArea()<<"  "<<rt2.getColor()<<"  "<<rt2.getMater()<<"  "<<rt2.getHeight()<<endl;
}