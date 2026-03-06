#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
using edge=pair<int,int>;
class Graph{
	vector<vector<edge>>adj;
	public:
	Graph(int V){
		adj.resize(V);
	}
	void add_edge(int u,int v,int weight){
		adj[u].push_back({v,weight});
		adj[v].push_back({u,weight});
	}
	void shortest_path(int source){
		priority_queue<edge,vector<edge>,greater<edge>>pq;
		vector<int>dis(adj.size(),INT_MAX);
		//distance,node
		pq.push({0,source});
		dis[source]=0;
		while(!pq.empty()){
			auto [d,node]=pq.top();
			pq.pop();
			for(auto&[neighbour,weight]:adj[node]){
				if(dis[neighbour]>d+weight){
					dis[neighbour]=d+weight;
					pq.push({dis[neighbour],neighbour});
				}
			}
		}
		for(int i=0;i<dis.size();i++){
			cout<<"0 to "<<i<<" shortest distance:"<<dis[i]<<endl;
		}
	}
};
int main(){
	Graph g(5);
	g.add_edge(0,1,3);
	g.add_edge(0,4,8);
	g.add_edge(0,3,7);
	g.add_edge(1,2,1);
	g.add_edge(1,3,4);
	g.add_edge(2,3,2);
	g.add_edge(3,4,3);

	g.shortest_path(0);
	return 0;
}

