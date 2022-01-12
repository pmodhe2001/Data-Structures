/*
Code : Find a node
For a given Binary Tree of type integer and a number X, find whether a node exists in the tree with data X or not.
*/
bool isNodePresent(BinaryTreeNode<int> *root,int x){
    if(root==NULL){
        return false;
    }
    
    if(root->data==x){
        return true;
    }
    
    bool leftPresent=isNodePresent(root->left,x);
    bool rightPresent=isNodePresent(root->right,x);
    
    return leftPresent || rightPresent;
}
