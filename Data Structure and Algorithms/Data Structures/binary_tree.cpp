#include<iostream>
using namespace std;

struct node
{
    int key;
    node *left;
    node *right;
    node *parent;
};

class binary_tree
{
private:
    node *root;
    node * insert(int, node *);
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
    node* searchtree(int,node *);
    node* findmintree(node *);
    node* findmaxtree(node *);
    void deletetree(int, node *);
public:
    binary_tree();
    void add(int);
    void inorderprint();
    void preorderprint();
    void postorderprint();
    void search(int);
    int findmin();
    int findmax();
    void deletetreehome(int);
};

binary_tree::binary_tree()
{
    root = NULL;
}   

node* binary_tree::findmaxtree(node *temp)
{
    if(temp->right==NULL)
    {
        return temp;
    }
    else
    {
        return findmaxtree(temp->right);
    }   
}

node* binary_tree::findmintree(node *temp)
{
    if(temp->left==NULL)
    {
        return temp;
    }
    else
    {
        return findmintree(temp->left);
    }
    
}

node* binary_tree::searchtree(int data, node *temp)
{
    if(temp==NULL)
    {
        cout<<"Cannot find data\n";
    }
    else
    {
        if(data==temp->key)
        {
            cout<<"Found\n";
        }
        else if(data>temp->key)
        {
            return searchtree(data, temp->right);
        }
        else
        {
            return searchtree(data, temp->left);
        }
    }
    return temp;
}

void binary_tree::inorder(node *temp)
{
    if(temp==NULL)
    {
        return;
    }
    else
    {
        inorder(temp->left);
        cout<<temp->key<<" ";
        inorder(temp->right);
    }
}

void binary_tree::preorder(node *temp)
{
    if(temp==NULL)
    {
        return;
    }
    else
    {
        cout<<temp->key<<" ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

void binary_tree::postorder(node *temp)
{
    if(temp==NULL)
    {
        return;
    }
    else
    {
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->key<<" ";
    }
}

node * binary_tree::insert(int data, node *temp)
{
    node *a = temp;
    if(temp==NULL)
    {
        a = new node;
        a->key = data;
        a->left = NULL;
        a->right = NULL;
    }
    else
    {
        if(temp->key>data)
        {
            a->left = insert(data, temp->left);
            a->left->parent = temp;
        }
        else
        {
            a->right = insert(data, temp->right);
            a->right->parent = temp;
        }
    }
    if(root==NULL)
        root = a;
    return a;
}

void binary_tree::deletetree(int data, node * temp)
{
    node* temp = searchtree(data, temp);
    if(temp->left==NULL && temp->right==NULL)
        delete temp;
    else
    {
        if(temp->left==NULL)
        {
            temp->key = temp->right->key;
            delete temp->right;
        }
        else if(temp->right==NULL)
        {
            temp->key = temp->left->key;
            delete temp->left;
        }
        else
        {
            node* temp1 = findmintree(temp->right);
            data = temp->key;
            temp->key = temp1->key;
            deletetree(data,temp->right);
        }
    }
}

void binary_tree::inorderprint()
{
    inorder(root);
    cout<<"\n";
}

void binary_tree::add(int data)
{
    insert(data, root);
}

void binary_tree::preorderprint()
{
    preorder(root);
    cout<<"\n";
}

void binary_tree::postorderprint()
{
    postorder(root);
    cout<<"\n";
}

void binary_tree::search(int data)
{
    searchtree(data, root);
}

int binary_tree::findmax()
{
    return findmaxtree(root)->key;
}

int binary_tree::findmin()
{
    return findmintree(root)->key;
}

void binary_tree::deletetreehome(int data)
{
    deletetree(data, head);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    binary_tree bt;
    bt.add(10);
    bt.add(8);
    bt.add(11);
    bt.add(15);
    bt.add(9);
    bt.add(2);
    bt.add(3);
    bt.add(0);
    bt.inorderprint();
    bt.preorderprint();
    bt.postorderprint();
    bt.search(5);
    bt.search(11);
    bt.search(10);
    cout<<bt.findmax()<<"\n";
    cout<<bt.findmin()<<"\n";
    return 0;
}