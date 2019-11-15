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
        int a, b, n;
        cin>>a>>b>>n;
        if(n%2!=0)
            a *=2;
        int ans = a>b?(a/b):(b/a);
        cout<<ans<<endl;
    }
    return 0;
}