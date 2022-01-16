/*
https://techiedelight.com/practice/?problem=PostorderTreeTraversal
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Input:
		   1
		 /   \
		/	  \
	   2	   3
	  /		  / \
	 /	  	 /	 \
	4		5	  6
		   / \
		  /   \
		 7	   8

Output: [4, 2, 7, 8, 5, 6, 3, 1]

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

	vector<int> findPostorderTraversal(Node* root)
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
	    	if(temp->left!=NULL){
	    		stk.push(temp->left);
	    	}
	    	
	    	if(temp->right!=NULL){
	    		stk.push(temp->right);
	    	}
	    
	    }
	    reverse(pre.begin(),pre.end());
	    return pre;
	}
};
