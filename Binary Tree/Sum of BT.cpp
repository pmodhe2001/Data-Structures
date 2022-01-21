void helper(Node *root,long int &sum){
    if(!root)return;
    sum+=root->key;
    helper(root->left,sum);
    helper(root->right,sum);
}
long int sumBT(Node* root)
{
    if(!root)return 0;
    long int sum=0;
    helper(root,sum);
    return sum;
}
