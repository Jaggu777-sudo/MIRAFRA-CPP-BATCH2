#include<iostream>
#include<vector>
#include<list>
#include<array>
using namespace std;
template<class Iterator>
void print_all(Iterator First,Iterator Last){
	while(First!=Last){
		cout<<*First<<" ";
		First++;
	}
	cout<<endl;
}
int main(){

	vector<char>v1={'a','b','c','d'};
	list<int>l1={10,20,30,40};
	std::array<int,5>a1={1,2,3,4,5};
	int arr[3]={5,10,15};
	print_all(v1.begin(),v1.end());
	print_all(l1.begin(),l1.end());
	print_all(a1.begin(),a1.end());
	print_all(arr,arr+3);

}
