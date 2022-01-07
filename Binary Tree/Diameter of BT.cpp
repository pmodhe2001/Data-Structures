
int diameterOfBinaryTree(BinaryTreeNode<int> *root){
    if(root==NULL){
        return 0;
    }
    int option1=diameterOfBinaryTree(root->left)+diameterOfBinaryTree(root->right);
    int option2=diameterOfBinaryTree(root->left);
    int option3=diameterOfBinaryTree(root->right);
    
    return max(option1,max(option2,option3));
}
