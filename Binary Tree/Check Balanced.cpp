/*
Given a binary tree, check if it is balanced. Return true if given binary tree is balanced, false otherwise.
Balanced Binary Tree:
A empty binary tree or binary tree with zero nodes is always balanced. For a non empty binary tree to be balanced, following conditions must be met:
1. The left and right subtrees must be balanced.
2. |hL - hR| <= 1, where hL is the height or depth of left subtree and hR is the height or depth of right subtree.    
*/

int height(BinaryTreeNode<int> *root){
    if(root == NULL)
        return 0;
    return 1 + max(height(root -> left), height(root -> right));
}


bool isBalanced(BinaryTreeNode<int> *root) {
    if(root == NULL)
        return true;
    int lh = height(root -> left);
    int rh = height(root -> right);
    
    if(lh - rh > 1 && rh - lh > 1)
        return false;
    if( abs(lh - rh) <= 1 && isBalanced(root -> left) && isBalanced(root -> right))
        return true;
    return false;
}
