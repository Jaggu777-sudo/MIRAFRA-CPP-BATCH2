#include<iostream>
#include<variant>
#include<string>
using namespace std;
int main(){
variant<int,char>v;
cout<<sizeof(v);
string s;
cout<<sizeof(s)<<endl;
	return 0;
}

