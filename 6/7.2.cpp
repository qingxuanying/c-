#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

class Building{
    private:
        int floor;//层数
        int room;//教室数或宿舍数
        int totArea;
    public:
        Building(int f,int r,int a){
            floor=f;
            room=r;
            totArea=a;
        }
        Building(){
            floor=0;
            room=0;
        }
        int getRoom(){
            return room;
        }
        int getFloor(){
            return floor;
        }
        int getArea(){
            return totArea;
        }
        void fixFloor(int f){
            floor=f;
        }
        void fixRoom(int r){
            room=r;
        }
        void fixArea(int a){
            totArea=a;
        }
};
class Teach_Building:public Building{
    private:
        int tid;
    public:
        Teach_Building(int f,int r,int a,int id):Building(f,r,a){
            tid=id;
        }
        int getId(){
            return tid;
        }
};
class Dorm_Building:public Building{
    private:
        int did;
        int num;
    public:
        Dorm_Building(int f,int r,int a,int id,int n):Building(f,r,a){
            did=id;
            num=n;
        }
        int getId(){
            return did;
        }
        int getNum(){
            return num;
        }
};
int main(){
    Teach_Building t1(11,99,12000,3);
    Dorm_Building d1(8,160,9365,7,3140);
    cout<<"教学楼编号:"<<t1.getId()<<"  教学楼层数:"<<t1.getFloor()<<"  教学楼面积:"<<t1.getArea()<<endl;
    cout<<"宿舍楼编号:"<<d1.getId()<<"  宿舍楼层数:"<<d1.getFloor()<<"  宿舍楼面积:"<<d1.getArea()<<"  宿舍楼容纳人数:"<<d1.getNum()<<endl;
    return 0;
}