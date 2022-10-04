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

//func to find if two trees are structurally identical or not
bool checkStructure(TreeNode<int>* root1,TreeNode<int>* root2){

    if(root1->data!=root2->data){
        return false;
    }
    bool ans=true;
    if(root1->children.size()==root2->children.size()){
        for(int i=0;i<root1->children.size();i++){
            ans=checkStructure(root1->children[i],root2->children[i]);
            if(ans==false){
                break;
            }
        }
    }
    return ans;
}

int main(){
    TreeNode<int>* root1 = takeInput2();
    TreeNode<int>* root2 = takeInput2();
    cout<<checkStructure(root1,root2)<<endl;
    delete root1;
    delete root2;
}