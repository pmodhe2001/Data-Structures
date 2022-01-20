//https://www.codingninjas.com/codestudio/problems/range-sum-of-bst_1262280?leftPanelTab=0
int rangeSum(TreeNode<int> *root, int low, int high)
{
    if(!root)return 0;
    int sum=0;
    if(root->data>=low && root->data<=high){
        sum+=root->data;
    }
    int left=rangeSum(root->left,low,high);
    int right=rangeSum(root->right,low,high);
    return sum+left+right;
}
