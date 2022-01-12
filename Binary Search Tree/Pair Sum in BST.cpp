/*
Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
Note:
1. Assume the given binary tree contains all unique elements.
2. In a pair, print the smaller element first. Order of different pairs doesn't matter.
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
