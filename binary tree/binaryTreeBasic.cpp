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

//inorder traversal : left-root-right
void inorder(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//preorder traversal : root-left-right'
void preorder(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//postorder traversal : left-right-root
void postorder(BinaryTreeNode<int>* root){
    if(root== NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

//func to take input recursive
BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter the data : "<<endl;
    cin>>rootData;

    if(rootData==-1){
        return NULL;
    }

    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();
    root->left=leftChild;
    root->right=rightChild;
}

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

//func to count no of nodesin tree
int countNodes(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return 1+countNodes(root->left)+countNodes(root->right);
}

//func to print the tree recursive
void printTree(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" : ";
    if(root->left != NULL){
        cout<<"L"<<root->left->data<<" ";
    }
    if(root->right != NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

//func to check if a node is present in the tree

bool checkNode(BinaryTreeNode<int>* root, int x){
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    return (checkNode(root->left,x)) || (checkNode(root->right,x));
}

//func to find height of the tree
int heightOfTree(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int h1= heightOfTree(root->left);
    int h2= heightOfTree(root->right);
    if(h1>h2){
        return 1+h1;
    }else{
        return 1+h2;
    }
}

//func to generate mirror image of tree
BinaryTreeNode<int>* mirrorImage(BinaryTreeNode<int>* root){
    if(root==NULL){
        return root;
    }
    BinaryTreeNode<int>* n1 = mirrorImage(root->left);
    BinaryTreeNode<int>* n2 = mirrorImage(root->right);
    root->left=n2;
    root->right=n1;
    return root;
}

int main(){
    /*BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
    root->left=node1;
    root->right=node2;*/
    BinaryTreeNode<int>* root= takeInput2();
    //int x;
    //cout<<"Enter no you wanna check : "<<endl ;
    //cin>>x;
    //printTree2(root);
    //cout<<countNodes(root);
    //cout<<checkNode(root,x)<<endl;
    //cout<<heightOfTree(root)<<endl;
    //BinaryTreeNode<int>* root2 = mirrorImage(root);
    //printTree2(root2);
    //printTree2(root);
    //inorder(root);
    //preorder(root);
    postorder(root);
    delete root;
}
