#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,s;
        cin>>n;
        cin>>x;
        cin>>s;
        for(int i=0;i<s;i++)
        {
            int a,b;
            cin>>a;
            cin>>b;
            if(a==x)
                x=b;
            else if(b==x)
            {
                x=a;
            }
        }
        cout<<x<<"\n";
    }
    return 0;
}