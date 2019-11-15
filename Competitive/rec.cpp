#include<iostream>
using namespace std;

void getPattern(int n)
{
    if(n == 1)
    {
        cout<<"1"<<" ";
    }
    else
    {
        getPattern(n-1);
        cout<<n<<" ";
        getPattern(n-1);
    }
    
}

int main()
{
    int n;
    cin>>n;
    getPattern(n);
}