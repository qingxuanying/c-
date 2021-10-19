#include<iostream>
#include<string.h>
using namespace std;
class Student{
    private:
        int id;
        char *name;
        char *sub1;
        double score1;
        char *sub2;
        double score2;
        char *sub3;
        double score3;
        double ave=0;
        static int avesub1;
        static int avesub2;
        static int avesub3;
        static int num;
        
    public:
        Student(int i,char *n,char *s1,int sc1,char *s2,int sc2,char *s3,int sc3){
            id=i;
            name=n;
            sub1=s1;
            score1=sc1;
            sub2=s2;
            score2=sc2;
            sub3=s3;
            score3=sc3;
            num++;
            avesub1 += sc1;
            avesub2 += sc2;
            avesub3 += sc3;
            ave=sc1+sc2+sc3;
        }
        double getsubAve(int i){
            if(i==1){
                return avesub1/num;
            }
            if(i==2){
                return avesub2/num;
            }
            else{
                return avesub3/num;
            }
        }
        double getStudentAve(){
            return ave/3;
        }
};
int Student::num = 0;
int Student::avesub1 = 0;
int Student::avesub2 = 0;
int Student::avesub3 = 0;
int main(){
    char name[20];
    strcpy(name, "汤先宁");
    char sub1[20];
    strcpy(sub1,"数学");
    char sub2[20];
    strcpy(sub2,"语文");
    char sub3[20];
    strcpy(sub3,"物理");
    Student s1(1,name,sub1,150,sub2,150,sub3,60);
    Student s2(2,name,sub1,130,sub2,120,sub3,68);
    cout<<"学生平均成绩"<<s1.getStudentAve()<<endl;
    cout<<"各课程班平均成绩"<<s1.getsubAve(1)<<' '<<s1.getsubAve(2)<<' '<<s1.getsubAve(3)<<endl;
    return 0;
}