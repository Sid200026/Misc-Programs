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
        void enqueue(int);
        int dequeue();
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

void queue::enqueue(int data)
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

int queue::dequeue()
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
    queue q1, q2;
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
                q1.enqueue(data);
                break;
            }
            case 2:
            {
                while(!q1.isEmpty())
                {
                    int ele = q1.dequeue();
                    if(q1.isEmpty())
                    {
                        cout<<ele<<endl;
                        break;
                    }
                    q2.enqueue(q1.dequeue());
                }
                while(!q2.isEmpty())
                {
                    q1.enqueue(q2.dequeue());
                }
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