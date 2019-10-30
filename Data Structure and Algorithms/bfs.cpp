#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Graph {
    map<int, vector<int> > graph;
    public:
        void addNode(int, vector<int>);
        void bfs(int);
};

void Graph::addNode(int key, vector<int> connect) {
    graph.emplace(key,connect);
}

void Graph::bfs(int start) {
    queue<int> q1;
    q1.push(start);
    vector<int> donelist;
    donelist.push_back(0);
    while(!q1.empty()) {
        cout<<q1.front()<<" ";
        q1.pop();
        auto itr = graph.find(start);
        vector<int> links = itr->second;
        for(int i=0; i<links.size();i++){
            if(find(donelist.begin(), donelist.end(), links.at(i)) == donelist.end()) {
                q1.push(links.at(i));
                donelist.push_back(links.at(i));
            }
        }
        start = q1.front();
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
    graph.bfs(0);
}