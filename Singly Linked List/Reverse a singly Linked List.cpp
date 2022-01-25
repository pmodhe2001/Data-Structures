#https://leetcode.com/problems/reverse-linked-list/

#Approach 1 : O(N^2) & Recursion
 ListNode* reverseList(ListNode* head) {
        if(!head or !head->next)return head;
        
        ListNode *smallans=reverseList(head->next);
        
        ListNode *temp=smallans;
        
        while(temp->next!=NULL){
            temp=temp->next;
        }
        
        temp->next=head;
        head->next=NULL;
        return smallans;
}

#Approach 2 : Using Pair class O(N) & Recursion

class Pair{
  public:
    ListNode *head;
    ListNode *tail;
};
class Solution {
public:
    Pair reverse(ListNode *head){
        if(!head or !head->next){
            Pair res;
            res.head=head;
            res.tail=head;
            return res;
        }
        Pair smallans=reverse(head->next);
        
        smallans.tail->next=head;
        head->next=NULL;
        Pair ans;
        ans.head= smallans.head;
        ans.tail=head;
        return ans;
        
        
        
    }
    ListNode* reverseList(ListNode* head) {
        if(!head or !head->next)return head;
        ListNode *res=reverse(head).head;
        return res;
    }
};

#Approach 3 : O(N) & Recursion

ListNode* reverseList(ListNode* head) {
        if(!head or !head->next)return head;
        
        ListNode *smallans=reverseList(head->next);
        ListNode *tail=head->next;
        tail->next=head;
        head->next=NULL;
        
        return smallans;
}

#Approach 4 : O(N) Iteration

ListNode* reverseList(ListNode* head) {
        if(!head or !head->next)return head;
        
        ListNode *temp = head;
        ListNode *prev = NULL;
        ListNode *curr = head;
    
        while(curr != NULL){
             temp = temp -> next;
             curr -> next = prev;
             prev = curr;
             curr = temp;
        }
   
        return prev;
}
