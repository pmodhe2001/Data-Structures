void traverse(TreeNode<int> *root,vector<int> &in){
    if(root==NULL){
        return;
    }
    traverse(root->left,in);
    in.push_back(root->data);
    traverse(root->right,in);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    if(root==NULL)return root;
    vector<int> in;
    traverse(root,in);
    TreeNode<int> *newRoot = new TreeNode<int>(in[0]);
	TreeNode<int> *curr = newRoot;
	for(int i = 1; i < in.size(); i++){
		TreeNode<int> *temp = new TreeNode<int>(in[i]);
		curr->left = NULL;
		curr->right = temp;
		curr = temp;
	}
	curr->left = NULL;
	curr->right = NULL;
	return newRoot;   
}
