#include<iostream>
#include<climits>
using namespace std;


//making stack of generic type
template<typename T>

class Stack{
    private:
    T *data;
    int capacity;
    int nextIndex;

    public:

    //constructor
    Stack(){
        data = new T[4];
        nextIndex=0;
        capacity=4;
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
    void push(T element){

        // if stack is full then creating new stack and moving the elements into new stack of large size
        if(nextIndex==capacity){
           T *newData = new T[2*capacity];
           for(int i=0;i<capacity;i++){
            newData[i]=data[i];
           }
           delete[] data;
           data = newData;
        }
        data[nextIndex]=element;
        nextIndex++;
    }

    //function to pop element from stack
    T pop(){
        if(isEmpty()){
            cout<<"Empty Stack"<<endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    //function to return top element of stack
    T top(){
        if(isEmpty()){
            cout<<"Empty Stack"<<endl;
            return 0;
        }
        return data[nextIndex-1];
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