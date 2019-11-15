#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int getsum(const int &n)
{
  int copy=n;
  int sum = 0;
  while(copy--)
  {
    sum +=copy;
  }
  return sum;
}

int adder(int tot)
{
  int sum = 0;
  int count=0;
  while(tot>sum)
  {
    sum+=++count;
  }
  return count;
}

int main()
{
  int test_cases;
  cin>>test_cases;
  for(int i=0;i<test_cases;i++)
  {
    int stock,buy,required;
    cin>>required>>stock>>buy;
    if(required>buy*stock-getsum(buy))
    {
      cout<<"-1"<<endl;
      continue;
    }
    int check = required - stock - (buy-1) -getsum(buy-1);
    int sum = 0;
    check=adder(check);
    if(check<0)
      check=0;
    for(int j=0;j<buy-1;j++)
    {
      cout<<check+j+1<<" ";
      sum += check+j+1;
    }
    cout<<required-sum<<endl;
  }
}
