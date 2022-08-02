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

//first approach
Node* eliminatedups(Node* head){
    Node*temp=head;
    while(temp->next!=NULL){
        if(temp->data==temp->next->data){
            Node* a = temp->next;
            temp->next=a->next;
            delete a;
            continue;
        }
        temp=temp->next;
    }
    return head;
}

//second approach
Node* eliminatedups2(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* t1 = head;
    Node* t2 = head;

    while(t2!=NULL){
        if(t1->data!=t2->data){
            t1->next=t2;
            t1=t2;
        }
        t2=t2->next;
    }
    if(t1!=t2){
            t1->next=NULL;
        }
    return head;
}

int main(){
    Node* head = takeinput2();
    //Node* newhead = eliminatedups(head);
    Node* newhead = eliminatedups2(head);
    print(newhead);
}