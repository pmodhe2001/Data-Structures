// https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1/#

//Approach 1 : Recursion , TC()
bool checkPerfect(int n){
	    int r=sqrt(n);
	    if(r*r==n){
	        return true;
	    }
	    return false;
	}
	int MinSquares(int n)
	{
	    if(n==1 || n==2 || n==3 || n==0){
	        return n;
	    }
	    
	    if(checkPerfect(n)){
	        return 1;
	    }
	    
	    int res=n;
	    
	    for(int i=1;i*i<=n;i++){
	        res=min(res,1+MinSquares(n-i*i));
	    }
	    
	    return res;
	}
//Approach 2 : DP , TC:O(nsqrt(n))
	int MinSquares(int n)
	{
	    
	    int *dp=new int[n+1];
	    dp[0]=0;
	    for(int i=1;i<=n;i++){
	        dp[i]=i;
	        // now we'll minimize ith element
	        for(int j=1;j*j<=i;j++){
	            int sq=j*j;
	            dp[i]=min(dp[i],1+dp[i-sq]);
	        }
	    }
	    
	    return dp[n];
	}
