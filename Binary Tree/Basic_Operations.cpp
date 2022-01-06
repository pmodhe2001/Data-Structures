
#include<iostream>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
       T data;
       BinaryTreeNode *left;
       BinaryTreeNode *right;
       BinaryTreeNode(T data){
           this->data=data;
           left=NULL;
           right=NULL;
       }
       ~BinaryTreeNode(){
           delete left;
           delete right;
       }
};

void printBinarytree(BinaryTreeNode<int> *root){
    if(root==NULL){
        return;
    }
    cout<<"Children of "<<root->data<<" are ";
    if(root->left!=NULL){
        cout<<root->left->data<<" and ";
         
    }else{
        cout<<"NO CHILD ";
    }
    if(root->right!=NULL){
          cout<<root->right->data;
    }else{
        cout<<"NO CHILD ";
    }
    cout<<endl;
    printBinarytree(root->left);
    printBinarytree(root->right);
}

BinaryTreeNode<int> *takeInput(){
    int rootData;
    cout<<"Enter Data : ";
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild=takeInput();
    BinaryTreeNode<int> *rightChild=takeInput();
    root->left=leftChild;
    root->right=rightChild;
    return root;
}

int main(){
    BinaryTreeNode<int> *root=takeInput();
    printBinarytree(root);
}
