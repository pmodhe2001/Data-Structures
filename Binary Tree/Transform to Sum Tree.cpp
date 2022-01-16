//https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1#
int helpertoSumTree(Node *node){
         if(node==NULL){
            return 0;
        }
        
        if(node->left==NULL && node->right==NULL){
            int temp=node->data;
            node->data=0;
            return temp;
        }
        
        int curr_data=node->data;
        node->data=helpertoSumTree(node->left)+helpertoSumTree(node->right);
        return curr_data+node->data;
}
void toSumTree(Node *node)
{
       helpertoSumTree(node);
}
