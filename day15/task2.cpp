#include<iostream>
#include<utility>
#include<list>
#include<unordered_map>
#include<limits>
#include<optional>
using namespace std;
template<typename N,typename T>
class Graph{
	unordered_map<N,list<pair<N,T>>>adjList;
	void dfs_impl(N src,N des,T time,int& mintime,unordered_map<N,bool>&vis){
		vis[src]=true;
		if(src==des){
		mintime=min(mintime,time);
		vis[src]=false;
		return;
		}
		for(auto const&[neigh,weight]:adjList[src]){
			if(!vis[neigh]){
				dfs_impl(neigh,des,time+weight,mintime,vis);
			}
		}
		vis[src]=false;
	}
	public:
	void add_edge(N u,N v,T weight){
		adjList[u].push_back({v,weight});
	}
	void print(){
		cout << "City Graph:\n";
		for(const auto& [key, neighbour] : adjList){
			cout << key << " -> ";
			for(const auto& [nei, weight] : neighbour){
				cout << "(" << nei << "," << weight << ") ";
			}
			cout << endl;
		}
	}
	optional<T>shortest_time(N src,N des){
	T mintime=numeric_limits<T>::max();
	unordered_map<N,bool>vis;
	dfs_impl(src,des,0,mintime,vis);
	if(mintime==numeric_limits<T>::max())
	return nullopt;
	return mintime;
	}

};
int main(){
	Graph<string,int> g;
	g.add_edge("Ware House","Hub",15);
	g.add_edge("Ware House","Bridge",3);
	g.add_edge("Bridge","Hub",4);
	g.add_edge("Bridge","Park",7);
	g.add_edge("Park","Customer Point",9);
	g.add_edge("Hub","Customer Point",10);
	g.print();
	auto res=g.shortest_time("Bridge","Customer Point");
	if(res.has_value()){
	cout<<"Shortest Time from Ware house To Customer point: "<<res.value()<<" minutes"<<endl;

}
}

