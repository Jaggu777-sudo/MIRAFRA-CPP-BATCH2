#include<iostream>
#include<queue>
using namespace std;
struct Tree{
	int data;
	Tree *left;
	Tree *right;
	Tree(int val):data(val),left(nullptr),right(nullptr){}
};
Tree* create(){

	Tree *root;
	int val;
	cout<<"enter root value"<<endl;
	cin>>val;
	if(val==-1){
		return nullptr;
	}
	root= new Tree(val);
	queue<Tree *>q;
	q.push(root);
	int l,r;
	while(!q.empty()){
		Tree *curr=q.front();
		q.pop();
		cout<<"enter left child values of"<<curr->data<<endl;
		cin>>l;
		if(l!=-1){
			curr->left=new Tree(l);
			q.push(curr->left);
		}
		cout<<"enter right child values of"<<curr->data<<endl;
		cin>>r;
		if(r!=-1){
			curr->right=new Tree(r);
			q.push(curr->right);
		}
	}
	return root;
}
void inorder(Tree *root){
	if(root==nullptr)
		return ;
	inorder(root->left);
	cout<<"Node data "<<root->data<<" address "<<root <<" left "<<root->left<<" right "<<root->right<<endl;
	inorder(root->right);
}

void preorder(Tree *root){
	if(!root)
		return ;
	cout<<"Node data "<<root->data<<" address "<<root <<" left "<<root->left<<" right "<<root->right<<endl;
	preorder(root->left);
	preorder(root->right);
}
Tree *insert(Tree*& root,int val){
	if(root==nullptr)
		return new Tree(val);
	if(val<root->data){
		root->left=insert(root->left,val);
	}
	else if(val>root->data){
		root->right=insert(root->right,val);
	}
	return root;
}
void delete_node(Tree *root){
	if(root==nullptr)
		return;
	delete_node(root->left);
	delete_node(root->right);
	delete root;
}
Tree* search(Tree *root,int val){
	if(root){
		if(root->data==val)
			return root;
		else if(val<root->data){
			return search(root->left,val);
		}
		else if(val>root->data){
			return search(root->right,val);
		}
	}
	else{
		return 0;
	}
	return 0;
}

int main(){
	Tree *root=create();
	insert(root,35);
	inorder(root);
	cout<<endl;
	preorder(root);
	cout<<endl;
	Tree* node=search(root,15);
	cout<<"search node address"<<node<<endl;
	//delete_node(root);
	return 0;
}

