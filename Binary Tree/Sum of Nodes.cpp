/*
For a given Binary Tree of integers, find and return the sum of all the nodes data.
Example:
                        10
                      /      \
                    20      30
                   /    \
                 40    50

When we sum up all the nodes data together, [10, 20, 30, 40 50] we get 150. Hence, the output will be 150.
*/
int getSum(BinaryTreeNode<int> *root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }
    return getSum(root->left)+getSum(root->right)+root->data;
}
