#include<iostream>
using namespace std;
int dp[100];

int catalan(int n)
{
    if(n==0)
        return 1;
    else
    {
        int sum = 0;
        if(dp[n] != -1)
        {
            return dp[n];
        }
        for(int i = 0; i<=n-1; i++)
        {
            sum+= catalan(i)*catalan(n-i-1);
        }
        dp[n] = sum;
        return dp[n];
    }
    
}

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i<100; i++)
    {
        dp[i] = -1; // To show that the array values at that index is empty
    }
    cout<<catalan(n-1);
}