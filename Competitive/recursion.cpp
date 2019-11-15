#include<iostream>
#include<vector>

//Factorial
/*
int fact(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    else
    {
        return fact(n-1)*n;
    }
    
}

int main()
{
    std::cout<<fact(4);
}
*/
//Fibonacci Series using Recursion
/*
void print(int a)
{
    std::cout<<a<<" ";
}

int Print_Recursion(int n)
{
    if(n<=1)
    {
        return n;
    }
    else
    {
        int alpha = Print_Recursion(n-1) + Print_Recursion(n-2);
        return alpha;
    }
}

int main()
{
    int n = 6;
    print(Print_Recursion(n));
}
*/

//Sum of array

int getSum(std::vector<int> arr,int start,int end)
{
    if(end==start)
    {
        return arr.at(start);
    }
    else
    {
        return arr.at(start) + getSum(arr,start+1,end);
    }
}

int main()
{
    std::vector<int> v1={1,2,3,4,5,6,7};
    std::cout<<getSum(v1,0,7-1);
}