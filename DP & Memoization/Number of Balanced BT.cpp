//https://practice.geeksforgeeks.org/problems/bbt-counter4914/1#
// Approach : 1 , Recursion , TC:O(2^h)
long long int mod=pow(10,9)+7;
    long long int countBT(int h) { 
        if(h<=1){
            return 1;
        }
        
        long long int x=countBT(h-1)%mod;
        long long int y=countBT(h-2)%mod;
        
        long long int res=((x*x)%mod+(2*x*y)%mod)%mod;
        return res;
}
// Approach : 2 , DP , TC:O(h)
long long int mod=pow(10,9)+7;
    long long int countBT(int h) { 
        long long int *dp=new long long int[h+1];
        
        dp[0]=dp[1]=1;
        
        for(int i=2;i<=h;i++){
            long long int x=dp[i-1]%mod;
            long long int y=dp[i-2]%mod;
            dp[i]= ((x*x)%mod+(2*x*y)%mod)%mod;
        }
        
        return dp[h];
        
        delete []dp;
    }
