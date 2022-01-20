//https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1/#
class Solution
{
public:
    void traversal(Node *root,vector<Node*> &set){
        if(root==NULL) return;
        traversal(root->left,set);
        set.push_back(root);
        traversal(root->right,set);
    }
    void populateNext(Node *root)
    {
        vector<Node*> set;
        traversal(root,set);
        for(int i=0;i<set.size();i++){
            set[i]->next=set[i+1];
        }
        set[set.size()-1]->next=NULL;
    }
};
