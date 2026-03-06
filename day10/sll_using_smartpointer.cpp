#include<iostream>
#include<memory>
using namespace std;
class LinkedList
{
	private:
		struct Node
		{
			int data;
			std::unique_ptr<Node> next;

			Node(int value) : data(value), next(nullptr) {}
		};

		std::unique_ptr<Node>head;

	public:
		LinkedList(): head(nullptr) {}

		void push_front(int value)
		{
			auto newNode = std::make_unique<Node>(value);

			newNode->next = std::move(head);
			head = std::move(newNode);
		}

		void print() const
		{
			Node* temp = head.get();

			while (temp)
			{
				std::cout << temp->data << " ";
				temp= temp->next.get();
			}
			std::cout << "\n";
		}
		void push_back(int value){

			auto new_node=std::make_unique<Node>(value);
			if(!head){
				head=std::move(new_node);
				return;
			}
			Node *temp=head.get();
			while(temp->next.get()!=nullptr){
				temp=temp->next.get();
			}
			temp->next=std::move(new_node);
		}
		void add_middle(int pos, int value)
		{
			if (pos == 0)
			{
				push_front(value);
				return;
			}
			auto new_node = std::make_unique<Node>(value);
			Node* temp = head.get();
			for(int i=0;i<pos -1 && temp != nullptr; i++)
			{
				temp= temp->next.get();
			}

			if(temp == nullptr)
			{
				return;
			}
			new_node->next= std::move(temp->next);
			temp->next= std::move(new_node);
		}
		void pop_front(){

		}

};
int main()
{
	LinkedList list;

	list.push_front(10);
	list.push_front(20);
	list.push_front(30);
	list.push_back(40);
	list.add_middle(2,50);
	list.print();

	return 0;
}

