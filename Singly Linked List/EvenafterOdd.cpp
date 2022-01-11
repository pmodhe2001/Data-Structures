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

Node *evenafterodd(Node *head){
    if(head==NULL){
        return head;
    }
    Node *evenhead=NULL,*eventail=NULL,*oddhead=NULL,*oddtail=NULL;
    while(head!=NULL){
        if(head->data%2==0){
            if(evenhead==NULL){
                evenhead=head;
                eventail=head;
            }
            else{
                eventail->next=head;
                eventail=eventail->next;
            }
        }else{
            if(head->data%2!=0){
                if(oddhead==NULL){
                    oddhead=head;
                    oddtail=head;
                }
                else{
                    oddtail->next=head;
                    oddtail=oddtail->next;
                }
            }
        }
        head=head->next;
    }
    if(oddhead==NULL){
        return evenhead;
    }
    else{
        oddtail->next=evenhead;
    }
    if(evenhead!=NULL){
        eventail->next=NULL;
    }
    
    return oddhead;
}

int main(){
    Node *head=takeInput();
    head=evenafterodd(head);
    print_recursively(head);
}
