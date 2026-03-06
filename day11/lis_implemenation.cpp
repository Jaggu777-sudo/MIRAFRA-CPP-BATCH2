#include <iostream>
using namespace std;

struct Node{
    Node *prev;
    int data;
    Node *next;

    Node (int val):data(val){
        prev = next = nullptr;
    }
};

template<class T>
class List{
    Node *head;
    Node *tail;

public:
    List (){
        head = nullptr;
        tail = nullptr;
    }

    ~List() {
        while (head)
            pop_front();   
    }

    List(const List& other) : head(nullptr), tail(nullptr) {
        Node* temp = other.head;
        while (temp) {
            push_back(temp->data);
            temp = temp->next;
        }
    }

    List(List&& other) noexcept 
        : head(other.head), tail(other.tail) {
        other.head = nullptr;
        other.tail = nullptr;
    }

    List& operator=(const List& other) {
        if (this == &other) 
            return *this;

        while (head)
            pop_front();

        Node* temp = other.head;
        while (temp) {
            push_back(temp->data);
            temp = temp->next;
        }

        return *this;
    }

    List& operator=(List&& other) noexcept {
        if (this == &other) 
            return *this;

        while (head)
            pop_front();

        head = other.head;
        tail = other.tail;

        other.head = nullptr;
        other.tail = nullptr;

        return *this;
    }

    void push_front(int v){
        Node *new_node = new Node(v);

        if(!head){
            head = tail = new_node;
        }
        else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    void push_back(int val){
        if(!head){
            push_front(val);
            return;
        }

        Node *new_node = new Node(val);

        tail->next = new_node;    
        new_node->prev = tail;
        tail = new_node;          
    }

    void pop_front() {
        if(!head)
            return;

        Node *temp = head;

        if(head->next) {
            head = head->next;
            head->prev = nullptr;
        }
        else {
            head = tail = nullptr;   
        }

        delete temp;
    }

    void pop_back() {
        if(!tail)
            return;

        Node *temp = tail;

        if(head == tail)
            head = tail = nullptr;
        else{
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;
    }

    T& front() {              
        return head->data;
    }
    Node *begin(){
    return head;
    }
    Node *end(){
    return tail;
    }

    bool empty() const {      
        return head == nullptr;
    }
};
int main()
{
List<int> l1;
l1.push_back(10);
l1.push_back(20);
l1.push_front(9);
l1.push_front(8);
l1.pop_back();
l1.pop_back();

for(auto it=l1.begin();it!=nullptr;it=it->next){

cout<<it->data<<" ";
}
cout<<endl;

}

