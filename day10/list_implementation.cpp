#include<iostream>
using namespace std;
class Node{
	public:
		Node *prev;
		int data;
		Node *next;
		Node (int val):data(val){

			prev=next=nullptr;
		}
};
class List{

	Node *head;
	Node *tail;
	public:
	List (){

		head=nullptr;
		tail=nullptr;
	}
	~List() {

		delete head;	
	}
	void push_front(int v){
		Node *new_node = new Node(v);
		if( head != nullptr ) {
			new_node->next=head;
			head->prev=new_node;
			tail
		}

		head=new_node;
		tail

	}

	void push_back(int val){

		if(!head)
		{

			push_front(val);

			return;

		}

		Node *new_node=new Node(val);

		Node *temp=head;

		while (temp->next)

		{

			temp=temp->next;

		}

		temp->next=new_node;

		new_node->prev=temp;

	}

	void pop_front() {

		if(!head){

			return ;

		}

		Node *temp=head;
		if(head->next) {
		
		head=head->next;
		
		head->prev=nullptr;
		
		}
		else {
		
		head=nullptr;
		
		}

		delete temp;

	}

	void pop_back() {

		if(!head) {

			return ;

		}
		if(!head->next) {
		head=nullptr

		Node *temp=head;
		
		while(temp->next) {

			temp=temp->next;

		}

		temp->prev->next=nullptr;

		delete temp;

	}

	void print(){

		if(!head){
			return;
		}

		Node *temp=head;
		Node *rtemp=nullptr;
		while (temp) {

			cout<<temp->data<<" ";

			rtemp=temp;

			temp=temp->next;

		}

		cout<<endl;

		cout<<"Reverse Print"<<endl;

		while (rtemp!=nullptr){

			cout<<rtemp->data<<" ";

			rtemp=rtemp->prev;

		}

		cout<<endl;

	}

}; 
int main(){

	List l1;
	l1.push_front(40);

	l1.push_front(30);

	l1.push_front(20);

	l1.push_front(10);

	l1.push_back(50);

	l1.push_back(60);

	l1.pop_front();

	l1.pop_front();

	l1.pop_back();

	l1.pop_back();

	l1.print();

	return 0;

}

