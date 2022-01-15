#include <iostream>
#include<unordered_map>
using namespace std;
int highestFrequency(int *input,int n){
    unordered_map<int,int> mp;   // unordered map mp is declared
    for(int i=0;i<n;i++){
        int key=input[i];
        if(mp.count(key)==0){     // to check if int value key exists in map mp count function gives false when key does n't exist
            mp[key]=1;            // if does not exist put 1 on map[key]
        }else{
            mp[key]++;            // if exist increment value of mp[key] by 1
        }
    }
    
    int max_element=mp[input[0]];
    int ans=input[0];
    for(int j=1;j<n;j++){
        if(mp[input[j]]>max_element){
            max_element=mp[input[j]];
            ans=input[j];
        }
    }
    return ans;
}
int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}
