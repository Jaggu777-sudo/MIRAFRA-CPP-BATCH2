#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{

	vector<int>v1={110,2,4,684,2,3,5,7,9};
	cout<<"Before sort"<<endl;
	for(const auto &i:v1)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	sort(v1.begin(),v1.end(),[](auto a,auto b){
			return a<b;
			});
	cout<<"ele divisable by 2"<<endl;
	auto l=[=](){
	for(const auto& i:v1){
	if(i%2==0)
	cout<<i<<" ";
	}
	cout<<endl;
	};
	l();
	cout<<"After sort"<<endl;
	for(const auto &i:v1)
	{
		cout<<i<<" ";
	}
	cout<<endl;


}
