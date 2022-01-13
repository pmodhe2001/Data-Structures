/*For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need 
to construct the tree and return the root.*/
BinaryTreeNode<int> *buildTreeHelper(int *preorder,int *inorder,int inS,int inE,int preS,int preE){
    if(inS>inE){
        return NULL;
    }
    int rootData=preorder[preS];
    int rootIndex=-1;
    for(int i=inS;i<=inE;i++){
        if(inorder[i]==rootData){
            rootIndex=i;
            break;
        }
    }
   
    int lInS=inS;
    int lInE=rootIndex-1;
    int lPreS=preS+1;  
    // lInE-lInS=lPreE-lPreS
    int lPreE=lInE-lInS+lPreS; 
    int rPreS=lPreE+1;
    int rPreE=preE;
    int rInS=rootIndex+1  ;
    int rInE=inE;
    
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootData);
    root->left=buildTreeHelper(preorder,inorder,lInS,lInE,lPreS,lPreE);
    root->right=buildTreeHelper(preorder,inorder,rInS,rInE,rPreS,rPreE);
    return root;
}

BinaryTreeNode<int>* buildTree(int *preOrder, int preLength, int *inOrder, int inLength) {
    return buildTreeHelper(preOrder,inOrder,0,inLength-1,0,preLength-1);
}
