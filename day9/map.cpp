#include<iostream>
#include<utility>
#include<map>
using namespace std;
int main()
{

map<int,string>m;
m.insert({1,"One"});
m.insert({2,"Two"});
m.insert({3,"Three"});
cout<<"Older C++ Way"<<endl;
for(const auto& ele:m){
cout<<ele.first<<" "<<ele.second<<endl;

}
cout<<"Modern C++ using structured Bindind"<<endl;
for(const auto& [key,val]:m){
cout<<key<<" "<<val<<endl;

}
cout<<m[]<<endl;
cout<<m.at(1)<<endl;
}
