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

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}

int main(){

    Node* n1 = new Node(10);     //creating node
    Node* head=n1;     //storing address of head node in head pointer

    Node* n2 = new Node(20);
    n1->next=n2;      //storing address of second node in next of first node

    Node* n3 = new Node(30);
    Node* n4 = new Node(40);
    Node* n5 = new Node(50);

    n2->next=n3;
    n3->next=n4;
    n4->next=n5;

    print(head);
}