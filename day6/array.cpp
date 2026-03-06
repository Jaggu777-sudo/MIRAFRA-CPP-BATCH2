#include<iostream>
#include<array>
#include<algorithm>
using namespace std;
int main()
{

array<int,5>a1={2,1,5,4,3};
array<int,5>a2={10,20,30,40};
cout<<a1.size()<<endl;
cout<<a1[2]<<endl;
cout<<a1.at(1)<<endl;
//fill(a1.begin(),a1.end(),10);
cout<<"Fist Ele:"<<a1.front()<<endl;
cout<<"last ELE: "<<a1.back()<<endl;
sort(a1.begin(),a1.end());
for(auto i:a1)
cout<<i<<" ";
cout<<endl; 
cout<<a1.data()<<endl;
cout<<&a1[0]<<endl;
cout<<a1.max_size()<<endl;
a1.swap(a2);
for(auto i:a2)
cout<<i<<" ";
cout<<endl;
for(auto it=a1.rbegin();it>=a1.rend();it--){

cout<<*it<<" ";
}
cout<<endl;
}
