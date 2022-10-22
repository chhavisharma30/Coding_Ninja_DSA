/*Given a BST, convert it into a sorted linked list. You have to return the head of LL.
Input format:
The first and only line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output Format:
The first and only line of output prints the elements of sorted linked list.*/
#include<iostream>
#include<queue>
using namespace std;

//binary tree node class
template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T data){
        this->data=data;
        left = NULL;
        right=NULL;
    }

    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

//linked list node
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        next = NULL;
    }
};

//func to print Linked List
void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

//func to take input for tree levelwise
BinaryTreeNode<int>* takeInput2(){
    int rootData;
    cout<<"Enter root data : "<<endl;
    cin>>rootData;

    if(rootData==-1){
        return NULL;
    }

    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int leftData;
        cout<<"Enter the left child of "<<front->data<<endl;
        cin>>leftData;
        if(leftData!=-1){
        BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftData);
        front->left = leftChild;
        pendingNodes.push(leftChild);
        }

        int rightData;
        cout<<"Enter the right child of "<<front->data<<endl;
        cin>>rightData;
        if(rightData!=-1){
        BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightData);
        front->right = rightChild;
        pendingNodes.push(rightChild);
        }
    }
    return root;
}

class LL{
    public:
    Node* head;
    Node* tail;
};

//func to make sorted LL from BST
LL sortedLL(BinaryTreeNode<int>* root){
    if(root==NULL){
        LL output;
        output.head = NULL;
        output.tail = NULL;
        return output;
    }

    Node* r = new Node(root->data);
    if(root->left==NULL && root->right==NULL){
        LL output;
        output.head = r;
        output.tail = r;
        return output;
    }
    else{
    LL leftop = sortedLL(root->left);
    LL rightop = sortedLL(root->right);

    LL output;

    if(leftop.head!=NULL && rightop.head!=NULL){
    leftop.tail->next= r;
    r->next = rightop.head;
    output.head = leftop.head;
    output.tail = rightop.tail;
    }

    else if(leftop.head==NULL){
        r->next=rightop.head;
        output.head=r;
        output.tail=rightop.tail;
    }
    
    else if(rightop.head==NULL){
        leftop.tail->next=r;
        output.head=leftop.head;
        output.tail=r;
    }
    
    return output;
    }
}

int main(){
    BinaryTreeNode<int>* root = takeInput2();
    LL output = sortedLL(root);
    print(output.head);
}