//https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1
Node *removeDuplicates(Node *head)
{
    if(!head)return head;
    
    Node *temp=head;
    
    while(temp!=NULL && temp->next!=NULL){
        if(temp->data==temp->next->data){
            temp->next=temp->next->next;
        }
        else{
            temp=temp->next;
        }
    }
    
    return head;
}
