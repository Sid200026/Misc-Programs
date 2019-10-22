#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *link;
};

class linked_list
{
private:
    node *head,*cur,*prev;
public:
    linked_list();
    void addbegin(int);
    void add(int,int);
    void traverse();
    void odd_even();
    void deletebegin();
    void deletepos(int);
    node* reverse(node*);
    void rev();
};

linked_list::linked_list()
{
    head = NULL;
    cur = head;
    prev = head;
}

node* linked_list::reverse(node* a)
{
    if(a->link = NULL)
    {
        head = a;
        return a;
    }
    else
    {
        node* temp = reverse(a);
        a->link = NULL;
        temp->link;
    }
    
}

void linked_list::addbegin(int item)
{
    node *temp = new node;
    temp->data = item;
    temp->link = head;
    head = temp;
}

void linked_list::add(int item, int pos)
{
    int position = 0;
    cur = head;
    while(pos!=position)
    {
        position++;
        cur = cur->link;
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
        temp->link = NULL;
        head = temp;
        return;
    }
    temp->link = cur->link;
    cur->link = temp;
}

void linked_list::traverse()
{
    cur = head;
    while(cur!=NULL)
    {
        cout<<cur->data<<" ";
        cur = cur->link;
    }
}

void linked_list::deletebegin()
{
    cur = head;
    if(head->link!=NULL)
    {
        head = head->link;
        delete cur;
    }
    else
    {
        delete head;
    }
}

void linked_list::deletepos(int pos)
{
    int position = 0;
    prev = head;
    cur = head;
    while(pos!=position)
    {
        position++;
        cur = cur->link;
        if(cur==NULL)
        {
            cout<<"Position out of bounds\n";
            return;
        }
    }
    if(cur==head)
    {
        head = cur->link;
    }
    prev->link = cur->link;
    delete cur;
}

void linked_list::odd_even()
{
    cur = head;
    int count = 0;
    while(cur!=NULL && cur->link!=NULL)
    {
        if(cur->data%2==0)
        {
            addbegin(cur->data);
            deletepos(count);
        }
        cur = cur->link;
    }
}

void linked_list::rev()
{
    reverse(head);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    linked_list ll;
    ll.addbegin(1);
    ll.addbegin(2);
    ll.addbegin(3);
    ll.addbegin(4);
    ll.addbegin(5);
    //ll.odd_even();
    ll.rev();
    //ll.traverse();
    return 0;
}