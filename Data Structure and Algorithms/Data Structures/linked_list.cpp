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
    node *cur,*prev;
public:
    node *head;
    linked_list();
    void addbegin(int);
    void add(int,int);
    void traverse();
    void deletebegin();
    void deletepos(int);
    node *reverse(node*);
};

linked_list::linked_list()
{
    head = NULL;
    cur = head;
    prev = head;
}

node *linked_list::reverse(node *temp)
{
    if(temp == NULL || temp->link == NULL)
    {
        head = temp;
        return temp;
    }
    else
    {
        node *ans = reverse(temp->link);
        ans->link = temp;
        temp->link = NULL;
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
        prev = cur;
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