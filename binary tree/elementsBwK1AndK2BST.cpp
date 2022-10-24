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

//func to print all no bw k1 and k2
void printNoInRangeBST(BinaryTreeNode<int>* root,int x1, int x2){
    if(root==NULL){
        return;
    }

    if(root->data>x1){
        printNoInRangeBST(root->left,x1,x2);
        }

    if(root->data>=x1 && root->data<=x2){
        cout<<root->data<<endl;
    }

        printNoInRangeBST(root->right,x1,x2);

}


int main(){
    BinaryTreeNode<int>* root = takeInput2();
    cout<<"Enter the upper limit : "<<endl;
    int x1,x2;
    cin>>x1;
    cout<<"Enter the lower limit : "<<endl;
    cin>>x2;
    printNoInRangeBST(root,x1,x2);
    delete root;
}