#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int k,n,a,b;
        cin>>n>>a>>b>>k;
        int lcm = (a*b)/__gcd(a,b);
        int com = floor(n/lcm);
        int attemp = floor(n/a)+floor(n/b);
        int did = attemp-2*com;
        if(did>=k)
            cout<<"Win\n";
        else
            cout<<"Lose\n";
    }
    return 0;
}