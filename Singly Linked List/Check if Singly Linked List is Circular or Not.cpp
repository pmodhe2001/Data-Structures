//https://practice.geeksforgeeks.org/problems/circular-linked-list/1#
bool isCircular(Node *head)
{
   if(head==NULL){
       return head;
   }
   Node *tmp=head->next;
   while(tmp!=NULL){
       if(tmp==head){
           return true;
       }
       tmp=tmp->next;
   }
   return false;
}
