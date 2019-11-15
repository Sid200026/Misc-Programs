#include<iostream>
#include<vector>
using namespace std;

int main()
{
  int test_cases;
  cin>>test_cases;
  while(test_cases--)
  {
    int thieves,minutes;
    cin>>thieves>>minutes;
    vector<int> time;
    int sum = 0;
    for(int i=0;i<thieves;i++)
    {
      int temp;
      cin>>temp;
      sum += temp;
      if(temp > minutes)
      {
        sum=minutes*2+1;
      }
      time.push_back(temp);
      for(int j=0;j<i;j++)
      {
        if(time[j]<time[i])
          swap(time[j],time[i]);
      }
    }
    if(sum>minutes*2)
    {
      cout<<"NO\n";
      continue;
    }
    int time1 = 0,time2 = 0;
    bool flag = true;
    for(int i=0;i<thieves;i++)
    {
      if(time1>time2)
      {
        time2+=time[i];
      }
      else
      {
        time1+=time[i];
      }
      if(time1>minutes || time2>minutes)
      {
        flag=false;
        break;
      }
    }
    cout<<endl<<time1<<" "<<time2<<endl;
    if(flag)
      cout<<"YES\n";
    else
      cout<<"NO\n";
  }
}
