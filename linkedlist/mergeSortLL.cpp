/*Given a singly linked list of integers, sort it using 'Merge Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
*/
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

Node* merge(Node*h1, Node* h2){
    Node* fh= NULL;
    Node* ft = NULL;

    if(h1->data<h2->data){
            fh = h1;
            ft = h1;
            h1 = h1->next;
    }
    else{
        fh = h2;
        ft = h2;
        h2 = h2->next;
    }

    while(h1!=NULL && h2 != NULL){
        if(h1->data<h2->data){
            ft->next=h1;
            h1 = h1->next;
        }
        else{
            ft->next=h2;
            h2 = h2->next;
        }
        ft = ft->next;
    }

    if(h1!=NULL){
        ft->next = h1;
    }
    if(h2!=NULL){
        ft->next = h2;
    }

    return fh;
}
int countlength(Node* head){     //recursively
    if(head==NULL){
        return 0;
    }
    int smallop = countlength(head->next);
    return smallop+1;
}

Node* mid(Node* head){
    int len = countlength(head);
    int m = (len-1)/2;                 // did len-1 cuz in case of even, we want to find the first mid 
    Node* temp = head;
    for(int i=0;i<m;i++){
        temp = temp->next;
    }
    return temp;
}

Node* mergeSort(Node* head){
    if(head == NULL||head->next==NULL){
        return head;
    }
    Node* m = mid(head);
    Node* head2 = m->next;
    m->next=NULL;
    Node* h1 = mergeSort(head);
    Node* h2 = mergeSort(head2);
    Node* finalhead = merge(h1,h2);
    return finalhead;
}

int main(){
    Node* head = takeinput2();
    Node* h1=mergeSort(head);
    print(h1);
}