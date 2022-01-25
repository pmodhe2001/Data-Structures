#https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1#
#Approach 1 : Recursion 
struct node *reverse (struct node *head, int k)
{ 
        if(head==NULL)return NULL;
        
        node *curr=head;
        node *prev=NULL;
        node *next=head;
        
        int count=0;
        
        while(curr!=NULL && count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        
        head->next=reverse(next,k);
        
        
        return prev;
}
