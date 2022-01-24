//https://www.codingninjas.com/codestudio/problems/detect-the-first-node-of-the-loop_1112628?leftPanelTab=0
Node *firstNode(Node *head)
{
      if(head==NULL){
          return head;
      }
    Node *temp=head;
    unordered_set<Node*> seen;
    while(temp!=NULL){
        if(seen.count(temp)==1){
            return temp;
        }
        else{
            seen.insert(temp);
        }
        temp=temp->next;
    }
    return NULL;
}
