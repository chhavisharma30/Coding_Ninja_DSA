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

void delnodes(Node* head,int m,int n){
    Node*t1=head;
    int c1,c2;

    while(t1!=NULL){
    for(c1 =1;c1<m && t1!=NULL; c1++){
        t1=t1->next;
    }
    Node* t2 = t1->next;
    for(c2 =1;c2<n&& t2!=NULL;c2++){
        t2=t2->next;
    }
    if(t2!=NULL){
        t2=t2->next;
    }
    t1->next=t2;
    t1=t2;
    c1=1;
    c2=1;
    }

}

int main(){
    Node* head = takeinput2();
    int m,n;
    cin>>m>>n;
    if(m==0){
        head=NULL;
        print(head);
        return 0;
    }
    delnodes(head,m,n);
    print(head);
    return 0;
}