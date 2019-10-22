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
    int search(int);
    void deletepos(int);
    void traverse();
};

linked_list::linked_list()
{
    head = NULL;
    cur = head;
    prev = head;
}

void linked_list::traverse()
{
    cur = head;
    while(cur!=NULL)
    {
        cout<<cur->data<<" ";
        cur = cur->link;
    }
    cout<<endl;
}

void linked_list::addbegin(int item)
{
    node *temp = new node;
    temp->data = item;
    temp->link = head;
    head = temp;
}

int linked_list::search(int val)
{
    int count = 0;
    cur = head;
    while(cur!=NULL)
    {
        if(cur->data == val)
            return count;
        count++;
        cur = cur->link;
    }
    return -1;
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

int hashfunc(int key, int size)
{
    int value = key;
    return value % size;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[5] = {400, 0, 600, 1, 2};
    linked_list hash[200];
/*     for(int i= 0;i<200;i++)
    {
        hash[i] = -1;
    } */
    for(int j=0;j<5;j++)
    {
        int index = hashfunc(arr[j], 200);
        hash[index].addbegin(arr[j]);
    }
    for(int i = 0;i<200;i++)
    {
/*         if(hash[i]==-1)
            continue; */
        if(hash[i].head == NULL)
            continue;
        hash[i].traverse();
    }

    int z = 600;
    int ind = hashfunc(z, 200);
    int res = hash[ind].search(z);
    if(res == -1)
        cout<<"Not found";
    else
    {
        hash[ind].deletepos(res);
        hash[ind].traverse();
    }
    return 0;
}




