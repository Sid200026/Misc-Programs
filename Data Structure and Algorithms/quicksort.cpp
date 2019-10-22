#include<bits/stdc++.h>
using namespace std;

/* Let the partition index be the first one */

int partition(int arr[], int first, int last)
{
    int i = first + 1;
    int index = last;
    int pivot = arr[first];
    for(;i<last;i++)
    {
        if(arr[i]<pivot)
        {
            int temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
            index-- ;
        }
    }    
    int temp = arr[i];
    arr[i] = arr[index];
    arr[index] = temp;
    return index;
}

void quicksort(int arr[], int first, int last)
{
    last = last;
    if(first<last)
    {
        int a = partition(arr,first,last);
        quicksort(arr, first, a-1);
        quicksort(arr,a+1,last);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[10] = {5,9,2,1,4,6,5,8,7,11};
    quicksort(arr, 0, 9);
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}