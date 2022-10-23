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

//func to find if a number exists in binary search tree
bool searchBST(BinaryTreeNode<int>* root,int x){
    if(root==NULL){
        return false;
    }

    if(root->data==x){
        return true;
    }

    else if(root->data<x){
        bool ans = searchBST(root->right,x);
        if(ans==true){
            return true;
        }
    }
    else{
        bool ans = searchBST(root->left,x);
        if(ans==true){
            return true;
        }
    }

    return false;
}

int main(){
    BinaryTreeNode<int>* root = takeInput2();
    cout<<"Enter the no you wanna search : "<<endl;
    int x;
    cin>>x;
    cout<<searchBST(root,x)<<endl;

}