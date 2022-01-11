#include<iostream>
using namespace std;

class DNode{
    public:
       int data;
       DNode *next;
       DNode *prev;
       DNode(int data){
           this->data=data;
           next=NULL;
           prev=NULL;
       }
};

void print_from_front(DNode *h1){
    DNode *tmp1=h1;
    cout<<"FRONT"<<" ";
    while(tmp1!=NULL){
        cout<<tmp1->data<<" ";
        tmp1=tmp1->next;
    }
    cout<<endl;
}

void print_from_end(DNode *h5){
    DNode *tmp1=h5;
    cout<<"END"<<" ";
    while(tmp1!=NULL){
        cout<<tmp1->data<<" ";
        tmp1=tmp1->prev;
    }
    cout<<endl;
}

DNode *takeinput(){
    int data;
    cin>>data;
    DNode *head=NULL;
    DNode *tail=NULL;
    while(data!=-1){
      DNode *newNode=new DNode(data);
    
      if(head==NULL){
        head=newNode;
        tail=newNode;
      }
      else{
         DNode *temp=tail;
         temp->next=newNode;
         tail=newNode;
         newNode->prev=temp;
      } 
      cin>>data;
    }
    return head;
}

DNode *movetolast(DNode *head){
    DNode *tmp=head;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    return tmp;
}
/*
DNode *insertatithpos(DNode *head,int data,int pos){
    DNode *tail=NULL;
    if(head==NULL){
        if(pos==0){
            DNode *newNode=new DNode(data);
            newNode->prev=NULL;
            newNode->next=NULL;
            head=newNode;
            tail=newNode;
        }
        return head;
    }
    if(pos==0){
        DNode *newNode=new DNode(data);
        newNode->prev=NULL;
        newNode->next=head;
        head=newNode;
        tail=newNode;
        return head;
    }
    else{
        DNode *newNode=new DNode(data);
         
    }
}*/
void deleteNode(DNode *head,DNode *del_node){
    if(head==NULL || del_node == NULL){
        return;
    }
    if(head==del_node){
        head=head->next;
    }
    if (del_node->next != NULL){
           del_node->next->prev = del_node->prev;
    }
    if (del_node->prev != NULL){
      del_node->prev->next = del_node->next;
    }
    free(del_node);
}
int main(){
    /*DNode *h1=new DNode(1);
    DNode *h2=new DNode(3);
    DNode *h3=new DNode(5);
    DNode *h4=new DNode(7);
    DNode *h5=new DNode(9);
    h1->next=h2;
    h2->next=h3;
    h3->next=h4;
    h4->next=h5;
    h5->next=NULL;
    h5->prev=h4;
    h4->prev=h3;
    h3->prev=h2;
    h2->prev=h1;
    h1->prev=NULL;*/
    DNode *head=takeinput();
    print_from_front(head);
    //DNode *last=movetolast(head);
    //print_from_end(last);
    deleteNode(head,head->next->next->next);
    print_from_front(head);
}
