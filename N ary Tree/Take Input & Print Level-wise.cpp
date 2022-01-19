#include <iostream>
#include<vector>
#include<queue>

using namespace std;
template<typename T>

class TreeNode{
    public:
       T data;
       vector<TreeNode<T>*> children;
       
       TreeNode(T data){
           this->data=data;
       }
};

TreeNode<int> *takeInputLevelWise(){
    int rootdata;
    cout<<"Enter Root Data : ";
    cin>>rootdata;
    TreeNode<int> *root= new TreeNode<int>(rootdata);
    
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int> *front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter number of childrens of : "<<front->data;
        for(int i=0;i<root->children.size();i++){
            int childData;
            cout<<"Enter "<<ith<<" child of "<<front->data<<endl;
            cin>>childData;
            TreeNode<int> *child=new TreeNode<int>*(childData);
            front->children.push_back(child)
            pendingNodes.push(child);
 
        }
    }
    return root;
}

void printTreeLevelWise(TreeNode<int> *root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    queue <TreeNode<int>*> pendingQ;
	pendingQ.push(root);
	while(pendingQ.size() != 0){
		TreeNode<int> *front = pendingQ.front();
		cout << front -> data <<":";
		pendingQ.pop();
		for (int i = 0; i < root->children.size(); i++) {
			pendingQ.push(root -> children[i]);
			
			if(root -> children.size() - 1 != i){
				cout << root -> children[i] -> data << ",";
			}
			else{
				cout << root -> children [i] -> data;
			}	
		}
		root = pendingQ.front();
		cout << endl;
	}
}

int main(){
    TreeNode<int> *root=takeInputLevelWise();
    printTreeLevelWise(root);
}
