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
    if(!root)return 0;
    return height(node->left)-height(node->right);
}

int main()
{
    
}
