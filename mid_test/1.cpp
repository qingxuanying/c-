#include <iostream>
#include <math.h>
using namespace std;

class Date
{
private:
    int year = 0;
    int month = 0;
    int day = 0;

public:
    void show()
    {
        cout << "年:" << year << "    月:" << month << "  日:" << day << endl;
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
            day = 1;
            month = 3;
        }
        if (month == 2 && day == 30 && year % 4 == 0)
        {
            day = 1;
            month = 3;
        }
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            if (day == 32)
            {
                day == 1;
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
                day == 1;
                month++;
            }
        }
    };
};
int main()
{
    int y, m, d;
    cout << "请输入日期 年 月 日" << endl;
    cin >> y >> m >> d;
    Date P(y, m, d);
    P.show();
    P.NewDay();
    P.show();
    return 0;
}