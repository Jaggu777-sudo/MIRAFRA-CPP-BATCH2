#include<iostream>
using namespace std;
class myList{
	public:
		struct Node{
			Node *next;
			Node *prev;
			int data;
			Node(int d=0):data(d),prev(nullptr),next(nullptr){}
		};
		int size;
		Node *head;
		Node *tail;
		myList(int s=0,int d=0):size(s){
			head=tail=nullptr;
			if(size>0){
				head=tail=new Node(d);
			}
			for(int i=1;i<size;i++)
			{
				Node *new_node=new Node(d);
				tail->next=new_node;
				new_node->prev=tail;
				tail=new_node;
			}
		}

		myList(std::initializer_list<int>l){
			size=l.size();
			head=tail=nullptr;
			for(int v:l){
				Node *new_node=new Node(v);
				if(!head){
					head=tail=new_node;
				}
				else{
					tail->next=new_node;
					new_node->prev=tail;
					tail=new_node;
				}
			}
		}

		myList(myList&&other){

			size=other.size;
			head=other.head;
			tail=other.tail;
			other.size=0;
			other.head=other.tail=nullptr;


		}
		myList(const myList& other){
			size=other.size;
			Node *temp=other.head;
			while(temp){

				Node *new_node=new Node(temp->data);
				if(!head){
					head=tail=new_node;
				}
				else{
					tail->next=new_node;
					new_node->prev=tail;
					tail=new_node;
				}
				temp=temp->next;
				size++;
			}
		}
		Node *begin(){

			return head;

		}
		Node *end(){

			return tail;

		}
		void assign(int val,const int &v){
			if(val>0)
				head=tail=new Node(v);
			for(int i=1;i<val;i++){
				Node *new_node=new Node(v);
				tail->next=new_node;
				new_node->prev=tail;
				tail=new_node;

			}
		}
		void pop_front(){
			if(!head)
				return ;
			Node *temp=head;
			head=head->next;
			if(head!=nullptr)
				head->prev=nullptr;
			delete temp;

		}
		void pop_back(){
			if(!head)
				return;
			if(head==tail){
				delete head;
				head=nullptr;
				tail=nullptr;
				return;
			}
			Node *temp=tail;
			tail=tail->prev;
			tail->next=nullptr;
			delete temp;

		}
		void push_front(const int& val){
			Node *new_node=new Node(val);
			if(!head){
				head=tail=new_node;
			}
			else{
				new_node->next=head;
				head->prev=new_node;
				head=new_node;
			}
			size++;
		}
		void push_back(const int& val){
			Node *new_node=new Node(val);
			if(!head)
				head=tail=nullptr;
			else
			{
				tail->next=new_node;
				new_node->prev=tail;
				tail=new_node;	
			}
		}
		void advance(Node *&it,int pos){
			while(pos-->0&&it!=nullptr){
				it=it->next;
			}
		}
		void erase(Node *it){
			if(!it)
				return;
			if(it->prev)
				it->prev->next=it->next;
			if(it->next)
				it->next->prev=it->prev;
			delete it;
		}

};
int main(){
	myList l1={1,2,3,4,5};
	myList l2;
	myList l3(5,10);
	l3.assign(10,100);
	l1.push_front(0);
	l1.push_front(-1);
	l1.push_front(-2);
	l1.push_back(6);
	l1.push_back(7);
	l1.pop_front();
	l1.pop_front();
	l1.pop_back();
	l1.pop_back();
	auto it=l1.begin();
	l1.advance(it,2);
	l1.erase(it);
	for(auto it=l1.begin();it!=nullptr;){
		cout<<it->data<<endl;
		it=it->next;
	}
	return 0;
}

