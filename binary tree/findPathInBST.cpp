#include<iostream>
#include<queue>
using namespace std;
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

//func to find path of node from root in BST
vector<int>* findPath(BinaryTreeNode<int>* root,int data){
    if(root==NULL){
        return NULL;
    }

    if(root->data==data){
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    else if(root->data>data){
    vector<int>* leftop = findPath(root->left,data);
    if(leftop!=NULL){
        leftop->push_back(root->data);
        return leftop;
    }else{
        return NULL;
    }
    }

    else if(root->data<data){
    vector<int>* rightop = findPath(root->right,data);
    if(rightop!=NULL){
        rightop->push_back(root->data);
        return rightop;
    }else{
        return NULL;
    }}
}

int main(){
    BinaryTreeNode<int>* root = takeInput2();
    int x;
    cout<<"Enter the node for which you want to find the path: ";
    cin>>x;
    vector<int>* op = findPath(root,x);
    for(int i=0;i<op->size();i++){
        cout<<op->at(i)<<" ";
    }
    delete op;
    delete root;
}