#include<iostream>
#include<initializer_list>
using namespace std;
template<typename T>
class myvector{
	public:
		T *data;
		int size;
		int cap;
		//constructor
		myvector(int s=0,int n=0){
			cout<<"constructor called"<<endl;
			size=s;
			cap=s;
			data=(cap==0)?nullptr:new T[cap];
			for(int i=0;i<s;i++){
				data[i]=n;
			}	
		}
		~myvector(){
			delete []data;
		}
		//copy constructor
		myvector(const myvector&other){
			cout<<"copy constructor called"<<endl;
			size=other.size;
			cap=other.cap;
			data=new T[other.size];
			for(int i=0;i<other.size;i++){
				data[i]=other.data[i];
			}
		}
		myvector& operator =(const myvector&other){
			cout<<"Copy assignment operator called"<<endl;
			if(this==&other)
				return *this;
			delete []data;
			size=other.size;
			cap=other.cap;
			data=(cap==0)?nullptr:new T[cap];
			for(int i=0;i<size;i++){
				data[i]=other.data[i];
			}
			return *this;
		}
		void push_back(const int& val){

			if(size==cap){
				grow();
			}
			data[size++]=val;

		}

		int& operator[](int index){
			return data[index];
		}
		int& at(int index){

			if(index>=size){
				throw std::out_of_range("Index Bounce");
			}
			return data[index];

		}
		int get_size()const{

			return size;
		}
		int capacity()const{
			return cap;
		}
		int* begin(){
			return data;
		}
		int* end(){
			return data+size;
		}
		void pop_back()
		{
			size--;
		}
		bool empty(){
			return size==0?true:false;
		}
		myvector(std::initializer_list<T> l){
			size=l.size();
			cap=l.size();
			data=(cap==0)?nullptr:new T[cap];
			int i=0;
			for(const auto&x:l)
				data[i++]=x;
		}
		myvector(myvector&&other)noexcept{
			cout<<"move constructor called"<<endl;
			size=other.size;
			cap=other.cap;
			data=other.data;
			other.data=nullptr;
			other.size=0;
			other.cap=0;
		}
		myvector& operator =(myvector&&other)noexcept{
			cout<<"move copy assigment operator  called"<<endl;
			if(this!=&other){
				delete []data;
				size=other.size;
				cap=other.cap;
				data=other.data;
				other.data=nullptr;
				other.size=0;
				other.cap=0;
			}
			return *this;
		}
		void resize(int count){
			if(count>size){
				if(count>cap){
					T* new_data=new T[count];
					for(int i=0;i<size;i++)
						new_data[i]=data[i];
					delete []data;
					size=count;
					data=new_data;
					cap=count;
				}
				for(int i=size;i<count;i++)
					data[i]=T{};
				size=count;
			}
			else{

				size=count;
			}
		}
		void clear(){
			size=0;
		}
		void insert(T *ptr,T val){
			int index=ptr-data;
			if(size==cap)
				grow();
			for(int i=size;i>index;i--)
				data[i]=move(data[i-1]);
			data[index]=val;
			size++;
		}
		T* erase(T *ptr){
			int index=ptr-data;
			for(int i=index;i<size;i++)
				data[i]=move(data[i+1]);
			size--;
			return (data+index);	
		}	
		T* rbegin(){
		return (data+size-1);
		}
	private:
			void grow(){
				int new_cap=(cap==0)?1:cap*2;
				T *new_data=new T[new_cap];
				for(int i=0;i<size;i++){
					new_data[i]=data[i];
				}
				delete []data;
				data=new_data;
				cap=new_cap;
			}


};
int main()
{

	//myvector v1={1,2,3,4,5};
	//cout<<"copy constructor"<<endl;
	//myvector v2(v1);
	//myvector v2=v1;
	//cout<<"v1 ele"<<endl;
	myvector<int>v1={10,20};
	//myvector<int>v2=move(v1);
	//v1.insert(v1.begin()+1,30);
	v1.erase(v1.begin());
	for(auto i:v1)
		cout<<i<<" ";
	cout<<endl;
	//cout<<"v2 ele"<<endl;
	//for(auto i:v2)
	//	cout<<i<<" ";
	//cout<<endl;
}
