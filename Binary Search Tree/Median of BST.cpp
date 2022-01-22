void traversal(struct Node *root,vector<float> &in){
    if(!root){
        return;
    }
    traversal(root->left,in);
    in.push_back(root->data);
    traversal(root->right,in);
}
float findMedian(struct Node *root)
{
      if(!root)return -1;
      vector<float> in;
      traversal(root,in);
      int n=in.size();
      if(n%2==0){
          float res=(in[n/2]+in[(n/2)-1])/2;
          return res;
      }
      else{
          float res=in[(n-1)/2];
          return res;
      }
      return 0;
}
