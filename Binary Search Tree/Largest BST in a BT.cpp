#include<climits>
#include<cmath>

int height(BinaryTreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
    int ans1 = 0; int ans2 = 0;
    
    ans1 = height(root -> left);
    ans2 = height(root -> right);
    
    if(ans1 > ans2){
        return ans1 + 1;
    }
    else{
        return ans2 + 1;
    }
    
}

bool isBST(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX){
    if(root == NULL){
        return true;
    }
    if(root -> data < min || root -> data > max){
        return false;
    }
    
    bool isLeftOK = isBST(root -> left, min, root -> data -1);
    bool isRightOK = isBST(root -> right, root -> data + 1, max);
    
    return isLeftOK && isRightOK;
}
int largestBSTSubtree(BinaryTreeNode<int> *root) {
	
    if(isBST(root)){
        return height(root);
    }
    else{
        int ans1 = largestBSTSubtree(root -> left);
        int ans2 = largestBSTSubtree(root -> right);
        
        return max(ans1, ans2);
    }
}
