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

//function to build tree using preorder and inorder
//Explanation : tree build krne k liye hme ek preorder array or inorder array given h. hm apne func m dono arrays or unke starting or ending index le rhe h. Then hm base and edge condition check kr rhe h jisse recursion stop hoga. Hm phle root le lenge preorder k first element se or uske baad recursively func call krdenge left or right preorder or inorder arrays pr. Uske liye hm calculations krke uske starting or ending indices calculate krenge.

BinaryTreeNode<int>* buildTree(int preo[],int ino[],int pres,int pree,int ins,int ine){
    if(ins>ine){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preo[pres]);
    int rootindex;
    for(int i=ins;i<=ine;i++){
        if(ino[i]==preo[pres]){
            rootindex=i;
            break;
        }
    }

    int leftpree=(rootindex-1)-ins+(pres+1);

    BinaryTreeNode<int>* leftChild = buildTree(preo,ino,pres+1,leftpree,ins,rootindex-1);
    BinaryTreeNode<int>* rightChild = buildTree(preo,ino,leftpree+1,pree,rootindex+1,ine);

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
    int preo[n],ino[n];
    cout<<"Enter the preorder traversal of tree : "<<endl;
    for(int i=0;i<n;i++){
        cin>>preo[i];
    }
    cout<<"Enter the inorder traversal of tree : "<<endl;
    for(int i=0;i<n;i++){
        cin>>ino[i];
    }

    BinaryTreeNode<int>* root= buildTree(preo,ino,0,n-1,0,n-1);
    printTree2(root);
}