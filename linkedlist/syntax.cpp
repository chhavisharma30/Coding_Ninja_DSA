#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        next=NULL;
    }
};

int main(){
    //Statically

    /*Node n1(1);  //creating node
    Node* head = &n1;   //storing address of head node in head pointer
    Node n2(2);

    n1.next=&n2;    //storing address of second node in next of first node
    cout<<n1.data<<" "<<n2.data<<endl;
    cout<<head->data<<" "<<head->next->data<<endl;*/

    //Dynamically

    Node* n3 = new Node(10);     //creating node
    Node* head=n3;     //storing address of head node in head pointer

    Node* n4 = new Node(20);
    n3->next=n4;      //storing address of second node in next of first node

    cout<<head->data<<" "<<head->next->data<<endl;
}