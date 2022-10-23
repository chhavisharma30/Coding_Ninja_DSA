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

//func to find max and min of tree
pair<int,int> maxAndMin(BinaryTreeNode<int>* root){
    if(root==NULL){
        pair<int,int> p;
        p.first=INT16_MIN;
        p.second=INT16_MAX;
        return p;
    }
    if(root->left==NULL && root->right ==NULL){
        pair<int,int> p;
        p.first = root->data;
        p.second = root->data;
        return p;
    }

    pair<int,int> leftans = maxAndMin(root->left);
    pair<int,int> rightans = maxAndMin(root->right);
    pair<int,int> ans;
    ans.first = max(root->data,max(leftans.first,rightans.first));
    ans.second = min(root->data,min(leftans.second,rightans.second));
    return ans;
}

int main(){
    BinaryTreeNode<int>* root = takeInput2();
    pair<int,int> p = maxAndMin(root);
    cout<<"Max : "<<p.first<<endl;
    cout<<"Min : "<<p.second<<endl; 
}