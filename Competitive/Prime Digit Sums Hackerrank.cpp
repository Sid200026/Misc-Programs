#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#define mod 1000000007
using namespace std;

bool checkprime(int n)
{
  int sum=0;
  while(n>0)
  {
    sum+=n%10;
    n/=10;
  }
  n=sum;
  vector<int> v1={2,3,5,7,11,13,17,19,23,29,31,37,41,43};
  if(find(v1.begin(),v1.end(),n)!=v1.end())
    return true;
  return false;
  // if(n==0 || n==1)
  //   return false;
  // for(int j=2;j<=sqrt(n);j++)
  //   if(n%j==0)
  //     return false;
  // return true;
}

bool Chloe3(int start,int n)
{
  int divide = pow(10,3);
  int counter = 0;
  while(start)
  {
    if(counter == n-2)
      break;
    counter++;
    int dig = start%divide;
    if(!checkprime(dig))
      return false;
    start/=10;
  }
  return true;
}

bool Chloe4(int start,int n)
{
  int divide = pow(10,4);
  int counter = 0;
  while(start)
  {
    if(counter == n-3)
      break;
    counter++;
    int dig = start%divide;
    if(!checkprime(dig))
      return false;
    start/=10;
  }
  return true;
}

bool Chloe5(int start, int n)
{
  int divide = pow(10,5);
  int counter = 0;
  while(start)
  {
    if(counter == n-4)
      break;
    counter++;
    int dig = start%divide;
    if(!checkprime(dig))
      return false;
    start/=10;
  }
  return true;
}

int main()
{
    int query;
    cin>>query;
    for(int i=0;i<query;i++)
    {
      int n;
      cin>>n;
      int counter = 0;
      int start = pow(10,n-1);
      for(int j=start;j<pow(10,n);j++)
      {
        /*if(Chloe3(j,n) && Chloe4(j,n) && Chloe5(j,n))
        {
          counter++;
        }*/
        int copy = j;
        int sum = j%pow(10,3);

        sum = sum%pow(10,4);

        sum = sum%pow(10,5);


      }
      cout<<counter%mod<<endl;
    }
}
