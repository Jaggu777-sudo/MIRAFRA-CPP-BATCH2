#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
enum City {
	Traffic_Control = 0,
	Power_Grid,
	Water_Supply,
	Hospital_Network,
	Police_Control,
	Data_Center
};
struct Edge {
	int u, v, cost;
};
class Network {
	vector<int> parent, rank;
	vector<Edge> edges;
	public:
	Network(int n) {
		parent.resize(n);
		rank.resize(n, 0);
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}
	void add_edge(int u, int v, int cost) {
		edges.push_back({u, v, cost});
	}
	
	int find_set(int node) {
		if (parent[node] != node)
			parent[node] = find_set(parent[node]);//path compression 
		return parent[node];
	}
	void union_find(int u, int v) {
		int rootU = find_set(u);
		int rootV = find_set(v);

		if (rootU != rootV) {
			if (rank[rootU] < rank[rootV]) {
				parent[rootU] = rootV;
			}
			else if (rank[rootU] > rank[rootV]) {
				parent[rootV] = rootU;
			}
			else {
				parent[rootV] = rootU;
				rank[rootU]++;
			}
		}
	}
	void kruskal() {
		sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
				return a.cost < b.cost;
				});
		int totalCost = 0;
		for (auto &e : edges) {
			if (find_set(e.u) != find_set(e.v)) {
				cout << e.u << " - " << e.v<< " : " << e.cost << " lakhs\n";
				totalCost += e.cost;
				union_find(e.u, e.v);
			}
		}
		cout << "Minimum Total Cost: "<< totalCost << " lakhs"<<endl;
	}
};
int main() {
	int V = 6;
	Network n(V);
	n.add_edge(0, 1, 4);
	n.add_edge(0, 2, 4);
	n.add_edge(1, 2, 2);
	n.add_edge(2, 3, 3);
	n.add_edge(2, 5, 2);
	n.add_edge(2, 4, 4);
	n.add_edge(3, 4, 3);
	n.add_edge(5, 4, 3);
	n.kruskal();
	return 0;
}
