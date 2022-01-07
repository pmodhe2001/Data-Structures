
int getSum(BinaryTreeNode<int> *root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }
    return getSum(root->left)+getSum(root->right)+root->data;
}
