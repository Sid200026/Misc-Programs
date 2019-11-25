#include<iostream>
using namespace std;

/* Let the partition index be the first one */

int partition(int arr[], int first, int last)
{
    int i = first + 1;
    int index = last;
    int pivot = arr[first];
    for(;i<=index;i++)
    {
        if(arr[i]>pivot)
        {
            int temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
            index-- ;
            i--;
        }
    }    
    int temp = arr[first];
    arr[first] = arr[index];
    arr[index] = temp;
    return index;
}

void quicksort(int arr[], int first, int last)
{
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
    int arr[20] = {5,4,3,2,1,4,5,6,4,3,7,7,9};
    quicksort(arr, 0, 13);
    for(int i=0;i<=13;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}