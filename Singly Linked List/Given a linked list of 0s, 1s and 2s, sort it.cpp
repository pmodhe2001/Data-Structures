#https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1#
Node* segregate(Node *head) {
        
        if(head==NULL)return NULL;
        
        Node *curr=head;
        Node *curr2=head;
        
        int count0=0,count1=0,count2=0;
        while(curr!=NULL){
            if(curr->data==0){
                count0++;
                
            }
            else if(curr->data==1){
                count1++;
                
            }
            else if(curr->data==2){
                count2++;
                
            }
            curr=curr->next;
        }
        
        
        
        while(count0--){
            curr2->data=0;
            curr2=curr2->next;
        }
        
        while(count1--){
            curr2->data=1;
            curr2=curr2->next;
        }
        
        while(count2--){
            curr2->data=2;
            curr2=curr2->next;
        }
        
        return head;
        
        
    }
