#include<algorithm>
void traverse(BinaryTreeNode<int> *root,vector<int> &in){
    if(root==NULL){
        return;
    }
    in.push_back(root->data);
    traverse(root->left,in);
    traverse(root->right,in);
}

void convert_tobst(BinaryTreeNode<int>*root,int &i,vector<int> &in){
    if(root==NULL){
        return;
    }
    convert_tobst(root->left,i,in);
    root->data=in[i];i++;
    convert_tobst(root->right,i,in);
}
BinaryTreeNode<int>* binaryTreeToBst(BinaryTreeNode<int>* root)
{
    vector<int> in;
    traverse(root,in);
    sort(in.begin(),in.end());
    int i=0
    convert_tobst(root,0,in);
    return root;
}
