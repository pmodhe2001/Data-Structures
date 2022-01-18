vector<int> inorder_arr(vector<int> &arr,int i,vector<int> &in_arr){
    if(i>=arr.size()){
        return in_arr;
    }
    inorder_arr(arr,(2*i+1),in_arr);
    in_arr.push_back(arr[i]);
    inorder_arr(arr,(2*i+2),in_arr);
    return in_arr;
}

int minimumSwaps(vector<int>&arr, int n) {
	vector<int> in_arr;
    in_arr=inorder_arr(arr,0,in_arr);
    vector<pair<int,int>> res;
    for(int i=0;i<n;i++){
        res.push_back({in_arr[i],i});
    }
    sort(res.begin(),res.end());
    int count=0;
    for (int i=0; i<n; i++){
        if(res[i].second==i){
            
        }
        else{
            count++;
            swap(res[i],res[res[i].second]);
            i--;
        }
    }
    return count;
}
