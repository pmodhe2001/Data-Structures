
#include<cmath>
int height(BinaryTreeNode<int> *root){
    if(root==NULL){
        return 0;
    }
    int Lbottom=height(root->left);
    int Rbottom=height(root->right);
    return max(Lbottom,Rbottom)+1;
}
