/*
https://techiedelight.com/practice/?problem=PreorderTreeTraversal
Given the root of a binary tree, return the preorder traversal of its nodes' values.

Input:
		   1
		 /   \
		/	    \
	   2	   3
	  /		  /   \
	 /	   / 	   \
	4		   5	    6
		   / \
		  /   \
		 7	   8

Output: [1, 2, 4, 3, 5, 7, 8, 6]

*/

class Solution
{
public:

	/*
		A binary tree node is defined as:

		class Node
		{
		public:
			int data;									// data field
			Node* left = nullptr, *right = nullptr;		// pointer to the left and right child

			Node() {}
			Node(int data): data(data) {}
			Node(int data, Node *left, Node *right): data(data), left(left), right(right) {}
		};
	*/
#include<stack>
	vector<int> findPreorderTraversal(Node* root)
	{
		vector<int> pre;
		if(root==NULL){
			return pre;
		}
	    stack<Node*> stk;
	    stk.push(root);
	    
	    while(stk.size()!=0){
	    	Node *temp=stk.top();
	    	stk.pop();
	    	pre.push_back(temp->data);
	    	if(temp->right!=NULL){
	    		stk.push(temp->right);
	    	}
	    	if(temp->left!=NULL){
	    		stk.push(temp->left);
	    	}
	    	
	    }
	    return pre;
	}
};
