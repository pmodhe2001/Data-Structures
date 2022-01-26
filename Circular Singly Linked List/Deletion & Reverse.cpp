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
   Node *curr=*head_ref;
   Node *temp;
   Node *ahead=curr->next;
   Node **initial_head=head_ref;
   while(ahead!=*initial_head){
       temp=ahead->next;
       ahead->next=curr;
       curr=ahead;
       ahead=temp;
   }
   ahead->next=curr;
   *head_ref=curr;
}
