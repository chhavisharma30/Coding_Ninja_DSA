/*You have been given a linked list of integers. Your task is to write a function that deletes a node from a given position, 'pos'.
Note :
Assume that the Indexing for the linked list always starts from 0.

If the position is greater than or equal to the length of the linked list, you should return the same linked list without any change.

Illustration :
The following images depict how the deletion has been performed.

Image-I :

Image-II :

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the linked list separated by a single space.

The second line of each test case contains the integer value of 'pos'. It denotes the position in the linked list from where the node has to be deleted.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the resulting linked list of integers in a row, separated by a single space.

Output for every test case will be printed in a seperate line.
You don't need to print explicitly, it has been taken care of.*/
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

/*Node* deletenode(Node* head, int i){

    if(i==0){
        Node* a = head;
        head = head->next;
        delete a;
        return head;
    }

    int count=0;
    Node*temp = head;

    while(temp != NULL && count<i-1){
        temp=temp->next;
        count++;
    }
    if(temp != NULL){
        Node* b = temp->next;
        Node* c = b->next;
        temp->next = c;
        delete b;
    }
    return head;
}*/

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
    return head;
}

int main(){
    Node* head = takeinput2();
    int i;
    cin>>i;
    head = deletenode(head,i);
    print(head);
}