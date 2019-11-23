#include<iostream>
using namespace std;
// int main()
// {
//     int n;
//     cin>>n;
//     int dp[n];
//     dp[0] = 0;
//     dp[1] = 1;
//     for(int i = 2; i<n; i++)
//     {
//         dp[i] = dp[i-1] + dp[i-2];
//     }
//     cout<<dp[n-1];
// }
int dp[100];
int fib(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    else
    {
        if(dp[n] != -1)
            return dp[n];
        else
        {
            dp[n]=fib(n-1)+fib(n-2);
            return dp[n];
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i = 0;i<100;i++)
    {
        dp[i] = -1;
    }
    cout<<fib(n-1);
}