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
        int n,k;
        cin>>n>>k;
        int arr[n];
        bool accept = false;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>k)
                continue;
            for(int i=j+1;i<n;i++)
            {
                if(arr[i]+arr[j]==k)
                {
                    accept = true;
                    break;
                }
            }
            if(accept)
                break;
        }
        if(accept)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}