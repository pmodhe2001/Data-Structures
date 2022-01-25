#define mod 1000000007
long long num(Node *head){
    Node *tmp=head;
    long long res=0;
    while(tmp!=NULL){
        res=(res*10+tmp->data)%mod;
        tmp=tmp->next;
    }
    return res;
}
long long  multiplyTwoLists (Node* l1, Node* l2)
{
  return (num(l1)*num(l2))%mod;
}
