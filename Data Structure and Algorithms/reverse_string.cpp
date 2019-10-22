#include<iostream>
#include<cstring>
using namespace std;

class stack
{
private:
    int top;
    char arr[20];
public:
    stack();
    bool isEmpty();
    bool isFull();
    void Push(char);
    char Pop();
    char GetTop();
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

void stack::Push(char data)
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

char stack::Pop()
{
    if(!isEmpty())
    {
        return arr[top--];
    }
    else
    {
        cout<<"Underflow\n";
        return '1';
    }
}

char stack::GetTop()
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
    string s;
    cin>>s;
    stack s1;
    for(int i=0;i<s.length();i++)
    {
        s1.Push(s[i]);
    }
    while(!s1.isEmpty())
    {
        cout<<s1.Pop();
    }
}