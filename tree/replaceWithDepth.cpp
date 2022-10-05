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

//func to replace all nodes with their depth
void replaceWithDepth(TreeNode<int>* root,int depth){
    root->data=depth;
    for(int i=0;i<root->children.size();i++){
        replaceWithDepth(root->children[i],depth+1);
    }
}

int main(){
    TreeNode<int>* root = takeInput2();
    replaceWithDepth(root,0);
    printTree2(root);
    delete root;
}