/*
For a given postorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists.
You just need to construct the tree and return the root.
*/

BinaryTreeNode<int>* buildTree(int *postOrder, int postLength, int *inOrder, int inLength) {
    
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(postOrder[postLength-1]);
    
    if(postLength == 1)    // base case when only root is present and no left or right node
        return root;
    
    if(postLength == 0)    //if one of both right or left is present check for 2, 1 2, 1 2;;;dry run it
        return NULL;
    
    int i = 0;
    
    for(;inOrder[i]!=root->data;i++){}

    int left_size = i;
    int right_size = inLength -i - 1;
      
    root -> left = buildTree(postOrder, left_size, inOrder, left_size);
    root -> right = buildTree(postOrder + left_size, right_size, inOrder + 1 + left_size, right_size);
    
    return root;
}
