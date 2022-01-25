#https://classroom.codingninjas.com/app/classroom/me/5110/content/65820/offering/718939/problem/330


int length(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp!=NULL){
        count++;
        temp= temp->next;
    }
    return count;
}

Node* reverse(Node* head){
    
    Node* cur = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(cur!=NULL){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    head = prev;
    return head;

}

bool isPalindrome(Node* head)
{   
    if(head==NULL)
        return true;
    Node* temp1 = head;
    Node* temp2 = NULL;
    Node* head2 = NULL;
    int len = length(head);
    int mid= len/2;
    if(len==1){
        return true;
    }
    for(int i=0;i<mid-1;i++){
        temp1=temp1->next;
    }
    if(len%2==0){
        head2 = temp1->next;
    }
    else{
        head2 = temp1;
    }
    
    head2 = reverse(head2);
    temp2=head2;
    temp1=head;
    while(temp1!=NULL&&temp2!=NULL){
        if(temp1->data!=temp2->data){
            return false;
        }
        else{
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
    }
    return true;
}
