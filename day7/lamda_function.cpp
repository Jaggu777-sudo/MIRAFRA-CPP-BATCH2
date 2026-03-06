#include<iostream>
#include<vector>
#include<functional>
using namespace std;
void func(std::function<int(int)>f)
{
	int res=f(10);
	cout<<"res: "<<res<<endl;

}
int main()
{

	vector<int>v1={1,2,3,4,5};
	auto l=[&](int val){
		for(int i=0;i<v1.size();i++){
			v1[i]+=val;
		}
		return v1[0];
	};
	func(l);
	cout<<"Updated vector"<<endl;
	for(auto &i:v1){
		cout<<i<<" ";
	}
	cout<<endl;
}
