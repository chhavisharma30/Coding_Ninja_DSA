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

void swapNodes(Node* head, int x,int y){
    Node* t1=head;
    Node* t2=head;

    for(int i=0;i<y-1;i++){
        if(i<x-1)
            {t1=t1->next;}
        t2=t2->next;   
    }

    Node* temp=t1->next;
    t1->next=t2->next;
    Node* temp2 = t2->next->next;
    t2->next->next=temp->next;
    temp->next=temp2;
    t2->next=temp;
}

int main(){
    Node* head = takeinput2();
    int x,y;
    cin>>x>>y;
    swapNodes(head,x,y);
    print(head);
}