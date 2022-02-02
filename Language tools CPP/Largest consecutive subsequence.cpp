//https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1/#

//  Approach 1 TC: O(nLogn) Using sorting
int findLongestConseqSubseq(int arr[], int N)
    {
      sort(arr,arr+N);
      int count=1,max=1;
      for(int i=0;i<N-1;i++){
          if(arr[i+1]-arr[i]==0){
              continue;
          }
          if(arr[i+1]-arr[i]==1){
              count++;
              if(count>max){
                 max=count;
              }
          }
          
          else{
              count=1;
          }
      }
      return max;
    }
};
//  Approach 2 : O(N) Using unordered set
int findLongestConseqSubseq(int arr[], int n)
    {
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(arr[i]);
        }
        int mini = INT_MAX;
        int maxi = INT_MIN;
      
        for(int i=0;i<n;i++){
          mini = min(mini, arr[i]);
          maxi = max(maxi, arr[i]);
        }
      
        int res = 0;
        int count = 0;
      
        for(int i = mini;i<=maxi;i++){
          if(st.find(i) != st.end()){
              count++;
              
              res = max(count,res);
          }
          else{
              count = 0;
          }
      }
      return res;
    }
