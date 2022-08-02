#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        next = NULL;
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

//its complexity is O(n^2)
/*Node* takeinput(){
    int d;
    cin>>d;
    Node* head = NULL;
    while(d != -1){
        Node* newnode = new Node(d);
        if(head == NULL){
            head = newnode;
        }
        else{
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next=newnode;
        }
        cin>>d;
    }
    return head;
}*/


//its complexity is O(n)
Node* takeinput2(){
    int d;
    cin>>d;
    Node* head = NULL;
    Node* tail = NULL;
    while(d != -1){
        Node* newnode = new Node(d);
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            Node* temp = head;
            tail->next=newnode; 
            tail = newnode;     //OR  tail = tail->next
        }
        cin>>d;
    }
    return head;
}

int main(){
    Node* head = takeinput2();
    print(head);
}