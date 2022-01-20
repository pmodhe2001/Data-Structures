int getCount(Node *root, int l, int h)
{
   if(!root){
       return 0;
   }
   int count=0;
   if(root->data>=l && root->data<=h){
       count+=1;
   }
   int left=getCount(root->left,l,h);
   int right=getCount(root->right,l,h);
   return count+left+right;
}
