#include<iostream>
#include<functional>
#include<vector>
using namespace std;
int main(){
	vector<int>v1={1,2,3,4,5,6};
	auto l=[&](int val){
		for(int i=0;i<v1.size();i++)
			v1[i]=v1[i]+val;
	};
	auto bind_lambda=std::bind(l,5);
	bind_lambda();
	cout<<"After Bind"<<endl;
	for(auto const&i:v1)
		cout<<i<<" ";
	cout<<endl;
}
