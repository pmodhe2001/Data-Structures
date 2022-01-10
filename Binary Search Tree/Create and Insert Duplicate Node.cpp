void InsertDuplicateNode(BinaryTreeNode<int> *root){
    if(root==NULL){
        return;
    }
    
    insertDuplicateNode(root->left);
    insertDuplicateNode(root->right);
    
    BinaryTreeNode<int> *save=root->left;
    BinaryTreeNode<int> *newNode= new BinaryTreeNode<int>(root->data);
    
    root->left=newNode;
    newNode->left=save;
}
