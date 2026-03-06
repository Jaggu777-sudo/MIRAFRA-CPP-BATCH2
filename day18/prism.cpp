#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
#include<utility>
#include<queue>
#include<list>
using namespace std;
using p1=pair<int,int>;
using p=pair<p1,int>;
vector<p>calculatePrismMST(int n,vector<p>&g){
	unordered_map<int,list<p1>>adj;
	for(int i=0;i<g.size();i++){
		int u=g[i].first.first;
		int v=g[i].first.second;
		int w=g[i].second;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	vector<int>key(n+1,INT_MAX);
	vector<bool>vis(n+1,false);
	vector<int>parent(n+1,-1);
	priority_queue<p1,vector<p1>,greater<p1>>pq;
	key[1]=0;
	pq.push({0,1});
	while(!pq.empty()){

		auto [k,u]=pq.top();
		pq.pop();
		if(vis[u])
			continue;
		vis[u]=true;
		for(auto[v,weight]:adj[u]){
			if(!vis[v] && weight<key[v]){
				key[v]=weight;
				parent[v]=u;
				pq.push({key[v],v});
			}
		}
	}
	vector<p>result;
	for(int i=2;i<n;i++){
		result.push_back({{parent[i],i},key[i]});
	}
	return result;
}
int main(){
	int n=6;
	vector<p> edges = {
		{{1,2}, 2}, // <u=1,v=2 >,w=2
		{{1,3}, 3},
		{{2,3}, 1},
		{{2,4}, 4},
		{{3,4}, 5},
		{{4,5}, 7}
	};
	auto mst=calculatePrismMST(n,edges);
	for(auto& edge:mst){
		cout<<edge.first.first<<" - "<<edge.first.second<<" weight: "<<edge.second<<endl;
	}
	return 0;
}
