 void gstHelper(TreeNode *root,int &initial_sum){
        if(!root)return;
        gstHelper(root->right,initial_sum);
        root->val+=initial_sum;
        initial_sum=root->val;
        gstHelper(root->left,initial_sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(!root)return root;
        int initial_sum=0;
        gstHelper(root,initial_sum);
        return root;
    }
