#include<iostream>
using namespace std;

int hashfunc(int key, int size)
{
    return key % size;
}

int hash2(int key, int size) // hash2 cannot be 0
{
    return 1+key%size;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[5] = {200, 400, 600, 800, 0};
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
        int i = 1;
        while(hash[index] != -1)
        {
            index = (temp+i*hash2(arr[j], 200)) % 200;
            if(temp == index)
            {
                flag = true;
                cout<<"Overflow";
                break;
            }
            i++;
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

    int z = 800;
    int ind = hashfunc(z, 200);
    int i = 1;
    int temp = ind;
    while(hash[ind] != z)
    {
        if(hash[ind] == -1)
        {
            cout<<"Not found";
            break;
        }
        ind = (temp +i*hash2(z, 200)) % 200;
        if(hash[ind] == z)
        {
            cout<<hash[ind]<<" "<<ind;
        }
        i++;
    }

    return 0;
}