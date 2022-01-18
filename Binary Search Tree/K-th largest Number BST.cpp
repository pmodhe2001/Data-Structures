void findmax(TreeNode<int> *root,int &k,int &kth){
    if(root==NULL)return;
    findmax(root->right,k,kth);
    k--;
    if(k==0){
        kth=root->data;
    }
    findmax(root->left,k,kth);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
   if(root==NULL){
       return 0;
   }
   int kth=-1;
   findmax(root,k,kth); 
   return kth;  
}
