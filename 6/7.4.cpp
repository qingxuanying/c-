#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

class Person{
    private:
        char *name;
        char *sex;
        char *pid;
        int year;
        int month;
        int day;
    public:
        Person(char *iname,char *isex,char *ipid,int y,int m,int d){
            name=new char[strlen(iname)+1];
            sex=new char[strlen(isex)+1];
            pid=new char[strlen(ipid)+1];
            strcpy(name,iname);
            strcpy(sex,isex);
            strcpy(pid,ipid);
            year=y;
            month=m;
            day=d;
        }
        Person(){
            year=0;
        }
        void getBrithday(){
            cout<<year<<"年"<<month<<"月"<<day<<"日"<<endl;
        }
        void getName(){
            cout<<"名字："<<name<<endl;
        }
        void getId(){
            cout<<"身份证号"<<pid<<endl;
        }
        void getSex(){
            cout<<"性别"<<sex<<endl;
        }
};
class Student:virtual public Person{
    private:
        char *sid;
        int grade;
    public:
        Student(char *iname,char *isex,char *ipid,int y,int m,int d,char *studentId,int g):Person(iname,isex,ipid,y,m,d){
            sid=new char[strlen(studentId)+1];
            strcpy(sid,studentId);
            grade=g;
        }
        Student(){
            sid=NULL;
        }
        void getStudentId(){
            cout<<"学号:"<<sid<<endl;
        }
        void getGrade(){
            cout<<"成绩:"<<grade<<endl;
        }
};
class Teacher:virtual public Person{
    private:
        char *position;
    public:
        Teacher(char *iname,char *isex,char *ipid,int y,int m,int d,char *pn):Person(iname,isex,ipid,y,m,d){
            position=new char[strlen(pn)+1];
            strcpy(position,pn);
        }
        Teacher(){
            position=NULL;
        }
        void getPosizion(){
            cout<<"职称:"<<position<<endl;
        }
};
class Stu_Tech:public Teacher,public Student{
    public:
        Stu_Tech(char *iname,char *isex,char *ipid,int y,int m,int d,char *pn,char *sid,int g):Person(iname,isex,ipid,y,m,d),
        Teacher(iname,isex,ipid,y,m,d,pn),Student(iname,isex,ipid,y,m,d,sid,g){

        };
};
int main(){
    Stu_Tech p1("汤先宁","男","500236200205263413",2002,5,26,"高级教师","2020212222",1000);
    p1.getName();
    p1.getBrithday();
    p1.getId();
    p1.getPosizion();
    p1.getStudentId();
    p1.getSex();
    p1.getGrade();
}