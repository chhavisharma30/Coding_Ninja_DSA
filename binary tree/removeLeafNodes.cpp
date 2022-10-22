/*Remove all leaf nodes from a given Binary Tree. Leaf nodes are those nodes, which don't have any children.
Note : Root will also be a leaf node if it doesn't have left and right child. You don't need to print the tree, just remove all leaf nodes and return the updated root.
Input format :
Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Output Format :
Elements are printed level wise, each level in new line (separated by space).

Sample Input :
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

Sample Output :
8
3 10
6 14*/
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

//func to remove all the leaf nodes of the tree
BinaryTreeNode<int>* removeLeaves(BinaryTreeNode<int>* root){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        delete root;
        return NULL;
    }
    BinaryTreeNode<int>* leftTree =  removeLeaves(root->left);
    BinaryTreeNode<int>* rightTree = removeLeaves(root->right);
    root->left=leftTree;
    root->right=rightTree;
    return root;
}

//func to print tree levelwise
void printTree2(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    while(pendingNodes.size()!=0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        if(front==NULL){
            cout<<endl;
            pendingNodes.pop();
            if(pendingNodes.size()!=0)
                pendingNodes.push(NULL);
        }else{
        cout<<front->data<<" ";
        pendingNodes.pop();
        if(front->left!=NULL)
            pendingNodes.push(front->left);
        
        if(front->right!=NULL)
           pendingNodes.push(front->right);
        
        }
    }
}

int main(){
    BinaryTreeNode<int>* root = takeInput2();
    BinaryTreeNode<int>* root2 = removeLeaves(root);
    printTree2(root2);
}
    