/*Implement a Stack Data Structure specifically to store integer data using a Singly Linked List.
The data members should be private.
You need to implement the following public functions :
1. Constructor:
It initialises the data members as required.
2. push(data) :
This function should take one argument of type integer. It pushes the element into the stack and returns nothing.
3. pop() :
It pops the element from the top of the stack and in turn, returns the element being popped or deleted. In case the stack is empty, it returns -1.
4. top :
It returns the element being kept at the top of the stack. In case the stack is empty, it returns -1.
5. size() :
It returns the size of the stack at any given instance of time.
6. isEmpty() :
It returns a boolean value indicating whether the stack is empty or not.
Operations Performed on the Stack:
Query-1(Denoted by an integer 1): Pushes an integer data to the stack.

Query-2(Denoted by an integer 2): Pops the data kept at the top of the stack and returns it to the caller.

Query-3(Denoted by an integer 3): Fetches and returns the data being kept at the top of the stack but doesn't remove it, unlike the pop function.

Query-4(Denoted by an integer 4): Returns the current size of the stack.

Query-5(Denoted by an integer 5): Returns a boolean value denoting whether the stack is empty or not.*/

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

int main(){
    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout<<s.top()<<endl;

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    cout<<s.size()<<endl;

    cout<<s.isEmpty()<<endl;

    Stack<char> s2;

    s2.push(100);
    s2.push(101);
    s2.push(102);
    s2.push(103);
    s2.push(104);

    cout<<s2.top()<<endl;

    cout<<s2.pop()<<endl;
    cout<<s2.pop()<<endl;
    cout<<s2.pop()<<endl;

    cout<<s2.size()<<endl;

    cout<<s2.isEmpty()<<endl;
}

//pushed the nodes in the beginning to perform pop operation in O(1) time complexity