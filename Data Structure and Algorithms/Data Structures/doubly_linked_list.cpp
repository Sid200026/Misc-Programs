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
};

doubly_linked_list::doubly_linked_list()
{
    head = NULL;
    cur = head;
}

void doubly_linked_list::traverse()
{
    cur = head;
    if(cur==NULL)
        return;
    while(cur->next!=NULL)
    {
        cout<<cur->data<<" ";
        cur = cur->next;
    }
    cout<<cur->data<<"\n";
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