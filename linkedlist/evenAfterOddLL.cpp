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

Node* deletenode(Node* head, int i){

    if(head==NULL){
        return head;
    }
    if(i==0){
        Node* a = head;
        head=head->next;
        delete a;
        return head;
    }
    Node* smallop = deletenode(head->next,i-1);
    head->next=smallop;
}

Node* arrange(Node* head){
    Node* temp = head;
    Node* headnew=NULL;
    Node* newlist;
    int pos=0;
    while(temp!=NULL){
        if(temp->data%2==0){
            if(headnew==NULL){
                headnew = new Node(temp->data);
                newlist=headnew;
            }
            else{
                newlist->next=temp;
                newlist = newlist->next;
                newlist->next = NULL;
            }
            head = deletenode(head,pos);
        }
        temp = temp->next;
        pos++;
    }
    temp->next = headnew;
    return head;
}

int main(){
    Node* head = takeinput2();
    Node* newh = arrange(head);
    print(newh);
}