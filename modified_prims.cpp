#include <iostream>
#include <string>
using namespace std;
#define INF 9999999
#define V 5

void dispString(string answer[], int count) {
    for(int i = 0;i<count;i++)
    {
        cout<<answer[i]<<"\n";
    }
}
 
int G[V][V] = {
  {0, 9, 75, 0, 0},
  {9, 0, 95, 19, 42},
  {75, 95, 0, 51, 66},
  {0, 19, 51, 0, 31},
  {0, 42, 66, 31, 0}
};
 
int edges[3] = {0,2,4};

int main () {
 
  int no_edge;
  int selected[V];
  memset (selected, false, sizeof (selected));
  no_edge = 0;
  selected[0] = true;
  int x;
  int y;
  cout << "Edge" << " : " << "Weight";
  cout << endl;
  bool flag = false;
  int counter = 0;
  while(!flag) {
        string answer[100];
        int count = 0;
        int included[100];
        int edgecount = 0;
        bool answercheck = false;
        if(counter>3)
        {
            cout<<"Cannot be formed";
            exit(0);
        }
        int temp1 = edges[counter++];
        while (no_edge < V - 1) {
            int min = INF;
            x = temp1;
            y = temp1;
            for (int i = 0; i < V; i++) {
                if (selected[i]) {
                    for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
                }
            }
            string a = to_string(x);
            string b = to_string(y);
            string c = to_string(G[x][y]);
            answer[count++].append(a+" - "+b+" : "+c);
            included[edgecount++] = x;
            included[edgecount++] = y;
            selected[y] = true;
            no_edge++;
            }
            
            for(int i = 0;i<3;i++)
            {
                bool checker = false;
                int test = edges[i];
                for(int j = 0;j<edgecount;j++)
                {
                    if(included[j] == test)
                    {
                        checker = true;
                        break;
                    }
                }
                if(!checker)
                {   
                    answercheck = true;
                    break;
                }
            }
            if(!answercheck)
            {
                dispString(answer, count);
                exit(0);
            }
  }

  return 0;
}