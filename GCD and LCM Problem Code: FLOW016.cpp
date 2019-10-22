#include<bits/stdc++.h>
using namespace std;

long long int gcd(long long int a,long long int b)
{
    if(a%b == 0)
        return b;
    else if(b%a == 0)
        return a;
    else
    {
        return gcd(b,a%b);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int a,b;
        cin>>a>>b;
        cout<<gcd(a,b)<<" "<<(a*b)/(gcd(a,b))<<endl;
    }
    return 0;
}