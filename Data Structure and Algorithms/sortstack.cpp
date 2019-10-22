#include<bits/stdc++.h>
using namespace std;

void sortStack(stack<int> &s1, stack<int> &s2)
{
    if(s1.empty())
    {
        return;
    }
    else
    {
        int temp = s1.top();
        if(s2.empty())
        {
            s2.push(temp);
            s1.pop();
        }
        else
        {
            if(temp>s2.top())
            {
                s2.push(temp);
                s1.pop();
            }
            else
            {
                s1.pop();
                s1.push(s2.top());
                s2.pop();
                s1.push(temp);
            }
        }
        sortStack(s1,s2);
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int> s1,s2;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        s1.push(temp);
    }
    sortStack(s1,s2);
    while(!s2.empty())
    {
        cout<<s2.top();
        s2.pop();
    }
    return 0;
}