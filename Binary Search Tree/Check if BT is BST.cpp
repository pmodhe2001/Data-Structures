#include<bits/stdc++.h>
bool helper(BinaryTreeNode<int> *root, int min, int max){
    
    if(root == NULL){
        return true;
    }
    
    if(root -> data < min || root -> data > max){
        return false;
    }
    
    bool left = helper(root -> left, min, root -> data - 1);
    bool right = helper(root -> right, root -> data, max);
    
    return left && right;
}

bool isBST(BinaryTreeNode<int> *root){
    
    int min = INT_MIN;
    int max = INT_MAX;
    
    return helper(root, min, max);
}
