#include<algorithm>
void traverse(TreeNode<int> *root,vector<int> &in){
    if(root==NULL){
        return;
    }
    in.push_back(root->data);
    traverse(root->left,in);
    traverse(root->right,in);
}
TreeNode<int> *tree(vector<int> input, int start, int end){
    if(start > end){    //base case
        return NULL;
    }
    int mid = (start + end) / 2;    //mid of array
    TreeNode<int> *root = new TreeNode<int>(input[mid]);    //assign mid as root
    root -> left = tree(input, start, mid - 1);    // call to left
    root -> right = tree(input, mid + 1, end);    // call to right
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    vector<int> main;
    traverse(root1,main);
    traverse(root2,main);
    sort(main.begin(),main.end()) ; 
    int end = main.size() - 1;    //end of array
    TreeNode<int>* mainroot=tree(main,0, end);
    return mainroot;
}
