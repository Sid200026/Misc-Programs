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
        string s;
        int total;
        cin>>total;
        cin>>s;
        int req = ceil(0.75*total);
        int have = 0;
        for(int i=0;i<total;i++)
        {
            if(s[i]=='P')
                have++;
        }
        int less = req - have;
        int proxy = 0;
        if(less<=0)
        {
            cout<<proxy<<"\n";
            continue;
        }
        bool flag = false;
        for(int i=2;i<total-2;i++)
        {
            if(s[i]=='A')
                if(s[i-1]=='P' || s[i-2]=='P')
                    if(s[i+1]=='P' || s[i+2]=='P')
                        proxy++;
            if(proxy+have == req)
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
            cout<<proxy<<"\n";
            continue;
        }
        cout<<"-1\n";
    }
    return 0;
}