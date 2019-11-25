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

int main()
{
    stack s1, s2;
    while(true)
    {
        cout<<"1. Enqueue\n";
        cout<<"2. Dequeue\n";
        cout<<"3. Exit\n";
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1: // Enqueue
            {
                int data;
                cin>>data;
                s1.push(data);
                break;
            }
            case 2: //Dequeue
            {
                if(s2.isEmpty())
                {
                    while(!s1.isEmpty())
                    {
                        s2.push(s1.pop());
                    }
                }
                cout<<s2.pop();
                break;
            }
            case 3:
                exit(0);
            default:
                cout<<"Wrong Choice";
        }
    }
}