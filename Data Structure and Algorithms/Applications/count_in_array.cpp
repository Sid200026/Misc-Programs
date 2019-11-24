#include<iostream>
using namespace std;

int count1(int arr[], int start, int end)
{
    if(start>=end)
        return 0;
    else
    {
        int mid = (start + end)/2;
        int val = (arr[mid]==1);
        return val + count1(arr, start, mid) + count1(arr,mid+1,end);
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<count1(arr,0,n);
}