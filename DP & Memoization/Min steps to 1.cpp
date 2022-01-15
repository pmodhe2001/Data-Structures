#include <iostream>
using namespace std;

int minStepsHelper(int n, int *ans) {
	// Base case
	if(n <= 1) {
		return 0;
	}

	// Check if output already exists
	if(ans[n] != -1) {
		return ans[n];
	}

	// Calculate output
	int x = minStepsHelper(n - 1, ans);

	int y = INT_MAX, z = INT_MAX;
	if(n % 2 == 0) {
		y = minStepsHelper(n/2, ans);
	}

	if(n % 3 == 0) {
		z = minStepsHelper(n/3, ans);
	}

	int output = min(x, min(y, z)) + 1;

	// Save output for future use
	ans[n] = output;

	return output;

}

int misSteps_2(int n) {
	int *ans = new int[n+1];

	for(int i = 0; i <= n; i++) {
		ans[i] = -1;
	}

	return minStepsHelper(n, ans);
}


int minSteps(int n) {
	// Base case
	if(n <= 1) {
		return 0;
	}

	// Recursive call
	int x = minSteps(n - 1);

	int y = INT_MAX, z = INT_MAX;
	if(n % 2 == 0) {
		y = minSteps(n/2);
	}

	if(n % 3 == 0) {
		z = minSteps(n/3);
	}

	// Calculate final output
	int ans = min(x, min(y, z)) + 1;
	return ans;

}

int countStepsToOne(int n){
    int *dp = new int[n+1];
    
    for(int i = 0; i <= n; i++) 
        dp[i] = 0;
    
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1
        ;
    int ans1,ans2,ans3;
    
    for(int i=4;i<=n;i++) { 
        ans1=ans2=ans3=INT_MAX;
        
        ans1=dp[i-1]; 
        if(i%2==0) { 
            ans2=dp[i/2];
        } 
        if(i%3==0) {
            ans3=dp[i/3];
        }
        dp[i]=1+min(min(ans1,ans2),ans3);
    }
    int ans=dp[n];
    delete dp;
    return ans;
}

int main() {
	int n;
	cin >> n;

	cout << countStepsToOne((n) << endl;
}
