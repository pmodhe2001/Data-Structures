#include<iostream>
using namespace std;

class CNode{
    public:
       int data;
       CNode *next;
       CNode(int data){
           this->data=data;
           next=NULL;
       }
};

CNode *addtoempty(CNode *last,int data){
    if(last!=NULL){
        return last;
    }
    CNode *newNode = new CNode(data);
    last=newNode;
    last->next=newNode;
    return last;
}

CNode *addtofront(CNode *last,int data){
    if(last==NULL){
        return addtoempty(last,data);
        
    }
    CNode *newNode = new CNode(data);
    newNode->next=last->next;
    last->next=newNode;
    return last;
}

CNode *addEnd(CNode *last,int data){
    if(last==NULL){
        return addtoempty(last,data);
    }
    CNode *newNode = new CNode(data);
    newNode->next=last->next;
    last->next=newNode;
    last=newNode;
    return newNode;
}

void print(CNode *tail){
    if(tail==NULL){
        return;
    }
    CNode *tmp = tail->next;

    do {
       cout << tmp->data << " ";
       tmp = tmp->next;
    } 
    while (tmp != tail->next);
}


int main(){
    CNode *last=NULL;
   last = addtoempty(last, 6);
  last = addEnd(last, 8);
  last = addtofront(last, 2);
  last = addEnd(last, 10);
  last = addEnd(last, 12);
    print(last);
}
    
