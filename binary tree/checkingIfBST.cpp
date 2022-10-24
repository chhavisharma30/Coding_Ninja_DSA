#include<iostream>
#include<queue>
using namespace std;

//binary tree node class
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

//func to check if given binary tree is BST or not -1 
bool checkBST(BinaryTreeNode<int>* root){
    if(root==NULL){
        return true;
    }
    
    if((root->left!=NULL && root->left->data>root->data) || (root->right!=NULL && root->right->data<root->data)){
        return false;
    }

    if(!checkBST(root->left)||!checkBST(root->right)){
        return false;
    };

    return true;
}

int maximum(BinaryTreeNode<int>* root){
    if(root==NULL){
        return INT16_MIN;
    }

    return max(root->data,max(maximum(root->left),maximum(root->right)));
}

int minimum(BinaryTreeNode<int>* root){
    if(root==NULL){
        return INT16_MAX;
    }

    return min(root->data,min(minimum(root->left),minimum(root->right)));
}

//isBST -2
//time complexity O(n*h)
bool checkBST2(BinaryTreeNode<int>* root){
    if (root==NULL)
        return true;

    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);

    bool output = (root->data > leftMax) && (root->data <=rightMin) && checkBST2(root->left) && checkBST2(root->right);

    return output;
}

class isBSTReturn{
    public:
     bool isBST;
     int minimum;
     int maximum;
};
//isBST -3
//time complexity O(n)
isBSTReturn checkBST3(BinaryTreeNode<int>* root){
    if(root==NULL){
        isBSTReturn output;
        output.isBST=true;
        output.maximum=INT16_MIN;
        output.minimum=INT16_MAX;
        return output;
    }

    isBSTReturn leftOP= checkBST3(root->left);
    isBSTReturn rightOP =  checkBST3(root->right);

    int maximum = max(root->data,max(leftOP.maximum,rightOP.maximum));
    int minimum = min(root->data,min(leftOP.minimum,rightOP.minimum));

    bool isBSTFinal = (root->data>leftOP.maximum) && (root->data<=rightOP.minimum) && leftOP.isBST && rightOP.isBST;

    isBSTReturn output;
    output.isBST=isBSTFinal;
    output.maximum=maximum;
    output.minimum=minimum;
    return output;

}

//isBST -4
bool checkBST4(BinaryTreeNode<int>* root, int min = INT16_MIN,int max = INT16_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data<min || root->data>max){
        return false;
    }

    bool leftOP = checkBST4(root->left,min,root->data-1);
    bool rightOP = checkBST4(root->right,root->data,max);

    return leftOP && rightOP;
}

int main(){
    BinaryTreeNode<int>* root = takeInput2();
    //cout<<checkBST(root)<<endl;
    //cout<<checkBST2(root)<<endl;
    //isBSTReturn ans = checkBST3(root);
    //cout<<ans.isBST<<endl;
    cout<<checkBST4(root)<<endl;
    delete root;
}