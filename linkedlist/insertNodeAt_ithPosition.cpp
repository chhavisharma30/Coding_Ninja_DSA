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

/*Node* insertnode(Node* head, int i,int data){
    Node* newnode = new Node(data);

    if(i==0){
        newnode->next=head;
        head = newnode;
        return head;
    }

    int count=0;
    Node*temp = head;

    while(temp != NULL && count<i-1){
        temp=temp->next;
        count++;
    }
    if(temp != NULL){
    newnode->next = temp->next;
    temp->next = newnode;
    }
    return head;
}*/

Node* insertnode(Node* head, int i,int data){     //recursively
   if(head==NULL){
    return head;
   }
   if(i==0){
    Node* newnode = new Node(data);
    newnode->next=head;
    head = newnode;
    return head;
   }

   Node* smallop=insertnode(head->next,i-1,data);
   head->next=smallop;
   return head;
}

int main(){
    Node* head = takeinput2();
    int i,data;
    cin>>i>>data;
    head = insertnode(head,i,data);
    print(head);
}