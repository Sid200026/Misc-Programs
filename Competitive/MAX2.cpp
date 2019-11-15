#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long int len;
    cin>>len;
    string s;
    cin>>s;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s.at(i)=='1')
        {
            cout<<len-i-1;
            return 0; 
        }
    }
}