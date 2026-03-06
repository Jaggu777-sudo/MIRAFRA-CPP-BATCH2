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

template<typename T>
class myqueue {
    List<T> l;

public:
    myqueue() {}

    myqueue(const myqueue& other) : l(other.l) {}

    myqueue(myqueue&& other) noexcept 
        : l(std::move(other.l)) {}

    myqueue& operator=(const myqueue& other) {
        if (this == &other) 
        return *this;
        l = other.l;
        return *this;
    }

    myqueue& operator=(myqueue&& other) noexcept {
        if (this == &other) 
        return *this;
        l = std::move(other.l);
        return *this;
    }

    void push(const T& value) {
        l.push_back(value);
    }

    void pop() {
        l.pop_front();
    }

    T& front() {
        return l.front();    
    }

    bool empty() const {
        return l.empty();
    }
};

int main() {
    myqueue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
   myqueue<int>q1=move(q);
   // cout << q1.front() << endl; 
   // cout << q.front() << endl;
   while(!q1.empty()){
   cout<<q1.front()<<" ";
   q1.pop();
   }
}

