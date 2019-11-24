#include<iostream>
using namespace std;
#define arrsize 20

class twoqueue
{
    int front1, rear1;
    int front2, rear2;
    int arr[20];
    public:
        twoqueue();
        bool isEmpty1();
        bool isEmpty2();
        bool isFull();
        void enqueue1(int);
        void enqueue2(int);
        int dequeue1();
        int dequeue2();
};

twoqueue::twoqueue()
{
    front1 = -1;
    rear1 = -1;
    rear2 = -1;
    front2 = -1;
}

// bool twoqueue::isEmpty()
// {
//     if(front1 == -1 && front2 == arrsize)
//         return true;
//     else
//     {
//         return false;
//     }
// }

bool twoqueue::isEmpty1()
{
    return ((front1==rear1 && rear1==-1) || front1>rear1);
}

bool twoqueue::isEmpty2()
{
    return ((front2==rear2 && front2==-1) || front2>rear2);
}

bool twoqueue::isFull()
{
    return rear1+rear2 == arrsize-2;
}

void twoqueue::enqueue1(int ele)
{
    if(isFull())
    {
        cout<<"Overflow";
    }
    else
    {
        if(front1==-1)
            front1 = 0;
        arr[++rear1] = ele;
    }
}

void twoqueue::enqueue2(int ele)
{
    if(isFull())
    {
        cout<<"Overflow";
    }
    else
    {
        if(front2==-1)
            front2 = 0;
        rear2++;
        arr[arrsize - rear2 - 1] = ele;
    }
}

int twoqueue::dequeue1()
{
    if(isEmpty1())
        cout<<"Underflow";
    else
    {
        return arr[front1++];
    }
}

int twoqueue::dequeue2()
{
    if(isEmpty2())
        cout<<"Underflow";
    else
    {
        return arr[arrsize-1-front2++];
    }
}

int main()
{
    twoqueue tq;
    tq.enqueue1(1);
    tq.enqueue2(2);
    tq.enqueue1(3);
    cout<<tq.dequeue1();
    cout<<tq.dequeue2();
}