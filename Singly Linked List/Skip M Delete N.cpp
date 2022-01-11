Node *skipMdeleteN(Node *head,int M,int N){
    if(M==0 or head==NULL){
        return NULL;
    }
    if(N==0){
        return head;
    }
    Node *currentnode=head;
    Node *temp=NULL;
    while(currentnode!=NULL){
        int take=0;int skip=0;
        while(currentnode!=NULL && take<M){
            if(temp==NULL){
                temp=currentnode;
            }
            else{
                temp->next=currentnode;temp=currentnode;
            }
            currentnode=currentnode->next;
            take++;
        }
        while(currentnode!=NULL && skip<N){
            Node *save=currentnode;
            delete save;
            currentnode=save->next;
            skip++;
        }
    }
    if(temp!=NULL){
        temp->next=NULL;
    }
    return head;
}
