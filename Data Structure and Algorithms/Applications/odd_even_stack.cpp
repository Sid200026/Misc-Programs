#include<iostream>
using namespace std;

class stack
{
private:
    int top;
    int arr[20];
public:
    stack();
    bool isEmpty();
    bool isFull();
    void Push(int);
    int Pop();
    int GetTop();
};
 
stack::stack()
{
    top = -1;
}

bool stack::isEmpty()
{
    return top == -1;
}

bool stack::isFull()
{
    return top == 19;
}

void stack::Push(int data)
{
    if(!isFull())
    {
        arr[++top] = data;
    }
    else
    {
        cout<<"Overflow\n";
    }
}

int stack::Pop()
{
    if(!isEmpty())
    {
        return arr[top--];
    }
    else
    {
        cout<<"Underflow\n";
        return -1;
    }
}

int stack::GetTop()
{
    if(!isEmpty())
    {
        return arr[top];
    }
    else
    {
        cout<<"Empty\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack s1,s2;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        if(data%2==0)
            s1.Push(data);
        else
            s2.Push(data);
    }
    while(!s1.isEmpty())
    {
        s2.Push(s1.Pop());
    }
    while(!s2.isEmpty())
    {
        cout<<s2.Pop()<<" "; 
    }
    return 0;
}