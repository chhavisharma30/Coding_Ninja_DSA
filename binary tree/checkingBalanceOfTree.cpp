/*Given a binary tree, check if its balanced i.e. depth of left and right subtrees of every node differ by at max 1. Return true if given binary tree is balanced, false otherwise.
Input format :
Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.

Sample Input 1 :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 1 :
false

Sample Input 2 :
1 2 3 -1 -1 -1 -1

Sample Output 2 :
true
*/

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
int heightOfTree(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int h1= heightOfTree(root->left);
    int h2= heightOfTree(root->right);
    if(h1>h2){
        return 1+h1;
    }else{
        return 1+h2;
    }
}

//func to check if tree is balanced
//time complexity O(n*h) where h is height of the tree
bool checkBalance(BinaryTreeNode<int>* root){
    if(root==NULL){
        return true;
    }

    if(abs(heightOfTree(root->left)-heightOfTree(root->right)) <= 1 ){
        return true;
    }
    else{
        return false;
    }
    bool ans1=checkBalance(root->left);
    bool ans2=checkBalance(root->right);

    return ans1&&ans2;
}

//helper function
pair<int,bool> checkBalanceHelper(BinaryTreeNode<int>* root){
    if(root==NULL){
        pair<int,bool> p;
        p.first = 0;
        p.second = true;
        return p;
    }

    pair<int,bool> leftans = checkBalanceHelper(root->left);
    pair<int,bool> rightans = checkBalanceHelper(root->right);

    pair<int,bool> ans;
    ans.first = 1+ max(leftans.first,rightans.first);
    if(leftans.second==false || rightans.second==false || abs(leftans.first-leftans.second)>1){
        ans.second=false;
    }else{
        ans.second=true;
    }
    return ans;
}

//func to check if tree is balanced - better approach
//time complexity - O(n)
bool checkBalance2(BinaryTreeNode<int>* root){
    pair<int,bool> p = checkBalanceHelper(root);
    return p.second;
}

int main(){
    BinaryTreeNode<int>* root = takeInput2();
    //cout<<checkBalance(root)<<endl;
    cout<<checkBalance2(root)<<endl;
}