//https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1#
class Solution{
    public:
    //Function to find the height of a binary tree.
   
   int height(struct Node* node)
   {
    if(node==NULL){
        return 0;
    }
    int leftsubtree=height(node->left);
    int rightsubtree=height(node->right);
    return 1+max(leftsubtree,rightsubtree);
    }
};
