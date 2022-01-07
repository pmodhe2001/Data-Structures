
#include <climits> 
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
    pair<int, int> ret = make_pair(INT_MAX, INT_MIN);
    if (root == NULL) { 
        return ret; 
    } 
    pair<int, int> leftPair = getMinAndMax(root->left); 
    pair<int, int> rightPair = getMinAndMax(root->right); 
    ret.first = min(min(leftPair.first, rightPair.first), root->data);
    ret.second = max(max(leftPair.second, rightPair.second), root->data); 
    return ret; 
}
