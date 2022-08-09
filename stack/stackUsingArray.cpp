#include<iostream>
#include<climits>
using namespace std;

class Stack{
    private:
    int *data;
    int capacity;
    int nextIndex;

    public:

    //constructor
    Stack(int totaLSize){
        data = new int[totaLSize];
        nextIndex=0;
        capacity=totaLSize;
    }

    //function to return size of stack
    int size(){
        return nextIndex;
    }

    //function to check whether stack is empty or not
    bool isEmpty(){
        /*if(nextIndex==0){
            return true;
        }
        else{
            return false;
        }*/

        return nextIndex==0;
    }

    //function to push an element in stack 
    void push(int element){
        if(nextIndex==capacity){
            cout<<"Stack Full"<<endl;
            return;
        }
        data[nextIndex]=element;
        nextIndex++;
    }

    //function to pop element from stack
    int pop(){
        if(isEmpty()){
            cout<<"Empty Stack"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    //function to return top element of stack
    int top(){
        if(isEmpty()){
            cout<<"Empty Stack"<<endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }
};

int main(){
    Stack s(4);

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
}