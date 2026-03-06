#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;
class Graph{
	unordered_map<int,list<pair<int,int>>>adjList;
	void dfs_impl(int node,vector<int>&vis){
		vis[node]=1;
		cout<<node<<" ";
		for(const auto& it:adjList[node]){
		if(!vis[it.first]){
		dfs_impl(it.first,vis);
		}
	}
	}
	public:
	void add_edge(int u,int v,int weight)
	{
		adjList[u].push_back({v,weight});
	}
	/*void display(){

	  for(const auto&[key,l]:adjList){
	  cout<<key<<" ->";
	  for(const auto&[neigh,w]:l){
	  cout<<"("<<neigh<<" ,"<<w<<" )"<<endl;

	  }

	  }

	  }*/
void dfs(int start){
vector<int>vis(5,0);
dfs_impl(start,vis);

}
	void bfs(int start){
		vector<int>vis(5,0);
		queue<int>q;
		q.push(start);
		vis[start]=1;
		while(!q.empty()){
			int node=q.front();
			q.pop();
			cout<<node<<" ";
			for(const auto& [nei,w]:adjList[node]){
				if(!vis[nei]){
					vis[nei]=1;
					q.push(nei);
				}
			}
		}
	}
};
int main(){
	Graph g;
	g.add_edge(1,2,1);
	g.add_edge(1,3,4);
	g.add_edge(0,1,3);
	g.add_edge(0,3,7);
	g.add_edge(0,4,8);
	g.add_edge(3,2,2);
	g.add_edge(4,3,3);
	//g.display();
	cout<<"BFS"<<endl;
	g.bfs(0);
	cout<<"DFS"<<endl;
	g.dfs(0);
	
	return 0;
}

