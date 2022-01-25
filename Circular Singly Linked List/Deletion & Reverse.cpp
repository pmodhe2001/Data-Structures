#https://practice.geeksforgeeks.org/problems/deletion-and-reverse-in-linked-list/1/#
void deleteNode(struct Node **head, int key)
{

     if(!*head)return;
     
     Node *curr=*head;
     
     while(curr->next->data!=key && curr->next!=*head){
         curr=curr->next;
     }
     
     Node *temp=curr->next;
     curr->next=curr->next->next;
     delete(temp);

}

/* Function to reverse the linked list */
 void reverse(struct Node** head_ref)
{
    /*if(!*head_ref)return;
    Node *curr=*head_ref;
    Node *agla=curr->next;
    Node *prev=NULL;
    
    while(curr->next!=*head_ref){
        agla=prev->next;
        prev->next=curr;
        prev=curr;
        curr=agla;
    }
    agla->next=prev;
    *head_ref=curr;
    */
}
