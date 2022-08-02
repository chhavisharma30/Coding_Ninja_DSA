/*You have been given two sorted(in ascending order) singly linked lists of integers.
Write a function to merge them in such a way that the resulting singly linked list is also sorted(in ascending order) and return the new head to the list.
Note :
Try solving this in O(1) auxiliary space.

No need to print the list, it has already been taken care.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the first sorted singly linked list separated by a single space.

The second line of the input contains the elements of the second sorted singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output :
For each test case/query, print the resulting sorted singly linked list, separated by a single space.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t = 10^2
0 <= N <= 10 ^ 4
0 <= M <= 10 ^ 4
Where N and M denote the sizes of the singly linked lists.

Time Limit: 1sec
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
            ft = h1;
            h1 = h1->next;
        }
        else{
            ft->next=h2;
            ft = h2;
            h2 = h2->next;
        }
    }

    if(h1!=NULL){
        ft->next = h1;
    }
    if(h2!=NULL){
        ft->next = h2;
    }

    return fh;
}

int main(){
    Node* head1 = takeinput2();
    Node* head2 = takeinput2();
    Node * fh = merge(head1,head2);
    print(fh);
}