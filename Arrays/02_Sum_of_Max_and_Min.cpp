//https://www.codingninjas.com/codestudio/problems/sum-of-max-and-min_1081476?topList=love-babbar-dsa-sheet-problems&leftPanelTab=2
#include<bits/stdc++.h>
int sumOfMaxMin(int arr[], int n){
    int min =arr[0];
    int max= arr[0];
    for(int i=1;i<n;i++){
        if(min>arr[i]){
            min=arr[i];
        }
        if(max<arr[i]){
            max=arr[i];
        }
    }
    return min+max;
	//Write your code here
}
