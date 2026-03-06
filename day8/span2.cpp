#include<iostream>
#include<span>
#include<vector>
using namespace std;
void print(std::span<int>s){
for(const auto& x:s)
{
cout<<x<<" "; 
}
cout<<endl;
}
int main()
{
vector<int>v1={1,2,3,4,5};
span<int>s(v1);
cout<<"size of vector v1"<<sizeof(v1)<<endl;
cout<<"size of span s"<<sizeof(s)<<endl;
print(v1);
auto first=s.first(3);
auto last=s.last(2);
auto middle=s.subspan(1,3);
//ZZs.at(2)=300;
cout<<"After"<<endl;
for(const auto&x:v1){
cout<<x<<" ";
}

}
