Node* swapNodes(Node *head,int i,int j) {
    Node *temp = head, *prev = NULL; 
    Node *Node1 = NULL, *Node2 = NULL, *node1_prev = NULL, *node2_prev = NULL;
    int pos = 0;
    
    // if i and j are equal
    if(i == j) return head; //No changes
    
    while(temp != NULL) {
        if(pos == i) {
            node1_prev = prev; 
            Node1 = temp;
        }
        else if(pos == j) {
            node2_prev = prev; Node2 = temp;
        }
        prev = temp;
        temp = temp -> next; pos++; 
    }
    if(node1_prev != NULL) {
        node1_prev -> next = Node2;
    }
    else { 
        head = Node2;
    }
    if(node2_prev != NULL) { 
        node2_prev -> next = Node1; 
    }
    else {
        head = Node1;
    }
    Node *temp1 = Node2 -> next;
    Node2 -> next = Node1 -> next; 
    Node1 -> next = temp1;
    return head;
}
