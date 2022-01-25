#https://www.codingninjas.com/codestudio/problems/find-pair-with-a-given-sum-in-a-doubly-linked-list_1164172?leftPanelTab=1
#Approach 1
bool findPair(Node* head, int k)
{   Node *first=head;
    Node *last=head;
    while(last->next!=NULL){
        last=last->next;
    }
    bool res=false;
    
    while(first!=last && last->next!=first){
        if(first->data+last->data==k){
            return true;
        }
        else if(first->data+last->data<k){
            first=first->next;
        }
        else if(first->data+last->data>k){
            last=last->prev;
        }
       
    }
     return false;
}

