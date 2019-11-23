#include<iostream>
using namespace std;

int dp[100][100];

int lcs(string s1, string s2, int a, int b)
{
    if(a<0 || b<0)
        return 0;
    else
    {
        if(dp[b][a] != -1)
            return dp[b][a];
        else
        {
            if(s1[a] == s2[b])
                return 1 + lcs(s1, s2, a-1, b-1);
            else
            {
                dp[b][a] = max(lcs(s1,s2,a-1,b), lcs(s1,s2,a,b-1));
                return dp[b][a];
            }
        }
        
    }
    
}

int main()
{
   string str1, str2;
   cin>>str1>>str2;
   for(int i = 0; i<=str1.length(); i++)
   {
       for(int j = 0; j<=str2.length();j++)
       {
           dp[j][i] = -1;
       }
   }
   cout<<lcs(str1, str2, str1.length()-1, str2.length()-1);
}