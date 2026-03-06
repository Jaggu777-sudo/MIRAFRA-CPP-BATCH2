#include<iostream>
#include<memory>
#include<optional>
using namespace std;
class BST{
	public:
		struct tree{
			int data;
			std::unique_ptr<tree>left;
			std::unique_ptr<tree>right;
			tree(int val):data(val){}

		};
		unique_ptr<tree>root;
		void inorder(){
			inorder_impl(root.get());
		}
		void delete_node(int val){
			delete_node_impl(root,val);
		}
		void insert(int val){
			insert_impl(root,val);
		}
		bool search(int val){
			return search_impl(root.get(),val);
		}
		std::optional<int> findMax()const{
			tree *curr=root.get();
			if(!curr){
				return nullopt;
			}
			while(curr->right)
			{
				curr=curr->right.get();
			}
			return curr->data;
		}
		std::optional<int>findMin()const{
		tree *curr=root.get();
		if(!curr){
			return nullopt;
		}
		while(curr->left){
			curr=curr->left.get();
		}
		return curr->data;
	}
	private:
		void inorder_impl(tree *root){
			if(!root)
				return;
			inorder_impl(root->left.get());
			cout<<root->data<<" ";
			inorder_impl(root->right.get());
		}
		void delete_node_impl(unique_ptr<tree>&node,int val){
			if(!node){
				return;
			}
			if(val<node->data){
				delete_node_impl(node->left,val);
			}
			else if(val>node->data){
				delete_node_impl(node->right,val);
			}
			else{
				if(!node->left && !node->right){//if it is leaf node reset() function automatically destroy that current object and make pointer to nullptr
					node.reset();
				}
				else if(!node->left){//if right child only exist transfer that right pointer to current node and make right pointer as nullptr 
					node=std::move(node->right);
				}
				else if(!node->right){//if left child only exist transfer that left pointer to current node and make left pointer as nullptr
					node=std::move(node->left);
				}
				else{
					/*tree *minNode=node->right.get();//minNode=40
					  while(minNode->left)
					  minNode=minNode->left.get();//finally minNode=32

					  node->data=minNode->data;//copy 30=32
					  delete_node_impl(node->right,minNode->data);//deleting duplicate data 32 in inorder succsessor(uniqueptr data(40),32)*/
					tree *maxNode=node->left.get();
					while(maxNode->right)
						maxNode=maxNode->right.get();
					node->data=maxNode->data;
					delete_node_impl(node->left,maxNode->data);
				}
			}
		}
		bool search_impl(const tree* root,int val) const {
			if(!root)
				return false;

			if(root->data==val)
				return true;

			if(val<root->data)
				return search_impl(root->left.get(),val);
			else
				return search_impl(root->right.get(),val);
		}
		void insert_impl(unique_ptr<tree>&root,int val){
			if(!root){
				root=make_unique<tree>(val);
				return ;
			}
			if(val<root->data){
				insert_impl(root->left,val);
			}
			else if(val>root->data)
				insert_impl(root->right,val);
		}
};								      
int main(){									
	BST obj;
	obj.insert(50);
	obj.insert(30);
	obj.insert(70);
	obj.insert(20);
	obj.insert(40);
	obj.insert(35);
	obj.insert(45);
	obj.insert(32);
	obj.insert(10);
	obj.insert(25);
	cout<<"Before delete 30"<<endl;
	obj.inorder();
	cout<<endl;
	cout<<"after deleting 30"<<endl;
	obj.delete_node(30);
	obj.inorder();
	cout<<endl;
	cout<<"search ele(100):"<<endl;
	cout<<boolalpha<<obj.search(100)<<endl;
	auto max=obj.findMax();
	if(max.has_value()){
	cout<<max.value()<<endl;
	}
	auto min=obj.findMin();
	if(min.has_value()){
	cout<<min.value()<<endl;
	}
	return 0;
}

