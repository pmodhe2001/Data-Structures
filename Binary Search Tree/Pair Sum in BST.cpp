/*
Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
Note:
1. Assume the given binary tree contains all unique elements.
2. In a pair, print the smaller element first. Order of different pairs doesn't matter.
*/

// Approach 1 : Sorting Based
#include<algorithm>
#include<vector>

void convertToArray(BinaryTreeNode<int> *root,vector<int> &output){
    if(root==NULL){
        return;
    }
    output.push_back(root->data);
    convertToArray(root->left,output);
    convertToArray(root->right,output);
    
}

void pairSum(BinaryTreeNode<int> *root,int sum){
    vector<int> output;
    convertToArray(root,output);
    sort(output.begin(),output.end());
    int i=0,j=output.size()-1;
    while(i<j){
        if(output[i]+output[j]==sum){
            cout<<output[i]<<" "<<output[j]<<endl;
            i++;j--;
        }
        else if(output[j]+output[i]<sum){
            i++;
        }
        else{
            j++;
        }
    }
}

// Approach 2 : Hashing Based
