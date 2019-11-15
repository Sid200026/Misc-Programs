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
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            arr[i]*=20;
        }
        int max = 0;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            arr[i]-=10*temp;
            if(arr[i]>max)
                max = arr[i];
        }
        cout<<max<<"\n";
    }
    return 0;
}