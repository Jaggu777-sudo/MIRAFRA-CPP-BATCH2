#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph{

	vector<vector<int>>adj;
	public:
	Graph(int v){
		adj.resize(v);
	}
	void add_edge(int u,int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bool detect_cycle(int src,vector<bool>&vis){
		vis[src]=true;
		queue<pair<int,int>>q;
		q.push({src,-1});
		while(!q.empty()){
			auto[node,parent]=q.front();
			q.pop();
			for(auto neighbour:adj[node]){
				if(!vis[neighbour]){
					vis[neighbour]=true;
					q.push({neighbour,node});
				}
				else if(neighbour!=parent){
					return true;
				}
			}
		}
		return false;
	}
};
int main(){
	Graph g(13);
	g.add_edge(1,2);
	g.add_edge(1,3);
	g.add_edge(2,5);
	g.add_edge(3,4);
	g.add_edge(3,6);
	g.add_edge(5,7);
	g.add_edge(6,7);
	g.add_edge(9,10);
	g.add_edge(9,11);
	g.add_edge(10,11);
	vector<bool> vis(12, false);
	bool result = false;

	for (int i = 1; i < 13; i++) {
		if (!vis[i]) {
			if (g.detect_cycle(i, vis)) {
				result = true;
				break;
			}
		}
	}

	if (result)
		cout << "Cycle Found" << endl;
	else
		cout << "Cycle Not Found" << endl;
	return 0;
}

