void printLevelWise(BinaryTreeNode <int> *root){
    if(root==NULL){
        return;
    }
    queue <BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    
    while(q.size()!=0){
        BinaryTreeNode<int> *front=q.front();
        q.pop();
        
        if(front==NULL){
            if(q.empty()==true){
                return;
            }
            else{
                cout<<endl;
                q.push(NULL);
            }
        }else{
            cout<<front->data<<" ";
            if(front->left!=NULL){
                q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }
        }
    }
}
