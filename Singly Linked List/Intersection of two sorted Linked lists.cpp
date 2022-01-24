//https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1#
//Approach 1 
Node* findIntersection(Node* head1, Node* head2)
{
    if(head1==NULL or head2==NULL){
        return NULL;
    }
    
    Node *res=new Node(NULL);
    Node *temp=res;
    
    while(head1!=NULL && head2!=NULL){
        if(head1->data==head2->data){
            Node *newNode=new Node(head1->data);
            temp->next=newNode;
            temp=newNode;
            head1=head1->next;
            head2=head2->next;
        }
        else if(head1->data < head2->data){
            head1=head1->next;
        }
        else if(head1->data > head2->data){
            head2=head2->next;
        }
    }
    
    return res->next;
}
