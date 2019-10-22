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
        int ans[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int count = 0;
        for(int i = 0; i<n;i++)
        {
            int answer = 0;
            for(int j = i+1; j<n;j++)
            {
                if(arr[j]>arr[i])
                {
                    answer = n-j;
                    break;
                }
            }
            ans[count++] = answer;
        }
        for(int j = 0;j< n;j++)
        {
            cout<<ans[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}