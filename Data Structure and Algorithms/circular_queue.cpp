#include<iostream>
using namespace std;

class circular_queue
{
private:
    int arr[5];
    int front,rear;
public:
    circular_queue();
    bool isEmpty();
    bool isFull();
    void push(int);
    int pop();
};

circular_queue::circular_queue()
{
    front = -1;
    rear = -1;
}

bool circular_queue::isEmpty()
{
    return (rear==-1);
}

bool circular_queue::isFull()
{
    return((front==4 && rear==0) || (front==(rear-1) && rear!= 0));
}

void circular_queue::push(int data)
{
    if(rear==-1)
        rear=0;
    if(!isFull())
    {
        if(front==4)
            front=-1;
        arr[++front] = data;
    }
    else
    {
        cout<<"Overflow\n";
    }
}

int circular_queue::pop()
{
    if(!isEmpty())
    {
        int temp = arr[rear];
        if(rear==4)
            rear = 0;
        if(front==rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {   
            rear++;
        }
        return temp;    
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    circular_queue q1;
    for(int i=0;i<7;i++)
        q1.push(i);
    cout<<q1.pop()<<" ";
    cout<<q1.pop()<<" ";
    q1.push(25);
    while(!q1.isEmpty())
        cout<<q1.pop()<<" ";
    return 0;
}