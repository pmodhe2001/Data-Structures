// Approach 1 : Using sorting O(NlogN)
int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int count=1;
        int maxCount=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i+1]-nums[i]==1){
                count++;
            }
            if(count>maxCount){
                maxCount=count;
            }
            
        }
        return maxCount;
}
// Approach 2 : Using Hashmap O(N)
    int longestConsecutive(vector<int>& nums) {
        
        int n=nums.size();
        
        unordered_map<int,bool> mp;
        
        for(int i=0;i<n;i++){
            mp[nums[i]]=true;
        }
        
        int maxCount=0;
        
        for(int i=0;i<n;i++){
            int count=0;
            if(mp.find(nums[i]-1)==mp.end()){
                int next=nums[i]+1;
                count=1;                                         
                while(mp.find(next)!=mp.end()){
                    count+=1;
                    next+=1;
                }
            }
            maxCount=max(maxCount,count);
        }   
           return maxCount; 
}
