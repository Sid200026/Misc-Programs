#include<iostream>
using namespace std;

class stackQueue
{
private:
    int top;
    int front;
    int rear;
    int arr[2];
public:
    stackQueue();
    bool isEmpty();
    bool isFull();
    void Push(int);
    int Pop();
    int GetTop();
    bool isQEmpty();
    bool isQFull();
    void push(int);
    int pop();
};
 
stackQueue::stackQueue()
{
    top = 50;
    rear = -1;
    front = -1;
}

bool stackQueue::isEmpty()
{
    return top == 50;
}

bool stackQueue::isQEmpty()
{
    return ((rear==front && front==-1) || (rear>front));
}

bool stackQueue::isFull()
{
    return top == rear;
}

bool stackQueue::isQFull()
{
    return top==rear;
}

void stackQueue::Push(int data)
{
    if(!isFull())
    {
        arr[--top] = data;
    }
    else
    {
        cout<<"Overflow\n";
    }
}

int stackQueue::Pop()
{
    if(!isEmpty())
    {
        return arr[top++];
    }
    else
    {
        cout<<"Underflow\n";
        return -1;
    }
}

void stackQueue::push(int data)
{
    if(!isFull())
    {
        if(front==-1)
            rear++;
        arr[++front] = data;
    }
    else
    {
        cout<<"Overflow\n";
    }
}

int stackQueue::pop()
{
    if(!isEmpty())
    {
        return arr[rear++];
    }
    else
    {
        cout<<"Underflow\n";
    }
    return -1;
}

int stackQueue::GetTop()
{
    if(!isEmpty())
    {
        return arr[top];
    }
    else
    {
        cout<<"Empty\n";
    }
    return -1;  
}

int main()
{
    stackQueue sq;
    sq.push(1);
    sq.Push(3);
    sq.push(2);
    sq.Push(4);
    cout<<sq.pop()<<endl;
    cout<<sq.pop()<<endl;
    cout<<sq.Pop()<<endl;
    cout<<sq.Pop()<<endl;
    return 0;
}