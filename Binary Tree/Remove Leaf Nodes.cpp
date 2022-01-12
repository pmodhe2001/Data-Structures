/*
Given a binary tree, remove all leaf nodes from it. Leaf nodes are those nodes, which don't have any children.
Note:
1. Root will also be a leaf node if it doesn't have left and right child. 
2. You don't need to print the tree, just remove all leaf nodes and return the updated root.
*/
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
