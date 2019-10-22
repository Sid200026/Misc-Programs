#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int i, int n)
{
    int maxindex = i;
    int leftindex = 2*i + 1;
    int rightindex = 2*i + 2;
    if(leftindex < n)
    {
        if(arr[maxindex] < arr[leftindex])
        {
            maxindex = leftindex;
        }
    }
    if(rightindex < n) 
    {
        if(arr[maxindex] < arr[rightindex])
        {
            maxindex = rightindex;
        }
    }
    int temp = arr[maxindex];
    arr[maxindex] = arr[i];
    arr[i] = temp;
    if(maxindex!=i)
        heapify(arr, maxindex, n);
}

void build_max_heap(int arr[], int n)
{
    for(int i = n/2-1;i>=0;i--)
    {
        heapify(arr, i, n);
    }
}

void insert(int arr[], int val, int ind)
{
    arr[ind] = val;
    int parent = (ind-1)/2;
    while(true)
    {
        heapify(arr, parent, ind+1);
        if(parent == 0)
            break;
        parent = (parent-1)/2;
    }
}

int del(int arr[], int n)
{
    int val = arr[0];
    int temp = arr[n-1];
    arr[n-1] = arr[0];
    arr[0] = temp;
    n--;
    heapify(arr, 0, n);
    return val;
}

void heapsort(int arr[], int n)
{
    for(int i= n-1;i>=0;i--)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        heapify(arr, 0, i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x = 5;
    int arr[100] = {3, 5, 2, 1, 6};

    build_max_heap(arr, x);
/*     insert(arr, 9, x);
    x++;

    cout<<del(arr, x)<<endl;
    x--; */

    heapsort(arr, x);

    for(int i=0;i<x;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}