
#include<iostream>
#include<queue>
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

BinaryTreeNode<int> *takeInputLevelwise(){
    int rootData;
    cout<<"Enter root data ";
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
     pendingNodes.push(root);
     while(pendingNodes.size()!=0){
         BinaryTreeNode<int> *front=pendingNodes.front();
         pendingNodes.pop();
         cout<<"Enter left child of"<<front->data<<endl;
         int leftchilddata;
         cin>>leftchilddata;
         if(leftchilddata!=-1){
             BinaryTreeNode<int> *child=new BinaryTreeNode<int>(leftchilddata);
             front->left=child;
             pendingNodes.push(child);
         }
         int rightChilddata;
         cout<<"Enter right child of "<<front->data<<endl;
         cin>>rightChilddata;
         if(rightChilddata!=-1){
             BinaryTreeNode<int> *child=new BinaryTreeNode<int>(rightChilddata);
             front->right=child;
             pendingNodes.push(child);
         }
     }
     return root;
}

void printLevelwise(BinaryTreeNode<int> *root){
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    
    while(pendingNodes.size()!=0){
        BinaryTreeNode<int> *p=pendingNodes.front();
        cout<<p->data<<":";
        pendingNodes.pop();
        
        if(root->left!=NULL){
            cout<<"L"<<root->left->data;
            pendingNodes.push(root->left);
        }
        else{
            cout<<"L"<<"-1"<<",";
        }
        if(root->right!=NULL){
            cout<<"R:"<<root->right->data;
            pendingNodes.push(root->right);
        }
        else{
            cout<<"R:"<<"-1";
        }
        cout<<endl; 
    root=pendingNodes.front();
    }
}
    

int main(){
    BinaryTreeNode<int> *root=takeInputLevelwise();
    printBinarytree(root);
    printLevelwise(root);
}
