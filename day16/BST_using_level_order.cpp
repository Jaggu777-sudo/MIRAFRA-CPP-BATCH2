#include<iostream>
#include<memory>
#include<queue>
using namespace std;
class BST{
	struct ECU{
		string name;
		bool status;
		ECU(string n,bool s):name(n),status(s){}
	};
	struct tree{
		ECU data;
		unique_ptr<tree>left;
		unique_ptr<tree>right;
		tree(string n,bool s):data(n,s){}
	};
	public:
	unique_ptr<tree>root;
	void insert(){
		root=make_unique<tree>("ECU",true);
		root->left=make_unique<tree>("Safety",true);
		root->right=make_unique<tree>("Dash Borad",true);
		root->left->left=make_unique<tree>("Airbag",true);
		root->left->right=make_unique<tree>("Childlock",false);
		root->right->left=make_unique<tree>("Speed",false);
		root->right->right=make_unique<tree>("Fuel",true);
	}
	void level_order(){
		if(!root){
			return;
		}
		queue<tree*>q;
		q.push(root.get());
		while(!q.empty()){
			tree *curr=q.front();
			q.pop();
			if(!curr->data.status){
				curr->data.status=true;
			}
			cout<<curr->data.name<<" "<<"Status: "<<(curr->data.status?"On":"OFF")<<endl;
			if(curr->left){
				q.push(curr->left.get());
			}
			if(curr->right){
				q.push(curr->right.get());
			}
		}
		cout<<endl;
	}


};
int main(){
	BST t;
	t.insert();
	cout<<"Level order Traversal"<<endl;
	t.level_order();

	return 0;
}

