#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<climits>
using namespace std;

using p = pair<int,int>;

class Router {
    vector<vector<p>> adj;
    struct compare{
	bool operator ()(const p&a,const p&b)const{
		return a.first>b.first;
		}
		};
public:
    Router(int V) {
        adj.resize(V);
    }

    void add_edge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    void shortest_path(int source) {

        priority_queue<p, vector<p>,compare> pq;
        vector<int> delay(adj.size(), INT_MAX);

        pq.push({0, source});
        delay[source] = 0;

        while (!pq.empty()) {

            auto [d, node] = pq.top();
            pq.pop();

            for (auto &neighbour : adj[node]) {

                auto [v, weight] = neighbour;

                if (delay[v] > delay[node] + weight) {
                    delay[v] = delay[node] + weight;
                    pq.push({delay[v], v});
                }
            }
        }

        cout << "From Router " << source << ":" << endl;

        for (int i = 0; i < delay.size(); i++) {
            cout << "Router " << i << " -> " << delay[i] << " ms" << endl;
        }
    }
};

int main() {

    Router g(6);

    g.add_edge(0,1,4);
    g.add_edge(0,2,2);
    g.add_edge(1,2,1);
    g.add_edge(1,3,5);
    g.add_edge(2,3,8);
    g.add_edge(2,4,10);
    g.add_edge(3,5,6);
    g.add_edge(4,5,2);

    g.shortest_path(0);
}
