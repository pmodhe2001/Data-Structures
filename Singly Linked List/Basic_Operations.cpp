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

Node *takeInput1(){
    int data;
    cin>>data;
   // Node *newNode=new Node(data);
    Node *head=NULL,*tail=NULL;
    while(data!=-1){
        Node *newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else if(head!=NULL){
            tail->next=newNode;
            tail=newNode;
        }
        cin>>data;
    }
    return head;
}

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

Node *takeInput_recursively(Node *head,int data,int pos){
    if(head==NULL){
        if(pos==0){
            Node *newNode=new Node(data);
            newNode->next=head;
            head=newNode;
            return newNode;
        }
        return head;
    }
    
    Node *newNode=new Node(data);
    
    if(pos==0){
        newNode->next=head;
        head=newNode;
        return newNode;
    }
    head->next=takeInput_recursively(head->next,data,pos-1);
    return head;
    
}

void print(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void print_recursively(Node *head){
    Node *temp=head;
    if(temp==NULL){
        return;
    }
    cout<<temp->data<<" ";
    print_recursively(temp->next);
}

Node *deleteatithpos(Node *head,int pos){
    if(head==NULL){
        return 0;
    }
    if(pos==0){
        Node *tmp=head;
        head=head->next;
        free(tmp);
        return head;
    }
    int i=0;
    Node *tmp=head;
    while(tmp!=NULL && i<pos-1){
        i++;
        tmp=tmp->next;
    }
    tmp->next=tmp->next->next;
    return head;
}

int length(Node *head){
    if(head==NULL){
        return 0;
    }
    return length(head->next)+1;
}

int length_iteratively(Node *head){
    if(head==NULL){
        return 0;
    }
    Node *tmp=head;
    int c=0;
    while(tmp!=NULL){
        c=c+1;
        tmp=tmp->next;
    }
    return c;
}

int main(){
    Node *head=takeInput();
    print(head);
    int d,p;
    cin>>d>>p;
    Node *h1=takeInput_recursively(head,d,p);
    print_recursively(h1);
    cout<<endl;
    int pos;
    cin>>pos;
    h1=deleteatithpos(h1,pos);
    print_recursively(h1);
    cout<<endl;
    cout<<length_iteratively(h1)<<endl;
    cout<<length(h1)<<endl;
}
