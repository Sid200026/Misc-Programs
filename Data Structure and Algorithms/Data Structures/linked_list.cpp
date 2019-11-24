#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};

class linked_list
{
private:
    node *cur,*prev;
public:
    node *head;
    linked_list();
    void addbegin(int);
    void add(int,int);
    void addend(int);
    void traverse();
    void deletebegin();
    void deletepos(int);
    void deleteend();
    bool search(int);
    void swap(int);
};

linked_list::linked_list()
{
    head = NULL;
    cur = head;
    prev = head;
}

void linked_list::swap(int pos)
{
    int position = 0;
    cur = head;
    prev = head;
    while(pos!=position)
    {
        prev = cur;
        position++;
        cur = cur->next;
        if(cur == NULL)
        {
            cout<<"Out of bounds";
            return;
        }
    }
    prev->next = cur->next;
    cur->next = cur->next->next;
    prev->next->next = cur;
}

bool linked_list::search(int data)
{
    cur = head;
    while(cur->data!=data)
    {
        cur = cur->next;
        if(cur==NULL)
        {
            return false;
        }
    }
    return true;
}

void linked_list::deleteend()
{
    cur = head;
    prev = head;
    while(cur->next!=NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
    delete cur;
}

void linked_list::addbegin(int item)
{
    node *temp = new node;
    temp->data = item;
    temp->next = head;
    head = temp;
}

void linked_list::add(int item, int pos)
{
    int position = 0;
    cur = head;
    while(pos!=position)
    {
        position++;
        cur = cur->next;
        if(cur==NULL)
        {
            cout<<"Position out of bounds\n";
            return;
        }
    }
    node *temp = new node;
    temp->data = item;
    if(head==NULL)
    {
        temp->next = NULL;
        head = temp;
        return;
    }
    temp->next = cur->next;
    cur->next = temp;
}

void linked_list::addend(int data)
{
    cur = head;
    while(cur->next!=NULL)
    {
        cur = cur->next;
    }
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;
    cur->next = temp;
}

void linked_list::traverse()
{
    cur = head;
    while(cur!=NULL)
    {
        cout<<cur->data<<" ";
        cur = cur->next;
    }
}

void linked_list::deletebegin()
{
    cur = head;
    head = head->next;
    delete cur;
}

void linked_list::deletepos(int pos)
{
    int position = 0;
    prev = head;
    cur = head;
    while(pos!=position)
    {
        prev = cur;
        position++;
        cur = cur->next;
        if(cur==NULL)
        {
            cout<<"Position out of bounds\n";
            return;
        }
    }
    prev->next = cur->next;
    delete cur;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    linked_list ll;
    ll.addbegin(3);
    ll.addbegin(2);
    ll.addbegin(1);
    ll.addbegin(0);
    ll.traverse();
    ll.reverse(ll.head);
    cout<<endl;
    ll.traverse();
    return 0;
}