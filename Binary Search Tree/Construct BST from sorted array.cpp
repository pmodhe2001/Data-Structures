BinaryTreeNode<int> *tree(int *input, int start, int end){
    if(start > end){    //base case
        return NULL;
    }
    int mid = (start + end) / 2;    //mid of array
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[mid]);    //assign mid as root
    root -> left = tree(input, start, mid - 1);    // call to left
    root -> right = tree(input, mid + 1, end);    // call to right
    return root;
}
BinaryTreeNode<int>* constructTree(int *input, int n) {
    int start = 0;    //start of array
    int end = n - 1;    //end of array
    tree(input, start, end);
}
