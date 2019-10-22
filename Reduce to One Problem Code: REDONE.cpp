#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t;
    cin>>t;
    long long int fact[1000001];
    fact[0] = 1;
    for(int i=1;i<1000001;i++)
    {
        fact[i] = (fact[i-1] * i)%1000000007;
    }
    while(t--)
    {
        long long int n;
        cin>>n;
        cout<<(fact[n+1]-1)%1000000007<<"\n";
    }
    return 0;
}