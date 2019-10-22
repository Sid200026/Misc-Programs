#include<bits/stdc++.h>
using namespace std;

int hashfunc(int key, int size)
{
    return key % size;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[5] = {800,400,200,350,60};
    int hash[200];
    for(int i= 0;i<200;i++)
    {
        hash[i] = -1;
    }
    for(int j=0;j<5;j++)
    {
        bool flag = false;
        int index = hashfunc(arr[j], 200);
        int temp = index;
        while(hash[index] != -1)
        {
            index = (index+1) % 200;
            if(temp == index)
            {
                flag = true;
                cout<<"Overflow";
                break;
            }
        }
        if(flag == false)
            hash[index] = arr[j];
    }
    for(int i = 0;i<200;i++)
    {
        if(hash[i] == -1)
            continue;
        cout<<hash[i]<<" "<<i<<" "<<endl;
    }

    cout<<endl;

    int hash1[400];
    for(int i=0;i<400;i++)
        hash1[i] = -1;
    for(int i = 0;i < 200; i++)
    {
        if(hash[i] != -1)
        {
            bool flag = false;
            int index = hashfunc(hash[i], 400);
            int temp = index;
            while(hash1[index] != -1)
            {
                index = (index+1) % 400;
                if(temp == index)
                {
                    flag = true;
                    cout<<"Overflow";
                    break;
                }
            }
            if(flag == false)
                hash1[index] = hash[i];
        }
    }

    for(int i = 0;i<400;i++)
    {
        if(hash1[i] == -1)
            continue;
        cout<<hash1[i]<<" "<<i<<" "<<endl;
    }

    return 0;
}