#include<iostream>
using namespace std;
template<class T>
class stack{
vector<T>v;
public:
stack(){}
stack(std::initializer_list<T>l){
v(l.size());
for(const auto& x:l){
v.push_back(x);
}

}
stack(const stack& other)
{

v(other.v.size());
for(const auto&other.v


}
void push(const T& val){

v.push_back(val);

}
void pop(){

v.pop_back(val);

}
T& top(){

return v.back();

}
int size()const{
return v.size();

}
bool empty(){

return size==0?false:true;

}



}
int main(){


	return 0;
}

