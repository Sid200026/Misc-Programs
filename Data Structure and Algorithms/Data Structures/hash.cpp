/* HASH with overwrite */

#include<iostream>
using namespace std;

bool prime(int n)
{
    if(n<=1)
        return false;
    for(int i = 2;i<n/2;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}


int hashfunc(string key, int size)
{
    int value = 0;
    for(int i=0;i<key.length();i++)
    {
        if(prime(i))
            value+= (int)key[i];
    }
    return value % size;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* int arr[5] = {500,200,350,60,8}; */
    string arr[5] = {"Singha", "Siddharth", "Roy"};
    string hash[200];
    for(int i= 0;i<200;i++)
    {
        hash[i] = "\0";
    }
    for(int j=0;j<5;j++)
    {
        int index = hashfunc(arr[j], 200);
        hash[index] = arr[j];
    }
    for(int i = 0;i<200;i++)
    {
        if(hash[i][0] == '\0')
            continue;
        cout<<hash[i]<<" "<<i<<" "<<endl;
    }
    return 0;
}