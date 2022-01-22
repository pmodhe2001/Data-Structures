bool helper(TreeNode* l,TreeNode *r){
        if(l==NULL && r==NULL){
            return true;
        }
        if(l==NULL ^ r ==NULL){
            return false;
        }
        bool check=l->val==r->val;
        return  check && helper(l->left,r->right) && helper(l->right,r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return helper(root->left,root->right);
    }
