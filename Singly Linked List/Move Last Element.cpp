//https://www.codingninjas.com/codestudio/problems/let-last-be-the-first_920455?leftPanelTab=0
//Approach 1
LinkedListNode<int>* moveToFront(LinkedListNode<int> *head) {

    if(head==NULL || head->next==NULL)return head;
    
    LinkedListNode<int> *temp=head;
    LinkedListNode<int> *newTail=NULL;
    while(temp->next!=NULL){
        newTail=temp;
        temp=temp->next;
    }
    newTail->next=NULL;
    temp->next=head;
    head=temp;
    return head;

}
