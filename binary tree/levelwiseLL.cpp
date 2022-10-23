/*Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//tree node
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

//func to make LinkedList levelwise
vector<Node*> makeLL(BinaryTreeNode<int>* root){
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    Node* head = NULL;
    Node* tail = NULL;
    vector<Node*> output;

    while(pendingNodes.size()!=0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        if(front==NULL){
            output.push_back(head);
            pendingNodes.pop();
            head = NULL;
            tail = NULL;
            if(pendingNodes.size()!=0)
                pendingNodes.push(NULL);
        }else{
            Node* temp = new Node(front->data);
            if(head == NULL){
                head = temp;
                tail = temp;
            }
            else{
                tail->next = temp;
                tail = temp;
            }

        pendingNodes.pop();
        if(front->left!=NULL)
            pendingNodes.push(front->left);
        
        if(front->right!=NULL)
           pendingNodes.push(front->right);
        
        }
    }
    return output;
}

int main(){
    BinaryTreeNode<int>* root = takeInput2();
    vector<Node*> output = makeLL(root);
    int x = output.size();
    int i=0;
    while(x!=0){
        print(output[i]);
        cout<<endl;
        i++;
        x--;
    }
}