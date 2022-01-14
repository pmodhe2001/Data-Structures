#include<vector>
vector<int>* getPath(BinaryTreeNode<int> *root , int data){
    if(root == NULL){
        return NULL;  // Base case when root is null
    }
    
    if(root -> data == data){
        vector<int> *output = new vector<int>();     // this vector is returned when required data  is found at root
        output -> push_back(root -> data);           // push back our root data in vector
        return output;                                
    }
    
    vector<int> *leftOutput = getPath(root -> left, data);  // this vector is returned when required data is found at left part of tree
    if(leftOutput != NULL){
        leftOutput -> push_back(root -> data);       
        return leftOutput;
    }
    
    vector<int> *rightOutput = getPath(root -> right, data);  // this vector is returned when required data is found at right part of tree
    if(rightOutput != NULL){
        rightOutput -> push_back(root -> data);
        return rightOutput;
    }
    else{
        return NULL;        // we reach here only when required data does not exists in our Binary Tree
    }
}
