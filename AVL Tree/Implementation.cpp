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

int main()
{
    
}
