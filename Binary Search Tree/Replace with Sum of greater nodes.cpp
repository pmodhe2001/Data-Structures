/*
Given a binary search tree, you have to replace each node's data with the sum of all nodes which are greater or equal than it. You need to include the current node's data also.
That is, if in given BST there is a node with data 5, you need to replace it with sum of its data (i.e. 5) and all nodes whose data is greater than or equal to 5.
Note: You don't need to return or print, just change the data of each node.
*/

int replaceWithLargerNodesSum(BinaryTreeNode<int> *root, int sum){
    
    if(root == NULL){
        return sum;
    }
    
    sum = replaceWithLargerNodesSum(root -> right, sum);
    
    sum = sum + root -> data;
    root -> data = sum;
    
    sum = replaceWithLargerNodesSum(root -> left, sum);
    
    return sum;
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
	
    int sum = 0;
    replaceWithLargerNodesSum(root, sum);
}
