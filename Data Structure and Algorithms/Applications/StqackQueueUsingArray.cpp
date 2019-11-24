#include<iostream>
using namespace std;
#define arrsize 20

class stackQueue
{
private:
    int top;
    int front;
    int rear;
    int arr[20];
public:
    stackQueue();
    bool isEmpty();
    bool isFull();
    void Push(int);
    int Pop();
    int GetTop();
    bool isQEmpty();
    void push(int);
    int pop();
};
 
stackQueue::stackQueue()
{
    top = -1;
    rear = -1;
    front = -1;
}

bool stackQueue::isEmpty()
{
    return top == -1;
}

bool stackQueue::isQEmpty()
{
    return ((rear==front && front==-1) || (front>rear));
}

bool stackQueue::isFull()
{
    return top + rear == arrsize - 2;
}

void stackQueue::Push(int data)
{
    if(!isFull())
    {
        arr[arrsize-1-(++top)] = data;
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
        return arr[arrsize-1-(top--)];
    }
    else
    {
        cout<<"Underflow\n";
        return -1;
    }
}

void stackQueue::push(int data) //enqueue
{
    if(!isFull())
    {
        if(rear==-1)
            front=0;
        arr[++rear] = data;
    }
    else
    {
        cout<<"Overflow\n";
    }
}

int stackQueue::pop() //dequeue
{
    if(!isQEmpty())
    {
        return arr[front++];
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
        return arr[arrsize - 1 -top];
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