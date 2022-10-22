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

//func to build BST using sorted array
BinaryTreeNode<int>* buildBST(int a[],int si,int ei){
    
    if(si>ei){
        return NULL;
    }

    int mid = (si+ei)/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(a[mid]);
    BinaryTreeNode<int>* leftNode = buildBST(a,si,mid-1);
    BinaryTreeNode<int>* rightNode = buildBST(a,mid+1,ei);
    root->left=leftNode;
    root->right=rightNode;
    return root;

}

//func to print tree levelwise
void printTree2(BinaryTreeNode<int>* root){
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

int main(){
    int n;
    cout<<"Enter size of the array : ";
    cin>>n;
    int a[n];
    cout<<"Enter array elements : "<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    BinaryTreeNode<int>* root = buildBST(a,0,n-1);
    printTree2(root);
    delete root;
}