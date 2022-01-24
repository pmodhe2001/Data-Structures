//https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#

//Approach 1 using slow & fast pointers
 void removeLoop(Node* head)
    {
        Node *slow=head;Node *fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                break;
            }
        }
        
        if(slow==head){
            while(fast->next!=slow){
                fast=fast->next;
            }
            fast->next=NULL;
        }
        else if(slow==fast){
            slow=head;
            while(slow->next!=fast->next){
                slow=slow->next;
                fast=fast->next;
            }
            fast->next=NULL;
        }
    }
//Approach 2 using Hashmaps
void removeLoop(Node* head)
    {
        unordered_map<Node*,int> mp;
        Node *temp=head;
        while(temp!=NULL){
            mp[temp]++;
            if(mp[temp->next]==1){
                temp->next=NULL;
                break;
            }
            temp=temp->next;
        }
    }
