#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class Graph{
	unordered_map<int,list<int>>adjList;
	public:
	void add_edge(int u,int v,bool directed=false){

		adjList[u].push_back(v);
		if(!directed){
			adjList[v].push_back(u);
		}
	}
	void print(){
		for(const auto& [key,neighbour]:adjList){
			cout<<key<<"->";
			for(const auto& l:neighbour){
				cout<<l<<" ";
			}
			cout<<endl;
		}
	}

};
int main(){
	Graph g;
	g.add_edge(0,1);
	g.add_edge(0,2);
	g.add_edge(1,3);
	g.print();

	return 0;
}

