#include<iostream>
#include<queue>         //header file to use inbuilt queue
using namespace std;

int main(){
    queue<int> q;
    q.push(10);         //to insert an element in queue
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    cout<<q.front()<<endl;      //to get first element of queue

    q.pop();            //to delete an element from queue

    q.push(70);
    q.push(80);
    
    cout<<q.front()<<endl;

    cout<<q.size()<<endl;       //to get size of queue

    cout<<q.empty()<<endl;      //to check whether queue is empty
}