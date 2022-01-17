//https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1#
int height(Node *root,bool &res){
        if(root==NULL)return 0;
        int left=height(root->left,res);
        int right=height(root->right,res);
        if(left!=NULL && right!=NULL && left!=right){
            res=false;
        }
        return 1+max(left,right);
    }
    bool check(Node *root)
    {
        if(root==NULL){
            return root;
        }
        bool check_level=true;
        height(root,check_level);
        return check_level;
    }
