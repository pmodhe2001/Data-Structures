#include<iostream>
using namespace std;

class Node{
  public:
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        Node *next=NULL;
    }
};

/* Iterative Functions */
Node *takeInput(){ // This is basically Insert at End
    Node *head=NULL;
    Node *tail=NULL;
    int data;
    cin>>data;
    while(data!=-1){
        if(head==NULL){
            Node *newNode=new Node(data);
            head=newNode;
            tail=newNode;
        }else{
            Node *newNode=new Node(data);
            tail->next=newNode;
            tail=newNode;
        }
        cin>>data;
    }
    return head;
}

void print(Node *head){
    Node *tmp=head;
    while(tmp){
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
}

Node* insertAtBeginning(Node *&head){
    int data;
    cin>>data;
    while(data!=-1){
        if(head==NULL){                                         //Edge case 1: if head == NULL
            Node *newNode=new Node(data);
            head=newNode;
        }
        else{
           Node *newNode=new Node(data);
           newNode->next=head;
           head=newNode;
        }
        cin>>data;
    }
    return head;
}

Node *insertAtithPos(Node *&head,int pos,int data){
    if(head==NULL && pos==0){                                       // Edge Case 1: if head is NULL and pos is equals to Zero
        Node *newNode=new Node(data);                                                           // then create newNode and return it
        head=newNode;
        return head;
    }
    if(head==NULL && pos!=0){                                       // Edge Case 2: if head is NULL and pos is non-zero
        cout<<"Given Singly Linked List is Empty & position is non zero"<<endl;                 // return NULL
        return NULL;
    }
    if(head!=NULL){
        Node *newNode=new Node(data);
        Node *tempHead=head;
        for(int i=0;i<pos-1;i++){
            tempHead=tempHead->next;
        }
        newNode->next=tempHead->next;
        tempHead->next=newNode;
    }
    return  head;
}

void del_at_Beginning(Node *&head){
    if(head==NULL)return;      // Edge case 1 : If head is at NULL
    Node *tmp_del=head;
    head=head->next;
    free(tmp_del);
}

void del_at_end(Node *&head){
    if(head==NULL)return;           // Edge case 1 : If head is at NULL
    Node *tmp=head;
    while(tmp->next->next!=NULL){
        tmp=tmp->next;
    }
    Node *temp_del=tmp->next;
    tmp->next=NULL;
    free(temp_del);
}

void delAtithPos(Node *&head,int pos){
    if(head==NULL){                  // Case 1 : If head is at NULL return
        return;                          
    }
    if(head!=NULL && pos==0){       // Case 2 : If head is not at NULL and pos is equal to zero
        Node *tmp_del=head;
        head=head->next;
        free(tmp_del);
        return;
    }
    if(head!=NULL){
        Node *temp_move=head;
        for(int i=0;i<pos-1;i++){
            temp_move=temp_move->next;
        }
        Node *temp_del=temp_move->next;
        temp_move->next=temp_move->next->next;
    }
}

int length(Node *head){
    Node *temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

int search(Node *head,int target){
    if(head==NULL)return -1;
    Node *temp=head;
    int count=0;
    while(temp!=NULL && temp->data!=target){
        count++;
        temp=temp->next;
    }
    return count;
}

void PrintIthNode(Node *head,int pos){
    if(head==NULL){
        return;
    }
    if(length(head)>pos){
        return;
    }
    Node *temp=head;
    int i=pos;
    while(temp!=NULL){
        if(pos==0){
            cout<<temp->data<<endl;
        }
        i--;
        temp=temp->next;
    }
}

/* Recursive Functions*/

Node *takeInput_Recursively(Node *head,int data,int pos){
    if(head==NULL){
        if(pos==0){
            Node *newNode=new Node(data);
            head=newNode;
            return head;
        }
        return head;
    }
    Node *newNode=new Node(data);
    if(pos==0){
        newNode->next=head;
        head=newNode;
        return newNode;
    }
    head->next=takeInput_Recursively(head->next,data,pos-1);
    return head;
}

void print_recursively(Node *head){
    if(head==NULL){
        return;
    }
    cout<<head->data<<" ";
    print_recursively(head->next);
}

Node* del_ithNodeRecursively(Node *head,int pos){
    if(head==NULL){
        return NULL;
    }
    if(pos==0){
        Node *temp_del=head;
        head=temp_del->next;
        free(temp_del);
        return head;
    }
    Node *x=del_ithNodeRecursively(head->next,pos-1);
    head->next=x;
    return head;
}

int lengthRecursively(Node *head){
    if(head==NULL){
        return 0;
    }
    return lengthRecursively(head->next)+1;
}

int SearchRecursively(Node *head,int data){
    if(head==NULL){
        return -1;
    }
    
    if(head->data==data){
        return 0;
    }
    
    return SearchRecursively(head->next,data)+1;
}
int main(){
    int choice;
    cin>>choice;
    Node *root=NULL;
    while(choice!=-1){
        if(choice==1){
          root=takeInput();  // Input at end
          print(root);
        }
       else if(choice==2){
          root=insertAtBeginning(root);  // Input from beginning
          print(root);
       }
       else if(choice==3){
           root=takeInput();  // Input at end
           int pos,d;
           cin>>pos>>d;
           root=insertAtithPos(root,pos,d);  // Input from ith Positon
           print(root);
       }
       else if(choice==4){
           root=takeInput();  // Input at end
           del_at_Beginning(root); // delete from beginning
           print(root);
       }
       else if(choice==5){
           root=takeInput();  // Input at end
           del_at_end(root); // delete from end
           print(root);
       }
       else if(choice==6){
           root=takeInput();  // Input at end
           int pos;
           cin>>pos;
           delAtithPos(root,pos); // delete from any position
           print(root);
       }
       else if(choice==7){
           root=takeInput();  // Input at end
           cout<<length(root)<<endl;
       }
       else if(choice==8){
           root=takeInput();  // Input at end
           int target;
           cin>>target;
           if(search(root,target)==-1){
               cout<<"Not found"<<endl;
           }
           else{
               cout<<"Found at index"<<" "<<search(root,target)<<endl;
           }
       }
       else if(choice==9){
           root=takeInput();  // Input at end
           int pos;
           cin>>pos;
           PrintIthNode(root,pos);
       }
       else if(choice==10){
           int data;int pos;
           root=takeInput();
           cin>>data>>pos;
           root=takeInput_Recursively(root,data,pos); // Input at ith pos Recursively 
           print_recursively(root);
       }
       else if(choice==11){
           Node *root=takeInput();
           print_recursively(root);
           int pos;
           cin>>pos;
           del_ithNodeRecursively(root,pos);
           print_recursively(root);
       }
       else if(choice==12){
           Node *root=takeInput();
           cout<<lengthRecursively(root)<<endl;
       }
       else if(choice==13){
           Node *root=takeInput();
           int data;
           cin>>data;
           if(SearchRecursively(root,data)==-1){
               cout<<"Does not exists"<<endl;
           }
           else{
               cout<<"Element at "<<SearchRecursively(root,data)<<endl;
           }
         
       }
    }
}
