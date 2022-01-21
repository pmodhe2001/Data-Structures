void findmin(TreeNode *root,int &k,int &kth){
        if(!root)return;
        findmin(root->left,k,kth);
        k--;
        if(k==0){
            kth=root->val;
        }
        findmin(root->right,k,kth);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root)return 0;
        int kth=-1;
        findmin(root,k,kth);
        return kth;
    }
