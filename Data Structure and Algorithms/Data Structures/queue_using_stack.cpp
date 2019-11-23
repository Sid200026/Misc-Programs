#include<bits/stdc++.h>
using namespace std;

class queue_using_stack
{
private:
    int top;
    int arr[20];
public:
    queue_using_stack();
    bool isEmpty();
    bool isFull();
    void Push(int);
    int Pop();
    int GetTop();
};
 
queue_using_stack::queue_using_stack()
{
    top = -1;
}

bool queue_using_stack::isEmpty()
{
    return top == -1;
}

bool queue_using_stack::isFull()
{
    return top == 19;
}

void queue_using_stack::Push(int data)
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

int queue_using_stack::Pop()
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

int queue_using_stack::GetTop()
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
    queue_using_stack qs1, qs2;
    while (1)
    {
        cout<<"1.Push\n2.Pop\n3.Exit\nEnter your choice\n";
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                int data;
                cin>>data;
                qs1.Push(data);
                break;
            }
            case 2:
            {
                if(qs2.isEmpty())
                {
                    while(!qs1.isEmpty())
                    {
                        qs2.Push(qs1.Pop());
                    }
                }
                int temp = qs2.Pop();
                if(temp!=-1)
                    cout<<"Pop Value: "<<temp<<endl;
                break;
            }
            case 3:
            {
                exit(0);
            }
            default:
            {
                cout<<"Wrong Choice\n";
            }
        }
    }
    return 0;
}