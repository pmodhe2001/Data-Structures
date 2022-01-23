vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<int> res;
    if(!root)return res;
    
    map<int,int> mp;
    queue<pair<BinaryTreeNode<int>*,int>> q;
    
    q.push({root,0});
    
    while(q.size()!=0){
        auto it=q.front();
        q.pop();
        
        BinaryTreeNode<int> *node=it.first;
        int line=it.second;
        
        mp[line]=node->data;
        
        if(node->left!=NULL){
            q.push({node->left,line-1});
        }
        if(node->right!=NULL){
            q.push({node->right,line+1});
        }
       
    }
     
    for(auto i:mp){
            res.push_back(i.second);
     }
        
     return res;
}
