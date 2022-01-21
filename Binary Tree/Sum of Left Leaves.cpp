void helper(TreeNode *root,int &sum){
        if(!root || !root->left && !root->right)return;
        helper(root->left,sum);
        if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL)
            sum=sum+root->left->val;
        helper(root->right,sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)return 0;
        int sum=0;
        helper(root,sum);
        return sum;
    }
