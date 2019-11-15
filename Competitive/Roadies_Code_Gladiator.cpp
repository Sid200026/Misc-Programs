#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

void printvector(vector<int> a)
{
    auto it=a.begin();
    while(it!=a.end())
    {
        cout<<*it<<"  ";
        it++;
    }
}

void getdigits(vector<int> &a,int num)
{
    while(num!=0)
    {
        a.push_back(num%10);
        num/=10;
    }
}

int main()
{
    int test_cases;
    cin>>test_cases;
    for(int i=0;i<test_cases;i++)
    {
        int number_of_boxes;
        cin>>number_of_boxes;
        vector<int> box;
        map<int,vector<int>> m;
        for(int j=0;j<number_of_boxes;j++)
        {
            int temp;
            cin>>temp;
            box.push_back(temp);
            vector<int> digits;
            getdigits(digits,temp);
            m[temp]=digits;
            for(int k=0;k<j;k++)
            {
                if(temp<box[k])
                {
                    swap(box[k],box[j]);
                }
            }
        }
        int maxsum=box.at(0);
        auto iterator=box.rbegin();
        for(;iterator!=box.rend();iterator++)
        {
            auto itfinddig=m.find(*iterator);
            int sum=*iterator;
            for(auto iter=m.begin();iter!=m.end();iter++)
            {
                bool check=true;
                if(iter==itfinddig)
                    break;
                for(auto loop=itfinddig->second.begin();loop!=itfinddig->second.end();loop++)
                {
                    if(find(iter->second.begin(),iter->second.end(),*loop)!=iter->second.end())
                    {
                        check=false;
                        break;
                    }
                }
                if(check)
                    sum+=iter->first;
            }
            if(maxsum<sum)
                maxsum=sum;
        }
        cout<<maxsum<<endl;
    }
}