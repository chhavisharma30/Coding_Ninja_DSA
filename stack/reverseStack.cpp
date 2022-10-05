#include<iostream>
using namespace std;

template<typename T>
class Node{
    public:
    T data;
    Node<T>* next;
    Node(T data){
        this->data=data;
        this->next=NULL;
    }
};

template<typename T>
class Stack{
    Node<T>* head;
    int s;

    public:

    Stack(){
        head = NULL;
        s=0;
    }

    int size(){
        return s;
    }

    bool isEmpty(){
        if(head==NULL){
            return true;
        }
        else{
            return false;
        }

        //OR return head==NULL;
    }

    void push(T element){
        Node<T>* newnode = new Node<T>(element);
            newnode->next=head;
            head=newnode;
        s++;
    }

    T pop(){
        if(isEmpty()){
            return 0;
        }
        Node<T>* temp = head;
        T ans = head->data;
        head = head->next;
        delete temp;
        s--;
        return ans;
    }

    T top(){
        if(isEmpty()){
            return 0;
        }
        return head->data;
    }
};

void reverseStack(Stack<int> s, Stack<int> temp){

    if(s.isEmpty()){
        return ;
    }
    int x = s.pop();
    reverseStack(s,temp);

    while(!(s.isEmpty())){
            temp.push(s.pop());
    }
    s.push(x);
    while(!(temp.isEmpty())){
            s.push(temp.pop());
    }
}

int main(){
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(10);

    Stack<int> temp;

    reverseStack(s,temp);
    cout<<s.top()<<endl;
}