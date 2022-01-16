// https://practice.geeksforgeeks.org/problems/level-order-traversal/1#
class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
     vector<int> bfs;
     queue<Node*> q;
     q.push(node);
     while(q.empty()==0)
     {
         Node* temp=q.front();
         bfs.push_back(temp->data);
         q.pop();
         if(temp->left)
           q.push(temp->left);
         if(temp->right)
           q.push(temp->right);
     }
     return bfs;
    }
};
