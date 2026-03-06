#include <iostream>
#include <utility> 
#include <string>

using namespace std;

#define SIZE 5 

template<class T>
class stack {
	T arr[SIZE];
	int s_top;

	public:
	stack() : s_top(-1) {}
	stack(const stack& other) {
		cout << "Copy constructor called\n";
		s_top = other.s_top;
		for (int i = 0; i <= s_top; i++)
			arr[i] = other.arr[i];
	}

	stack(stack&& other) noexcept {
		cout << "Move constructor called\n";
		s_top = other.s_top;
		for (int i = 0; i <= s_top; i++)
			arr[i] = std::move(other.arr[i]);
		other.s_top = -1;
	}

	stack& operator=(const stack& other) {
		cout<<"copy assigment is called"<<endl;
		if (this != &other) {
			s_top = other.s_top;
			for (int i = 0; i <= s_top; i++)
				arr[i] = other.arr[i];
		}
		return *this;
	}

	stack& operator=(stack&& other) noexcept {
		cout<<"move assigment is called"<<endl;
		if (this != &other) {
			s_top = other.s_top;
			for (int i = 0; i <= s_top; i++)
				arr[i] = std::move(other.arr[i]);
			other.s_top = -1;
		}
		return *this;
	}

	void push(const T& val) {
		if (s_top == SIZE - 1) {
			cout << "Stack overflow\n";
			return;
		}
		arr[++s_top] = val;
	}

	void pop() {
		if (empty()) {
			cout << "Stack underflow\n";
			return;
		}
		--s_top;
	}

	T& top() {
		return arr[s_top];
	}

	const T& top() const {
		return arr[s_top];
	}

	bool empty() const {
		return s_top == -1;
	}
};

struct sensor {
	int sensor_number;
	string sensor_name;
	sensor(){}
	sensor(int sn, string s_n)
		: sensor_number(sn), sensor_name(s_n) {}
};

int main() {
	stack<sensor> s1;

	s1.push({1, "Temperature Sensor"});
	s1.push({2, "Collision Sensor"});
	s1.push({3, "Pressure Sensor"});

	stack<sensor> s2;
	s2.push({4,"Humidity Sensor"});
	s1=std::move(s2);

	cout << "s2 elements\n";
	while (!s2.empty()) {
		cout << s2.top().sensor_number << " "
			<< s2.top().sensor_name << "\n";
		s2.pop();
	}

	cout << "s1 elements\n";
	while (!s1.empty()) {
		cout << s1.top().sensor_number << " "
			<< s1.top().sensor_name << "\n";
		s1.pop();
	}

	return 0;
}

