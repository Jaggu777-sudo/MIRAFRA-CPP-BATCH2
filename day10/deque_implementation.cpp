#include<iostream>
using namespace std;
class Mydeque{
	static int Block_Size;
	static int Table_Size;
	int **block_table;
	int start_block;
	int end_block;
	int start_offset;
	int end_offset;
	int current_size;
	public:
	Mydeque(){
		block_table=new int*[Table_Size];
		for(int i=0;i<Table_Size;i++){
			block_table[i]=nullptr;
		}
		start_block=end_block=Table_Size/2;
		block_table[start_block]=new int[Block_Size];
		start_offset=end_offset=current_size=0;
	}
	void push_back(int val){
		if(end_offset==Block_Size){
			end_block++;
			if(end_block==Table_Size)
				realloc();
			block_table[end_block]=new int[Block_Size];
			end_offset=0;
		}
		block_table[end_block][end_offset++]=val;
		current_size++;
	}
	void pop_front(){
		if(current_size==0)
			return;
		start_offset++;
		if(start_offset==Block_Size)
		{
			start_block++;
			start_offset=0;
		}
		current_size--;
	}
	void push_front(int val){
		if(start_offset>0)
			start_offset--;
		else{
			if(start_block==0)
				realloc();
			start_block--;
			block_table[start_block]=new int[Block_Size];
			start_offset=Block_Size-1;
		}
		block_table[start_block][start_offset]=val;
		current_size++;
	}
	void pop_back(){
		if(current_size==0)
			return;
		if(end_offset>0)
			end_offset--;
		else{
			end_block--;
			end_offset=Block_Size-1;
		}
		current_size--;

	}
	int size()const{
		return current_size;
	}
	int& operator[](int ind){

		int total_offset=start_offset+ind;
		int block=start_block+(total_offset/Block_Size);
		int offset=total_offset%Block_Size;
		return block_table[block][offset];

	}
	~Mydeque(){
		for(int i=0;i<Table_Size;i++)
			delete []block_table[i];
		delete []block_table;
	}
	void realloc(){
		cout<<"Reallocation Function Is Called"<<endl;
		int **new_block_table=new int*[Table_Size*2];
		int new_start_block=(Table_Size*2)/2;
		int new_end_block=new_start_block+(end_block-start_block);
		for(int i=0;i<Table_Size*2;i++)
			new_block_table[i]=nullptr;
		int j=new_start_block;
		for(int i=start_block;i<=end_block;i++){
			new_block_table[j++]=block_table[i];
		}
		delete []block_table;
		block_table=new_block_table;
		start_block=new_start_block;
		end_block=new_end_block;
		Table_Size=Table_Size*2;
	}

};
int Mydeque::Block_Size=4;
int Mydeque::Table_Size=4;
int main(){

	Mydeque d;
	d.push_front(30);
	d.push_front(20);
	d.push_front(10);
	d.push_back(40);
	d.push_back(50);
	d.push_back(60);
	d.pop_back();
	d.pop_front();
	for(int i=0;i<d.size();i++)
		cout<<d[i]<<" ";

}
