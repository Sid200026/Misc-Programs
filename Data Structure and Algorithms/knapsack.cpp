#include<iostream>
using namespace std;

int dp[100][100];

int knapsack(int wt[], int val[], int n, int tot)
{
    if(tot == 0 || n==0)
    {
        return 0;
    }
    else
    {
        if(tot<wt[n-1])
            return knapsack(wt, val, n-1, tot);
        else
        {
            if(dp[n-1][tot] != -1)
                return dp[n-1][tot];
            dp[n-1][tot] = max(val[n-1] + knapsack(wt, val, n-1, tot - wt[n-1]), knapsack(wt, val, n-1, tot));
            return dp[n-1][tot];
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int wt[n];
    int val[n];
    for(int i = 0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
    }
    int tot;
    cin>>tot;
    for(int i = 0;i <=tot; i++)
        for(int j = 0; j<=n;j++)
            dp[j][i] = -1;
    cout<<knapsack(wt, val, n, tot);
}