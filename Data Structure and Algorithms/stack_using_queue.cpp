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
    queue q1,q2;
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
                q1.push(data);
                break;
            }
            case 2:
            {
                if(q1.isEmpty())
                {
                    cout<<"Empty\n";
                    break;
                }
                while(!q1.isEmpty())
                {
                    int temp = q1.pop();
                    if(q1.isEmpty())
                        cout<<"Popped Value"<<temp<<endl;
                    else
                        q2.push(temp);
                }
                while(!q2.isEmpty())
                {
                    q1.push(q2.pop());
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