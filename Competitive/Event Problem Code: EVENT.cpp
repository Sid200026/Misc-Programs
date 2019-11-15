#include<bits/stdc++.h>
using namespace std;

int find(string s)
{
    string days[7] = {"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
    for(int i=0;i<7;i++)
    {
        if(s==days[i])
            return i;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        string s,e;
        cin>>s>>e;
        int a,b;
        a=find(s);
        b=find(e);
        int diff = (b-a+8)%7;
        int p,q;
        cin>>p>>q;
        int count = 0;
        bool flag = true;
        for(int i=diff;flag;i+=7)
        {
            if(i>=p && i<=q)
                count++;
            else
                flag=!flag;
        }
        if(count==0)
            cout<<"impossible";
        else if(count==1)
            cout<<diff<<"\n";
        else    
            cout<<"many\n";
    }
    return 0;
}