#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

class String
{
private:
    char str[30];
    int tos = 0;

public:
    String(const char *s){
        while(s[tos] != '\0'){
            str[tos]=s[tos];
            tos++;
        }
        str[tos]='\0';
        tos;
    }
    int length(){
        return tos;
    }
    void display(){
        cout<<str<<endl;
    }
    String operator+(String b){
        return String(strcat(str,b.str));
    }
    bool operator <(String b){
        cout<<"正在比较"<<endl;
        int k=tos>b.tos?b.tos:tos;
        int i=0;
        while(i<=k){
            if(str[i]>b.str[i]){
                return false;
            }
            i++;
        }
        if(tos > b.tos){
            return false;
        }
        return true;
    }
    bool operator ==(String b){
        if(tos != b.tos){
            return false;
        }
        int i=0;
        while(i<=tos){
            if(str[i] != b.str[i]){
                return false;
            }
        }
        return true;
    }
    bool operator>(String b){
        int k=tos>b.tos?b.tos:tos;
        int i=0;
        while(i<=k){
            if(str[i]<b.str[i]){
                return false;
            }
            i++;
        }
        if(tos < b.tos){
            return false;
        }
        return true;
    }
    //查找字符串
    int findSubstr(String s){
        int i=0;
        int flag=0;
        if(s.tos >tos){
            return -1;
        }
        while(i<=tos){
            while(flag<=s.tos){
                if(flag == s.tos){
                    return i+1;
                }
                if(str[i+flag] != s.str[flag]){
                    break;
                }
                flag++;
            }
            flag=0;
            i++;
        }
        return -1;
    }

    //替换单个字符
    void replaceSTR(char s,char m){
        int i=0;
        while(i<=tos){
            if(str[i]==s){
                str[i]=m;
            }
            i++;
        }
    }
    //替换字符串
    void replaceWords(char *str,char *mstr){
        int i=0;
        
    }
};
int main(){
    String str1("adfgsh");
    String sub("dfg");
    String str2("adfsfingg");
    cout<<str1.length()<<endl;
    //cout<<sub.length()<<endl;
    str1.display();
    //sub.display();
    //cout<<sub.findSubstr(str1)<<endl;
    cout<<str1.findSubstr(sub)<<endl;
    str1.replaceSTR('g','i');
    str1.display();
    if(str1 > 
    
    
    str2){
        cout<<"str1 > str2"<<endl;
    }
    if(str2 > str1){
        cout<<"str2>str1"<<endl;
    }
}