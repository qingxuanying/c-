#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
#define SIZE 20

class Stack
{
private:
    char stackarry[SIZE];
    int tos;

public:
    Stack()
    {
        tos = 0;
    }
    void push(char s)
    {
        if (tos < SIZE)
        {
            stackarry[tos] = s;
            tos++;
        }
        else
        {
            cout << "栈空间不足,push失败" << endl;
        }
    }
    void pop(char &s)
    {
        if (tos > 0)
        {
            s = stackarry[tos - 1];
            tos--;
        }
        else
        {
            cout << "栈为空，pop失败" << endl;
        }
    }
    void min(char &str){
        if(tos != 0){
            int st=1;
            char k=stackarry[0];
            while(st<tos){
                if(stackarry[st] <k){
                    k=stackarry[st];
                }
                st++;
            }
            str=k;
        }
        else{
            cout<<"栈为空,min操作失败"<<endl;
        }
    }
};
int main()
{
    Stack S;
    char cs,min;
    while (1)
    {
        scanf("%c",&cs);
        if (cs == '\n' || cs == ' ' || cs == '\t')
        {
            break;
        }
        S.push(cs);
    }
    S.pop(cs);
    cout << cs << endl;
    S.min(min);
    cout<<min<<endl;
}