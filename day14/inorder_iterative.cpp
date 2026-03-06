#include <iostream>
#include <stack>
struct Node
{
	int data;
	Node* left;
	Node* right;
	Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
void inorder(Node* root)
{
	std::stack<Node*> st;
	Node* current = root;
	while (current != nullptr || !st.empty())
	{
		while (current != nullptr)
		{
			st.push(current);
			current = current->left;
		}
		current = st.top();
		st.pop();
		std::cout << current->data << " ";
		current = current->right;
	}
}
int main()
{
	Node* root = new Node(50);
	root->left = new Node(30);
	root->right = new Node(70);
	root->left->left = new Node(20);
	root->left->right = new Node(40);
	std::cout << "Inorder Traversal: ";
	inorder(root);
	std::cout<<std::endl;
	return 0;
}
