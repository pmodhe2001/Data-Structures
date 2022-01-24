//https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1#
//Approach 1 : Using Sets
int intersectPoint(Node* head1, Node* head2)
{
    if(head1==NULL or head2==NULL){
        return NULL;
    }
    
    Node *temp1=head1;Node *temp2=head2;
    int res=-999;
    unordered_set<Node*> seen;
    
    while(temp1!=NULL){
        seen.insert(temp1);
        temp1=temp1->next;
    }
    
    while(temp2!=NULL){
        if(seen.find(temp2)!=seen.end()){
            res=temp2->data;
            break;
        }
        temp2=temp2->next;
    }
    
    return res;
}
