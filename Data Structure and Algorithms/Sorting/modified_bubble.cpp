#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for(int i = 0;i<n-1;i++)
    {
        bool sorted = false;
/*         for(int j=0;j<n-1;j++)
        {
            if(arr[j+1]>arr[j])
            {
                swap(arr[j], arr[j+1]);
                sorted = true;
            }
        } */
        for(int j=n-1;j>0;j--)
        {
            if(arr[j]>arr[j-1])
            {
                swap(arr[j], arr[j-1]);
                sorted = true;
            }
        }
        if(sorted == false)
            break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {5,6,8,2,1,3,6,4};
    int n = 8;
    bubbleSort(arr, n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}