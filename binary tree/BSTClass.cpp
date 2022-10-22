/*Problem Statement: BST Class
Problem Level: MEDIUM
Problem Description:
Implement the BST class which includes following functions -
1. search
Given an element, find if that is present in BST or not. Return true or false.
2. insert -
Given an element, insert that element in the BST at the correct position. Assume unique elements will be given.
3. delete -
Given an element, remove that element from the BST. If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.
4. printTree (recursive) -
Print the BST in ithe following format -
For printing a node with data N, you need to follow the exact format -
N:L:x,R:y

wherer, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print the children only if it is not null.
There is no space in between.
You need to print all nodes in the recursive format in different lines*/
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

//Binary Search Tree Class
class BST{
    BinaryTreeNode<int>* root;

    public:

    BST(){
        root=NULL;
    }

    ~BST(){
        delete root;
    }

    private:
    bool hasdata(int data, BinaryTreeNode<int>* node){
        if(node==NULL){
            return false;
        }
        if(node->data==data){
            return true;
        }
        else if(node->data>data){
            return hasdata(data,node->left);
        }
        else{
            return hasdata(data,node->right);
        }
    }

    BinaryTreeNode<int>* insertData(int data, BinaryTreeNode<int>* node){
        if(node==NULL){
            BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data); 
            return root;
        }
        else if(node->data>data){
            BinaryTreeNode<int>* leftroot= insertData(data, node->left);
            node->left=leftroot;
        }
        else{
            BinaryTreeNode<int>* rightroot= insertData(data, node->right);
            node->right=rightroot;
        }

        return node;
    }

    BinaryTreeNode<int>* deleteData(int data, BinaryTreeNode<int>* node){
        if(node == NULL){
            return NULL;
        }

        if(data>node->data){
            node->right = deleteData(data,node->right);
            return node;
        }else if(data<node->data){
            node->left=deleteData(data,node->left);
            return node;
        }else{
            if(node->left==NULL && node->right==NULL){
                delete node;
                return NULL;
            }
            else if(node->left==NULL){
                BinaryTreeNode<int>* temp = node->right;
                node->right=NULL;
                delete node;
                return temp;
            }
            else if(node->right==NULL){
                BinaryTreeNode<int>* temp = node->left;
                node->left=NULL;
                delete node;
                return temp;
            }
            else{
                BinaryTreeNode<int>* minNode = node->right;
                while(minNode->left!=NULL){
                    minNode=minNode->left;
                }
                int rightMin = minNode->data;
                node->data=rightMin;
                node->right=deleteData(rightMin,node->right);
                return node;
            }
        }


    }

    void printTree(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        cout<<front->data<<" : ";
        pendingNodes.pop();

        if(front->left==NULL){
            cout<<"L:-1"<<",";
        }
        else{
            cout<<"L:"<<front->left->data<<",";
            pendingNodes.push(front->left);
        }
        if(front->right==NULL){
            cout<<"R:-1";}
        else{
            cout<<"R:"<<front->right->data;
            pendingNodes.push(front->right);
        }

        cout<<endl;
    }
}

    public:

    //func to search data in BST
    bool hasdata(int data){
        hasdata(data,root);
    }

    //func to insert data in BST
    void insertData(int data){
        root=insertData(data,root);
    }

    //func to delete data in BST
    void deleteData(int data){
        root = deleteData(data,root);
    }

    //func to print tree levelwise
    void printTree(){
        printTree(root);
    }
};

int main(){
    BST b;
    b.insertData(10);
    b.insertData(5);
    b.insertData(20);
    b.insertData(7);
    b.insertData(3);
    b.insertData(15);
    b.printTree();

    b.deleteData(10);
    b.deleteData(100);
    b.printTree();
}

