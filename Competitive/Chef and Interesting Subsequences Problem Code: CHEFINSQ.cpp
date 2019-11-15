#include<bits/stdc++.h>
using namespace std;

int l[1001][1001] = { 0 }; 
  
int initialize() 
{ 
  
    // 0C0 = 1 
    l[0][0] = 1; 
    for (int i = 1; i < 1001; i++) { 
        // Set every nCr = 1 where r = 0 
        l[i][0] = 1; 
        for (int j = 1; j < i + 1; j++) { 
  
            // Value for the current cell of Pascal's triangle 
            l[i][j] = (l[i - 1][j - 1] + l[i - 1][j]); 
        } 
    } 
} 
  
// Function to return the value of nCr 
int nCr(int n, int r) 
{ 
    // Return nCr 
    return l[n][r]; 
} 

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
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        if(n==k)
        {
            cout<<1<<"\n";
            continue;
        }
        int checker = sizeof(arr)/sizeof(arr[0]);
        sort(arr,arr+checker);
        int last = arr[0];
        int lastcount = 1;
        for(int i=1;i<k;i++)
        {
            if(last == arr[i])
                lastcount++;
            else
            {
                last = arr[i];
                lastcount = 1;
            }
        }
        int pres = lastcount;
        for(int i=k;i<n;i++)
        {
            if(arr[i]==last)
                lastcount++;
            else
                break;
        }
        if(lastcount==1)
        {
            cout<<lastcount<<"\n";
            continue;
        }
        int maximum = (pres>(lastcount-pres))?pres:(lastcount-pres);
        int low = lastcount-maximum;
        int ans = nCr(maximum, low);
        cout<<ans<<"\n";
    }
    return 0;
}