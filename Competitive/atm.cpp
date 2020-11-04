#include <iostream>
using namespace std;

class UDtime
{
    int hours;
    int min;
    int sec;

public:
    bool operator<(UDtime &);
    friend istream &operator>>(istream &, UDtime &);
    friend ostream &operator<<(ostream &, UDtime &);
};

bool UDtime::operator<(UDtime &a)
{
    if (this->hours < a.hours)
    {
        return true;
    }
    else if (this->hours > a.hours)
    {
        return false;
    }
    if (this->min < a.min)
    {
        return true;
    }
    else if (this->min > a.min)
    {
        return false;
    }
    if (this->sec < a.sec)
    {
        return true;
    }
    return false;
}

class emp
{
    int empid;
    char name[20];
    UDtime arr_Time;

public:
    friend istream &operator>>(istream &, emp &);
    friend ostream &operator<<(ostream &, emp &);
    UDtime get_Time();
    void operator[](int);
};

UDtime emp::get_Time()
{
    return this->arr_Time;
}

void emp::operator[](int i)
{
}

ostream &operator<<(ostream &out, UDtime &c)
{
    out << c.hours << endl << c.min << endl << c.sec;
    return out;
}
i
ostream &operator<<(ostream &out, emp &c)
{
    out << c.empid << endl << c.name << endl << c.arr_Time << endl;
    return out;
}

istream &operator>>(istream &in, UDtime &c)
{
    in >> c.hours >> c.min >> c.sec;
    return in;
}

istream &operator>>(istream &in, emp &c)
{
    in >> c.empid >> c.name >> c.arr_Time;
    return in;
}

int main()
{
    int num;
    emp e[20];
    UDtime exp_Arr_Time;
    UDtime a_Time;
    cin >> num;
    for (int k = 0; k < num; k++)
        cin >> e[k];
    cin >> exp_Arr_Time;
    for (int j = 0; j < num; j++)
    {
        a_Time = e[j].get_Time();
        if (exp_Arr_Time < a_Time)
            cout << e[j];
    }
}
