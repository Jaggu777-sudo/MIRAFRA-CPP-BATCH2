#include<iostream>
#include<utility>
#include<list>
#include<unordered_map>
#include<limits>
#include<optional>
using namespace std;
template<typename N,typename T>
class Graph{
vector<vector<pair<N,T>>>adjList;
public:
int Graph(int v){
adjList.resize(v);
}
void add_edge(N source,N destination,T weight){
adj[source].push_back({destination,weight});
}
void bfs_shortest_time(N source,N destination){
int V=adjList.size();
vector<bool>vis(V,false);
vector<T>parent(V,-1);
bfs_impl(source,destination,0,vis,parent


}

};
int main(){
	Graph<string,int> g(6);
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

