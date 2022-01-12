/*
For a given a Binary Tree of type integer, duplicate every node of the tree and attach it to the left of itself.
The root will remain the same. So you just need to insert nodes in the given Binary Tree.
*/void InsertDuplicateNode(BinaryTreeNode<int> *root){
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
