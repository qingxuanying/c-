#include<iostream>
#include<math.h>
using namespace std;

class Point{
    private:
        double x;
        double y;
    public:
        double Distance(Point& p){
            double dx=p.x-x;
            double dy=p.y-y;
            double k=pow(dx,2)+pow(dy,2);
            double distance=pow(k,0.5);
            return distance;
        };
        Point(double cx,double cy){
            x=cx;
            y=cy;
        };
}; 
int main(){
    int x,y;
    cout<<"请输入第一个点的坐标"<<endl;
    cin>>x>>y;
    Point p(x,y);
    cout<<"请输入第二个点的坐标"<<endl;
    cin>>x>>y;
    Point q(x,y);
    cout<<"距离为:"<<q.Distance(p)<<endl;
    return 0;
}