// Approach 1 : Recursion
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCostPath(int **input, int m, int n, int i, int j) {
	// Base case
	if(i == m- 1 && j == n- 1) {
		return input[i][j]; // when 2d array is of size 1,1
	}

	if(i >= m || j >= n) {
		return INT_MAX; // when our calls goes out of 2d arr
	}

	// Recursive calls
	int x = minCostPath(input, m, n, i, j+1); // move vertically downwards
	int y = minCostPath(input, m, n, i+1, j+1); // move diagonally downwards
	int z = minCostPath(input, m, n, i+1, j);  // move horizontally right

	// Small Calculation
	int ans = min(x, min(y, z)) + input[i][j];
	return ans;
}

int minCostPath(int **input, int m, int n) {
    return minCostPath(input, m, n, 0, 0);    
}

int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
}


// Approach 2 : Memoization
// Wrong answer from this approach
#include<iostream>
#include<climits>
using namespace std;

int MinCostPath(int **input,int n,int m,int i,int j,int **output){
    if(i==n-1 || j==m-1){
        return input[i][j];
    }
    if(i>=m || j>=n){
        return INT_MAX;
    }
    
    if(output[i][j]!=-1){
        return output[i][j];
    }
    
    int x=MinCostPath(input,n,m,i,j+1,output);
    int y=MinCostPath(input,n,m,i+1,j+1,output);
    int z=MinCostPath(input,n,m,i+1,j,output);
    
    int ans=min(x,min(y,z)) + input[i][j];
    output[i][j]=ans;
    return ans;
}
int MinCostPathMem(int **arr,int n,int m,int i,int j){
    int **mem=new int*[n];
    for(int i=0;i<n;i++){
        mem[i]=new int[m];
        for(int j=0;j<m;j++){
            mem[i][j]=-1;
        }
    }
    return MinCostPath(arr,n,m,i,j,mem);
}
int main(){
    int n,m;
    cin>>n>>m;
    
    int **arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[m];
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    
   cout<< MinCostPathMem(arr,n,m,0,0)<<endl;;
    //cout<<MinCostPath(arr,)<<endl;
}


// Approach 3 , DP
#include <iostream>
#include <climits>
using namespace std;

int minCost_DP(int **input, int m, int n) {
	int **ans = new int*[m];
	for(int i = 0; i < m; i++) {
		ans[i] = new int[n];
	}

	ans[m-1][n-1] = input[m-1][n-1]; // Filling last row last col

	
	for(int j = n - 2; j >= 0; j--) {
		ans[m-1][j] = input[m-1][j] + ans[m-1][j+1]; // Filling row from last
	}

	
	for(int i = m-2; i >= 0; i--) {
		ans[i][n-1] = input[i][n-1] + ans[i+1][n-1]; // Filling last col from last
	}

	for(int i = m-2; i >= 0; i--) {
		for(int j = n-2; j >= 0; j--) {
			ans[i][j] = input[i][j] + min(ans[i][j+1], min(ans[i+1][j+1], ans[i+1][j]));  // getting minimim path by min func 
		}
	}
	return ans[0][0];
}

int main() {
	int m, n;
	cin >> m >> n;
	int **input = new int*[m];
	for(int i = 0; i < m; i++) {
		input[i] = new int[n];
		for(int j = 0; j < n; j++) {
			cin >> input[i][j];
		}	
	}
	cout << minCost_DP(input, m, n) << endl;
}
