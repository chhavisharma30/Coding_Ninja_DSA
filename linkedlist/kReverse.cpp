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

Node* reverse3(Node* head){
    Node* prev= NULL;
    Node* curr = head;
    Node* nexxt = NULL;

    while(curr!=NULL){
        nexxt = curr->next;
        curr->next=prev;
        prev= curr;
        curr = nexxt;
    }
    head = prev;
    return head;
}

Node* reverseK(Node* head, int k){
    if(k==0){
        return head;
    }

    Node* h1 = head;
    Node* t1 = head;
    Node* h2;

        int c=1;
        while(c!=k && t1->next!=NULL){
            t1 = t1->next;
            c++;
        }
        h2 = t1->next;

        Node* hnew2= reverseK(h2,k);
        
        t1->next=NULL;
        Node* hnew = reverse3(head);
        Node* tnew = hnew;
        while(tnew->next!=NULL){
            tnew=tnew->next;
        }
        
        tnew ->next = hnew2;
        return hnew;
}

int main(){
    Node* head = takeinput2();
    int k;
    cin>>k;
    Node *hnew = reverseK(head,k);
    print(hnew);
}