#include<iostream>
#include<vector>
#include<ranges>
using namespace std;
int main(){

	vector<int>v1={1,2,3,4,5,6,7};
	auto even=v1|std::views::filter([](int x){
			return x%2==0;
			});
	for(auto e:even){
		cout<<e<<" ";
	}
	cout<<endl;
	auto square=v1|std::views::transform([](int x){
			return x*x;
			});
	for(auto s:square){
		cout<<s<<" ";
	}
	cout<<endl;
	cout<<"After square origin vector "<<endl;
	for(auto& v:v1){
		cout<<v<<" ";
	}
	cout<<endl;
	auto take=v1|std::views::take(5);
	auto drop=take|std::views::drop(2);
	for(auto& t:take){
		cout<<t<<" ";
	}
	cout<<endl;
	for(auto& d:drop){
		cout<<d<<" ";
	}
	cout<<endl;
}
