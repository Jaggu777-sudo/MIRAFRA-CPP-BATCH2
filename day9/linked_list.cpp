#include<iostream>
using namespace std;
struct Node
{

	int data;
	struct Node *next;

};
void insert_front(Node *&head,int val){

	Node * new_node=new Node{val,head};
	head=new_node;

}
void insert_back(Node *&head,int val){
	Node *new_node=new Node{val,nullptr};
	if(head==nullptr){
		head=new_node;

	}
	Node *temp=head;
	while(temp->next!=nullptr){
		temp=temp->next;
	}
	temp->next=new_node;
}
void delete_front(Node*& head){
if(head==nullptr)
return;
Node *temp=head;
head=head->next;
delete temp;

}
void print(Node*& head){
	if(head==nullptr)
	return;
	Node *temp=head;
	while(temp!=nullptr){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}
int main(){
	Node *head=new Node{10,nullptr};
	Node *second=new Node{20,nullptr};
	Node *third=new Node{30,nullptr};
	head->next=second;
	second->next=third;
	third->next=nullptr;
	insert_back(head,40);
	print(head);
	delete_front(head);
	print(head);
	return 0;
}

