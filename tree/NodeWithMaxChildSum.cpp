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

    //second way of deleting the tree
 ~TreeNode(){
    for(int i=0;i<children.size();i++){
        delete children[i];
    }
 }
};

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

//func to find and return the node for which sum of its data and data of all its child nodes is maximum
TreeNode<int>* maxChildSum(TreeNode<int>* root){
    TreeNode<int>* ans = root;
    int sum=root->data;
    for(int i=0;i<root->children.size();i++){
        sum+=root->children[i]->data;
    }

    TreeNode<int>* x ;

    for(int i=0;i<root->children.size();i++){
        x = maxChildSum(root->children[i]);
    int xsum = x->data;
    for(int i=0;i<x->children.size();i++){
        xsum += x->children[i]->data;
    }

    if(xsum>sum){
        sum=xsum;
        ans=x;
    }
    }

    return ans;
}

int main(){
    TreeNode<int>* root = takeInput2();
    TreeNode<int>* res=maxChildSum(root);
    cout<<res->data<<endl;
    delete root;
}