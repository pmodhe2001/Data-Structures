//https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1/#
class Solution
{
    public:
    //Function to rotate a linked list.
    int len(Node *head){
        if(head==NULL){
            return 0;
        }
        return 1+len(head->next);
    }
    Node* rotate(Node* head, int k)
    {
        if(head==NULL){
            return NULL;
        }
        if(len(head)==k){
            return head;
        }
        Node *tmp=head;
        for(int i=0;i<k-1;i++){
            tmp=tmp->next;
        }
        Node *newHead=tmp->next;
        tmp->next=NULL;
        Node *join=newHead;
        while(join->next!=NULL){
            join=join->next;
        }
        join->next=head;
        head=newHead;
        return head;
    }
};
    
