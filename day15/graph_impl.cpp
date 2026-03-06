#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adjList;

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    void add_edge(int u, int v) {
        adjList[u][v]=v;
        adjList[v][u]=u;  
    }

    /*void print() {
        for(int i = 0; i < V; i++) {
            cout << i << " -> ";
            for(int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }*/
    void print(){
    for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
    cout<<adjList[i][j]<<" ";
    }
    cout<<endl;
    }
    }
    
};

int main() {
    Graph g(4);

    g.add_edge(1, 0);
    g.add_edge(2, 0);
    g.add_edge(1, 2);
    g.add_edge(2,3);
    g.print();
}

