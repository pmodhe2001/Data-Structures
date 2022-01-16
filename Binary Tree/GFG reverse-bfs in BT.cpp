//https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1#
vector<int> reverseLevelOrder(Node *root)
{
     vector<int> bfs;
     queue<Node*> q;
     stack<Node*> stk;
     q.push(root);
     while(q.empty()==0)
     {
         Node *temp=q.front();
         q.pop();
         stk.push(temp);
         if(temp->right)
           q.push(temp->right);
         if(temp->left)
           q.push(temp->left);
     }
      while (stk.empty() == 0)
    {
        root = stk.top();
        bfs.push_back(root->data);
        stk.pop();
    }
    return bfs;

}
