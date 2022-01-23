bool hasPathSum(Node *root, int S) {
           bool res=false;
           if(!root)return res;
           
           int leftSum=S-root->data;
           if(leftSum==0 && root->left==NULL && root->right==NULL){
               return true;
           }
           
           if(root->left!=NULL){
               res=res || hasPathSum(root->left,leftSum);
           }
           if(root->right!=NULL){
               res=res || hasPathSum(root->right,leftSum);
           }
           
           return res;
    }
