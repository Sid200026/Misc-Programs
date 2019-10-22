#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        long long int oddeven[n];
        for(long long int i=0;i<n;i++)
        {
            long long int temp;
            cin>>temp;
            if(temp%2==0)
                oddeven[i] = 0;
            else
                oddeven[i] = 1;
        }
        long long int count = 0;
        long long int incrementer = 0;
        for(long long int i=0;i<n;i++)
        {
            if(oddeven[i] == 0)
                incrementer++;
            else
            {
                count = count + incrementer;
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}