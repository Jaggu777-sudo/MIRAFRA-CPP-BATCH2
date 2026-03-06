#include <iostream>
#include <vector>
using namespace std;
void print(vector<int>v)
{
	for (auto x : v)
		cout << x << " ";
	cout << endl;
}

int main()
{
	vector<int> v1, v2;
	auto ref = [&](int m) {
		v1.push_back(m);
		v2.push_back(m);
	};
	auto val = [=](int m)mutable  {
		v1.push_back(m);
		v2.push_back(m);
	};
	auto mixed = [&v1, v2](int m) mutable {
		v1.push_back(m);
		v2.push_back(m);
	};
	
	ref(20);
	val(234);
	mixed(10);

	print(v1);
	print(v2);
}
