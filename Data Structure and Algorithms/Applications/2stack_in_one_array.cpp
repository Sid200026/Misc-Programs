#include<iostream>
using namespace std;
#define sizearr 20

class twostack
{
    int top1, top2;
    int arr[20];
    public:
        twostack();
        bool empty1();
        bool empty2();
        bool isFull();
        void push1(int);
        void push2(int);
        int pop1();
        int pop2();
};

twostack::twostack()
{
    top1 = -1;
    top2 = -1;
}

bool twostack::empty1()
{
    return (top1 == -1);
}

bool twostack::empty2()
{
    return (top2 == -1);
}

bool twostack::isFull()
{
    return (top1 + top2 == sizearr - 2);
}

void twostack::push1(int ele)
{
    if(isFull())
    {
        cout<<"Overflow";
    }
    else
    {
        arr[++top1] = ele;
    }
}

void twostack::push2(int ele)
{
    if(isFull())
    {
        cout<<"Overflow";
    }
    else
    {
        arr[sizearr-1-(++top2)] = ele;
    }
}

int twostack::pop1()
{
    if(empty1())
    {
        cout<<"Underflow";
    }
    else
    {
        return arr[top1--];
    }
}

int twostack::pop2()
{
    if(empty2())
    {
        cout<<"Underflow";
    }
    else
    {
        return arr[sizearr-1-(top2--)];
    }
}

int main()
{
    twostack stack12;
    stack12.push1(1);
    stack12.push1(2);
    stack12.push1(3);
    stack12.push2(4);
    stack12.push2(5);
    cout<<stack12.pop1();
    cout<<stack12.pop2();
}