#https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
Node *merge(Node *a,Node *b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    Node *smallAns;
    
    if(a->data<b->data){
        smallAns=a;
        smallAns->bottom=merge(a->bottom,b);
    }
    else{
        smallAns=b;
        smallAns->bottom=merge(a,b->bottom);
    }
    smallAns->next=NULL;
    return smallAns;
}    
Node *flatten(Node *root)
{
   if(root==NULL || root->next==NULL){
       return root;
   }
   
   
   return merge(root,flatten(root->next));
}

