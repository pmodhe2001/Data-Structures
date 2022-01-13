/*
Path Sum Root to Leaf
For a given Binary Tree of type integer and a number K, print out all root-to-leaf paths where the sum of all the node data along the path is equal to K.
*/
#include<vector>
void helper(BinaryTreeNode<int> *root, int k, vector<int> v){
    
    if(root == NULL){
        return;
    }
    
    if(root -> left == NULL && root -> right == NULL){
        if(k - root -> data == 0){
            int i = 0;
            while(i < v.size()){
                cout << v[i] << " ";
                i++;
            }
            
            cout << root -> data << endl;
        }
        return;
    }
    
    v.push_back(root -> data);
    helper(root -> left, k - root -> data, v);
    helper(root -> right, k - root -> data, v);
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
	
    vector<int> v;
    
    helper(root, k, v);
}
