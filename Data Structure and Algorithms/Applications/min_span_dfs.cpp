#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int weights[] = {
    1, // 0-1
    3, // 0-2
    6, // 0-3
    4, // 1-4
    8, // 1-2
};

bool sortAccToWeight(int a1, int a2) {
    return weights[a2-1]>weights[a1-1];
}

void sortStack(stack<int> &s) {
    vector<int> arr;
    while(!s.empty()) {
        arr.push_back(s.top());
        s.pop();
    }
    sort(arr.begin(), arr.end(), sortAccToWeight);
    for(auto i = arr.rbegin(); i!= arr.rend(); i++) {
        s.push(*i);
    }
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
        sortStack(s1);
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
    v1.push_back(4);
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
    graph.addNode(4,v1);
    graph.minspan();
}