//https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#
vector<int> leftView(Node *root)
{
   vector<int> lv;
   if(root==NULL){
       return lv;
   }
   queue<Node*> q;
   q.push(root);
   while(q.size()!=0){
       int n=q.size();
       lv.push_back(q.front()->data);
       for(int i=0;i<n;i++){
           Node *temp=q.front();
           q.pop();
           if (temp->left != NULL){
                q.push(temp->left); 
           }
           if (temp->right != NULL){
                q.push(temp->right);
           } 
       }
   }
   return lv;
}
