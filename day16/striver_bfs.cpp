#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
class Graph{
	vector<vector<int>>adjList;
	void bfs_impl(int start,int des,vector<bool>&vis,vector<int>&parent){
		vis[start]=true;
		queue<int>q;
		q.push(start);
		while(!q.empty()){
			int node=q.front();
			q.pop();
			if(node==des)
				break;
			for(const auto& neigh:adjList[node]){
				if(!vis[neigh]){
					vis[neigh]=true;
					parent[neigh]=node;
					q.push(neigh);
				}
			} 
		}
		vector<int>path;
		for(int v=des;v!=-1;v=parent[v])
			path.push_back(v);
		reverse(path.begin(),path.end());
		for(int v:path){
			cout<<v<<" ";
		}
		cout<<"Distance "<<path.size()-1<<endl;
	}
	public:
	Graph(int v){
		adjList.resize(v);
	}
	void add_edge(int u,int v){
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	void bfs_shortest_path(int start,int des){
		int V=adjList.size();
		vector<bool>vis(V,false);
		vector<int>parent(V,-1);
		bfs_impl(start,des,vis,parent);
	}
};
int main(){
	Graph g(9);
	g.add_edge(1,2);
	g.add_edge(1,3);
	g.add_edge(2,5);
	g.add_edge(2,6);
	g.add_edge(3,7);
	g.add_edge(3,4);
	g.add_edge(4,8);
	g.add_edge(7,8);
	cout<<"level order traversal"<<endl;
	g.bfs_shortest_path(1,4);

	return 0;
}

