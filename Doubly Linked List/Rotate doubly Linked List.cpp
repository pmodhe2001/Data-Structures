 #https://practice.geeksforgeeks.org/problems/rotate-doubly-linked-list-by-p-nodes/1/#
 Node *update(Node *start,int p)
    {
        if(!start or p==0)return start;
        
        Node *s=start;Node *tail=NULL;
        int count=0;
        while(count<p){
            s=s->next;
            count++;
        }
        s->prev->next=NULL; // This will be our last node
        s->prev=NULL;  // This will be our first node
        
        tail=s;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        tail->next=start;
        start->prev=tail;
        start=s;
        return start;
        
    }
