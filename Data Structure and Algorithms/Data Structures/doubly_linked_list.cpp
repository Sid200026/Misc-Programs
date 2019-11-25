#include<iostream>
using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
};

class doubly_linked_list
{
private:
    node *head,*cur;
public:
    doubly_linked_list();
    void traverse();
    void addAtStart(int);
    int deletepos(int);
    void addAtPos(int, int);
};

doubly_linked_list::doubly_linked_list()
{
    head = NULL;
    cur = head;
}

void doubly_linked_list::addAtPos(int data, int pos)
{
    int position = 0;
    cur = head;
    while(pos!=position)
    {
        position++;
        cur = cur->next;
        if(cur==NULL)
        {
            cout<<"Out of bounds";
            return;
        }
    }
    node *temp = new node;
    temp->data = data;
    temp->prev = cur;
    temp->next = cur->next;
    cur->next->prev = temp;
    cur->next = temp;
}

void doubly_linked_list::traverse()
{
    cur = head;
    while(cur!=NULL)
    {
        cout<<cur->data<<" ";
        cur = cur->next;
    }

}

int doubly_linked_list::deletepos(int pos)
{
    cur = head;
    int position = 0;
    while(pos!=position)
    {
        position++;
        cur = cur->next;
        if(cur == NULL)
        {
            cout<<"Out of bounds";
            return;
        }
    }
    // cur is the one that I will delete
    cur->prev->next = cur->next;
    delete cur;
}

void doubly_linked_list::addAtStart(int item)
{
    node *temp = new node;
    temp->data = item;
    temp->prev = NULL;
    if(head==NULL)
    {
        head=temp;
        head->next = NULL;
        return;
    }
    temp->next = head;
    head = temp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    doubly_linked_list dll;
    dll.addAtStart(1);
    dll.addAtStart(2);
    dll.traverse();
    return 0;
}