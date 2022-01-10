#include<iostream>
using namespace std;

class Node{
  public:
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

Node *takeInput(){
    int data;
    cin>>data;
    Node *head=NULL,*tail=NULL;
    while(data!=-1){
        Node *newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
        cin>>data;
    }
    return head;
}

void print_recursively(Node *head){
    Node *temp=head;
    if(temp==NULL){
        return;
    }
    cout<<temp->data<<" ";
    print_recursively(temp->next);
}

int length(Node *head){
    if(head==NULL){
        return 0;
    }
    return length(head->next)+1;
}

Node *appendLastNtofirst(Node *head,int n){
  if(n==0 || head==NULL){
      return head;
  }
    
   Node *fast=head;
   Node *slow=head;
   Node *initialhead=head;
    
   for(int i=0;i<n;i++){
       fast=fast->next;
   }
    
   while(fast->next!=NULL){
      slow=slow->next;
      fast=fast->next;
   }
    
    Node *temp=slow->next;
    slow->next=NULL;
    fast->next=initialhead;
    head=temp;
    return head;
}

Node *midpoint(Node *head){
    if(head==NULL){
        return head;
    }
    
    Node *slow=head;Node *fast=head->next;
    while(head!=NULL && fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int main(){
    Node *head=takeInput();
    Node *mid=midpoint(head);
    if(mid!=NULL){
        cout<<mid->data<<" ";
    }
    else{
        cout<<"NULL LIST"<<endl;
    }
}
