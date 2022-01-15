#include <iostream>
#include<unordered_map>

using namespace std;

int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
    int ans = 0;
	unordered_map<int, int>mp;
    
    for(int i = 0;i < n; i++){
	int c = arr[i] + k;
        ans += mp[c];
        if(k != 0){
            int c = arr[i] - k;
            ans += mp[c];
        }
        mp[arr[i]]++;
    }
	return ans;
}

int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}
