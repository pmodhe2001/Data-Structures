//https://www.codingninjas.com/codestudio/problems/normal-bst-to-balanced-bst_920472?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1
void traversal(TreeNode<int> *root,vector<int> &res){
    if(root==NULL){
        return;
    }
    traversal(root->left,res);
    res.push_back(root->data);
    traversal(root->right,res);
}
TreeNode<int> *buildBalanced(vector<int> &in,int start,int end){
    if(start>end){
        return NULL;
    }
    int mid=start+(end-start)/2;
    TreeNode<int> *root=new TreeNode<int>(in[mid]);
    root->left=buildBalanced(in,start,mid-1);
    root->right=buildBalanced(in,mid+1,end);
    return root;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    if(root==NULL)return root;
    vector<int> in;
    traversal(root,in);
    TreeNode<int>* main=buildBalanced(in,0,in.size()-1);
    return main;
}
