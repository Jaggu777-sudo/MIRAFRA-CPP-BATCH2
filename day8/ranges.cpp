#include<iostream>
#include<algorithm>
#include<ranges>
#include<vector>
using namespace std;
int main()
{
	vector<int>v1={1,2,3,4,5};
	std::ranges::sort(v1);
	auto it=ranges::find(v1,5);
	if(it!=v1.end()){
		cout<<"ele is present at index"<<ranges::distance(v1.begin(),it)<<endl;
	}
	vector<int>des(v1.size());
	std::ranges::copy(v1,des.begin());
	for(auto i:des)
		cout<<i<<" ";
	cout<<endl;
	cout<<std::ranges::size(v1)<<endl;
}
