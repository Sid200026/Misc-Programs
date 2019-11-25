#include<iostream>
using namespace std;
#define arrsize 20
class stack
{
    int top;
    int arr[20];
    public:
        stack();
        bool isEmpty();
        bool isFull();
        void push(int);
        int pop();
        int peep();
        stack sortstack();
};
stack::stack()
{
    top = -1;
}

bool stack::isEmpty()
{
    return top==-1;
}

bool stack::isFull()
{
    return top==arrsize-1;
}

void stack::push(int data)
{
    if(isFull())
        cout<<"Overflow";
    else
    {
        arr[++top] = data;
    }
}

int stack::pop()
{
    if(isEmpty())
        cout<<"Underflow";
    else
    {
        return arr[top--];
    }
}

int stack::peep()
{
    if(isEmpty())
        cout<<"Underflow";
    else
    {
        return arr[top];
    }
}

stack stack::sortstack()
{
    stack s1; //temporary stack to help in sorting
    while(!isEmpty())
    {
        int ele = pop();
        if(s1.isEmpty())
        {
            s1.push(ele);
        }
        else
        {
            while(!s1.isEmpty() && s1.peep()>ele)
            {
                push(s1.pop());
            }
            s1.push(ele);
        }
    }
    return s1;
}

int main()
{
    stack s;
    s.push(5);
    s.push(3);
    s.push(11);
    s.push(4);
    stack sorted = s.sortstack();
    while(!sorted.isEmpty())
    {
        cout<<sorted.pop()<<" " ;
    }
}