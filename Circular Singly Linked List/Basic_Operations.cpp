#include<iostream>
using namespace std;

class Node{
  public:
     int data;
     Node *next=NULL;
     Node(int data){
         this->data=data;
         Node *next=NULL;
     }
};

Node *takeInput(Node *&tail){
    int data;
    cin>>data;
    while(data!=-1){
        if(tail==NULL){
            Node *newNode=new Node(data);
            newNode->next=newNode;
            tail=newNode;
        }
        else{
            Node *newNode=new Node(data);
            newNode->next=tail->next;
            tail->next=newNode;
            tail=newNode;
        }
        cin>>data;
    }
    
    return tail;
}

Node *takeInput_Begg(Node *tail){
    int data;
    cin>>data;
    while(data!=-1){
        if(tail==NULL){
           Node *newNode=new Node(data);
           newNode->next=newNode;
           tail=newNode;
        }
        else{
           Node *newNode=new Node(data);
           newNode->next=tail->next;
           tail->next=newNode;
        }
        cin>>data;
    }
    
    return tail;
}
void print(Node *&tail){
    
    Node *tmp=tail->next;
    while(tmp!=tail){
        cout<<tmp->data<<" ";
        tmp=tmp->next;
        
    }
    cout<<tail->data<<" "; 
    cout<<endl;
}

Node *delFrombegg(Node *&tail){
    if(tail==NULL){
        return NULL;
    }
    Node *tmp_del=tail->next;
    tail->next=tail->next->next;
    free(tmp_del);
    return tail;
}

Node *delFromEnd(Node *head){   
    if(head==NULL)return NULL;
    Node *tmp=head;
    while(tmp->next->next!=head){
        tmp=tmp->next;
    }
    Node* temp_del = tmp->next;
    tmp->next = head;
    free(temp_del);  
    return tmp;
}
int main()
{
    int choice=-1;
    cin>>choice;
    while(choice!=-1){
        if(choice==1){
            Node *tail=NULL;
            tail=takeInput(tail); // Taking Input from end
            print(tail);
        }
        else if(choice==2){
            Node *tail=NULL;
            tail=takeInput_Begg(tail);
            print(tail);
        }
        else if(choice==3){
            Node *tail=NULL;
            tail=takeInput(tail); // Taking Input from end
            print(tail);
            tail=delFrombegg(tail); // Deleting from beggining
            print(tail);
        }else if(choice==4){
            Node *tail=NULL;
            tail=takeInput(tail); // Taking Input from end
            print(tail);
            tail=delFromEnd(tail->next); // Deleting from End
            print(tail);
        }
        cin>>choice;
    }
   
}
