#include<algorithm>
#include<limits.h>

bool checkdead(TreeNode<int>* root, int minimum, int maximum) {
	if(root == NULL){
        return false;
    }
    if(root->left == NULL && root->right == NULL){
        if(minimum == maximum){
            return true;
        }
        return false;
    }
    bool left=checkdead(root->left, minimum, min(root->data - 1, maximum));
    bool right=checkdead(root->right, max(root->data + 1, minimum), maximum);  
    return left or right;
}

bool isDeadEnd(TreeNode<int>* root) {
    if(root == NULL){
        return false;
    }
    int minimum = 1, maximum = INT_MAX;
    return checkdead(root, minimum, maximum);
}
