  void traversal(Node *root,vector<int> &in){
        if(!root)return;
        
        traversal(root->left,in);
        in.push_back(root->data);
        traversal(root->right,in);
        
    }
    Node *dll(vector<int> &res){
        Node *head=new Node();
        head->data=res[0];
        Node *temp=head;
        
        for(int i=1;i<res.size();i++){
            Node *newN=new Node();
            newN->data=res[i];
            temp->right=newN;
            newN->left=temp;
            temp=newN;
        }
        return head;
    }
    Node * bToDLL(Node *root)
    {
        if(!root)return root;
        
        vector<int> res;
        traversal(root,res);
        return dll(res);
    }
