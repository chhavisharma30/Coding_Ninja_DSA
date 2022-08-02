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

int countlength(Node* head){     //recursively
    if(head==NULL){
        return 0;
    }
    int smallop = countlength(head->next);
    return smallop+1;
}

//complexity O(n^2)
void rev1(Node* head){
    int len = countlength(head);
    for(int i=0;i<len;i++){
        Node* temp = head;
        for(int j=0;j<len-i-1;j++){
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }
}

//complexity O(n)
void rev(Node* head){
    if(head==NULL){
        return;
    }
    rev(head->next);
    cout<<head->data<<endl;
}

int main(){
    Node* head = takeinput2();
    //rev(head);
    rev1(head);
}