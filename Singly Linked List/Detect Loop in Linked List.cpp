//https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1#

//Approach 1 using fast & slow pointers
bool detectLoop(Node* head)
    {
        Node *slow=head;
        Node *fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        
        return false;
    }

//Approach 2 using Unordered Map
 bool detectLoop(Node* head)
    {
        unordered_map<Node*,int> mp;
        Node* tmp=head;
        
        while(tmp!=NULL){
            mp[tmp]++;
            if(mp[tmp->next]==true){
                return true;
                break;
            }
            tmp=tmp->next;
        }
        return false;
    }
