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

//func to find value just larger than x
TreeNode<int>* justLarger(TreeNode<int>* root, int x){
    TreeNode<int>* ans;
    if(root->data>x){
        ans=root;
    }
    else{
        ans=NULL;
    }

    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* temp = justLarger(root->children[i],x);
        if(ans==NULL || ans>temp){
            ans=temp;
        }
    }

    return ans;
}

int main(){
    TreeNode<int>* root = takeInput2();
    int x;
    cout<<"Enter the no for which the larger no is to be found : "<<endl;
    cin>>x;
    cout<<justLarger(root,x)->data<<endl;
    delete root;
}