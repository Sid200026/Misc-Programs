#include<iostream>
using namespace std;
int dp[100][100];

int matrix_mult(int arr[], int i, int j)
{
    if(i==j)
    {
        return 0;
    }
    else
    {
        int min = 100000;
        int count;
        for(int k = i; k<j; k++ )
        {
            if(dp[i][k]!=-1)
                return dp[i][k];
            count = matrix_mult(arr, i, k) + matrix_mult(arr, k+1, j) + arr[i-1] * arr[k] * arr[j];
            if(count<min)
            {
                 min = count;
            }
            dp[i][k] = min;
        }
        return min;
    }
    
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n; i++)
    {
        cin>>arr[i];
    }
    for(int i = 0;i<n;i++)
    {
        for(int j = 0; j<n;j++)
            dp[i][j] = -1;
    }
    cout<<matrix_mult(arr, 1, n-1);
}