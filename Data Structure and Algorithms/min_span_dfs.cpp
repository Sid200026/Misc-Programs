#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<stack>
int weights[] = {
    1, // 0-1
    3, // 0-2
    6, // 0-3
    4, // 1-4
    8, // 1-2
};
using namespace std;

void sortStack(stack<int> &s) {
    
}

class Graph {
    map<int, vector<int> > graph;
    public:
        void addNode(int, vector<int>);
        void minspan(int);
};

void Graph::addNode(int key, vector<int> connect) {
    graph.emplace(key,connect);
}

void Graph::minspan(int start = 0) {
    stack<int> s1;
    s1.push(start);
    vector<int> donelist;
    donelist.push_back(0);
    while(!s1.empty()) {
        cout<<start<<" ";
        s1.pop();
        auto itr = graph.find(start);
        vector<int> links = itr->second;
        for(int i=0; i<links.size();i++){
            if(find(donelist.begin(), donelist.end(), links.at(i)) == donelist.end()) {
                s1.push(links.at(i));
                donelist.push_back(links.at(i));
            }
        }
        if(s1.empty()) {
            break;
        }
        start = s1.top();
    }
}

int main() {
    Graph graph;
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    graph.addNode(0,v1);
    v1.clear();
    v1.push_back(0);
    v1.push_back(2);
    v1.push_back(5);
    graph.addNode(1,v1);
    v1.clear();
    v1.push_back(0);
    v1.push_back(1);
    graph.addNode(2,v1);
    v1.clear();
    v1.push_back(0);
    graph.addNode(3,v1);
    v1.clear();
    v1.push_back(1);
    graph.addNode(5,v1);
    graph.minspan();
}