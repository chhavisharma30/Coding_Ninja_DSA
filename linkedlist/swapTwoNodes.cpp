/*You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th'  and 'j-th' positions.
Note :
Remember, the nodes themselves must be swapped and not the datas.

No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'i,' and 'j,' respectively. A single space will separate them.

Remember/consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= i < M
0 <= j < M*/

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

Node* swapNodes(Node* head, int x,int y){
   Node* t1 = head;
   Node* t2 = head;
   Node* p1 = head;
   Node* p2 = head;


    // when nodes to be swapped are head and 1 node
   if(x==0 && abs(x-y)==1){
        int count =0;
        while(count!=y){
            t2=t2->next;
            count++;
        }

        t1->next = t2->next;
        t2->next=t1;
        head = t2;
        return head;
    }

    //when one node is head node
    else if(x==0){
        int count =0;
        while(count!=y-1){
            p2=p2->next;
            count++;
        }
        t2=p2->next;

        Node* temp = t2->next;
        t2->next = t1->next;
        p2->next=t1;
        t1->next = temp;
        head = t2;
        return head;
    }

    //when nodes to be swapped are adjacent to each other
    else if(abs(x-y)==1){

        int count = 0;
        while(count!=x-1){
    p1 = p1->next;
    count++;
   }
   t1=p1->next;
    count =0;
    while(count!=y){
        t2 = t2->next;
        count++;
    }

   p1->next=t2;
   Node* temp = t2->next;
   t2->next=t1;
   t1->next=temp;

   return head;
    }

    else{
   int count =0;

   while(count!=x-1){
    p1 = p1->next;
    count++;
   }

    t1 = p1->next;
    count =0;
    while(count!=y-1){
        p2 = p2->next;
        count++;
    }

    t2=p2->next;

    p1->next=t2;
    Node*temp = t2->next;
    t2->next=t1->next;
    p2->next=t1;
    t1->next=temp;

    return head;
    }
}

int main(){
    Node* head = takeinput2();
    int x,y;
    cin>>x>>y;
    head = swapNodes(head,x,y);
    print(head);
}