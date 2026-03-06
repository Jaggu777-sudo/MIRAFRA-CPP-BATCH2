#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
vector<int>v1={1,2,3,4,5};
v1.insert(v1.begin()+2,10);
cout<<v1[1]<<endl;
cout<<v1.at(3)<<endl;
v1.erase(v1.end());
for(auto i:v1){
cout<<i<<" ";
}
cout<<endl;
auto it=find(v1.begin(),v1.end(),4);
cout<<*it<<endl;
vector<int>v2(3,0);
cout<<"size of v2 "<<v2.size()<<endl;
cout<<"capacity of v2 "<<v2.capacity()<<endl;
}
