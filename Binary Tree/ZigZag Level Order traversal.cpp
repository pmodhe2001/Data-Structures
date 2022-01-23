vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)return res;
        
        queue<TreeNode*> q;
        q.push(root);
        bool l2r=true;
        
        while(q.size()!=0){
            int n=q.size();
            vector<int> row(n);
            for(int i=0;i<n;i++){
                TreeNode *node=q.front();
                q.pop();
                
                int index=-1;
                if(l2r==true){
                    index=i;
                }
                else{
                    index=n-i-1;
                }
                
                row[index]=node->val;
                
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
                
            }
            l2r=!l2r;
            res.push_back(row);
        }
        return res;
    }
