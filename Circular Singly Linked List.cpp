

#include<iostream>
using namespace std;

class CNode{
    public:
       int data;
       Node *next;
       CNode(int data){
           this->data=data;
           next=NULL;
       }
}

void print(CNode *head){
    CNode *tmp=head;
    while(true){
        cout<<tmp->data<<" ";
        tmp=tmp->next;
        if(tmp==head){
            break;
        }
    }
    cout<<endl;
}

CNode *takeInput_atfront(CNode *head){
    CNode *tail=NULL;
    CNode *newNode= new CNode(data);
    if(head==NULL){
        head=newNode;
        newNode->next=newNode;
    }
    else{
        CNode *tmp=head;
        
    }
}
int main(){
    
}
