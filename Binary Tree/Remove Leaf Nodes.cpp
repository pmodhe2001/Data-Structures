BinaryTreeNode<int>* RemoveLeafNodes(BinaryTreeNode<int> *root){
    if(root==NULL){
        return NULL;
    }
    
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    else{
        root->left=removeLeafNodes(root->left);
        root->right=removeLeafNodes(root->right);
    }
    return root;
}
