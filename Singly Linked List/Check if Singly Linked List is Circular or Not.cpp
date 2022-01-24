//https://practice.geeksforgeeks.org/problems/circular-linked-list/1#
bool isCircular(Node *head)
{
   if(!head)return head;
   
   Node *temp=head->next;
   while(temp!=NULL){
       if(temp==head){
           return true;
       }
       temp=temp->next;
   }
   return false;
}
