#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

class String{
    private:
        char *string;
        int L;
    public:
        String(char *s){
            string =new char[strlen(s)+1];
            strcpy(string,s);
            L=strlen(s);
        }
        String(const char *str){
            string = new char[strlen(str)+1];
            strcpy(string,str);
            L=strlen(str);
        }
        void toUppercase(){
            int i=0;
            while(string[i]!='\0'){
                if(string[i]>='a' && string[i]<='z'){
                    string[i]=string[i]-32;
                    cout<<string[i];
                }
                i++;
            }
            cout<<endl;
        }
        int str2num(){
            int num=0;
            int j=1,k;
            for(int i=L-1;i>=0;i--){
                char tmp=string[i];
                if(tmp>'9' || tmp<'0'){
                    cout<<"无法转换"<<endl;
                    return -1;
                }
                else{
                    k=tmp-'0';
                    num=num+k*j;
                    j=j*10;
                }
            }
            return num;
        }
        bool IsSubstring(const char *str){
            int len=strlen(str);
            if(L<len){
                return false;
            }
            int i=L-len;
            while(1){
                if(i<0){
                    return false;
                }
                char *tmp=(char*)malloc((len+1)*sizeof(char));
                memcpy(tmp,string+i,len*sizeof(char));
                tmp[len]='\0';
                if(strcmp(tmp,str) == 0){
                     return true;
                }
                i--;
            }
        }
        bool IsSubstring(const String &Str){
            int len=Str.L;
            if(L<len){
                return false;
            }
            int i=L-len;
            while(1){
                if(i<0){
                    return false;
                }
                char *tmp=(char*)malloc((len+1)*sizeof(char));
                memcpy(tmp,string+i,len*sizeof(char));
                tmp[len]='\0';
                if(strcmp(tmp,Str.string) == 0){
                    return true;
                }
                i--;
            }
        }
};
int main(){
    char s[20];
    strcpy(s,"abcdefg");
    String str(s);
    String str1("bcd");
    String str2("54210");
    if(str.IsSubstring("fg")){
        cout<<"ture"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }

    if(str.IsSubstring(str1)){
        cout<<"ture"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    cout<<str2.str2num()<<endl;
    str.toUppercase();
    return 0;
}