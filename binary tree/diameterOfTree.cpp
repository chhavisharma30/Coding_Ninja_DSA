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

//func to find height of the tree
int height(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return 1+ max(height(root->left),height(root->right));
}

//func to find diameter of the tree
//time complexity = O(n*h) where h = height
//for its time complexity explanation - visit dsa notes folder
int diameter(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int d1 = height(root->left)+height(root->right);
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);

    return max(d1,max(d2,d3)); 
}

//func to find diameter of tree - better approach
//time complexity = O(n)
pair<int,int> heightDiameter(BinaryTreeNode<int>* root){
    if(root==NULL){
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }

    pair<int,int> leftans = heightDiameter(root->left);
    pair<int,int> rightans = heightDiameter(root->right);

    int ld = leftans.second;
    int lh= leftans.first;
    int rd = rightans.second;
    int rh = rightans.first;

    int height = 1 + max(lh,rh);
    int diameter = max(lh+rh,max(ld,rd));
    pair<int,int> p ;
    p.first = height;
    p.second = diameter;
    return p;
}

int main(){
    BinaryTreeNode<int>* root = takeInput2();
    pair<int,int> p = heightDiameter(root);
    cout<<"Height : "<<p.first<<endl;
    cout<<"Diameter : "<<p.second<<endl;
}