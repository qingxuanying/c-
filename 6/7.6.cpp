#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

class Date
{
private:
    int year = 0;
    int month = 0;
    int day = 0;

public:
    void showdate()
    {
        cout << year << "年 " << month << "月 " << day << "日 ";
    }
    Date(int y, int m, int d)
    {
        int falg = 0;
        if (d < 0 || d > 32)
        {
            cout << "输入非法" << endl;
            exit(-1);
        }
        if ((m == 2 || y % 4 == 0) && d > 29)
        {
            cout << "输入非法" << endl;
            exit(-1);
        }
        if ((m == 2 || y % 4 != 0) && d > 28)
        {
            cout << "输入非法" << endl;
            exit(-1);
        }
        year = y;
        month = m;
        day = d;
    }
    void NewDay()
    {
        day++;
        if (month == 2 && day == 29 && year % 4 != 0)
        {
            day = 0;
            month = 3;
        }
        if (month == 2 && day == 30 && year % 4 == 0)
        {
            day = 0;
            month = 3;
        }
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            if (day == 32)
            {
                day == 0;
                month++;
                if (month == 13)
                {
                    month == 1;
                    year++;
                }
            }
        }
        else
        {
            if (day == 31)
            {
                day == 0;
                month++;
            }
        }
    };
};

class Clock
{
private:
    int H = 0;
    int Min = 0;
    int S = 0; //表示现在时间
public:
    Clock(int h, int m, int s)
    {
        H = s;
        Min = m;
        S = s;
    }
    int addS()
    {
        S++;
        if (S == 60)
        {
            S = 0;
            Min++;
            if (Min == 60)
            {
                Min = 0;
                H++;
                if (H == 24)
                {
                    H = 0;
                    return 1;
                }
            }
        }
        return 0;
    }
    void showtime()
    {
        cout << H << "时 " << Min << "分 " << S << "秒 " << endl;
    }
};

class ClockWithDate : public Clock, public Date
{
public:
    ClockWithDate(int h, int m, int s, int y, int mo, int d) : Clock(h, m, s), Date(y, mo, d){};
    void run()
    {
        int k = addS();
        if (k == 1)
        {
            NewDay();
        }
    }
    void showDate_Time()
    {
        showdate();
        showtime();
    }
};

int gettime(){
    return clock()/CLOCKS_PER_SEC;
}

int main()
{
    int y, m, d, h, min, s;
    int lasttime=0;
    cout << "请输入日期 年 月 日" << endl;
    cin >> y >> m >> d;
    cout << "请输入时间 时 分 秒" << endl;
    cin >> h >> min >> s;
    ClockWithDate p(h,min,s,y,m,d);
    p.showDate_Time();
    while(1){
        int now=gettime();
        if(now- lasttime >= 1){
            p.addS();
            p.showDate_Time();
            lasttime = now;
        }
    }
    return 0;
}