#include<iostream>
#include<stack>
#include<memory>
#include<optional>
using namespace std;
class BST{
	public:
		struct Tree{
			int sensor_id;
			double temperature_reading;
			unique_ptr<Tree>left;
			unique_ptr<Tree>right;
			Tree(int s,double r):sensor_id(s),temperature_reading(r){}
		};
		unique_ptr<Tree>root;
		void insert(int id,double reading){
			insert_impl(root,id,reading);
		}
		std::optional<double> findMax(){
			if(!root){
				return nullopt;
			}
			Tree *curr=root.get();
			while(curr->right){
				curr=curr->right.get();
			}
			return curr->temperature_reading;
		}
		std::optional<double> findMin(){
			if(!root){
				return nullopt;
			}
			Tree *curr=root.get();
			while(curr->left){
				curr=curr->left.get();
			}
			return curr->temperature_reading;
		}
		bool search(int id){
			return search_impl(root.get(),id);
		}
	private:
		bool search_impl(Tree *root,int id){
			if(!root){
				return false;
			}
			stack<Tree *>s;
			s.push(root);
			while(!s.empty()){
				Tree *curr=s.top();
				s.pop();
				if(curr->sensor_id==id){
					return true;
				}
				if(curr->right){
					s.push(curr->right.get());
				}
				if(curr->left){
					s.push(curr->left.get());
				}
			}
			return false;
		}
		void insert_impl(unique_ptr<Tree>&root,int id,double reading){
			if(!root){
				root=std::make_unique<Tree>(id,reading);
				return;
			}
			if(reading<root->temperature_reading){
				insert_impl(root->left,id,reading);
			}
			else if(reading>root->temperature_reading){
				insert_impl(root->right,id,reading);
			} 
		}
};
int main(){
	BST obj;
	obj.insert(1001,24.5);//Air Temperature Sensor
	obj.insert(1006,18.2);//Soil Temperature Sensor
	obj.insert(1016,22.0);//Humidity Sensor
	obj.insert(2007,15.8);//soil temperature Sensor
	obj.insert(2018,19.1);//Leaf temperature Sensor
	cout<<"Search Leaf temperature Sensor"<<endl;
	cout<<boolalpha<<obj.search(2018)<<endl;
	auto max_temp=obj.findMax();
	if(max_temp.has_value()){
		cout<<"Max Temperature Value :"<<max_temp.value()<<endl;
	}
	auto min_temp=obj.findMin();
	if(min_temp.has_value()){
		cout<<"Min Temperature Value :"<<min_temp.value()<<endl;
	}
	return 0;
}

