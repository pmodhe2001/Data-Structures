#include<iostream>
using namespace std;

class Node{
    public:
       int data;
       Node *prev;
       Node *next;
       Node(int data){
           this->data=data;
           prev=NULL;
           next=NULL;
       }
};

Node *takeInput(){
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=-1){
         
         if(head==NULL || tail==NULL){
              Node *newNode=new Node(data);
              head=newNode;
              tail=newNode;
         }
         else{
              Node *newNode=new Node(data);
              tail->next=newNode;
              newNode->prev=tail;
              tail=newNode;
        }
        cin>>data;
    }
   return head;
}

Node* move_tofront(Node *tail){
    Node *temp=tail;
    while(temp==NULL){
        temp=temp->prev;
    }
    return temp;
}

Node  *move_toend(Node *head){
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    return temp;
}
void print_toend(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void print_tofront(Node *tail){
    Node *temp=tail;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout<<endl;
}

Node *InsertAtBeginning(Node *head,int data){
    Node*tail=NULL;
    if(head==NULL ){
        Node *newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return head;
    }
    Node *newNode=new Node(data);
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
    return newNode;
}

Node *InsertAtithPos(Node *head,int data,int pos){
    Node *tail=NULL;
    if(head==NULL && pos==0){
        Node *newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return head;
    }
    if(head!=NULL && pos==0){
        Node *newNode=new Node(data);
        newNode->next=head;
        head->prev=newNode;
        return head;
    }
    if(head!=NULL && pos>0){
        Node *tmp=head;
        Node *newNode=new Node(data);
        for(int i=0;i<pos-1;i++){
            tmp=tmp->next;
        }
        newNode->next=tmp->next;
        tmp->next->prev=newNode;
        tmp->next=newNode;
        newNode->prev=tmp;
        return head;
    }
    return NULL;
}

Node *Deletion_fromBeginning(Node *head,Node *tail){
    if(head==NULL){
        return head;
    }
    if(head==tail){
        head=NULL;
        tail=NULL;
        return head;
    }
    Node *delHead=head;
    head=head->next;
    head->prev=NULL;
    free(delHead);
    return head;
}

Node *Deletion_fromEnd(Node *head,Node *&tail){
    if(head==NULL){
        return head;
    }
    if(head==tail){
        head=NULL;
        tail=NULL;
        return head;
    }
    Node *tmp=head;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->prev->next=NULL;
    tmp->prev=NULL;
    return head;
}

Node *Deletion_fromithPos(Node *head,Node *tail,int pos){
    if(head==NULL){
        return NULL;
    }
    if(head!=NULL && pos==0){
        if(head==tail){
           head=NULL;
           tail=NULL;
           return head;
        }
        Node *delHead=head;
        head=head->next;
        head->prev=NULL;
        free(delHead);
        return head;
    }
    if(head!=NULL && pos>0){
        Node *tmp=head;
        for(int i=0;i<pos-1;i++){
            tmp=tmp->next;
        }
        tmp->next->next->prev=tmp;
        tmp->next=tmp->next->next;
        
    }
    return head;
}
int main(){
    Node *root=NULL;
    Node *tail=NULL;
    int ch;
    cin>>ch;
    while(ch!=-1){
        if(ch==1){
            // Print from back-side
            root=takeInput();
            root=move_toend(root);
            print_tofront(root);
        }
        else if(ch==2){
            // Print from front-side
            root=takeInput();
            root=move_tofront(root);
            print_toend(root);
        }
        else if(ch==3){
            // Insert at beginning
            root=takeInput();
            int data;
            cin>>data;
            root=InsertAtBeginning(root,data);
            root=move_tofront(root);
            print_toend(root);
            root=move_toend(root);
            print_tofront(root);
        }
        else if(ch==4){
            // Insert at any position
            root=takeInput();
            int data,pos;
            cin>>data>>pos;
            root=InsertAtithPos(root,data,pos);
            root=move_tofront(root);
            print_toend(root);
            root=move_toend(root);
            print_tofront(root);
            
        }
        else if(ch==5){
            //Deletion from beginning
            root=takeInput();
            tail=move_toend(root);
            root=Deletion_fromBeginning(root,tail);
            root=move_tofront(root);
            print_toend(root);
            root=move_toend(root);
            print_tofront(root);
        }
        else if(ch==6){
            //Deletion from end
            root=takeInput();
            tail=move_toend(root);
            root=Deletion_fromEnd(root,tail);
            root=move_tofront(root);
            print_toend(root);
            root=move_toend(root);
            print_tofront(root);
        }
        else if(ch==7){
            //Deletion from ith Position
            root=takeInput();
            tail=move_toend(root);
            int pos;
            cin>>pos;
            root=Deletion_fromithPos(root,tail,pos);
            root=move_tofront(root);
            print_toend(root);
            root=move_toend(root);
            print_tofront(root);
        }
        cin>>ch;
    }
}
