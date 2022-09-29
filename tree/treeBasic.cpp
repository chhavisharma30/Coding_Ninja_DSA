#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//tree node class
template <typename T>
class TreeNode{
 public:
 T data;
 vector<TreeNode<T>*> children;

 TreeNode(T data){
    this->data=data;
 }   
};

//func to take input from user

TreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter the data : "<<endl;
    cin>>rootData;

    TreeNode<int>* root = new TreeNode<int>(rootData);

    int n;
    cout<<"Enter the no of children of "<<rootData<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }

    return root;
}


/*Coding Problem
Problem Statement: Print Tree level wise
Problem Level: MEDIUM
Problem Description:
Given a generic tree, print the input tree in level wise order.
For printing a node with data N, you need to follow the exact format -
N:x1,x2,x3,...,xn
where, N is data of any node present in the generic tree. x1, x2, x3, ...., xn are the children of node N. Note that there is no space in between.

You need to print all nodes in the level order form in different lines.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

Output Format :
The first and only line of output contains the elements of the tree in level wise order, as described in the task.

Constraints:
Time Limit: 1 sec

Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0

Sample Output 1:
10:20,30,40
20:40,50
30:
40:
40:
50:*/
//func to take input from user levelwise
TreeNode<int>* takeInput2(){
    int rootData;
    cout<<"Enter the data : "<<endl;
    cin>>rootData;

    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter no of children of "<<front->data<<endl;
        int numChild;
        cin>>numChild;

        for(int i=0;i<numChild;i++){
            int childData;
            cout<<"Enter the "<<i+1<<"th child of "<<front->data<<endl;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);    //we are not allocating statically anything because we would not be able to access its memory in next iteration and outside of this function
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

//func to print tree
void printTree(TreeNode<int>*root){
    if(root == NULL){   //edge case (not a base case)
        return;
    }

    cout<<root->data<<" : ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;

    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}

//func to print tree level wise
void printTree2(TreeNode<int>* root){

    queue<TreeNode<int>*> pNodes;
    pNodes.push(root);

    while(pNodes.size()!=0){
        TreeNode<int>* front = pNodes.front();
        cout<<front->data<<" : ";
        for(int i=0;i<front->children.size();i++){
        cout<<front->children[i]->data<<",";
        pNodes.push(front->children[i]);
    }
        cout<<endl;
        pNodes.pop();
    }
}

int main(){
    /*TreeNode<int> * root = new TreeNode<int>(1); 
    TreeNode<int> * node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);    

    root->children.push_back(node1);
    root->children.push_back(node2);*/


    //TreeNode<int>* root = takeInput();
    TreeNode<int>* root = takeInput2();
    //printTree(root);
    printTree2(root);
}