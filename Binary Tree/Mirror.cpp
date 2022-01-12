/*
Code : Mirror
For a given Binary Tree of type integer, update it with its corresponding mirror image.
*/
void mirrorBinaryTree(BinaryTreeNode<int> *root){
    if(root==NULL){
        return;
    }
    
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    
    BinaryTreeNode<int> *tmp=root->left;
    root->left=root->right;
    root->right=tmp;
}
