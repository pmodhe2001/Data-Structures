 void traversalwithmap(TreeNode *root,unordered_map<int,int> &mp){
        if(!root)return;
        mp[root->val]++;
        traversalwithmap(root->left,mp);
        
        traversalwithmap(root->right,mp);
    }
    vector<int> findMode(TreeNode* root) {
        
        vector<int> res;
        unordered_map<int,int> mp;
        traversalwithmap(root,mp);
            
        int max=INT_MIN;   
        
        for(auto i:mp){
            if(i.second>max){
                res.clear();
                max=i.second;
                res.push_back(i.first);
            }
            else if(i.second==max){
                res.push_back(i.first);
            }
        }
        return res;
    }
