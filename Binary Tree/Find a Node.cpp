
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
