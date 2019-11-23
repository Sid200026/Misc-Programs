#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int first, int mid, int last)
{
    int left[100];
    int leftcount = 0;
    for(int i = first; i <=mid; i++)
    {
        left[leftcount++] = arr[i];
    }
    int right[100];
    int rightcount = 0;
    for(int i = mid+1; i<=last;i++)
    {
        right[rightcount++] = arr[i];
    }
    int i=0,j=0;
    while(i<leftcount && j<rightcount)
    {
        if(left[i]<right[j])
        {
            arr[first++] = left[i++];
        }
        else
        {
            arr[first++] = right[j++];
        }
    }
    while(i<leftcount)
        arr[first++] = left[i++];
    while(j<rightcount)
        arr[first++] = right[j++];
}

void mergesort(int arr[], int first, int last)
{
    if(first<last)
    {
        int mid = (first+last)/2;
        mergesort(arr, first, mid);
        mergesort(arr, mid+1, last);
        merge(arr, first, mid, last);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[10] = {9,8,7,6,5,4,3,2,1,0};
    mergesort(arr, 0, 9);
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}