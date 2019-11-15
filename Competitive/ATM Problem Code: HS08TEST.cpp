#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int transaction;
    float balance;
    cin>>transaction>>balance;
    if(!(transaction+0.50>balance || transaction %5!=0))
    {
        balance -= transaction + 0.50;
    }
    cout<<fixed<<setprecision(2)<<balance;
    return 0;
}