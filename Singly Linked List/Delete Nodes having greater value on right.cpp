#https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1#
Node *helper(Node *root){
        if(!root || !root->next){
            return root;
        }
        Node *temp=helper(root->next);
        root->next=temp;
        
        if(root->data<temp->data){
            Node *del=root;
            delete del;
            return temp;
        }
        else{
            return root;
        }
    }
    Node *compute(Node *head)
    {
        Node *res=helper(head);
        return res;
    }
