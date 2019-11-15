#include<iostream>
using namespace std;
int main()
{
    int num_of_cases;
    cin>>num_of_cases;
    long int new_max_value;
    long int copy;
    for(int i=0;i<num_of_cases;i++)
    {
        cin>>new_max_value;
        copy=new_max_value;
        for(int j=1;j<=new_max_value;j++)
        {
            if(j==copy)
                break;
            new_max_value=j+new_max_value+j*new_max_value;
            new_max_value%=1000000007;
        }
        cout<<new_max_value<<endl;
    }
}