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

Node *merge2sortedLL(Node *head1,Node *head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    if(head1->data<head2->data){
        head1->next=merge2sortedLL(head1->next,head2);
        return head1;
    }
    if(head2->data<head1->data){
        head2->next=merge2sortedLL(head1,head2->next);
        return head2;
    }
    return 0;
}
int main(){
    Node *head1=takeInput();
    Node *head2=takeInput();
    Node *head3=merge2sortedLL(head1,head2);
    print_recursively(head3);
}
