#include <iostream>
using namespace std;

class AvlNode{
    public:
       int data;
       AvlNode *left;
       AvlNode *right;
       int height;
};

int height(AvlNode *root){
    if(!root)return 0;
    return root->height;
}

int max(int a,int b){
    return (a>b)? a:b;
}

AvlNode *newNode(int data){
    AvlNode *node=new AvlNode();
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return node;
}

AvlNode *rightRotation(AvlNode *y){
    AvlNode *x=y->left;
    AvlNode *temp_null=x->right;
    
    // Performing rightRotation
    x->right=y;
    y->left=temp_null;
    //Updating height
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    
    return x;
}

AvlNode *leftRotation(AvlNode *x){
    AvlNode *y=x->right;
    AvlNode *temp_null=y->left;
    
    //Performing leftRotation
    y->left=x;
    x->right=temp_null;
    //Updating height
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    
    return y;
}

int BalanceFactor(AvlNode *node){
    if(!node)return 0;
    return height(node->left)-height(node->right);
}

AvlNode *insertNode(AvlNode* root,int key){
    if(!root)return newNode(key);
    
    if(key<root->data){
        root->left=insertNode(root->left,key);
    }
    else if(key>root->data){
        root->right=insertNode(root->right,key);
    }
    else{
        return root;
    }
    root->height=1+max(height(root->left),height(root->right));
    int balance=BalanceFactor(root);
    
    if(balance>1 && key<root->left->data){   // Right Rotation Case
        return rightRotation(root);
    }
    
    if(balance<-1 && key>root->right->data){
        return leftRotation(root);          // Left Rotation Case
    }
    
    if(balance>1 && key>root->left->data){
        root->left=leftRotation(root);       // Left Right Rotation
        return rightRotation(root);
    }
    
    if(balance<-1 && key<root->right->data){
        root->right=rightRotation(root);     // Right Left Rotation
        return leftRotation(root);
    }
    
    return root;
    
}

AvlNode *minDataNode(AvlNode *root){
    if(!root)return root;
    
    AvlNode* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

void traversal(AvlNode *root){
    if(root!=NULL){
        return;
    }
    traversal(root->left);
    cout<<root->data<<" ";
    traversal(root->right);
    
}

int main()
{
    AvlNode *root=NULL;
    root=insertNode(root,10);
    root=insertNode(root,90);
    root=insertNode(root,50);
    root=insertNode(root,70);
    root=insertNode(root,28);
    root=insertNode(root,19);
    root=insertNode(root,65);
    root=insertNode(root,57);
    traversal(root);
}
