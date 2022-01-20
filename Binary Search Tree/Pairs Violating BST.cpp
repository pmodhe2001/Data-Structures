// https://www.codingninjas.com/codestudio/problems/pairs-violating-bst_1404414?leftPanelTab=0
void traverse(BinaryTreeNode<int> *root,vector<int> &in){
    if(root==NULL){
        return;
    }
    
    traverse(root->left,in);
    in.push_back(root->data);
    traverse(root->right,in);
}

int pairsViolatingBST(BinaryTreeNode<int> *root)
{
    if(!root)return 0;
    vector<int> arr;int count=0;
    traverse(root,arr);
    for (int i = 0;i<arr.size(); i++) {
        for (int j=i+1;j<arr.size();j++) {
            if (arr[i]>arr[j]) {
                count++;
            }
        }
    }
    return count;
}
