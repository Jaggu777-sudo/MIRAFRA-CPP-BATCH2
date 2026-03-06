#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<climits>
using namespace std;
struct vertex{
	string city_name;
	int distance;
};
class Graph{
	unordered_map<string,vector<vertex>>um;
	struct comparator{
		bool operator()(const vertex &v1,const vertex& v2)const{
			return v1.distance>v2.distance;
		}
	};
	public:
	void add_edge(string u,string v,int dis){
		um[u].push_back({v,dis});
		um[v].push_back({u,dis});
	}
	void shortest_path(string source){
		priority_queue<vertex,vector<vertex>,comparator>pq;
		unordered_map<string,int>dis;
		//distance,node
		for(auto&p:um){
			dis[p.first]={INT_MAX};
		}
		pq.push({source,0});
		dis[source]=0;
		while(!pq.empty()){
			auto [s,d]=pq.top();
			pq.pop();
			for(auto& neighbour:um[s]){
				if(dis[neighbour.city_name]>d+neighbour.distance){
					dis[neighbour.city_name]=d+neighbour.distance;
					pq.push({neighbour.city_name,dis[neighbour.city_name]});
				}
			}
		}
		for(auto &p:dis){
			cout<<"Kurnool"<<"to"<<p.first<<" shortest distance "<<p.second<<endl;
		}
	}
};
int main(){
	Graph g;
	g.add_edge("Kurnool","Hyderabad",300);
	g.add_edge("Kurnool","Tirupati",400);
	g.add_edge("Kurnool","Banglore",600);
	g.add_edge("Tirupati","Banglore",200);
	g.add_edge("Hyderabad","Mumbai",500);
	g.add_edge("Hyderabad","Banglore",800);
	g.add_edge("Banglore","Mumbai",900);
	g.shortest_path("Kurnool");
	return 0;
}

