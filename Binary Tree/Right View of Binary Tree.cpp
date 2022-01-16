//https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
vector<int> rightView(Node *root)
{
   vector<int> rv;
   if(root==NULL){
       return rv;
   }
   queue<Node*> q;
   q.push(root);
   while(q.size()!=0){
       int n=q.size();
       //lv.push_back(q.front()->data);
       for(int i=1;i<=n;i++){
           Node *temp=q.front();
           if(i==n){
               rv.push_back(temp->data);
           }
           q.pop();
           if (temp->left != NULL){
                q.push(temp->left); 
           }
           if (temp->right != NULL){
                q.push(temp->right);
           } 
       }
   }
   return rv;
}
