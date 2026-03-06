#include<iostream>
#include<iomanip>
#include<vector>
#include<limits>
using namespace std;
template<class T>
class DGraph{
	int V;
	T INF;
	vector<vector<T>>adjMatrix;
	public:
	DGraph(int vertices):V(vertices),INF(std::numeric_limits<T>::max()),adjMatrix(V,vector<T>(V,INF)){}
	void add_edge(int src,int des,T weight){
		if(src>=0 && src<V && des>=0 && des<V){
			adjMatrix[src][des]=weight;
		}
	}
	void print()const{
		for(const auto& row:adjMatrix){
			for(const auto& col:row){
				if(col==INF){
					cout<<"INF"<<" ";
				}
				else
					cout<<col<<" ";
			}
			cout<<endl;
		}
	}
};
int main(){
	DGraph<int> g(4);
	cout<<"Graph Is empty"<<endl;
	g.print();
	g.add_edge(0,1,5);
	g.add_edge(0,2,2);
	g.add_edge(0,3,3);
	g.add_edge(2,1,1);
	g.add_edge(2,3,6);
	g.print();
	return 0;
}
