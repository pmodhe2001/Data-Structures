//https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1#

//Approach 1 Using Hashmaps
Node * removeDuplicates( Node *head) 
    {
       if(!head)return head;
       
       Node *tmp=head;
       unordered_map<int,int> freq;
       
       freq[tmp->data]=1;
       
       while(tmp!=NULL && tmp->next!=NULL){
           if(freq.count(tmp->next->data)==1){
               tmp->next=tmp->next->next;
           }
           else{
               tmp=tmp->next;
               freq[tmp->data]++;
           }
       }
       
       return head;
    }

/*Approach 2 Using Unordered Set :
Giving wrong answer of 1 test case : 
1
23
*/
Node * removeDuplicates( Node *head) 
    {
       if(head==NULL){
           return NULL;
       }
       
       unordered_set<int> unique;
       Node *temp=head;
       //unique.insert(head->data);
       while(temp->next!=NULL){
           unique.insert(temp->data);
           if(unique.find(temp->next->data)!=unique.end()){
               temp->next=temp->next->next;
           }
           else{
               temp=temp->next;
           }
       }
       
       return head;
    }
// Approach 3 Using 2 loops
Node * removeDuplicates( Node *head) 
    {
       if(head==NULL || head->next==NULL){
           return NULL;
       }
       
       
       Node *f=head;
       Node *s=head;
       
       while(f!=NULL){
           s=f->next;
           Node *prev=f;
           while(s!=NULL){
               if(f->data==s->data){
                  f->next=s->next;
                  s=prev->next;
              }
              else{
                  prev=s;
                  s=s->next;
              }
           }
           f=f->next;
       }
       return head;
    }
