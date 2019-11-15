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
        int arr[3];
        for(int i=0;i<3;i++)
            cin>>arr[i];
        int cost[3];
        for(int i=0;i<3;i++)
            cin>>cost[i];
        for(int i=1;i<3;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[j]<arr[i])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    temp = cost[i];
                    cost[i] = cost[j];
                    cost[j] = temp;
                }    
            }
        }
        bool err = false;
        for(int i=1;i<3;i++)
        {
            if(arr[i]==arr[i-1])
            {
                if(cost[i]!=cost[i-1])
                {
                    err = true;
                }
            }
            else
            {
                if(!(cost[i-1]>cost[i]))
                {
                    err = true;
                }
            }
            if(err)
                break;
        }
        cout<<(err?"NOT FAIR\n":"FAIR\n");
    }
    return 0;
}