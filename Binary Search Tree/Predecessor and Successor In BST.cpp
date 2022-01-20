 void traversal(binaryTreeNode *root,vector<int> &set){
        if(root==NULL) return;
        traversal(root->left,set);
        set.push_back(root->data);
        traversal(root->right,set);
 }
int binary_search(vector<int> &in,int key,int start,int end){
    if(start>end){
        return -1;
    }
    while(start<=end){
        int mid=start+(end-start)/2;
        if(in[mid]==key){
            return mid;
        }
        if(in[mid]>key){
           return binary_search(in,key,start,mid-1);
        }
        if(in[mid]<key){
            return binary_search(in,key,mid+1,end);
        }
    }
}
    
    

vector<int> findPreSuc(binaryTreeNode *root, int key)
{
    vector<int> in;
    vector<int>res;
    if(!root)return res;
    traversal(root,in);
    int index=binary_search(in,key,0,in.size()-1);
    int pre=index-1;int succ=index+1;
    if(index==0){
        pre=-1;
        succ=in[index+1];
        res.push_back(pre);
    res.push_back(succ);
        return res;
    }
    if(index==in.size()){
        succ=-1;
        pre=in[index-1];
         res.push_back(pre);
    res.push_back(succ);  
        return res;
    }
 
    res.push_back(in[pre]);
    res.push_back(in[succ]);
    return res;
}
