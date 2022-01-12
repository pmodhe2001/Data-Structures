/*
Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space of the order of O(log n).
*/

// Approach 1 : Sorting Based
#include<bits/stdc++.h>
void helper(BinaryTreeNode<int> *root, vector<int> &arr){
	if(root == NULL){
        return;
    }
    
    
    
    helper(root -> left, arr);
    arr.push_back(root -> data);
    helper(root -> right, arr);
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    
    vector<int> output;
    
    helper(root, output);
    
    //sort(output.begin(), output.end());
    
    int i = 0; int j = output.size() - 1;
    while(i < j){
        
        if(output[i] + output[j] > s){
            j--;
        }
        else if(output[i] + output[j] < s){
            i++;
        }
        else{
            cout << output[i] << " " << output[j] << endl;
            i++;
            j--;
        }
    }

}


// Approach 2 : Hashing Based
