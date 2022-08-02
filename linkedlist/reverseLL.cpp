/*Given a singly linked list of integers, reverse it using recursion and return the head to the modified list.
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^4
Where M is the size of the singly linked list.

Time Limit: 1sec*/

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

//complexity O(n^2)
/*Node* reverse(Node* head){
    if(head->next==NULL){
        return head;
    }

    Node* smallhead = reverse(head->next);
    Node* temp = smallhead;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = head;
    head->next=NULL;
    return smallhead;
}*/

//complexity O(n)-make a class in which maintain head and tail of pair both
/*class Pair{
    public:
    Node* head;
    Node* tail;
};

Pair reverse1(Node* head){
    if(head->next==NULL){
        Pair ans;
        ans.head=head;
        ans.tail=head;
        return ans;
    }

    Pair smallans = reverse1(head->next);
    smallans.tail->next=head;
    head->next=NULL;
    Pair ans;
    ans.head = smallans.head;
    ans.tail = head;
    return ans;
}

Node* rev1(Node* head){
    return (reverse1(head).head);
}*/

//complexity O(n)-best approach
/*Node* reverse2(Node* head){
    if(head->next==NULL){
        return head;
    }

    Node* smallhead = reverse2(head->next);
    Node* tail = head->next;
    tail->next = head;
    head->next=NULL;
    return smallhead;
}*/

//Iterative approach O(n)
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

int main(){
    Node* head = takeinput2();
    Node* hnew= reverse3(head);
    print(hnew);
}