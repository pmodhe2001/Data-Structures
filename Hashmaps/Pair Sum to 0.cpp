#include <iostream>
#include <unordered_map>

using namespace std;

int pairSum(int *arr, int n) {
    int cnt = 0;
  unordered_map<int,int> ourmap;
    for (int i = 0; i < n; i++)
    {
    	int complement = -arr[i];
        if(ourmap.find(complement) != ourmap.end()){
            cnt += ourmap[complement];
        }
        
       ourmap[arr[i]]++;
    } 	
    return cnt;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}
