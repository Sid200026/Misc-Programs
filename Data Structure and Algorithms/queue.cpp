#include<iostream>
using namespace std;

class queue
{
    private:
        int arr[20];
        int rear;
        int front;
    public:
        queue();
        bool isEmpty();
        bool isFull();
        void push(int);
        int pop();
};

queue::queue()
{
    rear = -1;
    front = -1;
}

bool queue::isEmpty()
{
    return ((rear==front && front==-1) || (rear>front));
}

bool queue::isFull()
{
    return front==19;
}

void queue::push(int data)
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

int queue::pop()
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    queue q;
    q.push(5);
    q.push(6);
    q.push(7);
    int a = 4;
    while(a--)
        cout<<q.pop()<<"\n";
    return 0;
}