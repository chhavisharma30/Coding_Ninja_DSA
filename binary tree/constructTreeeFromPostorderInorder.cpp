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

//function to build tree using postorder and inorder

BinaryTreeNode<int>* buildTree(int posto[],int ino[],int posts,int poste,int ins,int ine){
    if(ins>ine){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(posto[poste]);
    int rootindex;
    for(int i=ins;i<=ine;i++){
        if(ino[i]==posto[poste]){
            rootindex=i;
            break;
        }
    }

    int leftposte=(rootindex-1)-ins+posts;

    BinaryTreeNode<int>* leftChild = buildTree(posto,ino,posts,leftposte,ins,rootindex-1);
    BinaryTreeNode<int>* rightChild = buildTree(posto,ino,leftposte+1,poste-1,rootindex+1,ine);

    root->left=leftChild;
    root->right=rightChild;
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
    cout<<"Enter no of nodes : "<<endl;
    cin>>n;
    int posto[n],ino[n];
    cout<<"Enter the preorder traversal of tree : "<<endl;
    for(int i=0;i<n;i++){
        cin>>posto[i];
    }
    cout<<"Enter the inorder traversal of tree : "<<endl;
    for(int i=0;i<n;i++){
        cin>>ino[i];
    }

    BinaryTreeNode<int>* root= buildTree(posto,ino,0,n-1,0,n-1);
    printTree2(root);
}