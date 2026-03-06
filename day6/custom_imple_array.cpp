#include<iostream>
using namespace std;
template<typename T,size_t N>
class MyArray{
	T data[N];
	public:
	int size()const{
		return N;
	}
	T& operator[](size_t index){
		return data[index];
	}
	T& at(size_t index){
		if(index>=5){
			throw std::out_of_range("int array::at");
		}
		return data[index];
	}
	void fill(const T& value){
		for(size_t i=0;i<N;i++)
		data[i]=value;

	}
	T* begin(){
		return data;
	}
	T* end(){
		return data+N;
	}
	T* data1(){
		return data;
	}
	T& front(){
	return (*data);
	}
	T& back(){
	return *(data+N-1);
	}
};
int main()
{

	MyArray<int,5>a1;
	for(int i=0;i<5;i++){
	a1[i]=i*100;
	}
	cout<<a1[2]<<endl;
	cout<<a1.size()<<endl;
	for(auto it=a1.begin();it<a1.end();it++){
	cout<<*it<<" ";
	}
	cout<<endl;
	cout<<a1.front()<<endl;
	cout<<a1.back()<<endl;
}

