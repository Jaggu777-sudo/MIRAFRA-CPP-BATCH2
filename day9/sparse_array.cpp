#include<iostream>
#include<utility>
#include<vector>
using namespace std;
class SpareArray{

vector<pair<int,int>>data;
public:
void set(int index,int value){

if(value!=0){
data.push_back({index,value});
}

}
int get(int index)const{

for(const auto&[i,v]:data)
{
if(i==index)
return v;
}
return 0;
}
void print()const{
for(const auto& [i,v]:data)
{
cout<<i<<"->"<<v<<endl;
}
}
};
int main()
{

SpareArray a;
a.set(0,10);
a.set(1,20);
cout<<"at index 0 value is "<<a.get(0)<<endl;


}
