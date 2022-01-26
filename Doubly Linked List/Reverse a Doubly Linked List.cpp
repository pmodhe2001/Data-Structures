#https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1#
Node* reverseDLL(Node *head)
{
   if(head==NULL){
        return head;
    }
    if(head->next==NULL){
        head->prev=NULL;
        return head;
    }
    Node *smallAns=reverseDLL(head->next);
    head->next->next=head;
    head->prev=head->next;
    head->next=NULL;
    return smallAns;
}
