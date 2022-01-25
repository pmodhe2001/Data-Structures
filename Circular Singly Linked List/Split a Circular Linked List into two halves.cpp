#https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1
#Approach 1 : O(N)

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *slow=head;Node *fast=head;
    
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    
    *head1_ref=head;
    *head2_ref=slow->next;
    slow->next=head;
    
    if(fast->next==head){
        fast->next=*head2_ref;
    }
    else{
        fast->next->next=*head2_ref;
    }
    
}
