#include<iostream>
using namespace std;
consteval int square(int x){
return x*x;
}
int main(){
const int j=10;
constexpr int a=square(j);
cout<<a<<endl;
int c=square(5);
cout<<c<<endl;
return 0;
}

